#include <chrono>
#include <thread>
#include <fstream>

#include "headers/Game.h"

int Game::resources = 0;
int Game::score = 0;
int Game::highScore = 0;

void readHighScore() {
    int highScore;
    std::ifstream fin("high_score.txt");
    fin >> highScore;
    Game::setHighScore(highScore);
}

int main() {
    readHighScore();
    Game game;
    game.run();
    return 0;
}
