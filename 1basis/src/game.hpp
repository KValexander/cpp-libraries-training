#pragma once

// Подключение библиотеки SFMl
#include <SFML/Graphics.hpp>

// Подключение файлов
#include "player.hpp"

// Пространство имён sf
using namespace sf;

// Класс Игра
class Game {
// Приватные методы
private:

	// Позиция игрока
	float x, y;
	float dx, dy;

	RenderWindow* window; // окно
	VideoMode video_mode; // размер окна
	Event event; // событие
	Mouse mouse;

	// Текстуры
	Texture texture;

	// Спрайты
	Sprite sprite;

	// Игрок
	Player player;

	// Игровые объекты
	RectangleShape enemy;

	// Инициализация переменных и окна
	void init_variables();
	void init_window();
	void init_textures();
	void init_sprites();
	void init_enemies();

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
