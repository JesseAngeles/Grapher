#include "../include/grapher.h"

using namespace std;

void printMessage();

int main()
{
    grapher grapher(720, 405, "prueba");
    grapher.drawAxes(-12, -12, 16, 15);

    grapher.drawText("hola mundo", 12, 1, -1, {255, 0, 255}, true);
    grapher.drawText("axzx", 10, 1, 1, {0, 0, 0}, true);
    grapher.drawLine(-4, 3, 4, -12, {0, 0, 0}, true);
    grapher.drawCircle(1, -1, 30, {255, 0, 0}, true);
    grapher.drawRectangle(1, 1, 1, 1, {0, 255, 0}, true);

    Button button({100, 100}, {200, 50}, "Click Me", grapher.getFont(), {0, 0, 255});
    button.setFunction(printMessage);

    grapher.insertButton(button);

    grapher.draw();

    return 0;
}

void printMessage()
{
    cout << "hello world" << endl;
}