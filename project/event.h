#pragma once

#include <chrono>
#include <iostream>


struct Event
{
	Event(int id) : id{id} {};
	~Event() {};
	int id;
	int param1 = 1;
	int param2 = 2;
	int param3 = 3;
	const std::time_t curr_date_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
};