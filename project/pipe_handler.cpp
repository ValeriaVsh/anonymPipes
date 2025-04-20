#include "pipe_handler.h"

PipeHandler::PipeHandler() : hReadPipe(NULL), hWritePipe(NULL) {}

PipeHandler::~PipeHandler() {
    if (hReadPipe) CloseHandle(hReadPipe);
    if (hWritePipe) CloseHandle(hWritePipe);
}

bool PipeHandler::Initialize() {
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    if (!CreatePipe(&hReadPipe, &hWritePipe, &saAttr, 0)) {
        return false;
    }

    // Ensure the read handle to the pipe for the child process is not inherited
    if (!SetHandleInformation(hReadPipe, HANDLE_FLAG_INHERIT, 0)) {
        return false;
    }

    return true;
}

bool PipeHandler::WriteEvent(const Event& event) {
    DWORD bytesWritten;
    return WriteFile(hWritePipe, &event, sizeof(Event), &bytesWritten, NULL) 
           && bytesWritten == sizeof(Event);
}

bool PipeHandler::ReadEvent(Event& event) {
    DWORD bytesRead;
    return ReadFile(hReadPipe, &event, sizeof(Event), &bytesRead, NULL) 
           && bytesRead == sizeof(Event);
} 