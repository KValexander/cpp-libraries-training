#pragma once

// Подключение библиотеки SFMl
#include <SFML/Graphics.hpp>

// Пространство имён sf
using namespace sf;

// Класс Игрок
class Player {
private:

	Vector2f position; // позиция
	float dx, dy; 	   // скорость
	bool is_jump; 	   // состояние прыжка
	bool is_dead; 	   // состояние смерти
	int lives; 	  	   // жизни
	int direction; 	   // направление

	// Фреймы
	Vector2f frame_size; // размер фрейма
	Vector2f current_frame; // текущий фрейм
	int count_frames; // количество фреймов

public:
	
	Player(); // конструктор
	virtual ~Player(); // деструктор

	int get_lives(); // получить количество жизней игрока
	bool get_is_dead(); // получить состояние смерти игрока

	Vector2f get_position(); // получить позицию
	Vector2f get_size(); // получить позицию
	Vector2f get_scale(); // получить масштаб
	IntRect get_frame_rect(); // вернуть данные текущего фрейма

	void increase_dy(float gravity); // прибавить скорость падения
	void stop_falling(float y); // остановка падения
	void die(); // убить игрока

	void reset(); // сбросить данные

	void jump(); // прыжок
	void update(int frame); // обновление данных игрока

};