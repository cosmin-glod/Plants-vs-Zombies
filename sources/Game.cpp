//
// Created by Cosmin on 04.04.2024.
//

#include "../headers/Game.h"

sf::Vector2i Game::mousePosWindow = sf::Vector2i();
sf::Vector2f Game::mousePosView = sf::Vector2f();

bool Game::isMousePressed = false;

float Game::spawnOnceSeconds = 15.f;
int Game::currentDificulty = 1;
float Game::nextDificultyStage = 100.f;

int Game::resources = 100;
int Game::score = 0;
int Game::highScore = 0;

sf::RenderWindow Game::window = sf::RenderWindow(sf::VideoMode(1500, 850), "Cats vs. Boxes", sf::Style::Titlebar | sf::Style::Close);

Game::Game() :
    shooterCatButton{Button<ShooterCat>(TextureManager::getTexture("textures/cat-icons/shooter-cat-icon.png"), sf::Vector2f (5.f, 5.f))},
    generatorCatButton{Button<GeneratorCat>(TextureManager::getTexture("textures/cat-icons/generator-cat-icon.png"), sf::Vector2f (205.f, 5.f))},
    wallCatButton{Button<WallCat>(TextureManager::getTexture("textures/cat-icons/wall-cat-icon.png"), sf::Vector2f (405.f, 5.f))},
    cats{5, 10}
//    grid{std::vector<std::vector<bool>>(5, std::vector<bool>(10, false))}
    {

    /// Initializare tiles
    sf::Sprite tile;
    tile.setTexture(TextureManager::getTexture("textures/bg/background-tile.png"));

    window.setFramerateLimit(60);

    /// construire background
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            tile.setPosition(float(j) * 150.f, 100.f + 150.f * float(i));
            background_tiles.push_back(tile);
        }
    }
    sf::Sprite slot;
    slot.setTexture(TextureManager::getTexture("textures/bg/slot.png"));
    for (int i = 0; i < 3; ++i) {
        slot.setPosition(float(i) * 200.f, 0.f);
        background_tiles.push_back(slot);
    }

    /// construire box-uri pt scor si altele
    resourcesBox.setter(TextureManager::getTexture("textures/info-bar/resourcesBox.png"), sf::Vector2f (600.f, 0.f));
    dificultyBox.setter(TextureManager::getTexture("textures/info-bar/dificultyBox.png"), sf::Vector2f (900.f, 0.f));
    scoreBox.setter(TextureManager::getTexture("textures/info-bar/scoreBox.png"), sf::Vector2f (1200.f, 0.f));
    /// construire text
    if (!font.loadFromFile("./fonts/yoster.ttf")) {
        throw MissingFont("The font \"./fonts/yoster.ttf\" was not found! :(\n");
    }
    scoreText.setFont(font);
    scoreText.setPosition(sf::Vector2f(1210.f, 10.f));
    scoreText.setString("Score: 0\nHigh Score: " + std::to_string(highScore));

    resourcesText.setFont(font);
    resourcesText.setPosition(sf::Vector2f (630.f, 30.f));

    dificultyText.setFont(font);
    dificultyText.setPosition(sf::Vector2f (925.f, 30.f));

//    spawnEnemy();
}
void Game::update() {

    stageTime = stageTimer.getElapsedTime();
    if (stageTime >= sf::seconds(nextDificultyStage)) {
        currentDificulty++;
        if (currentDificulty == 5)
            currentDificulty = 2;
        switch (currentDificulty) {
            case 2:
                spawnOnceSeconds = 2.f;
                nextDificultyStage += 30.f;
                break;
            case 3:
                spawnOnceSeconds = 1.f;
                nextDificultyStage += 100.f;
                break;
            case 4:
                spawnOnceSeconds = 0.5f;
                nextDificultyStage += 20.f;
                break;
            default:
                break;
        }
    }

//    Spawn Enemies
    sf::Time deltaTime = spawnTimer.getElapsedTime();
    if (deltaTime >= sf::seconds(spawnOnceSeconds)) {
        spawnEnemy();
        spawnTimer.restart();
    }

    /// Move Enemies
    for (unsigned int i = 0; i < enemies.size(); ++i) {
        enemies[i].move();
        if (enemies[i].getSprite().getPosition().x <= 0.f)
            enemies.erase(enemies.begin() + i);
    }

    /// Each cat does its thing
//    for (auto &cat : cats) {
//        if (!std::dynamic_pointer_cast<WallCat>(cat))
//            cat->run();
//    }
    cats.run();
//    for (auto &cat : cats)
//        cat->run();

    /// Move Projectiles
    ShooterCat::moveProjectiles();

    /// Collect Whiskas in the handleEvents function

    /// Update Score
    scoreText.setString("Score: " + std::to_string(score) + "\nHigh Score: " + std::to_string(highScore));
    resourcesText.setString("Whiskas: " + std::to_string(resources));
    dificultyText.setString("Dificulty : " + std::to_string(currentDificulty));

    ShooterCat::checkProjectilesCollisions(enemies);

    for (auto &enemy : enemies) {
        enemy.nowCanMove();
    }
    cats.enemyCollision(enemies);
    /// Cat - Enemy Collision
//
//    for (auto &enemy : enemies) {
//        for (unsigned j = 0; j < cats.size(); ++j) {
//            if (enemy.getSprite().getGlobalBounds().intersects(cats[j]->getSprite().getGlobalBounds())) {
////                std::cout << "am intrat\n";
//                cats[j]->gotHit();
////                std::cout << cats[i]->getHealth() << '\n';
//                enemy.cannotMoveAnymore();
//                if (!cats[j]->isAlive()) {
//                    int x = static_cast<int>(cats[j]->getX()) / 150;
//                    int y = static_cast<int>(cats[j]->getY() - 100.f) / 150;
////                    std::cout << cats[j]->getY() << ' ' << cats[j]->getX() << '\n';
//                    grid[y][x] = false;
//                    cats.erase(cats.begin() + j);
//                    --j;
//                }
//            }
//        }
//    }

    /// Drag and drop
    if (isMousePressed)
        handleDragAndDrop();
}

