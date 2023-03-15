#pragma once
#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <mutex>

enum class LogPriority
{
    TracePriority,
    DebugPriority,
    InfoPriority,
    WarnPriority,
    ErrorPriority,
    CriticalPriority
};

class Logger
{
private:
    static LogPriority mPriority;
    static std::mutex log_mutex;

public:
    static void set_priority(LogPriority new_priority)
    {
        mPriority = new_priority;
    }

    template <class... Args>
    static void Trace(const char *message, Args... args)
    {
        if (mPriority <= LogPriority::TracePriority)
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            printf("[Trace]\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template <class... Args>
    static void Debug(const char *message, Args... args)
    {
        if (mPriority <= LogPriority::TracePriority)
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            printf("[Debug]\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template <class... Args>
    static void Info(const char *message, Args... args)
    {
        if (mPriority <= LogPriority::TracePriority)
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            printf("[Info]\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template <class... Args>
    static void Warn(const char *message, Args... args)
    {
        if (mPriority <= LogPriority::TracePriority)
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            printf("[Warn]\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template <class... Args>
    static void Error(const char *message, Args... args)
    {
        if (mPriority <= LogPriority::TracePriority)
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            printf("[Error]\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template <class... Args>
    static void Critical(const char *message, Args... args)
    {
        if (mPriority <= LogPriority::TracePriority)
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            printf("[Trace]\t");
            printf(message, args...);
            printf("\n");
        }
    }
};

LogPriority Logger::mPriority = LogPriority::TracePriority;
std::mutex Logger::log_mutex;

#endif LOGGER_H