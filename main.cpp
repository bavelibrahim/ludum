#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "StateMachine/StateMachine.h"
#include "MainMenu/MainMenu.h"

using namespace std;

bool fullScreen = false;        //Boolean used to change the window mode
bool sound = true;              //Boolean to turn on and off the sound of the game
bool music = true;              //Boolean to turn on and off the music of the game
int level;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Project Ludum");

int main() {

    window.setView(window.getDefaultView());
    MainMenu mainMenu(1920, 1080);
    StateMachine stateMachine;
    stateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);


    return 0;
}
