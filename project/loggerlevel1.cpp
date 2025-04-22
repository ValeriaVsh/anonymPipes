#include "loggerlevel1.h"
#include "sstream"

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

	if (_myfile.is_open())
	{
		std::stringstream ss;
		ss << event.curr_date_time;
		std::string timestr = ss.str();
		ss << event.id;
		std::string idstr = ss.str();
		const std::string log = "log level 0\ntime: " + timestr + "\nevent id: "+ idstr + "\n";
		char* log_c = new char[log.size()];
		for (int i = 0; i < log.size(); i++)
		{
			log_c[i] = log[i];
		}

		
		_myfile.write(log_c, log.size());
		//_myfile << "log level 0" << '\n' << time << '\n' << "event id: " << event.id << '\n';

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
