#include "logger.h"

#include "loggerlevel1.h"
#include "loggerlevel2.h"
#include "loggerlevel3.h"

 Logger* Logger::GetLogger(Level level)
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
	return nullptr;

 }

Logger* Logger::GetLogger(Level level, char* filename)
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
	return nullptr;

}