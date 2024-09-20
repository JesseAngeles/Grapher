#include "../include/grapher.h"

using namespace std;

int main()
{
    grapher grapher(600, 600, "prueba");
    //TODO corregir error de escalado
    grapher.drawAxes(-5, -3, 2, 1);

    grapher.drawText("hola mundo", 12, 1, -1, {255, 0, 255}, true);
    grapher.drawText("axzx", 10, 1, 1, {0, 0, 0}, true);
    grapher.drawLine(0, 0, 100, 200, {0, 255, 255}, false);
    grapher.drawLine(0, 0, 4, 4, {0, 0, 0}, true);
    grapher.draw();

    cout << "Hola mundo";

    return 0;
}
