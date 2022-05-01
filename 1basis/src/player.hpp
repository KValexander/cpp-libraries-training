#pragma once

// Подключение библиотеки SFMl
#include <SFML/Graphics.hpp>

// Пространство имён sf
using namespace sf;

// Класс Игрок
class Player {
private:

	Vector2f position; // позиция
	float dx, dy; // скорость

public:
	
	Player(); // конструктор
	virtual ~Player(); // деструктор

	Vector2f get_position(); // получить позицию
	void increase_dy(float gravity); // прибавить скорость падения

	void stop_falling(); // остановка падения
	void update(); // обновление данных игрока

};