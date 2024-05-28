#include <chrono>
#include <thread>
#include <fstream>

#include "headers/Game.h"

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
    std::ofstream fout("high_score.txt");
    Game::updateHighScore(fout);
    fout.close();
    return 0;
}
