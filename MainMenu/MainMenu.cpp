#include "MainMenu.h"
#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>

MainMenu::MainMenu(float width, float height) {

    font.loadFromFile("data/FROSTBITE-Wide Bold.ttf");
    StartGameButton.loadFromFile("Buttons/PlayButton.png");
    ScoreButton.loadFromFile("Buttons/HighscoreButton.png");
    UpgradesButton.loadFromFile("Buttons/UpgradeButton.png");
    SettingButton.loadFromFile("Buttons/SettingButton.png");
    ExitButton.loadFromFile("Buttons/ExitButton.png");
    ButtonHighlighter.loadFromFile("Buttons/ButtonHighlight.png");
    ButtonNotHighlighter.loadFromFile("Buttons/BtnNotHighlight.png");

    MainMenuButtons[0].setTexture(StartGameButton);
    MainMenuButtons[0].setPosition(width / 2 + 300, height / 9 * 1);

    HighlightedButtons[0].setTexture(ButtonHighlighter);
    HighlightedButtons[0].setPosition(width / 2 + 240, height / 9 * 1);

    MainMenuButtons[1].setTexture(ScoreButton);
    MainMenuButtons[1].setPosition(width / 2 + 300, height / 9 * 2);

    HighlightedButtons[1].setTexture(ButtonNotHighlighter);
    HighlightedButtons[1].setPosition(width / 2 + 240, height / 9 * 2);

    MainMenuButtons[2].setTexture(UpgradesButton);
    MainMenuButtons[2].setPosition(width / 2 + 300, height / 9 * 3);

    HighlightedButtons[2].setTexture(ButtonNotHighlighter);
    HighlightedButtons[2].setPosition(width / 2 + 240, height / 9 * 3);

    MainMenuButtons[3].setTexture(SettingButton);
    MainMenuButtons[3].setPosition(width / 2 + 300, height / 9 * 4);

    HighlightedButtons[3].setTexture(ButtonNotHighlighter);
    HighlightedButtons[3].setPosition(width / 2 + 240, height / 9 * 4);

    MainMenuButtons[4].setTexture(ExitButton);
    MainMenuButtons[4].setPosition(width / 2 + 300, height / 9 * 5);

    HighlightedButtons[4].setTexture(ButtonNotHighlighter);
    HighlightedButtons[4].setPosition(width / 2 + 240, height / 9 * 5);

    Choices = 0;
}

MainMenu::~MainMenu() {

}

void MainMenu::draw(sf::RenderWindow &window) {
    MenuPanel.loadFromFile("MainMenu/MainMenu.png");
    sf::Sprite menuPanel;
    menuPanel.setPosition(1920 / 2 - 290, 1080 / 8);
    menuPanel.setTexture(MenuPanel);
    window.setView(window.getDefaultView());
    //window.draw(menuPanel);
    for (int i = 0; i < 5; ++i) {
        window.draw(MainMenuButtons[i]);
        window.draw(HighlightedButtons[i]);
    }
}

void MainMenu::MoveUp() {
    if (Choices - 1 >= 0) {
        HighlightedButtons[Choices].setTexture(ButtonNotHighlighter);
        Choices--;
        HighlightedButtons[Choices].setTexture(ButtonHighlighter);

    }
}

void MainMenu::MoveDown() {
    if (Choices + 1 < 5) {
        HighlightedButtons[Choices].setTexture(ButtonNotHighlighter);
        Choices++;
        HighlightedButtons[Choices].setTexture(ButtonHighlighter);
    }
}