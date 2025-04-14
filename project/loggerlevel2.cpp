#include "loggerlevel2.h"

LoggerLevel2::LoggerLevel2()
{

}
LoggerLevel2::LoggerLevel2(char* filename)
{

}
LoggerLevel2::~LoggerLevel2()
{

}

LoggerLevel2* LoggerLevel2::Write(Event event)
{
	std::cout << "Logger level 2"<<std::endl;
	return this;
}