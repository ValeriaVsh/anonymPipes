#include "loggerlevel1.h"


LoggerLevel1::LoggerLevel1()
{
	if (!_myfile.is_open())
		_myfile.open("default_logs.txt", std::ios::app);

}
LoggerLevel1::LoggerLevel1(char* filename)
{
	if (!_myfile.is_open())
		_myfile.open(filename, std::ios::app);

}
LoggerLevel1::~LoggerLevel1()
{
	if (_myfile.is_open())
		_myfile.close();

}

LoggerLevel1* LoggerLevel1::Write(Event event)
{

	if (_myfile.is_open())
	{
		// ѕреобразуем врем€ в читаемый формат
		std::tm* timeinfo = std::localtime(&event.curr_date_time);
		char timeBuffer[80];
		std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", timeinfo);

		// «аписываем данные в текстовом виде (CSV-подобный формат)
		_myfile << "\nEvent id: "<<event.id 
				<< "\ntime: " << timeBuffer << "\n";

	}
	else
	{
		std::cout << "cannot open file";
	}
	
	 //to do: write to pipe? not to file
	//and add function that will read from pipe and write to file
	
	return this;

}

//bool LoggerLevel1::operator==(const LoggerLevel1& other) const
//{
//	return false;
//}
