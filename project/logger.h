#pragma once

#include "event.h"
class LoggerLevel1;
class LoggerLevel2;
class LoggerLevel3;

enum Level {
	Level1,
	Level2,
	Level3
};

class Logger
{
protected:
	Logger(){};
	Logger(char* fileName){};
	

public:
	virtual ~Logger() {};
	static Logger* GetLogger(Level level);
	

	static Logger* GetLogger(Level level, char* filename);


	virtual Logger* Write(Event event) = 0;

};
