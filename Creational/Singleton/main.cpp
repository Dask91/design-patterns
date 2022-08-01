#include "Logger.h"


// Singleton example:
// Logger
int main()
{
    Logger& Logger = Logger::GetLogger();
    Logger.Log("Hello World!");
    return 0;
}