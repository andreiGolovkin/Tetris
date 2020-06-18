#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "FieldParam.h"


using namespace sf;
using namespace std;


class field{
    public:
        static vector< vector<int> > m;
        RectangleShape cell;

        field();

        void draw(RenderWindow* window);

        static double getX(int x);
        static double getY(int y);
    protected:

    private:
};

#endif // FIELD_H
