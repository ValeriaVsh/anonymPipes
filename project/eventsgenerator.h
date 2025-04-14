#pragma once

#include "event.h"
#include "chrono"
#include "cstdlib"
#include "atomic"
#include "thread"
#include "chrono"
#include "iostream"
#include "logger.h"
#include "loggerlevel1.h"
#include "loggerlevel2.h"
#include "loggerlevel3.h"

class EventsGenerator
{
public:
	explicit EventsGenerator();
	~EventsGenerator();
	void generateEvents(int average_iterval_sec, std::atomic<bool> &running);
	void resetAverageInterval(int& average_iterval_sec);

private:
	int _generateInterval();

private:
	int _interval_min{ 0 };
	int _interval_max{ 0 };




};
