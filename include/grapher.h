#ifndef GRAPHER_H
#define GRAPHER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace sf;

class grapher
{
public:
    grapher(int, int, std::string, Color background = {255, 255, 255});
    void drawAxes(float xMin, float yMin, float xMax, float yMax);

    void drawText(std::string content, int fontSize, float x, float y, Color color, bool isScaled);
    void drawLine(float x1, float y1, float x2, float y2, Color color, bool isScaled);
    void drawCircle(float x, float y, float radius, Color color, bool isScaled);
    void drawRectangle(float width, float height, float x, float y, Color color, bool isScaled);
    void draw();

private:
    // Atributes
    int width;
    int height;
    std::string name;
    Color background;
    RenderWindow window;

    // Background
    Texture backgroundTexture;
    Sprite backgroundSprite;

    // Limites
    float xMin, yMin, xMax, yMax;

    // Escala
    float xScale, yScale;

    // Texto
    Font font;
    std::vector<Text> texts;

    // Lineas
    std::vector<VertexArray> axes;
    std::vector<VertexArray> lines;

    // Circulos
    std::vector<CircleShape> circles;

    // Rectangulos
    std::vector<RectangleShape> rectangles;

    // Funciones
    void scale(float &x, float &y); // Escala el texto: factor de escala y rotacion del eje y

};

#endif // GRAPHER_H