#pragma once

#include "logger.h"
#include "event.h"
#include "fstream"
#include <chrono>

class LoggerLevel2 : public Logger
{

public:
	LoggerLevel2();
	LoggerLevel2(char* filename);
	~LoggerLevel2();

	LoggerLevel2* Write(Event event);

private:
	std::ofstream _myfile;





};