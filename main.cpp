#include <iostream>
#include <array>
#include <chrono>
#include <thread>
#include <fstream>

#include "headers/Game.h"

int main() {
    int highScore;

    std::ifstream fin("high_score.txt");
    fin >> highScore;
    Game game{highScore};

    game.run();
    return 0;
}
