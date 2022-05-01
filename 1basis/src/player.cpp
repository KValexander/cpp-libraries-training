// Подключение библиотек
#include <cmath>

// Подключение файлов
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
	// delete this;
}

// Получение позиции
Vector2f Player::get_position() {
	return this->position;
}

// Увеличение скорости падения
void Player::increase_dy(float gravity) { 
    this->dy += gravity;
}

// Остановка падения
void Player::stop_falling() {
    this->dy = 0.0f;
}

// Обновление данных игрока
void Player::update() {

    // Обработка нажатий на клавиши

    // Движение в право
    if(Keyboard::isKeyPressed(Keyboard::Right)) {
    	this->dx += 0.5f;
    	if(this->dx > 6)
    		this->dx = 6;
    }

    // Движение в лево
    else if(Keyboard::isKeyPressed(Keyboard::Left)) {
    	this->dx -= 0.5f;
    	if(this->dx < -6)
    		this->dx = -6;
    }

    // Стоячее состояние по горизонтали
    else {
    	this->dx *= 0.8f;
    	if(abs(this->dx) < 0.1f)
    		this->dx = 0;
    }

    // Движение в верх
    if(Keyboard::isKeyPressed(Keyboard::Up)) {
    	this->dy -= 0.5f;
    	if(this->dy < -6)
    		this->dy = -6;
    }

    // // Движение в низ
    // else if(Keyboard::isKeyPressed(Keyboard::Down)) {
    // 	this->dy += 0.5f;
    // 	if(this->dy > 6)
    // 		this->dy = 6;
    // }

    // // Стоячее состояние вертикали
    // else {
    // 	this->dy *= 0.8f;
    // 	if(abs(this->dy) < 0.1f)
    // 		this->dy = 0;
    // }

    // Обновление позиции игрока
    this->position.x += this->dx;
    this->position.y += this->dy;

}