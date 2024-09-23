#include "./Button.h"
#include "Button.h"

Button::Button(Vector2f position, Vector2f size, const std::string content, Font fontS, Color color)
{
    shape.setPosition(position); // Posición del botón
    shape.setSize(size);         // Tamaño del botón
    shape.setFillColor(color);   // Color de fondo del botón

    Font font;
    if (font.loadFromFile("./resources/fonts/Roboto-Medium.ttf"))
    {
        std::cout << "Error loading font";
        return;
    }

    // Configuración del texto
    text.setFont(font);        // Asignar fuente
    text.setString(content);   // Asignar el contenido del texto
    text.setCharacterSize(24); // Tamaño del texto

    // Centrar el texto dentro del botón
    FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                   textBounds.top + textBounds.height / 2.0f);
    text.setPosition(
        position.x + size.x / 2.0f, // Centrar en el botón en X
        position.y + size.y / 2.0f  // Centrar en el botón en Y
    );
}

void Button::draw(RenderWindow &window)
{
    window.draw(shape);
    window.draw(text);
}

void Button::actionlistener(Vector2i pos)
{
    bool isClicked = shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos));
    if (action != nullptr && isClicked)
        action();
}