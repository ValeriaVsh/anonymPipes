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
#include "eventgen_thread.h"

using namespace std;



int main()
{
	int count_id = 0;

	Logger* logger = Logger::GetLogger(Level1);


	string command;
	EventsGenerator* generator = new EventsGenerator;
	LoggerThread *logger_thread = new LoggerThread(generator->GetPipeHandler(), logger);
	logger_thread->Start();
	
	int default_interval{ 5 };
	atomic<bool> running = true;
	EventGen_Thread* events_thread = new EventGen_Thread(generator, default_interval);
	events_thread->Start();

	

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
		else if (command == "pause")
		{
			logger_thread->Stop();
			logger_thread->Join();
			events_thread->Stop();
			events_thread->Join();

			
		}
		else if (command == "resume")
		{
			logger_thread->Stop();
			events_thread->Stop();
			
			logger_thread->Start();
			events_thread->Start();
			

		}

		else if (command == "stop")
		{
			running = false;
			break;
		}

	}
	
	logger_thread->Stop();
	logger_thread->Join();
	events_thread->Stop();
	events_thread->Join();

	
	delete logger;
	delete generator;
	delete logger_thread;
	delete events_thread;
	
	
	
	return 0;

 

}
