#include "cli/cli.hpp"

Cli::Cli(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        arguments.emplace_back(argv[i]);
    }
}