#include "grapher.h"

grapher::grapher(int width, int height, std::string name, Color background)
    : width(width), height(height), name(name), window(VideoMode(width, height), name), background(background)
{
    if (!this->font.loadFromFile("resources/fonts/Roboto-Medium.ttf"))
    {
        std::cout << "Error loading font";
        return;
    }
}

// Dibujar los ejes
void grapher::drawAxes(float xMin, float yMin, float xMax, float yMax)
{
    this->xMin = floor(xMin);
    this->yMin = floor(yMin);
    this->xMax = ceil(xMax);
    this->yMax = ceil(yMax);

    xScale = static_cast<float>(this->width) / static_cast<float>(this->xMax - this->xMin);
    yScale = static_cast<float>(this->height) / static_cast<float>(this->yMax - this->yMin);

    VertexArray xAxis(Lines, 2);
    VertexArray yAxis(Lines, 2);
    for (float x = 0, i = this->xMin; i < this->xMax; i++, x += xScale)
    {
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(x, 0);
        line[1].position = Vector2f(x, height);
        line[0].color = line[1].color = Color(50, 50, 50);

        if (i == 0)
        {
            line[0].color = line[1].color = Color(0, 0, 0);
            xAxis = line;
            continue;
        }

        line[0].color = line[1].color = Color(200, 200, 200);
        this->axes.push_back(line);
    }

    for (float y = 0, i = this->yMax; i > this->yMin; i--, y += yScale)
    {
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(0, y);
        line[1].position = Vector2f(width, y);

        if (i == 0)
        {
            line[0].color = line[1].color = Color(0, 0, 0);
            yAxis = line;
            continue;
        }
        line[0].color = line[1].color = Color(200, 200, 200);
        this->axes.push_back(line);
    }

    if (xAxis.getVertexCount() > 0)
        this->axes.push_back(xAxis);

    if (yAxis.getVertexCount() > 0)
        this->axes.push_back(yAxis);
}

// Dibujar texto
void grapher::drawText(std::string content, int fontSize, float x, float y, Color color, bool isScaled)
{
    if (isScaled)
        scale(x, y);

    Text text;
    text.setFont(this->font);
    text.setString(content);
    text.setCharacterSize(fontSize);
    text.setFillColor(color);
    text.setPosition(x, y);

    this->texts.push_back(text);
}

void grapher::drawLine(float x1, float y1, float x2, float y2, Color color, bool isScaled)
{
    if (isScaled)
    {
        scale(x1, y1);
        scale(x2, y2);
    }

    VertexArray line(Lines, 2);

    line[0].position = Vector2f(x1, y1);
    line[1].position = Vector2f(x2, y2);

    line[0].color = line[1].color = color;

    this->lines.push_back(line);
}

void grapher::scale(float &x, float &y)
{
    x = (x - this->xMin) * xScale;
    y = (this->yMax - y) * yScale;
}

void ::grapher::drawCircle(float x, float y, float radius, Color color, bool isScaled)
{
    if (isScaled)
        scale(x, y);
    CircleShape circle(radius);
    circle.setPosition(x - radius, y - radius);
    circle.setFillColor(color);

    this->circles.push_back(circle);
}

void grapher::drawRectangle(float width, float height, float x, float y, Color color, bool isScaled)
{
    if (isScaled)
    {
        scale(x, y);
        width *= this->xScale;
        height *= this->yScale;
    }

    RectangleShape rectangle(Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setOutlineThickness(0);
    rectangle.setFillColor(color);

    this->rectangles.push_back(rectangle);
}

void grapher::draw()
{

    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            // Manejar el clic del botón
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
                // Probar clic del boton
                if(!buttons.empty())
                    for (Button &button : buttons)
                        button.actionlistener(mousePos);
            }
        }


        window.clear(background);

        // Dibujar elementos estaticos
        if (!axes.empty())
            for (const VertexArray &axis : axes)
                window.draw(axis);

        if (!texts.empty())
            for (const Text &text : texts)
                window.draw(text);

        if (!lines.empty())
            for (const VertexArray &line : lines)
                window.draw(line);

        if (!circles.empty())
            for (const CircleShape &circle : circles)
                window.draw(circle);

        if (!rectangles.empty())
            for (const RectangleShape &rectangle : rectangles)
                window.draw(rectangle);

        if(!buttons.empty())
            for (Button &button : buttons)
                button.draw(window);
            
        window.display();
    }
}