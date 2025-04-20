#pragma once

#include <Windows.h>
#include <thread>
#include <atomic>
#include "pipe_handler.h"
#include "logger.h"

class LoggerThread {
public:
    LoggerThread(PipeHandler* pipeHandler, Logger* logger);
    ~LoggerThread();

    void Start();
    void Stop();
    void Join();

private:
    void Run();

    PipeHandler* pipeHandler;
    Logger* logger;
    std::thread thread;
    std::atomic<bool> running;
}; 