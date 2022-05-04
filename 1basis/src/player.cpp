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

    // Направление
    /*
        0 - Лево
        1 - Право
    */
    this->direction = 0;

    // Размер фреймов
    this->frame_size.x = 64;
    this->frame_size.y = 64;

    // Текущий фрейм
    this->current_frame.x = 0;
    this->current_frame.y = 0;

    // Количество фреймов
    this->count_frames = 2;

}

// Деструктор
Player::~Player() {
	// delete this;
}

// Получение позиции
Vector2f Player::get_position() {
    return this->position;
}

// Получение размеры
Vector2f Player::get_size() {
    return this->frame_size;
}

// Получение масштаб
Vector2f Player::get_scale() {
    return Vector2f((this->direction) ? 1.f : -1.f, 1.f);
}

// Получение данных текущего фрейма
IntRect Player::get_frame_rect() {
    return IntRect(
        this->frame_size.x * this->current_frame.x,
        this->frame_size.y * this->current_frame.y,
        this->frame_size.x,
        this->frame_size.y
    );
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
void Player::update(int frame) {

    // Обработка нажатий на клавиши

    // Нажатие на прыжок
    if(Keyboard::isKeyPressed(Keyboard::Up))
        this->jump();

    // Движение в право
    if(Keyboard::isKeyPressed(Keyboard::Right)) {
        this->direction = 1;
        // this->current_frame.x = 1;
        if(frame % 10 == 0)
            this->current_frame.x = (this->current_frame.x >= 1) ? 0 : ++this->current_frame.x;
    	this->dx += 0.5f;
    	if(this->dx > 6)
    		this->dx = 6;
    }

    // Движение в лево
    else if(Keyboard::isKeyPressed(Keyboard::Left)) {
        this->direction = 0;
        // this->current_frame.x = 1;
        if(frame % 10 == 0)
            this->current_frame.x = (this->current_frame.x >= 1) ? 0 : ++this->current_frame.x;
    	this->dx -= 0.5f;
    	if(this->dx < -6)
    		this->dx = -6;
    }

    // Стоячее состояние по горизонтали
    else {
        this->current_frame.x = 0;
    	this->dx *= 0.8f;
    	if(abs(this->dx) < 0.1f)
    		this->dx = 0;
    }

    // Анимация прыжка
    if(this->is_jump)
        this->current_frame.x = 1;

    // Обновление позиции игрока
    this->position.x += this->dx;
    this->position.y += this->dy;

}