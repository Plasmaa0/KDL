#include <iostream>

#include "Keyboard.h"
#include "Display.h"

int main() {
    Keyboard::instance(); // Конструктор OK, Деструктор ERROR
    Display::instance(); // ошибка в конструкторе
    std::cout << "\t\tEND OF PROGRAM" << std::endl;
    return 0;
}
