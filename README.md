# anonymPipes
Project includes 3 threads: user input, event generator, and logger. Data is supposed to be transmitted between threads by anonym pipes

main thread handles user input commands
second thread: event generator thread. 
third thread: event logger thread.
 
event generator thread generates events within random period of time (1 - 10 seconds) and writes event to anonym pipe.
logger thread reads event from pipe and writes event log to file "default_logs.txt" (in folder where .exe of program is)

user input commands:
"stop" - stops the proggram
"pause" - pauses events generation
"resume" - resumes events generation
"date" - outputs current date
"time" - outputs current time
"logger1" - changes logger level to level 1 (event's id and datetime is logged)
"logger2" - changes logger level to level 2 (event's id, datetime and parameter 1 is logged)
"logger3" - changes logger level to level 3 (all event's data is logged)
