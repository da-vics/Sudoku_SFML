#include "Includes/GamePlayPage.h"

void GamePlayPage::setUp() {


	if (!this->_bgTexture.loadFromFile("Images/WoodenBoard.jpg")) {
		std::cout << "Error Loading Images/WoodenBoard.jpg" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->_HeaderFont.loadFromFile("Fonts/Handlee.ttf")) {
		std::cout << "Error Loading Fonts" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	auto textureSize = this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);

	this->_gameBoard.setFillColor(sf::Color(209, 201, 178));
	this->_gameBoard.setSize(sf::Vector2f(500.f, 450.f));
	this->_gameBoard.setPosition(sf::Vector2f(this->_window->getSize().x / 2.f - this->_gameBoard.getLocalBounds().width / 2.f,
		this->_window->getSize().y / 2.f - this->_gameBoard.getLocalBounds().height / 2.f));

#pragma region Vertical BoardLine

	auto boardOriginX = this->_gameBoard.getPosition().x;
	auto boardOriginY = this->_gameBoard.getPosition().y;

	this->_vLine1.setFillColor(LineColor);
	this->_vLine1.setSize(sf::Vector2f(3.f, 450));
	this->_vLine1.setPosition(sf::Vector2f(boardOriginX + 166.7f, boardOriginY));

	this->_vLine2.setFillColor(LineColor);
	this->_vLine2.setSize(sf::Vector2f(3.f, 450));
	this->_vLine2.setPosition(sf::Vector2f(boardOriginX + 333.3f, boardOriginY));

#pragma endregion


#pragma region Horizontal BoardLine

	this->_hLine1.setFillColor(LineColor);
	this->_hLine1.setSize(sf::Vector2f(500.f, 3.f));
	this->_hLine1.setPosition(sf::Vector2f(boardOriginX, boardOriginY + 150.f));

	this->_hLine2.setFillColor(LineColor);
	this->_hLine2.setSize(sf::Vector2f(500.f, 3.f));
	this->_hLine2.setPosition(sf::Vector2f(boardOriginX, boardOriginY + 300.f));

#pragma endregion

	auto buttonX = boardOriginX + 43;
	auto ButtonY = boardOriginY - 55;

	this->_submitButton.setFillColor(LineColor);
	this->_submitButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_submitButton.setPosition(sf::Vector2f(buttonX, ButtonY));

	this->_submitText.setFont(this->_HeaderFont);
	this->_submitText.setCharacterSize(20);
	this->_submitText.setFillColor(sf::Color::White);

	float sizex;
	float sizey;

	if (this->computerPlay == true)
	{
		this->_submitText.setString("Start");
		sizex = this->_submitText.getLocalBounds().width / 1.2f;
		sizey = this->_submitText.getLocalBounds().height / 2.f;
		this->_submitText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));
	}

	else
	{
		this->_submitText.setString("Submit");
		sizex = this->_submitText.getLocalBounds().width / 2.f;
		sizey = this->_submitText.getLocalBounds().height / 2.f;
		this->_submitText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));

	}

	buttonX += 140.f;

	this->_checkButton.setFillColor(LineColor);
	this->_checkButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_checkButton.setPosition(sf::Vector2f(buttonX, ButtonY));

	this->_checkText.setFont(this->_HeaderFont);
	this->_checkText.setCharacterSize(20);
	this->_checkText.setFillColor(sf::Color::White);
	this->_checkText.setString("Check-Board");

	sizex = this->_checkText.getLocalBounds().width / 12.f;
	sizey = this->_checkText.getLocalBounds().height / 2.f;

	this->_checkText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));
	buttonX += 140.f;

	this->_undoButton.setFillColor(LineColor);
	this->_undoButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_undoButton.setPosition(sf::Vector2f(buttonX, ButtonY));

	this->_undoText.setFont(this->_HeaderFont);
	this->_undoText.setCharacterSize(20);
	this->_undoText.setFillColor(sf::Color::White);
	this->_undoText.setString("Undo");

	sizex = this->_undoText.getLocalBounds().width / 1.2f;
	sizey = this->_undoText.getLocalBounds().height / 2.f;

	this->_undoText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));

#pragma region SetInitGrid

	auto gridPosX = boardOriginX;
	auto gridPosY = boardOriginY;


	for (int i = 0; i < SudokuMapGen::MaxSize;++i) {

		for (int j = 0; j < SudokuMapGen::MaxSize;++j) {

			this->_gameGridMap[i][j].setFillColor(sf::Color(223, 229, 237));
			this->_gameGridMap[i][j].setOutlineColor(sf::Color(sf::Color(92, 95, 99)));
			this->_gameGridMap[i][j].setOutlineThickness(2.f);
			this->_gameGridMap[i][j].setSize(sf::Vector2f(55.55f, 50.f));
			this->_gameGridMap[i][j].setPosition(sf::Vector2f(gridPosX, gridPosY));

			this->_textGridMap[i][j].setFont(this->_HeaderFont);
			this->_textGridMap[i][j].setCharacterSize(30);
			this->_textGridMap[i][j].setFillColor(sf::Color(55, 57, 59));

			auto boxVal = this->_sudokuMap.gameMap[i][j];           // load values from gridMap 
			auto strBoxVal = std::to_string(boxVal);
			this->_textGridMap[i][j].setString(strBoxVal);

			auto sizex = this->_textGridMap[i][j].getLocalBounds().width / 0.8f;
			auto sizey = this->_textGridMap[i][j].getLocalBounds().height / 2.f;

			this->_textGridMap[i][j].setPosition(sf::Vector2f(gridPosX + sizex, gridPosY + sizey));

			gridPosX += 55.55f;
		}
		gridPosY += 50.f;
		gridPosX = boardOriginX;
	}

