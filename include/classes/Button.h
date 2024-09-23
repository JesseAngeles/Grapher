#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Button
{
public:
    Button() = default;
    Button(Vector2f position, Vector2f size, const std::string content, Font, Color color);
    void draw(RenderWindow &window);
    void setFunction(void (*action)()) { this->action = action; }

    void actionlistener(Vector2i pos);

private:
    RectangleShape shape;
    Text text;

    void (*action)() = nullptr;
};

#endif // BUTTON_H