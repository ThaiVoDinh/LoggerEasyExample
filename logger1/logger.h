#pragma once
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>

namespace gits
{
    enum class LogSeverity
    {
        ERROR,
        WARNING,
        INFO,
        DEBUG
    };

    enum class LogOutput
    {
        console,
        file,
        everywhere
    };

    std::string stringtify(const LogSeverity mSeverity)
    {
        std::map<LogSeverity, std::string> S_SEVERITY_MAP =
            {
                {LogSeverity::ERROR, "ERROR"},
                {LogSeverity::WARNING, "WARNING"},
                {LogSeverity::INFO, "INFO"},
                {LogSeverity::DEBUG, "DEBUG"},
            };

        std::string result = "NONE";
        auto it = S_SEVERITY_MAP.find(mSeverity);
        if (it != S_SEVERITY_MAP.end())
        {
            result = it->second;
        }
        return result;
    }

    ////////////

    class Logger
    {
    public:
        Logger(){

        };

        ~Logger(){

        };

        void init(const std::string &filename,
                  const LogOutput output)
        {
            m_fileName = filename;
            m_Output = output;
        };

        void open()
        {
            if (m_isOpened)
            {
                return;
            }

            if (m_Output == LogOutput::everywhere || m_Output == LogOutput::file)
            {
                m_file.open(m_fileName, std::ios::out);
                m_isOpened = m_file.is_open();

                if (!m_isOpened)
                {
                    throw std::runtime_error("Couldn't open a log file");
                }
            }

            m_isOpened = true;
        };

        void close()
        {
            flush();
            if (m_Output == LogOutput::everywhere || m_Output == LogOutput::file)
            {
                m_file.close();
            }
        };

        void flush()
        {
            if (m_Output == LogOutput::everywhere || m_Output == LogOutput::file)
            {
                m_file.flush();
            }
        };

        void log(const std::string &message, const LogSeverity severity)
        {
            std::string results = stringtify(severity) + "." + message;
            if (m_Output == LogOutput::console)
            {
                std::cout << results << std::endl;
            }
            if (m_Output == LogOutput::everywhere)
            {
                std::cout << results << std::endl;
                m_file << results << std::endl;
            }
            if (m_Output == LogOutput::file)
            {
                m_file << results << std::endl;
            }
        }

        template <class T>
        void log(const T &t, const LogSeverity severity)
        {
            std::stringstream ss;
            ss << t;
            log(ss.str(), severity);
        }

    private:
        std::string m_fileName;
        std::fstream m_file;
        LogOutput m_Output = LogOutput::everywhere;

        bool m_isOpened = false;
    };

}