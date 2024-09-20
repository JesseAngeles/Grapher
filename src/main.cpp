#include "../include/grapher.h"

using namespace std;

int main()
{
    grapher grapher(600, 600, "prueba");
    //TODO corregir error de escalado
    grapher.drawAxes(-12, -12, 16, 15);

    grapher.drawText("hola mundo", 12, 1, -1, {255, 0, 255}, true);
    grapher.drawText("axzx", 10, 1, 1, {0, 0, 0}, true);
    grapher.drawLine(-4, 3, 4, -12, {0, 0, 0}, true);
    grapher.drawCircle(1, -1, 30, {255, 0, 0}, true);
    grapher.drawRectangle(1, 1, 1, 1, {0, 255, 0}, true);
    grapher.draw();

    cout << "Hola mundo";

    return 0;
}