#pragma endregion


#pragma region Option Selector

	if (this->computerPlay == false)
	{
		gridPosX = boardOriginX;
		gridPosY += 20;
		int fillval = 1;

		for (int i = 0; i < SudokuMapGen::MaxSize; ++i) {

			this->_optionField[i].setFillColor(sf::Color(223, 229, 237));
			this->_optionField[i].setOutlineColor(sf::Color(sf::Color(92, 95, 99)));
			this->_optionField[i].setOutlineThickness(1.f);
			this->_optionField[i].setSize(sf::Vector2f(55.55f, 50.f));
			this->_optionField[i].setPosition(sf::Vector2f(gridPosX, gridPosY));

			this->_optionText[i].setFont(this->_HeaderFont);
			this->_optionText[i].setCharacterSize(30);
			this->_optionText[i].setFillColor(sf::Color(55, 57, 59));
			this->_optionText[i].setString(std::to_string(fillval));

			auto sizex = this->_optionText[i].getLocalBounds().width / 0.8f;
			auto sizey = this->_optionText[i].getLocalBounds().height / 2.f;

			this->_optionText[i].setPosition(sf::Vector2f(gridPosX + sizex, gridPosY + sizey));

			gridPosX += 55.55f;
			++fillval;
		}

		this->_optionField[this->_selectedIndex].setFillColor(sf::Color(193, 154, 107));
	}//

#pragma endregion

}

void GamePlayPage::Display() {

	this->_window->clear();

	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_gameBoard);

	for (int i = 0; i < SudokuMapGen::MaxSize;++i) {

		if (this->computerPlay == false) {
			this->_window->draw(this->_optionField[i]);    //Option Selector
			this->_window->draw(this->_optionText[i]);
		}

		for (int j = 0; j < SudokuMapGen::MaxSize;++j) {

			this->_window->draw(this->_gameGridMap[i][j]); //

			if (this->_sudokuMap.gameMap[i][j] == 0)
				continue;
			this->_window->draw(this->_textGridMap[i][j]);
		}
	}//

	this->_window->draw(this->_vLine1);
	this->_window->draw(this->_vLine2);
	this->_window->draw(this->_hLine1);
	this->_window->draw(this->_hLine2);

	if (this->computerPlay == false) {

		this->_window->draw(this->_checkButton);
		this->_window->draw(this->_undoButton);
		this->_window->draw(this->_checkText);
		this->_window->draw(this->_undoText);
	}

	this->_window->draw(this->_submitButton);
	this->_window->draw(this->_submitText);

	this->_window->display();
}

void GamePlayPage::MouseMoveTigger() {

	for (int i = 0; i < SudokuMapGen::MaxSize; ++i) {

		if (this->IsMouseOverButton(this->_optionField[i]))
			this->_optionField[i].setFillColor(sf::Color(193, 154, 107));
		else
		{
			if (i != this->_selectedIndex)
				this->_optionField[i].setFillColor(sf::Color(223, 229, 237));
		}

		for (int j = 0; j < SudokuMapGen::MaxSize; ++j) {

			if (this->IsMouseOverButton(this->_gameGridMap[i][j]))
				this->_gameGridMap[i][j].setFillColor(sf::Color(193, 154, 107));
			else
				this->_gameGridMap[i][j].setFillColor(sf::Color(223, 229, 237));
		}
	}

	HoverCheck(&this->_submitButton, &this->_submitText);
	HoverCheck(&this->_checkButton, &this->_checkText);
	HoverCheck(&this->_undoButton, &this->_undoText);
}

void GamePlayPage::HoverCheck(sf::RectangleShape* button, sf::Text* buttonText) {

	if (this->IsMouseOverButton(*button))
	{
		button->setFillColor(sf::Color::White);
		buttonText->setFillColor(LineColor);
	}
	else
	{
		button->setFillColor(LineColor);
		buttonText->setFillColor(sf::Color::White);
	}
}

