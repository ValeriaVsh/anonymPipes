#include "eventsgenerator.h"

EventsGenerator::EventsGenerator()
{

}
EventsGenerator::~EventsGenerator()
{

}
void EventsGenerator::setLogger(Logger* logger)
{
	_logger = logger;
}

void EventsGenerator::generateEvents(int average_iterval_sec, std::atomic<bool> &running)
{
	resetAverageInterval(average_iterval_sec);
	while (running)
	{
		int interval = _generateInterval();
		std::cout << "interval: " << interval << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(interval));

		Event* event = new Event(_event_id);
		_events_queue.push(*event);

		Logger* logger1 = Logger::GetLogger(Level1);
		logger1 = logger1->Write(*event);

		/*Logger* logger2 = Logger::GetLogger(Level2);
		logger2 = logger2->Write(*event);

		Logger* logger3 = Logger::GetLogger(Level3);
		logger3 = logger3->Write(*event);*/

		delete event;
		//delete[] logger1;
		/*delete[] logger2;
		delete[] logger3;*/


	}
	
}
void EventsGenerator::resetAverageInterval(int& average_iterval_sec)
{
	_interval_min = average_iterval_sec - 5;
	_interval_max = average_iterval_sec + 5;
	if (_interval_min < 1)
		_interval_min = 1;

}
int EventsGenerator::_generateInterval()
{
	srand((unsigned)time(NULL));
	int interval{ _interval_min + rand() % _interval_max};


	return interval;
}