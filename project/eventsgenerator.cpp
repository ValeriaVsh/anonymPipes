#include "eventsgenerator.h"

EventsGenerator::EventsGenerator()
{

}
EventsGenerator::~EventsGenerator()
{

}

void EventsGenerator::generateEvents(int average_iterval_sec, std::atomic<bool> &running)
{
	resetAverageInterval(average_iterval_sec);
	while (running)
	{
		int interval = _generateInterval();
		std::cout << "interval: " << interval << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(interval));
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