#include "includes/StartPage.h"


void StartPage::setUp() {

	if (!this->_HeaderFont.loadFromFile("Fonts/Handlee.ttf")) {
		std::cout << "Error Loading Fonts" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->_bgTexture.loadFromFile("Images/WoodenBoard.jpg")) {
		std::cout << "Error Loading Images/WoodenBoard.jpg" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	auto textureSize = this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("SudoKu");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::White);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.2f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;
	this->_PlayGameButton.setSize(sf::Vector2f(170.f, height));
	this->_PlayGameButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_PlayGameButton.setFillColor(CaramelColor);

	this->_playGameText.setFillColor(sf::Color::White);
	this->_playGameText.setFont(this->_HeaderFont);
	this->_playGameText.setCharacterSize(20);
	this->_playGameText.setString("Play Game");
	auto Framex = Posx + this->_PlayGameButton.getLocalBounds().width / 1.4f - (this->_PlayGameButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_PlayGameButton.getLocalBounds().height / 1.5f - (this->_PlayGameButton.getLocalBounds().height / 2.f);
	this->_playGameText.setPosition(Framex, Framey);


	Posy += 65;
	this->_computerPlayButton.setSize(sf::Vector2f(170.f, height));
	this->_computerPlayButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_computerPlayButton.setFillColor(CaramelColor);

	this->_computerPlayText.setFillColor(sf::Color::White);
	this->_computerPlayText.setFont(this->_HeaderFont);
	this->_computerPlayText.setCharacterSize(20);
	this->_computerPlayText.setString("Computer Play");
	Framex = Posx + this->_computerPlayButton.getLocalBounds().width / 1.6f - (this->_computerPlayButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_computerPlayButton.getLocalBounds().height / 1.5f - (this->_computerPlayButton.getLocalBounds().height / 2.f);
	this->_computerPlayText.setPosition(Framex, Framey);


	Posy += 65;
	this->_exitButton.setSize(sf::Vector2f(170.f, height));
	this->_exitButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_exitButton.setFillColor(CaramelColor);

	this->_exitButtonText.setFillColor(sf::Color::White);
	this->_exitButtonText.setFont(this->_HeaderFont);
	this->_exitButtonText.setCharacterSize(20);
	this->_exitButtonText.setString("Quit");
	Framex = Posx + this->_exitButton.getLocalBounds().width / 1.15f - (this->_exitButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_exitButton.getLocalBounds().height / 1.5f - (this->_exitButton.getLocalBounds().height / 2.f);
	this->_exitButtonText.setPosition(Framex, Framey);
}

void StartPage::Display() {

	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_PlayGameButton);
	this->_window->draw(this->_playGameText);
	this->_window->draw(this->_computerPlayButton);
	this->_window->draw(this->_computerPlayText);
	this->_window->draw(this->_exitButton);
	this->_window->draw(this->_exitButtonText);

	this->_window->display();
}

void StartPage::OnFocusEvent() {

	if (this->IsMouseOverButton(this->_PlayGameButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::GamePlayPage_P;
	}

	else if (this->IsMouseOverButton(this->_computerPlayButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::GamePlayPage_C;
	}

	else if (this->IsMouseOverButton(this->_exitButton)) {

		this->_window->close();
	}
}

void StartPage::MouseMoveTigger() {

	if (this->IsMouseOverButton(this->_PlayGameButton)) {

		this->_PlayGameButton.setFillColor(sf::Color::White);
		this->_playGameText.setFillColor(CaramelColor);
	}                                                                       //PlayGame
	else {
		this->_PlayGameButton.setFillColor(CaramelColor);
		this->_playGameText.setFillColor(sf::Color::White);
	}


	if (this->IsMouseOverButton(this->_computerPlayButton)) {

		this->_computerPlayButton.setFillColor(sf::Color::White);
		this->_computerPlayText.setFillColor(CaramelColor);
	}                                                                       //CompPlay
	else {
		this->_computerPlayButton.setFillColor(CaramelColor);
		this->_computerPlayText.setFillColor(sf::Color::White);
	}

	if (this->IsMouseOverButton(this->_exitButton)) {

		this->_exitButton.setFillColor(sf::Color::White);
		this->_exitButtonText.setFillColor(CaramelColor);
	}                                                                       //exit
	else {
		this->_exitButton.setFillColor(CaramelColor);
		this->_exitButtonText.setFillColor(sf::Color::White);
	}
}


void StartPage::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}