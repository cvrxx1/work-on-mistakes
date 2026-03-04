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
return 0;
}
