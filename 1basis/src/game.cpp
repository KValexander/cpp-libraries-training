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
	this->init_surfaces(); // инициализиция противника

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

	// Точки линии
	this->line[0][0] = Vertex(Vector2f(0.0f, 0.0f));
	this->line[0][1] = Vertex(Vector2f(960 / 2 - 50, 540 / 2 - 50));

	this->line[1][0] = Vertex(Vector2f(960, 0));
	this->line[1][1] = Vertex(Vector2f(960 / 2 + 50, 540 / 2 - 50));

	this->line[2][0] = Vertex(Vector2f(0, 540));
	this->line[2][1] = Vertex(Vector2f(960 / 2 - 50, 540 / 2 + 50));

	this->line[3][0] = Vertex(Vector2f(960, 540));
	this->line[3][1] = Vertex(Vector2f(960 / 2 + 50, 540 / 2 + 50));

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

// Инициализация поверхностей
void Game::init_surfaces() {

	// Задать позицию
	this->surface.setPosition(0, 500);
	// Задать размер
	this->surface.setSize(Vector2f(960.f, 40.f));
	// Задать масштаб
	// this->surface.setScale(Vector2f(0.5f, 0.5f));
	// Задать цвет
	this->surface.setFillColor(Color(255,255,255,255));
	// Задать цвет обводки
	// this->surface.setOutlineColor(Color(0,0,0,255));
	// Задать размер обводки
	// this->surface.setOutlineThickness(5.f);
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

// Проверка пересечения прямоугольников
int Game::collision_rectangle(float x1, float y1, float x2, float y2, float w1, float h1, float w2, float h2) {
    return (!((x1 > (x2+w2)) || (x2 > (x1+w1)) || (y1 > (y2+h2)) || (y2 > (y1+h1))));
}

// Коллизии
void Game::collision() {

	Vector2f player_pos = this->player.get_position();
	Vector2u player_size = this->texture.getSize();

	Vector2f surface_pos = this->surface.getPosition();
	Vector2f surface_size = this->surface.getSize();

	if(this->collision_rectangle(
		player_pos.x,
		player_pos.y,
		surface_pos.x,
		surface_pos.y,
		player_size.x,
		player_size.y,
		surface_size.x,
		surface_size.y
	)) this->player.stop_falling();

	// player_pos.x > (surface_pos.x + surface_size.x)
	// surface_pos.x > (player_pos.x + player_size.x)

	// player_pos.y > (surface_pos.y + surface_size.y)
	// surface_pos.y > (player_pos.y + player_size.y)
	
}

// Обновление данных
void Game::update() {

    // Обработка событий
    this->events();

    // Коллизии
    this->collision();

	// Обновление данных игрока
	this->player.update();

	// Обновление позиции спрайта
	this->sprite.setPosition(this->player.get_position());
	
	// Гравитация игрока
	this->player.increase_dy(GRAVITY);
}

// Отрисовка данных
void Game::render() {
	// Очистка заднего фона
	this->window->clear(Color(128, 128, 128, 255));

	// Отрисовка линии
	for(int i = 0; i < 4; i++)
		this->window->draw(this->line[i], 5, Lines);

	// Отрисовка противника
	this->window->draw(this->enemy);

	// Отрисовка игрока
	this->window->draw(this->sprite);

	// Отрисовка поверхностей
	this->window->draw(this->surface);

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