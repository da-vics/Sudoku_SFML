#pragma once

#include "BasePageClass.h"
#include "SudokuMapGen.h"

class GamePlayPage : public BasePageClass
{

public:

	GamePlayPage(sf::RenderWindow* window, bool compPlay) : BasePageClass(window)
	{
		this->_pageID = "MainPage";
		this->NavTOPage = GamePages::None;
		this->computerPlay = compPlay;
		this->setUp();

	}

	bool computerPlay; // if true "AI" is playing
	void Display() override;
	void HandleEvents(sf::Event*) override;

private:
	void setUp();
	void MouseMoveTigger();
	void HoverCheck(sf::RectangleShape*, sf::Text*);
	void OnFocusEvent();
	bool AISolve(int grid[SudokuMapGen::MaxSize][SudokuMapGen::MaxSize]);
	SudokuMapGen _sudokuMap;
	sf::RectangleShape _gameBoard;
	sf::Font _HeaderFont;
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::RectangleShape _vLine1;
	sf::RectangleShape _vLine2;
	sf::RectangleShape _hLine1;
	sf::RectangleShape _hLine2;
	sf::RectangleShape _gameGridMap[SudokuMapGen::MaxSize][SudokuMapGen::MaxSize];
	sf::Text _textGridMap[SudokuMapGen::MaxSize][SudokuMapGen::MaxSize];
	sf::Text _optionText[SudokuMapGen::MaxSize];
	sf::RectangleShape _optionField[SudokuMapGen::MaxSize];
	int _selectedNumber{ 1 }; //default
	int _selectedIndex{ 0 }; //default
	std::vector<Field> _selections;
	sf::RectangleShape _submitButton;
	sf::RectangleShape _undoButton;
	sf::RectangleShape _checkButton;
	sf::Text _submitText;
	sf::Text _undoText;
	sf::Text _checkText;
	const sf::Color LineColor = sf::Color(193, 154, 107);
	bool _checkErr{ false };
	bool _resetErrColor{ false };
	bool _aiDone{ false };
	bool _initAi{ false };
};

