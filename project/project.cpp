// project.cpp: определяет точку входа для приложения.
//

#include "project.h"
#include "iostream"
#include "thread"
#include "chrono"
#include "string.h"

#include "event.h"
#include "eventsgenerator.h"
#include <atomic>
#include "logger_thread.h"

using namespace std;

void thr1func(EventsGenerator &gen, atomic<bool> &running, int interval)
{
	gen.generateEvents(interval, running);

}


int main()
{
	int count_id = 0;

	//Event new_event(count_id);

	Logger* logger = Logger::GetLogger(Level1);


	string command;
	EventsGenerator generator;
	LoggerThread *logger_thread = new LoggerThread(generator.GetPipeHandler(), logger);
	logger_thread->Start();
	//generator.setLogger(logger);
	int default_interval{ 5 };
	atomic<bool> running = true;

	thread th1(thr1func, ref(generator), ref(running), default_interval);

	while (running)
	{
		cin >> command;

		if (command == "date")
		{
			auto datetime{ chrono::system_clock::now() };
			//auto date{ floor<chrono::days>(datetime) };
			chrono::year_month_day date{ floor<chrono::days>(datetime) };
			
			cout<<date << endl;
		}
		else if(command == "time")
		{
			auto datetime = chrono::system_clock::now();
			auto date{ floor<chrono::days>(datetime) };
			chrono::hh_mm_ss time{ floor<chrono::milliseconds>(datetime - date) };
			cout <<time << endl;

		}
		else if (command == "stop")
		{
			running = false;
			break;
		}

	}
	th1.join();
	logger_thread->Stop();
	logger_thread->Join();
	delete logger;
	
	
	
	return 0;

 

}
