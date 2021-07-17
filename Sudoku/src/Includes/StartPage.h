#pragma once

#include"BasePageClass.h"

class StartPage : public BasePageClass
{
public:

	StartPage(sf::RenderWindow* window) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "StartPage";
		this->NavTOPage = GamePages::None;
	}

	void Display() override;
	void HandleEvents(sf::Event*) override;

	const sf::Color CaramelColor = sf::Color(193, 154, 107);

private:
	void setUp();
	void MouseMoveTigger();
	void OnFocusEvent();
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::Text _mainTitle;
	sf::Font _HeaderFont;
	sf::RectangleShape _PlayGameButton;
	sf::RectangleShape _computerPlayButton;
	sf::RectangleShape _exitButton;
	sf::Text _playGameText;
	sf::Text _computerPlayText;
	sf::Text _exitButtonText;
};