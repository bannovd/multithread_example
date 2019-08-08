#include "logger.h"
#include "logger_impl.h"
#include <string>


namespace bridge
{
    logger::logger(logger_impl *p) : pimpl(p)
    { }

    logger::~logger( )
    {
        delete pimpl;
    }

    console_logger::console_logger() : logger(
          #ifdef MT
            new mt_logger_impl()
          #else
            new st_logger_impl()
          #endif
        )
    { }

    void console_logger::log(std::string & str)
    {
        pimpl->console_log(str);
    }

    file_logger::file_logger(std::string & file_name)
        : logger(
          #ifdef MT
            new mt_logger_impl()
          #else
            new st_logger_impl()
          #endif
        ), m_file(file_name)
    { }

    void file_logger::log(std::string & str)
    {
        pimpl->file_log(m_file, str);
    }
}
