#include "player.hpp"

// Конструктор
Player::Player() {

	// Позиция
	this->position.x = 0;
	this->position.y = 0;

	// Ускорение
	this->dx = 0;
	this->dy = 0;

}

// Деструктор
Player::~Player() {
	delete this;
}

// Обновление данных игрока
void Player::update() {

    // Обработка нажатий на клавиши
    if(Keyboard::isKeyPressed(Keyboard::Right)) // вправо
    	this->position.x += 10;
    else if(Keyboard::isKeyPressed(Keyboard::Left)) // влево
    	this->position.x -= 10;

    if(Keyboard::isKeyPressed(Keyboard::Up)) // вверх
    	this->position.y -= 10;
    else if(Keyboard::isKeyPressed(Keyboard::Down)) // вниз
    	this->position.y += 10;

}