#pragma once

#include <Windows.h>
#include "event.h"
#include <string>

class PipeHandler {
public:
    PipeHandler();
    ~PipeHandler();

    bool Initialize();
    bool WriteEvent(const Event& event);
    bool ReadEvent(Event& event);
    bool HasDataToRead();
    HANDLE GetReadHandle() const { return hReadPipe; }
    HANDLE GetWriteHandle() const { return hWritePipe; }

private:
    HANDLE hReadPipe;
    HANDLE hWritePipe;
}; 