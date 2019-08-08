#ifndef LOGGER_IMPL_H
#define LOGGER_IMPL_H

#include <string>

namespace bridge
{
    class logger_impl
    {
      public:
        virtual ~logger_impl() {}
        virtual void console_log(std::string & str) = 0;
        virtual void file_log(std::string & file, std::string & str) = 0;
    };

    class st_logger_impl : public logger_impl
    {
      public:
        void console_log(std::string & str);
        void file_log(std::string & file, std::string & str);
    };

    class mt_logger_impl : public logger_impl
    {
      public:
        void console_log(std::string & str);
        void file_log(std::string & file, std::string & str);
    };
}

#endif // LOGGER_IMPL_H
