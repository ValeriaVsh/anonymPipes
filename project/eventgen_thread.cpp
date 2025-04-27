#include "eventgen_thread.h"
#include "iostream"

EventGen_Thread::EventGen_Thread(EventsGenerator* generator, int interval)
	: gen(generator), interval(interval), running(false)
{

}
EventGen_Thread::~EventGen_Thread()
{
	Stop();
	Join();

}

void EventGen_Thread::Start()
{
	if (!running)
	{
		running = true;
		thread = std::thread(&EventGen_Thread::Run, this);

	}
		
}

void EventGen_Thread::Stop()
{
	if (running)
	{
		running = false;
	}

}
void EventGen_Thread::Join()
{
	if (thread.joinable())
	{
		thread.join();
	}

}

void EventGen_Thread::Run()
{
	
	gen->generateEvents(interval, running);

	
}