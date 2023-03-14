#include <iostream>
using namespace std;
#include "logger.h"
#include <thread>

void log_test(int n)
{
    Logger::Trace("Test thread %d", n);
}

int main()
{
    int mAge = 86;

    thread mThread[10];
    for (int i = 0; i < 10; i++)
    {
        mThread[i] = thread(log_test, mAge);
    }

    return 0;
}