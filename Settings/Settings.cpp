#include "Settings.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
#include "../StateMachine/StateMachine.h"


bool Settings::init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level) {

    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");                          //The font used on the texts in the window
    SoundMutingButton.loadFromFile("Buttons/SoundButton.png");                  //Add a texture to the sound button when sound is on
    MusingMutingButton.loadFromFile("Buttons/MusicButton.png");                 //Add a texture to the music button when music is on
    MutedSoundButton.loadFromFile("Buttons/MutedSoundButton.png");              //Add a texture to the sound button when sound is off
    MutedMusicButton.loadFromFile("Buttons/MutedMusicButton.png");              //Add a texture to the music button when music is off
    ChangeToWindowScreen.loadFromFile("Buttons/WindowModeButton.png");          //Add a texture to the screen mode button when the mode is windowed
    ChangeToFullScreen.loadFromFile("Buttons/FullscreenButton.png");            //Add a texture to the screen mode button when mode is full screen
    BigSizeScreen.loadFromFile("Buttons/1920x1080sizeButton.png");              //Add a texture to the 1920x1080 size button
    MiddleSizeScreen.loadFromFile("Buttons/1600x900sizeButton.png");            //Add a texture to the 1600x900 size button
    SmallSizeScreen.loadFromFile("Buttons/1280x720sizeButton.png");             //Add a texture to the 1080x720 size button
    ButtonBackground.loadFromFile("Buttons/ButtonBackground.png");              //Add a texture to the background of the size buttons
    ClearProgressButton.loadFromFile("Buttons/ClearProgressButton.png");        //Add a texture to the progress deleting button
    ReturnButton.loadFromFile("Buttons/ReturnButton.png");                      //Add a texture to the go back button
    ButtonHighlighter.loadFromFile("Buttons/ButtonHighlight.png");              //Add a texture to the highlighter icon
    ButtonNotHighlighter.loadFromFile("Buttons/BtnNotHighlight.png");           //Add a texture to the empty highlighter
    SizeButtonHighlight.loadFromFile("Buttons/SizeButtonHighlight.png");        //Add a texture to the highlighter icon for the size buttons

    if (sound) {
        SettingButtons[0].setTexture(SoundMutingButton);
        SettingButtons[0].setPosition(1920 / 2 - 300, 1080 / 9 * 1);
    } else if (!sound) {
        SettingButtons[0].setTexture(MutedSoundButton);
        SettingButtons[0].setPosition(1920 / 2 - 300, 1080 / 9 * 1);
    }

    HighlightedButtons[0].setTexture(ButtonHighlighter);
    HighlightedButtons[0].setPosition(1920 / 2 - 360, 1080 / 9 * 1);

    if (music) {
        SettingButtons[1].setTexture(MusingMutingButton);
        SettingButtons[1].setPosition(1920 / 2 - 300, 1080 / 9 * 2);
    } else if (!music) {
        SettingButtons[1].setTexture(MusingMutingButton);
        SettingButtons[1].setPosition(1920 / 2 - 300, 1080 / 9 * 2);
    }

    HighlightedButtons[1].setTexture(ButtonNotHighlighter);
    HighlightedButtons[1].setPosition(1920 / 2 - 360, 1080 / 9 * 2);

    if (!fullScreen) {
        SettingButtons[2].setTexture(ChangeToWindowScreen);
        SettingButtons[2].setPosition(1920 / 2 - 300, 1080 / 9 * 3);
    } else if (fullScreen) {
        SettingButtons[2].setTexture(ChangeToFullScreen);
        SettingButtons[2].setPosition(1920 / 2 - 300, 1080 / 9 * 3);
    }
    HighlightedButtons[2].setTexture(ButtonNotHighlighter);
    HighlightedButtons[2].setPosition(1920 / 2 - 360, 1080 / 9 * 3);

    BtnsBackground.setTexture(ButtonBackground);
    BtnsBackground.setPosition(1920 / 2 - 300, 1080 / 9 * 4);

    SettingButtons[3].setTexture(BigSizeScreen);
    SettingButtons[3].setPosition(1920 / 2 - 300, 1080 / 9 * 4);

    HighlightedButtons[3].setTexture(ButtonNotHighlighter);
    HighlightedButtons[3].setPosition(1920 / 2 - 299, 1080 / 9 * 4);

    SettingButtons[4].setTexture(MiddleSizeScreen);
    SettingButtons[4].setPosition(1920 / 2 - 100, 1080 / 9 * 4);

    HighlightedButtons[4].setTexture(ButtonNotHighlighter);
    HighlightedButtons[4].setPosition(1920 / 2 - 99, 1080 / 9 * 4);

    SettingButtons[5].setTexture(SmallSizeScreen);
    SettingButtons[5].setPosition(1920 / 2 + 100, 1080 / 9 * 4);

    HighlightedButtons[5].setTexture(ButtonNotHighlighter);
    HighlightedButtons[5].setPosition(1920 / 2 + 99, 1080 / 9 * 4);

    SettingButtons[6].setTexture(ClearProgressButton);
    SettingButtons[6].setPosition(1920 / 2 - 300, 1080 / 9 * 5);

    HighlightedButtons[6].setTexture(ButtonNotHighlighter);
    HighlightedButtons[6].setPosition(1920 / 2 - 360, 1080 / 9 * 5);

    SettingButtons[7].setTexture(ReturnButton);
    SettingButtons[7].setPosition(1920 / 2 - 300, 1080 / 9 * 6);

    HighlightedButtons[7].setTexture(ButtonNotHighlighter);
    HighlightedButtons[7].setPosition(1920 / 2 - 360, 1080 / 9 * 6);

    Choices = 0;
    sf::Texture textureBackground;
    textureBackground.loadFromFile("data/MainBackground.png");
    sf::Sprite background(textureBackground);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            MoveUp();
                            break;
                            //Get the function MoveDown from the GameMenu class
                        case sf::Keyboard::Down:
                            MoveDown();
                            break;
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Return:

                            switch (GetItemSelect()) {
                                case 0:
                                    if (sound) {
                                        sound = false;
                                        SettingButtons[0].setTexture(MutedSoundButton);
                                    } else if (!sound) {
                                        sound = true;
                                        SettingButtons[0].setTexture(SoundMutingButton);
                                    }
                                    break;
                                case 1:
                                    if (music) {
                                        music = false;
                                        SettingButtons[1].setTexture(MutedMusicButton);
                                    } else if (!music) {
                                        music = true;
                                        SettingButtons[1].setTexture(MusingMutingButton);
                                    }
                                    break;
                                case 2:
                                    if (fullScreen) {
                                        fullScreen = false;
                                        window.create(sf::VideoMode(1920, 1080), "Ludum");
                                        SettingButtons[2].setTexture(ChangeToWindowScreen);
                                    } else if (!fullScreen) {
                                        fullScreen = true;
                                        window.create(sf::VideoMode(1920, 1080), "Ludum", sf::Style::Fullscreen);
                                        SettingButtons[2].setTexture(ChangeToFullScreen);
                                    }
                                    break;
                                case 3:
                                    window.create(sf::VideoMode(1920, 1080), "Ludum");
                                case 4:
                                    window.create(sf::VideoMode(1600, 900), "Ludum");
                                case 5:
                                    window.create(sf::VideoMode(1280, 720), "Ludum");
                                case 6:
                                    ClearProgress();
                                case 7:
                                    StateMachine StateMachine;
                                    StateMachine.SendSignal(Signals::menu, window, fullScreen, sound, music, level);
                                    break;
                            }
                            break;
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
        window.setView(window.getDefaultView());
        window.draw(BtnsBackground);
        for (int i = 0; i < 8; ++i) {
            window.draw(SettingButtons[i]);
            window.draw(HighlightedButtons[i]);
        }
        window.display();
    }
    return true;
}

