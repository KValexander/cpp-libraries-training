#include <iostream>

#include "game.hpp"
	
// Конструктор
Game::Game() {

	// Инициализация
	this->init_variables(); // инициализиция переменных
	this->init_window(); // инициализиция окна
	this->init_textures(); // инициализиция текстур
	this->init_sprites(); // инициализиция спрайтов
	this->init_enemies(); // инициализиция противника

}

// Деструктор
Game::~Game() {

	// Удаление окна
	delete this->window;

}

// Инициализация переменных
void Game::init_variables() {

	// Окно
	this->window = nullptr;

	// Позиция
	this->x = 0;
	this->y = 0;

}

// Инициализация окна
void Game::init_window() {

	// Размеры окна
	this->video_mode.width = 960;
	this->video_mode.height = 540;

	// Создание окна
	this->window = new RenderWindow(
		this->video_mode,
		"Basis");

    // FPS
    this->window->setFramerateLimit(60);

}

// Инициализация текстур
void Game::init_textures() {

	// Загрузка изображения в текстуру
	if(!this->texture.loadFromFile("assets/one.png"))
		std::cout << "Error" << std::endl;

}

// Инициализация спрайтов
void Game::init_sprites() {

	// Загрузка текстуры в спрайт
	this->sprite.setTexture(this->texture);

}

// Инициализация противника
void Game::init_enemies() {

	// Задать позицию
	this->enemy.setPosition(960 / 2 - 50, 540 / 2 - 50);
	// Задать размер
	this->enemy.setSize(Vector2f(100.f, 100.f));
	// Задать масштаб
	// this->enemy.setScale(Vector2f(0.5f, 0.5f));
	// Задать цвет
	this->enemy.setFillColor(Color(255,255,255,255));
	// Задать цвет обводки
	this->enemy.setOutlineColor(Color(0,0,0,255));
	// Задать размер обводки
	this->enemy.setOutlineThickness(5.f);
}

// Обработка событий
void Game::events() {

	// Получение позиции мыши
	// Vector2i mxy = this->mouse.getPosition(*this->window);
	// std::cout << "Mouse pos: " << mxy.x << " " << mxy.y << std::endl;

    // Отслеживание событий
    while(this->window->pollEvent(this->event)) {

        // Событие закрытия окна
        if(this->event.type == Event::Closed)
            this->window->close();

        // Обработка событий нажатия мыши
    //     if(this->event.type == Event::MouseButtonPressed)
    //     	// Нажатие на левую кнопку мыши
    //     	if(this->event.mouseButton.button == Mouse::Left)
    //     		// Изменение позиции противника
				// this->enemy.setPosition(mxy.x - 50, mxy.y - 50);

    }


}

// Обновление данных
void Game::update() {
	
	// Обновление данных игрока
	this->player.update();

	// Обновление позиции спрайта
	this->sprite.setPosition(this->player.position);

    // Обработка событий
    this->events();

}

// Отрисовка данных
void Game::render() {
	// Очистка заднего фона
	this->window->clear(Color(128, 128, 128, 255));

	// Отрисовка противника
	this->window->draw(this->enemy);
	this->window->draw(this->sprite);

	this->window->display(); // отрисовка
}

// Аксессор
const bool Game::running() const {
	return this->window->isOpen();
}

// Игровой цикл
void Game::game_loop() {

    // Игровой цикл
    while(this->running()) {

        // Обновление данных
        this->update();

        // Отрисовка
        this->render();

    }


}