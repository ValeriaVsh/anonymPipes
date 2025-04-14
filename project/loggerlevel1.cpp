#include "loggerlevel1.h"

LoggerLevel1::LoggerLevel1()
{

}
LoggerLevel1::LoggerLevel1(char* filename)
{

}
LoggerLevel1::~LoggerLevel1()
{

}

LoggerLevel1* LoggerLevel1::Write(Event event)
{
	std::cout << "Logger level 1"<<std::endl;
	return this;

}

//bool LoggerLevel1::operator==(const LoggerLevel1& other) const
//{
//	return false;
//}
