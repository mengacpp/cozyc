#include "utils/log.hpp"

void log_impl()
{
    std::cout << std::endl;
}

std::string log_type_to_string(LogType type)
{
    switch (type)
    {
    case LogType::INFO:
        return "[INFO]   ";
    case LogType::WARNING:
        return "[WARNING]";
    case LogType::ERROR:
        return "[ERROR]  ";
    }
}

std::ostream &operator<<(std::ostream &os, const LogType &type)
{
    os << log_type_to_string(type);
    return os;
}
