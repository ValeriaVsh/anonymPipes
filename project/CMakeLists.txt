﻿# CMakeList.txt: проект CMake для project; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("project")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (project "project.cpp" "project.h" "event.h" "eventsgenerator.h" "eventsgenerator.cpp"  "logger.h" "loggerlevel1.h" "loggerlevel1.cpp" "loggerlevel2.h" "loggerlevel2.cpp" "loggerlevel3.h" "loggerlevel3.cpp" "logger.cpp"
"pipe_handler.h" "pipe_handler.cpp" "logger_thread.h" "logger_thread.cpp" "eventgen_thread.h" "eventgen_thread.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET project PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
