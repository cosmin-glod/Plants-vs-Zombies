//
// Created by Cosmin on 04.04.2024.
//

#include "../headers/Game.h"

sf::Vector2i Game::mousePosWindow = sf::Vector2i();
sf::Vector2f Game::mousePosView = sf::Vector2f();

bool Game::isMousePressed = false;
float Game::dificulty = 0.1f;
float Game::nextDificultyIncrease = 15.f;
int Game::dificultyIncreaseCounter = 5;

int Game::resources = 300;
int Game::score = 0;
int Game::highScore = 0;

Game::Game() :
    window{sf::RenderWindow(sf::VideoMode(1500, 850), "Cats vs. Boxes", sf::Style::Titlebar | sf::Style::Close)},
    shooterCatButton{Button<ShooterCat>(Button<ShooterCat>(sf::Vector2f(200.f, 100.f), 0.f, 0.f, sf::Color(202, 209, 12), 100))},
    generatorCatButton{Button<GeneratorCat>(sf::Vector2f(200.f, 100.f), 200.f, 0.f, sf::Color(12, 209, 28), 50)},
    wallCatButton{Button<WallCat>(sf::Vector2f(200.f, 100.f), 400.f, 0.f, sf::Color(12, 182, 209), 150)},

    grid{std::vector<std::vector<bool>>(5, std::vector<bool>(10, false))}
    {

        /// Initializare tiles
    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f (150.f, 150.f));
    tile.setFillColor(sf::Color(144, 238, 144));
    tile.setOutlineThickness(3.f);
    tile.setOutlineColor(sf::Color(165, 42, 42));

    window.setFramerateLimit(60);

    /// construire background
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            tile.setPosition(float(j) * 150.f, 100.f + 150.f * float(i));
            background_tiles.push_back(tile);
        }
    }

    /// construire box-uri pt scor si altele
    resourcesBox.setter(sf::Vector2f(300.f, 100.f), sf::Vector2f(600.f, 0.f), sf::Color(186,85,211));
    enemyCountBox.setter(sf::Vector2f(300.f, 100.f), sf::Vector2f(900.f, 0.f), sf::Color(255,196,12));
    scoreBox.setter(sf::Vector2f(300.f, 100.f), sf::Vector2f(1200.f, 0.f), sf::Color(0,128,128));

    /// construire text
    font.loadFromFile("./fonts/yoster.ttf");
    scoreText.setFont(font);
    scoreText.setPosition(sf::Vector2f(1210.f, 10.f));
    scoreText.setString("Score: 0\nHigh Score: " + std::to_string(highScore));

    resourcesText.setFont(font);
    resourcesText.setPosition(sf::Vector2f (630.f, 30.f));

    enemyCountText.setFont(font);
    enemyCountText.setPosition(sf::Vector2f (925.f, 30.f));
}
void Game::update() {

//     Update speedMultiplier based on elapsed time
    if (dificultyIncreaseCounter) {
        deltaDificultyTime = dificultyTimer.getElapsedTime();
        if (deltaDificultyTime >= sf::seconds(nextDificultyIncrease)) {
            dificulty += 0.2f; // Adjust the increment as needed
            dificultyIncreaseCounter--;

            nextDificultyIncrease += 10.f; // After another 15 seconds, increase after 10 seconds

            dificultyTimer.restart();
        }
    }

    /// Spawn Enemies
    sf::Time deltaTime = spawnTimer.getElapsedTime();
    if (deltaTime >= sf::seconds(1.5f / dificulty)) {
        spawnEnemy();
        spawnTimer.restart();
    }

    /// Move Enemies
    for (unsigned int i = 0; i < enemies.size(); ++i) {
        enemies[i].move();
        if (enemies[i].getShape().getPosition().x <= 0.f)
            enemies.erase(enemies.begin() + i);
    }

    /// Each cat does its thing
    for (auto &cat : cats)
        cat->run();

    /// Move Projectiles
    ShooterCat::moveProjectiles();

    /// Collect Whiskas in the handleEvents function

    /// Update Score
    scoreText.setString("Score: " + std::to_string(score) + "\nHigh Score: " + std::to_string(highScore));
    resourcesText.setString("Whiskas: " + std::to_string(resources));
    enemyCountText.setString("Speed : " + std::to_string(dificulty));

    ShooterCat::checkProjectilesCollisions(enemies);

    /// Drag and drop
    if (isMousePressed)
        handleDragAndDrop();
}

