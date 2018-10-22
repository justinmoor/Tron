#include "Player.h"
#include "Util.h"
#include "Game.h"

Player::Player(const sf::Vector2f start_position, const sf::Color color) :
	current_position(start_position),
	color(color)
{ }


void Player::update() {
	switch(direction){
		case UP: current_position.y += 1;
					break;
		case DOWN: current_position.y -= 1;
					break;
		case LEFT: current_position.x -= 1;
					break;
		case RIGHT: current_position.x += 1;
					break;
	}

	if (current_position.x >= WIDTH)	current_position.x = 0;
	if (current_position.x < 0)			current_position.x = WIDTH - 1;
	if (current_position.y >= HEIGHT)	current_position.y = 0;
	if (current_position.y < 0)			current_position.y = HEIGHT -1;
}

void Player::set_direction(Direction new_direction){
	if (direction == Direction::UP && new_direction != Direction::DOWN)		direction = new_direction;
	if (direction == Direction::DOWN && new_direction != Direction::UP)		direction = new_direction;
	if (direction == Direction::LEFT && new_direction != Direction::RIGHT)	direction = new_direction;
	if (direction == Direction::RIGHT && new_direction != Direction::LEFT)	direction = new_direction;
}

void Player::draw(sf::RenderTexture& rt) const{
	sf::RectangleShape linePart(sf::Vector2f(5, 5));
	linePart.setPosition(current_position);
	linePart.setFillColor(color);

	rt.draw(linePart);
}


