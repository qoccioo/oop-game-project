#include "game_controller.hpp"
#include "gamemodel.hpp"
#include "consolerenderer.hpp"  
#include "logger.hpp"           
#include "visualizer.hpp"    
#include <iostream>

int main(int argc, char* argv[])
{
    LogOutput mode = LogOutput::Console;

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--log=none")         mode = LogOutput::None;
        else if (arg == "--log=console") mode = LogOutput::Console;
        else if (arg == "--log=file")    mode = LogOutput::File;
        else if (arg == "--log=both")    mode = LogOutput::Both;
    }

    Game game(10, 10);
    GameController<CommandInput> controller(game, mode);

    controller.Run();
    return 0;
}


