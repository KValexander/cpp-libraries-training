#include <SFML/Graphics.hpp>

// using namespace std;

using namespace sf;

extern void init(Window *window);
extern void events(Window *window);
extern void update(Window *window);
extern void render(Window *window);
extern void game_loop(Window *window);

// Инициализация
void init(Window *window) {

    // Создание окна
    window->create(
        VideoMode(960, 540), // разрешение окна
        "Basis" // титулник
    );

    // FPS
    window->setFramerateLimit(60);

}

// Отслеживание событий
void events(Window *window) {

    // Отслеживание событий
    Event event; // событие
    while(window->pollEvent(event)) {

        // Событие закрытия окна
        if(event.type == Event::Closed)
            window->close();

    }

}

// Обновление данных
void update(Window *window) {

}

// Отрисовка данных
void render(Window *window) {

    window->display(); // конец отрисовки
}

// Игровой цикл
void game_loop(Window *window) {

    // Игровой цикл
    while(window->isOpen()) {

        // Отслеживание событий
        events(window);

        // Обновление данных
        update(window);

        // Отрисовка
        render(window);

    }

}

// Старт
int main()
{

    Window window;

    // Инициализация
    init(&window);

    // Игровой цикл
    game_loop(&window);

    return 0;
}