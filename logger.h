#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace bridge
{
    class logger_impl;

    class logger
    {
      public:
        logger(logger_impl* p);
        virtual ~logger( );
        virtual void log(std::string & str) = 0;
      protected:
        logger_impl * pimpl;
    };

    class console_logger : public logger
    {
      public:
        console_logger();
        void log(std::string & str);
    };

    class file_logger : public logger
    {
      public:
        file_logger(std::string & file_name);
        void log(std::string & str);
      private:
        std::string m_file;
    };
}
#endif // LOGGER_H
