#include "eventsgenerator.h"

EventsGenerator::EventsGenerator()
{
	if (!pipeHandler.Initialize()) {
		throw std::runtime_error("Failed to initialize pipe handler");
	}
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
		Event event(_event_id++);
		
		// Write event to pipe
		if (!pipeHandler.WriteEvent(event)) {
			std::cerr << "Failed to write event to pipe" << std::endl;
			continue;
		}

		// Also write to logger if set
		// if (_logger) {
		// 	_logger->Write(event);
		// }

		std::this_thread::sleep_for(std::chrono::seconds(_generateInterval()));
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
	return _interval_min + (rand() % (_interval_max - _interval_min + 1));
}