void Game::render() {
    window.clear();
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
    dificultyBox.draw(window, sf::RenderStates::Default);
    scoreBox.draw(window, sf::RenderStates::Default);

    /// Render cats
    cats.draw(window, sf::RenderStates::Default);
//    for (auto &cat : cats) {
//        cat->draw(window, sf::RenderStates::Default);
//    }

    /// Render projectiles
    ShooterCat::displayProjectiles(window, sf::RenderStates::Default);

    /// Render Whiskas
    GeneratorCat::displayWhiskas(window, sf::RenderStates::Default);

    /// Render text
    window.draw(scoreText);
    window.draw(resourcesText);
    window.draw(dificultyText);

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

bool Game::isRunning() {
    return window.isOpen();
}

void Game::handleEvents() {
    /// Fereastra se inchide cand apasam X-ul ferestrei sau Esc
    sf::Event ev{};
    while (window.pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                closeWindow();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    closeWindow();
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
    std::uniform_int_distribution<> lineDis(0, 4);
    int randomLine = lineDis(gen);

    // Define the probabilities
    std::uniform_real_distribution<> probDis(0.0, 1.0);
    double probability = probDis(gen);

    if (probability < 0.6) {
        Enemy enemy = EnemyFactory::EasyEnemy(randomLine);
        enemies.push_back(enemy);
    } else if (probability < 0.9) {
        Enemy enemy = EnemyFactory::MediumEnemy(randomLine);
        enemies.push_back(enemy);
    } else {
        Enemy enemy = EnemyFactory::HardEnemy(randomLine);
        enemies.push_back(enemy);
    }
}

void Game::updateMousePosition() {
    mousePosWindow = sf::Mouse::getPosition(window);
    mousePosView = window.mapPixelToCoords(mousePosWindow);
//    std::cout << mousePosView.x << " " << mousePosView.y << "\n";
}

void Game::handleDragAndDrop() {
    if (Button<ShooterCat>::isDragging())
        Button<ShooterCat>::drag(mousePosView);
    else if (Button<GeneratorCat>::isDragging())
        Button<GeneratorCat>::drag(mousePosView);
    else if (Button<WallCat>::isDragging())
        Button<WallCat>::drag(mousePosView);

    else {  /// poate apasa butonul pentru a instantia o entitate
        if (mousePosView.y <= 100.f) {  /// trebuie sa fie apasat sus
            if (mousePosView.x <= 200.f) {  /// shooter cat
                if (resources >= Button<ShooterCat>::getCost())
                    Button<ShooterCat>::instantiate(mousePosView);
            }
            else if (mousePosView.x <= 400.f) {
                if (resources >= Button<GeneratorCat>::getCost()) /// generator cat
                    Button<GeneratorCat>::instantiate(mousePosView);
            }
            else if (mousePosView.x <= 600.f) {
                if (resources >= Button<WallCat>::getCost()) /// wall cat
                    Button<WallCat>::instantiate(mousePosView);
            }
        }
    }
}

void Game::handleButtonRelease() {
    try {
        if (mousePosView.y > 100) {
            if (Button<ShooterCat>::isDragging()) {
                Button<ShooterCat>::place(mousePosView, cats);
                decreaseResources(Button<ShooterCat>::getCost());
            } else if (Button<GeneratorCat>::isDragging()) {
                Button<GeneratorCat>::place(mousePosView, cats);
                decreaseResources(Button<GeneratorCat>::getCost());
            } else if (Button<WallCat>::isDragging()) {
                Button<WallCat>::place(mousePosView, cats);
                decreaseResources(Button<WallCat>::getCost());
            }
        } else
            throw InvalidPosition("Pozitie invalida!");
    }
    catch (InvalidPosition&) {
            Button<GeneratorCat>::deleteEntity();
            Button<ShooterCat>::deleteEntity();
            Button<WallCat>::deleteEntity();

            std::cout << "The cat wasn't placed !";
    }
    catch (OccupiedPosition &) {
        Button<GeneratorCat>::deleteEntity();
        Button<ShooterCat>::deleteEntity();
        Button<WallCat>::deleteEntity();

        std::cout << "There is no place here for this cat! Sorry.\n";
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

void Game::closeWindow() {
    window.close();
}

