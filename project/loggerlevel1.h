#pragma once
#include "logger.h"

class LoggerLevel1 : public Logger
{

public:
	LoggerLevel1();
	LoggerLevel1(char* filename);
	~LoggerLevel1();

	LoggerLevel1* Write(Event event) override;





};