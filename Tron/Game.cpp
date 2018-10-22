#include "Game.h"
#include "Player.h"
#include <vector>
#include <SFML/Graphics.hpp>


Game::Game() : player1(sf::Vector2f(200,  100), sf::Color::Red), player2(sf::Vector2f(1000, 700), sf::Color::Blue)
{

}

void Game::fill_grid(std::vector<sf::RectangleShape> & grid) const {
	const int offset = 20;
	for (int x = 0; x < 1200; x += offset) {
		sf::RectangleShape line(sf::Vector2f(800, 1));
		line.setFillColor(sf::Color(0, 0, 0));
		line.rotate(90);
		line.setPosition(x, 0);
		grid.push_back(line);
	}

	for (int y = 0; y < 800; y += offset) {
		sf::RectangleShape line(sf::Vector2f(1200, 1));
		line.setFillColor(sf::Color(0, 0, 0));
		line.setPosition(0, y);
		grid.push_back(line);
	}
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tron", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Sprite sprite;
	sf::RenderTexture rt;
	rt.create(1200, 800);
	rt.setSmooth(true);
	sprite.setTexture(rt.getTexture());
	rt.clear(sf::Color(0, 0, 50));

	const float speed = 0.2f;

	std::vector<sf::RectangleShape> grid;

	bool running = true;

	bool field[WIDTH][HEIGHT] = { false };

	player1.set_direction(Player::UP);
	player2.set_direction(Player::DOWN);

	fill_grid(grid);

	for (auto & line : grid) rt.draw(line);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		auto delta_time = clock.restart().asMilliseconds();
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			handle_input();
		}

		if (!running) continue;
		
		for (auto i = 0; i < (speed * delta_time); i++) {

			player1.update();
			player2.update();

			const auto p1x = static_cast<int>(round(player1.current_position.x));
			const auto p1y = static_cast<int>(round(player1.current_position.y));

			const auto p2x = static_cast<int>(round(player2.current_position.x));
			const auto p2y = static_cast<int>(round(player2.current_position.y));

			if (field[p1x][p1y]) running = false;
			if (field[p2x][p2y]) running = false;

			field[p1x][p1y] = true;
			field[p2x][p2y] = true;

			player1.draw(rt);
			player2.draw(rt);
		}

		window.draw(sprite);
		window.display();
	}
}

void Game::handle_input(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player1.set_direction(Player::LEFT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player1.set_direction(Player::RIGHT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player1.set_direction(Player::UP);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player1.set_direction(Player::DOWN);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player2.set_direction(Player::LEFT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player2.set_direction(Player::RIGHT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player2.set_direction(Player::UP);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player2.set_direction(Player::DOWN);
	}
}
