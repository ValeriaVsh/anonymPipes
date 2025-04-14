#pragma once
#include "logger.h"
#include "event.h"


class LoggerLevel1 : public Logger
{

public:
	LoggerLevel1();
	LoggerLevel1(char* filename);
	~LoggerLevel1();

	LoggerLevel1* Write(Event event) override;





	//bool operator==(const LoggerLevel1& other) const;
};