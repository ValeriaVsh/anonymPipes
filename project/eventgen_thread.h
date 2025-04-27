#pragma once
#include <thread>
#include <atomic>
#include "eventsgenerator.h"


class EventGen_Thread
{
public:
	EventGen_Thread(EventsGenerator *generator, int interval);
	~EventGen_Thread();

	void Start();
	void Stop();
	void Join();

private:

	void Run();

	std::atomic<bool> running;
	std::thread thread;
	EventsGenerator* gen;
	int interval;

};