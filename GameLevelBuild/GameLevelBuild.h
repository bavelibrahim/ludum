#ifndef PROJECT_LUDUM_GAMELEVELBUILD_H
#define PROJECT_LUDUM_GAMELEVELBUILD_H

#include <list>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "../map/map.h"

class Object;

class GameLevelBuild {
public:

    GameLevelBuild();
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music);
    void run(sf::RenderWindow &window, bool fullScreen, bool sound, bool music);
    std::list<std::shared_ptr<Object>> objects;
    sf::View minimapView;
    sf::View view;
    sf::CircleShape shape;

    Map map;

protected:
    bool gameTick(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, std::list<std::shared_ptr<Object>>& objects, float deltaTime);

    // List of game objects. Should of course be put somewhere else in a bigger game
    sf::Clock clock;
    sf::RenderWindow window;

};

#endif //PROJECT_LUDUM_GAMELEVELBUILD_H
