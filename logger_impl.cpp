#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include "logger_impl.h"


namespace bridge
{
    void st_logger_impl::console_log(std::string & str)
    {
        auto now = std::chrono::high_resolution_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::chrono::microseconds micros = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch());
        std::cout << "[" << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S.") << micros.count() % 1000000 << "] "<< str << "\n";
    }

    void st_logger_impl::file_log(std::string & file, std::string & str )
    {
        std::cout << "Single-threaded file logger" << std::endl;
    }

    void mt_logger_impl::console_log(std::string & str)
    {
        std::cout << "Multithreaded console logger" << std::endl;
    }

    void mt_logger_impl::file_log(std::string & file, std::string & str )
    {
        std::cout << "Multithreaded file logger" << std::endl;
    }
}
