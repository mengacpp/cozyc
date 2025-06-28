#pragma once

#include <iostream>

enum class LogType
{
    INFO,
    WARNING,
    ERROR,
};

std::string log_type_to_string(LogType stype);
std::ostream &operator<<(std::ostream &os, const LogType &type);

template <typename... Rest> void log(LogType type, Rest... rest);
template <typename T, typename... Rest> void log_impl(T first, Rest... rest);

void log_impl();

template <typename... Rest> void log(LogType type, Rest... rest)
{
    std::cout << log_type_to_string(type) << " ";
    log_impl(rest...);
}

template <typename T, typename... Rest> void log_impl(T first, Rest... rest)
{
    std::cout << first << " ";
    log_impl(rest...);
}