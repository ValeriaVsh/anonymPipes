#include "loggerlevel2.h"

LoggerLevel2::LoggerLevel2()
{
	_myfile.open("default_logs.txt", std::ios::app);

}
LoggerLevel2::LoggerLevel2(char* filename)
{
	_myfile.open(filename, std::ios::app);

}
LoggerLevel2::~LoggerLevel2()
{
	_myfile.close();

}

LoggerLevel2* LoggerLevel2::Write(Event event)
{
	

	if (_myfile.is_open())
	{
		// ѕреобразуем врем€ в читаемый формат
		std::tm* timeinfo = std::localtime(&event.curr_date_time);
		char timeBuffer[80];
		std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", timeinfo);

		// «аписываем данные в текстовом виде (CSV-подобный формат)
		_myfile << "\nEvent id: " << event.id
				<< "\ntime: " << timeBuffer
				<< "\nparametr 1: "<<event.param1 << "\n";

	}
	else
	{
		std::cout << "cannot open file";
	}

	//to do: write to pipe? not to file
   //and add function that will read from pipe and write to file

	return this;
}