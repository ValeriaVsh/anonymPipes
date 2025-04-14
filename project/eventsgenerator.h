#pragma once

#include "event.h"
#include "chrono"
#include "cstdlib"
#include "atomic"
#include "thread"
#include "chrono"
#include "queue"
#include "iostream"
#include "logger.h"
#include "loggerlevel1.h"
#include "loggerlevel2.h"
#include "loggerlevel3.h"
#include "Windows.h"

class EventsGenerator
{
public:
	explicit EventsGenerator();
	~EventsGenerator();
	void generateEvents(int average_iterval_sec, std::atomic<bool> &running);
	void resetAverageInterval(int& average_iterval_sec);
	void setLogger(Logger* logger);

private:
	int _generateInterval();

private:
	int _interval_min{ 0 };
	int _interval_max{ 0 };
	int _event_id{ 0 };
	std::queue<Event> _events_queue;
	Logger* _logger = nullptr;




};