void Settings::MoveUp() {
    if (Choices - 1 >= 0) {
        HighlightedButtons[Choices].setTexture(ButtonNotHighlighter);
        Choices--;
        if (Choices == 3 || Choices == 4 || Choices == 5) {
            HighlightedButtons[Choices].setTexture(SizeButtonHighlight);
        } else {
            HighlightedButtons[Choices].setTexture(ButtonHighlighter);
        }
    }
}

void Settings::MoveDown() {
    if (Choices + 1 < 8) {
        HighlightedButtons[Choices].setTexture(ButtonNotHighlighter);
        Choices++;
        if (Choices == 3 || Choices == 4 || Choices == 5) {
            HighlightedButtons[Choices].setTexture(SizeButtonHighlight);
        } else {
            HighlightedButtons[Choices].setTexture(ButtonHighlighter);
        }
    }
}

void Settings::ClearProgress() {

//    CleanMoney.open("Upgrades/money.txt", std::ofstream::trunc);
//    CleanMoney.close();
//    CleanMoney.open("Upgrades/Upgrade.txt", std::ofstream::trunc);
//    CleanMoney.close();;
//    CleanMoney.open("Highscore/score.txt", std::ofstream::trunc);
//    CleanMoney.close();
//    std::ofstream ScoreWrite;
//    ScoreWrite.open("Highscore/score.txt");
//    for (int i = 0; i < 8; ++i) {
//        ScoreWrite << 0 << std::endl;
//    }
//
//    ScoreWrite.close();

}
