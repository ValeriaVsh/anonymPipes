#include "logger_thread.h"
#include <iostream>

LoggerThread::LoggerThread(PipeHandler* pipeHandler, Logger* logger)
    : pipeHandler(pipeHandler), logger(logger), running(false) {
}

LoggerThread::~LoggerThread() {
    Stop();
    Join();
}

void LoggerThread::Start() {
    if (!running) {
        running = true;
        thread = std::thread(&LoggerThread::Run, this);
    }
}

void LoggerThread::Stop() {
    running = false;
    delete logger;
}

void LoggerThread::Join() {
    if (thread.joinable()) {
        thread.join();
    }
}

void LoggerThread::Run() {
    Event event(0);
    while (running) {
        if (pipeHandler->ReadEvent(event)) {
            std::cout << "logger thread received event with id: " << event.id << std::endl;
            logger->Write(event);
        }
        else {
            // Pipe read failed, might be closed or error
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
} 