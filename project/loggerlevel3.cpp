#include "loggerlevel3.h"


LoggerLevel3::LoggerLevel3()
{
	_myfile.open("default_logs.txt", std::ios::app);

}
LoggerLevel3::LoggerLevel3(char* filename)
{
	_myfile.open(filename, std::ios::app);

}
LoggerLevel3::~LoggerLevel3()
{
	_myfile.close();

}
LoggerLevel3* LoggerLevel3::Write(Event event)
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
				<< "\nparametr 1: " << event.param1
				<< "\nparametr 2: " << event.param2 
				<< "\nparametr 3: " << event.param3 << "\n";

	}
	else
	{
		std::cout << "cannot open file";
	}

	//to do: write to pipe? not to file
   //and add function that will read from pipe and write to file

	return this;
}