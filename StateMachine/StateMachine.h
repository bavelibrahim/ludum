#ifndef PROJECT_LUDUM_STATEMACHINE_H
#define PROJECT_LUDUM_STATEMACHINE_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class State {
    MENU, PLAY, HIGHSCORE, SETTINGS, UPGRADES, PAUSE, LEVEL1, LEVEL2, LEVEL3, LEVEL4, WINSCREEN, LOSESCREEN
};
enum class Signals {
    menu, play, highscore, settings, upgrades, pause, level1, level2, level3, level4, winscreen, losescreen
};

class StateMachine {

public:

    StateMachine();

    ~StateMachine();

    void SendSignal(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);
    State state;
protected:

    //One function for each state. Receives signal for processing

    State StateMenu(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);
    State StateSetting(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);
    State StatePlay(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);


};
#endif //PROJECT_LUDUM_STATEMACHINE_H
