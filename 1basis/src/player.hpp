#pragma once

// Подключение библиотеки SFMl
#include <SFML/Graphics.hpp>

// Пространство имён sf
using namespace sf;

// Класс Игрок
class Player {
private:
	float dx, dy; // ускорение

public:
	Vector2f position; // позиция
	
	Player(); // конструктор
	virtual ~Player(); // деструктор

	void update(); // обновление данных игрока

};