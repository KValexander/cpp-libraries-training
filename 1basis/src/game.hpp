#pragma once

// Константы
#define GRAVITY 0.4f // гравитация
#define NUM_SURFACES 100

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
	int frame; // время

	RenderWindow* window; // окно
	VideoMode video_mode; // размер окна
	Event event; // событие
	Mouse mouse;

	// Область отрисовки
	View view;

	// Текстуры
	Texture texture;

	// Спрайты
	Sprite sprite;

	// Игрок
	Player player;

	// Игровые объекты
	RectangleShape enemy;

	// Поверхность
	RectangleShape surfaces[NUM_SURFACES];

	// Инициализация переменных и окна
	void init_variables();
	void init_window();
	void init_view();
	void init_textures();
	void init_sprites();
	void init_enemies();
	void init_surfaces();

// Публичные методы
public:
	Game(); // Конструктор
	virtual ~Game(); // Деструктор

	// Аксессор
	const bool running() const;

	// Проверка пересечения прямоугольников
	int collision_rectangle(float x1, float y1, float x2,
		float y2, float w1, float h1, float w2, float h2);

	// Обновление области отрисовки
	void update_view(Vector2f position);

	void events(); // Обработка событий
	void collision(); // коллизии
	void update(); // Обновление данных
	void render(); // Отрисовка данных
	void game_loop(); // Игровой цикл

};
