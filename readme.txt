Все строки имеют вид:
YYYY-MM-DD HH:MM:SS.mmm PID:THREAD_ID (MODULE) LEVEL: PAYLOAD

YYYY-MM-DD - дата (год, месяц, день)
HH:MM:SS.mmm - время (час, мин, сек, мсек)
PID - id процесса
THREAD_ID - id вторая часть (16-ая строка)
(MODULE) - название модуля, сгенерировавшего процесс
LEVEL: - характер сообщения (info, warning, error)
PAYLOAD - о чем говорит сообщение

Есть кол-во строки которые отличаются немного:
- Строки с многострочным PAYLOAD
- Строки с PID имееющим маркер (OUT, HD-CheckCpu.exe...) 