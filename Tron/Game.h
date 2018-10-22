#pragma once
#include "Player.h"

constexpr int HEIGHT = 800;
constexpr int WIDTH = 1200;

class Game
{
public:
	Game();
	~Game() = default;
	void run();

private:
	Player player1;
	Player player2;
	void fill_grid(std::vector<sf::RectangleShape> & grid) const;
	void handle_input();
};