void Game::render() {
    /// Render background tiles
    for (auto &tile : background_tiles)
        window.draw(tile);

    /// Render enemies
    for (auto &enemy : enemies)
        enemy.draw(window, sf::RenderStates::Default);

    /// Render buttons
    shooterCatButton.draw(window, sf::RenderStates::Default);
    generatorCatButton.draw(window, sf::RenderStates::Default);
    wallCatButton.draw(window, sf::RenderStates::Default);

    resourcesBox.draw(window, sf::RenderStates::Default);
    enemyCountBox.draw(window, sf::RenderStates::Default);
    scoreBox.draw(window, sf::RenderStates::Default);

    /// Render cats
    for (auto &cat : cats) {
        cat->draw(window, sf::RenderStates::Default);
    }

    /// Render projectiles
    ShooterCat::displayProjectiles(window, sf::RenderStates::Default);

    /// Render Whiskas
    GeneratorCat::displayWhiskas(window, sf::RenderStates::Default);

    /// Render text
    window.draw(scoreText);
    window.draw(resourcesText);
    window.draw(enemyCountText);

    /// Render new instance of a cat
    if (Button<ShooterCat>::isDragging())
        Button<ShooterCat>::displayEntity(window, sf::RenderStates::Default);
    else if (Button<GeneratorCat>::isDragging())
        Button<GeneratorCat>::displayEntity(window, sf::RenderStates::Default);
    else if (Button<WallCat>::isDragging())
        Button<WallCat>::displayEntity(window, sf::RenderStates::Default);

    /// Display
    window.display();
}

bool Game::isRunning() const {
    return window.isOpen();
}

void Game::handleEvents() {
    /// Fereastra se inchide cand apasam X-ul ferestrei sau Esc
    sf::Event ev{};
    while (window.pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (ev.mouseButton.button == sf::Mouse::Left) {
                    isMousePressed = true;
                    GeneratorCat::collectWhiskas();
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (ev.mouseButton.button == sf::Mouse::Left) {
                    isMousePressed = false;
                    handleButtonRelease();
                }
                break;
            default:
                break;
        }
    }
}

void Game::run() {
    while (isRunning()) {
        updateMousePosition();
        handleEvents();

        update();
        render();
    }
}

void Game::setHighScore(const int &s) {
    Game::highScore = s;
}

void Game::spawnEnemy() {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Randomly generate a line between 0 and 4
    std::uniform_int_distribution<> dis(0, 4);
    int randomLine = dis(gen);

    // Create and initialize the enemy with the random line
    Enemy enemy(randomLine, 1.5f); // NOLINT(*-use-auto)

    // Add the enemy to your collection or perform further actions
    // For example, you might have a vector of enemies
    enemies.push_back(enemy);
}

void Game::updateMousePosition() {
    mousePosWindow = sf::Mouse::getPosition(window);
    mousePosView = window.mapPixelToCoords(mousePosWindow);
//    std::cout << mousePosView.x << " " << mousePosView.y << "\n";
}

void Game::handleDragAndDrop() {
    ///
    std::cout << "Mouse apasaat\n";
    if (Button<ShooterCat>::isDragging())
        Button<ShooterCat>::drag(mousePosView);
    else if (Button<GeneratorCat>::isDragging())
        Button<GeneratorCat>::drag(mousePosView);
    else if (Button<WallCat>::isDragging())
        Button<WallCat>::drag(mousePosView);

    else { /// poate apasa butonul pentru a instantia o entitate
        if (mousePosView.y <= 100.f) { /// trebuie sa fie apasat sus
            if (mousePosView.x <= 200.f && resources >= 100) { /// shooter cat
                Button<ShooterCat>::instantiate(mousePosView);
            }
            else if (mousePosView.x <= 400.f && resources >= 50) { /// generator cat
                Button<GeneratorCat>::instantiate(mousePosView);
            }
            else if (mousePosView.x <= 600.f && resources >= 150) { /// wall cat
                Button<WallCat>::instantiate(mousePosView);
            }
        }
    }
}

void Game::handleButtonRelease() {
    if (mousePosView.y > 100) {
        if (Button<ShooterCat>::isDragging()) {
            Button<ShooterCat>::place(mousePosView, cats, grid);
            decreaseResources(100);
        } else if (Button<GeneratorCat>::isDragging()) {
            Button<GeneratorCat>::place(mousePosView, cats, grid);
            decreaseResources(50);
        } else if (Button<WallCat>::isDragging()) {
            Button<WallCat>::place(mousePosView, cats, grid);
            decreaseResources(150);
        }
    }
}

void Game::updateHighScore(std::ostream& fout) {
    if (score > highScore)
        highScore = score;
    fout << highScore;
}

void Game::increaseScore() {
    ++score;
}

void Game::increaseResources(int amount) {
    resources += amount;
}

sf::Vector2f Game::getMousePosition() {
    return mousePosView;
}

void Game::decreaseResources(int amount) {
    resources -= amount;
}

