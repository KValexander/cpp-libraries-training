#include "game.hpp"
	
// Конструктор
Game::Game() {

	// Инициализация
	this->init_variables();
	this->init_window();

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

// Обработка событий
void Game::events() {

    // Отслеживание событий
    while(this->window->pollEvent(this->event)) {

        // Событие закрытия окна
        if(this->event.type == Event::Closed)
            this->window->close();

    }

}

// Обновление данных
void Game::update() {

    // Обработка событий
    this->events();

}

// Отрисовка данных
void Game::render() {


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