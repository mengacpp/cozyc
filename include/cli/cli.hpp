#pragma once

#include <string>
#include <vector>


struct Argument
{
    Argument(const std::string &value) : value(value) {}
    std::string value;
};


class Cli
{
public:
    Cli(int argc, char *argv[]);

    const Argument &getArgumentAt(size_t i) const { return arguments.at(i); }
    const size_t getArgumentCount() const { return arguments.size(); }

private:
    std::vector<Argument> arguments;
};