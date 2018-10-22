#pragma once
#include <SFML\Graphics.hpp>

class Player {
public:

	enum Direction {
		UP, DOWN, LEFT, RIGHT
	};

	Player(sf::Vector2f start_position, sf::Color color);
	~Player() = default;

	void update();
	void draw(sf::RenderTexture & rt) const;

	void set_direction(Direction new_direction);
	sf::Vector2f current_position;

private:
	sf::Color color;
	Direction direction = RIGHT;
};
