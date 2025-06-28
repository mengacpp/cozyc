#include "cli/cli.hpp"
#include "utils/log.hpp"

int main(int argc, char *argv[])
{
    Cli cli(argc, argv);

    for (size_t i = 0; i < cli.getArgumentCount(); ++i)
    {
        log(LogType::INFO, i, ": ", cli.getArgumentAt(i).value);
    }
}