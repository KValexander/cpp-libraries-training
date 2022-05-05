#include <iostream>
#include <ctime>
#include <cstdlib>

#include "game.hpp"
	
// Конструктор
Game::Game() {

	// Инициализаия генератора рандомных чисел
	srand(time(NULL));

	// Инициализация
	this->init_variables(); // инициализиция переменных
	this->init_window(); // инициализиция окна
	this->init_view(); // инициализиция области отрисовки
	this->init_textures(); // инициализиция текстур
	this->init_sprites(); // инициализиция спрайтов
	this->init_enemies(); // инициализиция противника
	this->init_surfaces(); // инициализиция поверхностей

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

// Инициализация области отрисовки
void Game::init_view() {

	// Данные отрисовки
	view.setCenter(Vector2f(this->video_mode.width / 2, this->video_mode.height / 2));
	view.setSize(Vector2f(this->video_mode.width, this->video_mode.height));

}

// Инициализация текстур
void Game::init_textures() {

	// Загрузка изображения в текстуру
	if(!this->texture.loadFromFile("assets/player.png"))
		std::cout << "Error" << std::endl;

}

// Инициализация спрайтов
void Game::init_sprites() {

	// Загрузка текстуры в спрайт
	this->sprite.setTexture(this->texture);

	// Точка основы
	this->sprite.setOrigin(32, 0);

}

// Инициализация противников
void Game::init_enemies() {

	// Противники
	for(int i = 0; i < NUM_ENEMIES; i++) {
		// Размер
		this->enemies[i].setSize(Vector2f(64.f, 64.f));
		// Цвет
		this->enemies[i].setFillColor(Color(128,64,64,255));

		// Позиция
		this->enemies[i].setPosition(
			this->video_mode.width / 2 + rand() % LENGTH,
			rand() % this->video_mode.height
		);
	}

	// Задать позицию
	// this->enemy.setPosition(960 / 2 - 50, 540 / 2 - 50);
	// Задать размер
	// this->enemy.setSize(Vector2f(100.f, 100.f));
	// Задать масштаб
	// this->enemy.setScale(Vector2f(0.5f, 0.5f));
	// Задать цвет
	// this->enemy.setFillColor(Color(255,255,255,255));
	// Задать цвет обводки
	// this->enemy.setOutlineColor(Color(0,0,0,255));
	// Задать размер обводки
	// this->enemy.setOutlineThickness(5.f);
}

// Инициализация поверхностей
void Game::init_surfaces() {

	// Инициализация поверхностей
	for(int i = 0; i < NUM_SURFACES; i++) {
		// Позиция поверхности
		this->surfaces[i].setPosition(
			i*384, // x
			300 + 100 - rand() % 200 // y
		);
		// Размер поверхности
		this->surfaces[i].setSize(Vector2f(256.f, 64.f));
		// Цвет поверхности
		this->surfaces[i].setFillColor(Color(255,255,255,255));
	}
	
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
bool Game::collision_rectangle(float x1, float y1, float x2, float y2, float w1, float h1, float w2, float h2) {
    return (!((x1 > (x2+w2)) || (x2 > (x1+w1)) || (y1 > (y2+h2)) || (y2 > (y1+h1))));
}

// Проверка коллизий объектов
bool Game::object_collision(Player player, RectangleShape object) {

	Vector2f player_pos = player.get_position();
	Vector2f player_size = player.get_size();

	Vector2f object_pos = object.getPosition();
	Vector2f object_size = object.getSize();

	if(this->collision_rectangle(
		player_pos.x - 32,
		player_pos.y,
		object_pos.x,
		object_pos.y,
		player_size.x,
		player_size.y,
		object_size.x,
		object_size.y
	)) return true;

	return false;
}

// Коллизии
void Game::collision() {

	// Коллизии противников
	for(int i = 0; i < NUM_ENEMIES; i++)
		if(this->object_collision(this->player, this->enemies[i]))
			this->player.die();

	// Коллизии поверхностей
	for(int i = 0; i < NUM_SURFACES; i++)
		if(this->object_collision(this->player, this->surfaces[i]))
			this->player.stop_falling(this->surfaces[i].getPosition().y);
	
}

// Обновление камеры
void Game::update_view(Vector2f position) {

	// Корректирование позиции
	position.x += 64 / 2 - 32;
	position.y += 64 / 2;

	// Проверка позиции области отрисовки
	if(position.x < this->video_mode.width / 2)  position.x = this->video_mode.width / 2;
	if(position.y > this->video_mode.height / 2)  position.y = this->video_mode.height / 2;

	// Передвижение области отрисовки
	this->view.setCenter(position);

    // Обновление области отрисовки
    this->window->setView(this->view);

}

// Обновление данных
void Game::update() {
	this->frame++; // увеличение времени

    // Обработка событий
    this->events();

	// Обновление данных игрока
	this->player.update(this->frame);

	// Обновление позиции спрайта
	this->sprite.setScale(this->player.get_scale());
	this->sprite.setTextureRect(this->player.get_frame_rect());
	this->sprite.setPosition(this->player.get_position());
	
	// Гравитация игрока
	this->player.increase_dy(GRAVITY);

	// Обновление области отрисовки
	this->update_view(this->player.get_position());

    // Коллизии
    this->collision();
}

// Отрисовка данных
void Game::render() {
	// Очистка заднего фона
	this->window->clear(Color(128, 128, 128, 255));

	// Отрисовка игрока
	this->window->draw(this->sprite);

	// Отрисовка противника
	for(int i = 0; i < NUM_ENEMIES; i++)
		this->window->draw(this->enemies[i]);

	// Отрисовка поверхностей
	for(int i = 0; i < NUM_SURFACES; i++)
		this->window->draw(this->surfaces[i]);

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