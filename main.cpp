#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

// struct
struct LogEntry {
char date[11]; // YYYY-MM-DD
char time[13]; // HH:MM:SS.mmm
int pid; // ID процесса
char thread[9]; // Thread ID (hex)
char module[30]; // Название модуля
char level[8]; // INFO/WARNING/ERROR
char* payload; // Текст сообщени
};

// lines count
int countLines(const char* filename) {
std::ifstream file(filename);
if (!file.is_open()) return -1;
int count = 0;
std::string line;
while (std::getline(file, line)) {
count++;
}
return count;
}

int main() {
const char* filename = "BlueStacks-Installer_5.21.150.1021.log";
int totalLines = countLines(filename);
std::cout << "Всего строк в файле: " << totalLines << std::endl;
// memory for arrays
LogEntry** entries = new LogEntry*[totalLines];
for (int i = 0; i < totalLines; i++) {
entries[i] = nullptr;
}
// read & pars file
std::ifstream file(filename);
std::string line;
int validCount = 0;
while (std::getline(file, line)) {
std::istringstream iss(line);
LogEntry* entry = new LogEntry();
std::string date, time, pidThread, module, level;
iss >> date >> time >> pidThread >> module >> level;
// date & time
strcpy(entry->date, date.c_str());
strcpy(entry->time, time.c_str());
// pid:thread_id
size_t colonPos = pidThread.find(':');
if (colonPos != std::string::npos) {
entry->pid = std::stoi(pidThread.substr(0, colonPos));
std::string threadId = pidThread.substr(colonPos + 1);
strcpy(entry->thread, threadId.c_str());
}
// module
if (module.size() >= 2) {
module = module.substr(1, module.size() - 2);
}
strcpy(entry->module, module.c_str());
// Убираем двоеточие из level
if (!level.empty() && level.back() == ':') {
level.pop_back();
}
strcpy(entry->level, level.c_str());
// Получаем payload (все что осталось)
std::string payload;
std::getline(iss, payload);
if (!payload.empty() && payload[0] == ' ') {
payload = payload.substr(1);
}
// Выделяем память под payload
entry->payload = new char[payload.length() + 1];
strcpy(entry->payload, payload.c_str());
entries[validCount] = entry;
validCount++;
}
file.close();
std::cout << "Успешно распарсено: " << validCount << " строк" << std::endl;
return 0;
}
