#pragma once

#include "logger.h"

class LoggerLevel2 : public Logger
{

public:
	LoggerLevel2();
	LoggerLevel2(char* filename);
	~LoggerLevel2();

	LoggerLevel2* Write(Event event);





};