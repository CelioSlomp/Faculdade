#include <iostream>

class FigGeo
{
    // Classe pai para figuras geometricas (qualquer coisa que está no plano)
public:
    void setterX(int nX);
    void setterY(int nY);
    int getterX();
    int getterY();

protected:
    int x;
    int y;
};