#include "StateMachine.h"
#include <iostream>
#include "StateMachine.h"
#include "../MainMenu/MainMenu.h"
#include "../Settings/Settings.h"
#include "../GameLevelBuild/GameLevelBuild.h"
#include <SFML/Audio.hpp>

sf::Music MenuMusic;
sf::Music SettingMusic;
sf::Music GameMusic;

GameLevelBuild gameLevelBuild;
StateMachine::StateMachine() {
    this->state = State::MENU;
}

StateMachine::~StateMachine() {

}

void StateMachine::SendSignal(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                              int level) {
    window.setView(window.getDefaultView());

    switch (state) {
        case State::MENU:
            state = StateMenu(signals, window, fullScreen, sound, music, level);
            break;
        case State::PLAY:
            state = StatePlay(signals, window, fullScreen, sound, music, level);
            break;
        case State::SETTINGS:
            state = StateSetting(signals, window, fullScreen, sound, music, level);
            break;
    }
}

State
StateMachine::StateMenu(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {
    SettingMusic.stop();
    GameMusic.stop();
    MenuMusic.openFromFile("Sound/AMemoryAway.ogg");
    if (music) {
        MenuMusic.play();
    } else if (!music) {
        MenuMusic.stop();
    }

    switch (signals) {
        case Signals::menu: {
            //Make a new window
            sf::Texture textureBackground;
            textureBackground.loadFromFile("data/MainBackground.png");
            sf::Sprite background(textureBackground);

            //Make vectors to use as 2 dim sizes for window and the texture
            sf::Vector2u TextureSize;
            sf::Vector2u WindowSize;
            //
            TextureSize = textureBackground.getSize();
            WindowSize = window.getSize();

            float ScaleX = (float) WindowSize.x / TextureSize.x;
            float ScaleY = (float) WindowSize.y / TextureSize.y;

            background.setScale(ScaleX, ScaleY);

            //Make an object of the class GameMenu
            MainMenu MainMenu(WindowSize.x, WindowSize.y);
            while (window.isOpen()) {

                sf::Event event;
                while (window.pollEvent(event)) {
                    switch (event.type) {
                        case sf::Event::KeyPressed:
                            switch (event.key.code) {
                                //Get the function MoveUp from the GameMenu class
                                case sf::Keyboard::Up:
                                    MainMenu.MoveUp();
                                    break;
                                    //Get the function MoveDown from the GameMenu class
                                case sf::Keyboard::Down:
                                    MainMenu.MoveDown();
                                    break;
                                case sf::Keyboard::Escape:
                                    window.close();
                                    break;
                                case sf::Keyboard::Return:
                                    switch (MainMenu.GetItemSelect()) {
                                        case 0:
                                            SendSignal(Signals::play, window, fullScreen, sound, music, level);
                                            break;
                                        case 1:
                                            SendSignal(Signals::highscore, window, fullScreen, sound, music, level);
                                            break;
                                        case 2:
                                            SendSignal(Signals::upgrades, window, fullScreen, sound, music, level);
                                            break;
                                        case 3:
                                            SendSignal(Signals::settings, window, fullScreen, sound, music, level);
                                            break;
                                        case 4:
                                            window.close();
                                            exit(0);
                                    }
                            }

                            break;
                        case sf::Event::Closed:
                            window.close();
                            break;
                        case sf::Event::Resized:
                            sf::FloatRect visibleArea(0,0,event.size.width, event.size.height);
                            window.setView(sf::View(visibleArea));
                            break;
                    }

                }

                window.draw(background);
                MainMenu.draw(window);
                window.display();
            }
        }

        case Signals::play:
            return StatePlay(signals, window, fullScreen, sound, music, level);
        case Signals::settings:
            return StateSetting(signals, window, fullScreen, sound, music, level);

    }
    return State::MENU;
}

State StateMachine::StatePlay(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                int level) {

    SettingMusic.stop();
    MenuMusic.stop();
    GameMusic.openFromFile("Sound/FieldMusic.ogg");
    if (music) {
        GameMusic.play();
    } else if (!music) {
        GameMusic.stop();
    }

    switch (signals) {

        case Signals::play: {
            window.clear();
            gameLevelBuild.objects.clear();
            gameLevelBuild.init(window, fullScreen, sound, music);
            gameLevelBuild.run(window, fullScreen, sound, music);
            window.display();
            break;
        }

    }

    return State::PLAY;
}

State StateMachine::StateSetting(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music,
                                 int level) {
    MenuMusic.stop();
    GameMusic.stop();
    SettingMusic.openFromFile("Sound/NetherplaceLooping.wav");
    if (music) {
        SettingMusic.play();
    } else if (!music) {
        SettingMusic.stop();
    }

    switch (signals) {

        case Signals::settings:
            Settings settings;
            window.clear();
            settings.init(window, fullScreen, sound, music, level);
            window.display();
            break;
    }
    return State::SETTINGS;
}
