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

    // Состояние прыжка
    this->is_jump = false;

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

// Прыжок
void Player::jump() {
    if(!this->is_jump) {
        this->dy = -10;
        this->is_jump = true;
    } this->dy -= 0.2f; // для плавности падения
}

// Остановка падения
void Player::stop_falling(float y) {
    this->position.y = y - 64;
    this->dy = 0.0f; // остановка скорости падения
    this->is_jump = false; // состояние прыжка
}

// Обновление данных игрока
void Player::update() {

    // Обработка нажатий на клавиши

    // Нажатие на прыжок
    if(Keyboard::isKeyPressed(Keyboard::Up))
        this->jump();


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

    // Обновление позиции игрока
    this->position.x += this->dx;
    this->position.y += this->dy;

}