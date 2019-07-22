#ifndef PROJECT_LUDUM_SETTINGS_H
#define PROJECT_LUDUM_SETTINGS_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>

class Settings {

public:
    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void MoveUp();                                      //A function used to make it possible to move up with the arrows

    void MoveDown();                                    //A function used to make it possible to move down with the arrows

    int GetItemSelect() { return Choices; }             //A function to see what choice is the user on

private:
    int         Choices;                                //An integer that is used to check which choice is the user on
    sf::Font    font;                                   //The font used on the screen
    sf::Texture ButtonBackground;                       //A background that is used for multiple buttons like the screen size buttons
    sf::Texture SizeButtonHighlight;                    //A highlighter used under to mark the the screen size buttons
    sf::Texture SoundMutingButton;                      //The sound button before the sound is muted
    sf::Texture MusingMutingButton;                     //The music button before the music i muted
    sf::Texture ChangeToFullScreen;                     //The full screen button shown while the screen is windowed
    sf::Texture ChangeToWindowScreen;                   //The windowed screen button while the screen is full
    sf::Texture MutedSoundButton;                       //The sound button when the sound is muted
    sf::Texture MutedMusicButton;                       //The music button when the music is muted
    sf::Texture ClearProgressButton;                    //The button used to clear all the saves
    sf::Texture BigSizeScreen;                          //The button that shows the 1920x1080
    sf::Texture MiddleSizeScreen;                       //The button that shows the 1600x900
    sf::Texture SmallSizeScreen;                        //The button that shows the 1280x720
    sf::Texture ReturnButton;                           //The button to return to the previous window
    sf::Texture ButtonHighlighter;                      //An icon to make it easier to see what choice is the user on
    sf::Texture ButtonNotHighlighter;                   //Empty texture to mark the choices that the user is not on

    //Sprites that are printed on the screen
    sf::Sprite  HighlightedButtons[9];                   //The buttons that marks the choices
    sf::Sprite  SettingButtons[9];                       //The buttons shown on the screen
    sf::Sprite  BtnsBackground;

    std::ofstream CleanMoney;
    std::ofstream CleanUpgrades;
    std::ofstream CleanScore;

    void ClearProgress();                               //A function that is used to delete all the progress of the game
};




#endif //PROJECT_LUDUM_SETTINGS_H
