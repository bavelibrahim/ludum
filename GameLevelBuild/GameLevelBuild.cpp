#include "GameLevelBuild.h"
#include <memory>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../map/map.h"
#include "../objects/object.h"
#include "../objects/layer.h"
#include "../objects/sprite.h"
#include "../GlobalVariables.h"

using namespace std;

GameLevelBuild::GameLevelBuild() {
    // Load map information from JSON into object list
    map.loadFromFile("TiledMaps/StartPoint.json");
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(300, 100);
}

bool GameLevelBuild::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music) {

    // Copy layer references from map object to Game list
    std::copy(map.getLayers().begin(), map.getLayers().end(), std::back_inserter(objects));
    // Copy sprite references from map object to Game list
    std::copy(map.getSprites().begin(), map.getSprites().end(), std::back_inserter(objects));

    // Double the size of the screen
    view = window.getDefaultView();
    view.setSize(view.getSize().x / 2, view.getSize().y / 2);
    view.setCenter(view.getCenter().x / 2, view.getCenter().y / 2);

    minimapView = window.getDefaultView();
    minimapView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

    window.setView(view);
    window.setView(minimapView);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    shape.setScale(0.5,0.5);
    cout << view.getCenter().x << " X " << view.getCenter().y << endl;
    cout << shape.getPosition().x << " X " << shape.getPosition().x << endl;

    return true;
}

void GameLevelBuild::run(sf::RenderWindow &window, bool fullScreen, bool sound, bool music) {
    float deltaTime = 0;
    clock.restart();
    // Game loop
    while (gameTick(window, fullScreen, sound, music, objects, deltaTime)) {
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

// Process and draws one frame of the game
bool GameLevelBuild::gameTick(sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                              std::list<std::shared_ptr<Object>> &objects, float deltaTime) {

    window.setView(window.getDefaultView());                    //Set the window view to the view shown on the screen

    while (window.isOpen()) {
        sf::Event event;

        // Process events from the OS
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    return false;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Down) {
                        view.move(0, 10);
                        cout << view.getCenter().x << " X " << view.getCenter().y << endl;

                    }
                    if (event.key.code == sf::Keyboard::Up) {
                        view.move(0, -10);
                        cout << view.getCenter().x << " X " << view.getCenter().y << endl;
                    }
                    if (event.key.code == sf::Keyboard::Left) {
                        view.move(-10, 0);
                        cout << view.getCenter().x << " X " << view.getCenter().y << endl;
                    }
                    if (event.key.code == sf::Keyboard::Right) {
                        view.move(10, 0);
                        cout << view.getCenter().x << " X " << view.getCenter().y << endl;
                    }
                case sf::Event::KeyReleased:
                    // Reload map on F5
                    if (event.key.code == sf::Keyboard::F5) {
                        objects.clear();

                        if (!map.loadFromFile("TiledMaps/StartPoint.json")) {
                            std::cout << "Failed to reload map data." << std::endl;
                            return false;
                        }

                        std::copy(map.getLayers().begin(), map.getLayers().end(), std::back_inserter(objects));
                        std::copy(map.getSprites().begin(), map.getSprites().end(), std::back_inserter(objects));
                    }

                    // Exit program on escape
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return false;
                    }
                    break;

                default:
                    // Ignore the other events
                    break;

            }

        }

        window.clear(sf::Color::Cyan);

        // Process and render each object
        for (auto &object: objects) {
            object->process(deltaTime);
            object->draw(window);
        }
        //window.setView(view);
        window.setView(minimapView);
        window.setView(window.getDefaultView());
        window.setView(view);
        window.draw(shape);
        window.display();
    }

    return true;
}


