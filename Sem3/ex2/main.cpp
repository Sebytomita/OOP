#include "Canvas.h"
#include <iostream>

int main() {
    // Crearea unui canvas de dimensiuni 25x15
    Canvas canvas(25, 15);

    // Desenarea unei linii orizontale
    canvas.DrawLine(2, 2, 22, 2, '*');

    // Desenarea unei linii verticale
    canvas.DrawLine(2, 2, 2, 12, '*');

    // Desenarea unei linii orizontale
    canvas.DrawLine(22, 2, 22, 12, '*');

    // Desenarea unei linii verticale
    canvas.DrawLine(2, 12, 22, 12, '*');

    // Desenarea unui cerc
    canvas.DrawCircle(13, 7, 4, '2');

    // Umplerea unui cerc
    canvas.FillCircle(18, 5, 3, '3');

    // Desenarea unui dreptunghi
    canvas.DrawRect(5, 4, 18, 9, '0');

    // Umplerea unui dreptunghi
    canvas.FillRect(7, 5, 16, 8, '1');

    // Afișarea canvasului
    canvas.Print();

    return 0;
}
