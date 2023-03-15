#include "logger.h"

using namespace gits;

int main()
{
    Logger logger;
    logger.init("Thai.txt", LogOutput::console);

    logger.open();
    logger.log("test.log", LogSeverity::DEBUG);

    logger.close();

    // std::cout << stringtify(LogSeverity::ERROR) << std::endl;
    // std::cout << stringtify(LogSeverity::WARNING) << std::endl;
    // std::cout << stringtify(LogSeverity::INFO) << std::endl;
    // std::cout << stringtify(LogSeverity::DEBUG) << std::endl;
    return 0;
}