#pragma once

#include "event.h"
#include "loggerlevel1.h"
#include "loggerlevel2.h"
#include "loggerlevel3.h"

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
	virtual ~Logger() {};

public:
	static Logger* GetLogger(Level level)
	{
		if (level == Level::Level1)
		{			
			return new LoggerLevel1;
		}
		if (level == Level::Level2)
		{
			return new LoggerLevel2;
		}
		if (level == Level::Level3)
		{
			return new LoggerLevel3;
		}
		
	};

	static Logger* GetLogger(Level level, char* filename)
	{
		if (level == Level::Level1)
		{
			return new LoggerLevel1(filename);
		}
		if (level == Level::Level2)
		{
			return new LoggerLevel2(filename);
		}
		if (level == Level::Level3)
		{
			return new LoggerLevel3(filename);
		}

	};

	virtual Logger* Write(Event event) = 0;

};
