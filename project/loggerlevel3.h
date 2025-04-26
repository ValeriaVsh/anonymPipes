#pragma once
#include "logger.h"
#include "event.h"
#include "fstream"
#include <chrono>

class LoggerLevel3 : public Logger
{

public:
	LoggerLevel3();
	LoggerLevel3(char* filename);
	~LoggerLevel3();


	LoggerLevel3* Write(Event event);

private:
	std::ofstream _myfile;




};