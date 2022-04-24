#pragma once

// Подключение библиотеки SFMl
#include <SFML/Graphics.hpp>

// Пространство имён sf
using namespace sf;

// Класс Game
class Game {
// Приватные методы
private:

	RenderWindow* window; // окно
	Event event; // событие
	VideoMode video_mode; // размер окна

	// Инициализация переменных и окна
	void init_variables();
	void init_window();

// Публичные методы
public:
	Game(); // Конструктор
	virtual ~Game(); // Деструктор

	// Аксессор
	const bool running() const;

	void events(); // Обработка событий
	void update(); // Обновление данных
	void render(); // Отрисовка данных
	void game_loop(); // Игровой цикл

};
