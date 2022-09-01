#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>


class Logger
{

public:

    // The only way to obtain a Logger instance
    static Logger& GetLogger();

    Logger(const Logger& Copy) = delete;
    Logger& operator=(const Logger& Copy) = delete;
    
    void Log(std::string Log);

private:

    Logger() = default;

};


Logger& Logger::GetLogger()
{
    static Logger Singleton;
    return Singleton;
}

void Logger::Log(std::string Log)
{
    time_t Now = time(nullptr);
    std::cout << std::ctime(&Now) << Log << std::endl;
}