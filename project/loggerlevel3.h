#pragma once
#include "logger.h"

class LoggerLevel3 : public Logger
{

public:
	LoggerLevel3() {};
	LoggerLevel3(char* filename) {};
	~LoggerLevel3() {};

	LoggerLevel3* Write(Event event);




};