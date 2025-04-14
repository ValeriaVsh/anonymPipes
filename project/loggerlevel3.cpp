#include "loggerlevel3.h"


LoggerLevel3::LoggerLevel3()
{

}
LoggerLevel3::LoggerLevel3(char* filename)
{

}
LoggerLevel3::~LoggerLevel3()
{

}
LoggerLevel3* LoggerLevel3::Write(Event event)
{
	std::cout << "Logger level 3"<<std::endl;
	return this;
}