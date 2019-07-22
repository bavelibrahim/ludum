#ifndef PROJECT_LUDUM_MAINMENU_H
#define PROJECT_LUDUM_MAINMENU_H


#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu(float width, float height);

    ~MainMenu();

    void draw(sf::RenderWindow &window);

    void MoveUp();                              //A function used to make it possible to move up with the arrows

    void MoveDown();                            //A function used to make it possible to move down with the arrows

    int GetItemSelect() { return Choices; }     //A function to see what choice is the user on

private:
    int         Choices;                        //An integer that is used to check which choice is the user on
    sf::Font    font;
    sf::Texture MenuPanel;
    sf::Texture StartGameButton;                //A button to start the game
    sf::Texture ScoreButton;                    //A button to go to the high score window
    sf::Texture UpgradesButton;                 //A button to go to the upgrades window
    sf::Texture SettingButton;                  //A button to go to the settings window
    sf::Texture ExitButton;                     //A button to close the game
    sf::Texture ButtonHighlighter;              //An icon to make it easier to see what choice is the user on
    sf::Texture ButtonNotHighlighter;           //Empty texture to mark the choices that the user is not on
    sf::Sprite  MainMenuButtons[5];             //The buttons shown on the screen
    sf::Sprite  HighlightedButtons[5];          //The buttons that marks the choices

};


#endif //PROJECT_LUDUM_MAINMENU_H
