#include"Includes/PagesManager.h"
#include"Includes/SudokuMapGen.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Sudoku", sf::Style::Titlebar | sf::Style::Close);
	PagesManager pageManager(&window);
	/*SudokuMapGen gen;                       
	gen.printGrid(gen.gameMap);
	gen.Solve(gen.gameMap);                // debug
	std::cout << "\n\n\n\n";
	gen.printGrid(gen.gameMap);*/


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			pageManager.HandleEvents(&event);

		}
		pageManager.Display();
	}
}