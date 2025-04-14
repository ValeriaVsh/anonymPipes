#include "loggerlevel1.h"

LoggerLevel1::LoggerLevel1()
{
	_myfile.open("default_logs.txt");

}
LoggerLevel1::LoggerLevel1(char* filename)
{
	_myfile.open(filename);

}
LoggerLevel1::~LoggerLevel1()
{
	_myfile.close();

}

LoggerLevel1* LoggerLevel1::Write(Event event)
{
	auto datetime = std::chrono::system_clock::now();
	auto date{ floor<std::chrono::days>(datetime) };
	std::chrono::hh_mm_ss time{ floor<std::chrono::milliseconds>(datetime - date) };

	_myfile <<"log level 0"<<'\n' << time << '\n' << "event id: " << event.id << '\n';
	 //to do: write to pipe? not to file
	//and add function that will read from pipe and write to file
	
	return this;

}

//bool LoggerLevel1::operator==(const LoggerLevel1& other) const
//{
//	return false;
//}
