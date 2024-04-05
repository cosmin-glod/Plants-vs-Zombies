#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include "headers/Game.h"

#include <Helper.h>

int main() {
    Game game;

    game.run();
    return 0;
}
