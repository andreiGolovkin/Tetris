#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <time.h>

#include "piece.h"

using namespace sf;
using namespace std;


class shape
{
    public:
        int type;
        int state;

        static vector< vector< vector<Vector2i> > > type_state_list;
        vector<piece*> pieces;

        int x;
        int y;
        int w;
        int h;

        int offsetX;
        int offsetY;

        shape();

        void reshape();
        void rotate();
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();

        void setColor(Vector2i color);

        bool isTouching(int vertical, int horizontal);

    protected:

    private:
};

#endif // SHAPE_H