void GamePlayPage::OnFocusEvent() {

	for (int i = 0; i < SudokuMapGen::MaxSize; ++i) {

		if (this->IsMouseOverButton(this->_optionField[i])) {

			this->_optionField[this->_selectedIndex].setFillColor(sf::Color(223, 229, 237)); //reset element Previously highlighted.. 
			this->_selectedIndex = i;
			this->_optionField[i].setFillColor(sf::Color(193, 154, 107));
			this->_selectedNumber = this->_selectedIndex + 1;
		}

		for (int j = 0; j < SudokuMapGen::MaxSize; ++j) {

			if (this->IsMouseOverButton(this->_gameGridMap[i][j])) {

				if (this->_sudokuMap.gameMap[i][j] == 0)
				{
					this->_textGridMap[i][j].setString(std::to_string(this->_selectedNumber));
					this->_sudokuMap.gameMap[i][j] = this->_selectedNumber;
					this->_selections.push_back({ i,j });
				}
			}
		}
	}

	if (this->IsMouseOverButton(this->_submitButton)) {

		int rol, col;
		if (this->_sudokuMap.FindUnassignedLocation(this->_sudokuMap.gameMap, rol, col))
		{
			this->AlertWindow(this->_HeaderFont, "Grid not completely filled!", 300, 100, sf::Color(223, 229, 237), LineColor);
		}

		else
		{
			if (this->_checkErr == false) {

				for (int i = 0; i < SudokuMapGen::MaxSize; ++i) {
					for (int j = 0; j < SudokuMapGen::MaxSize; ++j) {

						auto value = this->_sudokuMap.gameMap[i][j];

						if (this->_sudokuMap.isSafe(this->_sudokuMap.gameMap, i, j, value) == false)
						{
							this->_checkErr = true;
							this->_textGridMap[i][j].setFillColor(sf::Color::Red);
						}
					}
				}//
			}//
			if (this->_checkErr == false) {

				this->AlertWindow(this->_HeaderFont, "Completed! You Won!", 200, 100, sf::Color(223, 229, 237), LineColor);
			}
		}
	}

	if (this->IsMouseOverButton(this->_undoButton)) {

		if (this->_selections.size() > 0) {

			auto field = this->_selections.end() - 1;
			this->_sudokuMap.gameMap[field->row][field->col] = 0;
			this->_textGridMap[field->row][field->col].setString(" ");
			this->_selections.pop_back();
		}

		else
			this->AlertWindow(this->_HeaderFont, "Nothing to undo!", 300, 100, sf::Color(223, 229, 237), LineColor);

		if (this->_checkErr) {
			for (int i = 0; i < SudokuMapGen::MaxSize; ++i) {

				for (int j = 0; j < SudokuMapGen::MaxSize; ++j) {
					this->_textGridMap[i][j].setFillColor(sf::Color(55, 57, 59));
				}
			}
			this->_checkErr = false;
		}
	}

	if (this->IsMouseOverButton(this->_checkButton)) {

		for (int i = 0; i < SudokuMapGen::MaxSize; ++i) {
			for (int j = 0; j < SudokuMapGen::MaxSize; ++j) {

				auto value = this->_sudokuMap.gameMap[i][j];
				if (value == 0)
					continue;

				if (this->_sudokuMap.isSafe(this->_sudokuMap.gameMap, i, j, value) == false)
				{
					this->_checkErr = true;
					this->_textGridMap[i][j].setFillColor(sf::Color::Red);
				}
			}
		}//

		if (this->_checkErr == false)
			this->AlertWindow(this->_HeaderFont, "No errors for now..", 300, 100, sf::Color(223, 229, 237), LineColor);
	}//

}

void GamePlayPage::HandleEvents(sf::Event* event) {

	if (this->computerPlay == false) {

		if (event->type == sf::Event::MouseButtonPressed)
			this->OnFocusEvent();

		if (event->type == sf::Event::MouseMoved)
			this->MouseMoveTigger();
	}

	else
	{
		if (event->type == sf::Event::MouseMoved)
			HoverCheck(&this->_submitButton, &this->_submitText);

		if (event->type == sf::Event::MouseButtonPressed) {

			if (this->IsMouseOverButton(this->_submitButton))
				this->_initAi = true;
		}
	}

	if (event->type == sf::Event::KeyPressed) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) // Go back to startPage
		{
			this->_window->clear(sf::Color::Black);
			this->ChangePage = true;
			this->NavTOPage = GamePages::StartPage;
		}
	}

	if (this->computerPlay == true && this->_aiDone != true && this->_initAi) {

		auto check = this->AISolve(this->_sudokuMap.gameMap);
		this->_aiDone = true;

		if (check)
			this->AlertWindow(this->_HeaderFont, "Completed!", 150, 100, sf::Color(223, 229, 237), LineColor);
		else
			this->AlertWindow(this->_HeaderFont, "Can't be Solved!", 200, 100, sf::Color(223, 229, 237), LineColor);
	}
}

bool GamePlayPage::AISolve(int grid[SudokuMapGen::MaxSize][SudokuMapGen::MaxSize])
{
	int row, col;

	if (!this->_sudokuMap.FindUnassignedLocation(grid, row, col))
		return true;

	for (int value = 1; value <= SudokuMapGen::MaxSize; value++)
	{

		if (this->_sudokuMap.isSafe(grid, row, col, value))
		{
			grid[row][col] = value;
			this->_textGridMap[row][col].setString(std::to_string(value));
			this->Display();

			if (AISolve(grid))
				return true;

			grid[row][col] = 0;
			this->_textGridMap[row][col].setString(std::to_string(0));
			this->Display();
		}
	}
	return false;
}