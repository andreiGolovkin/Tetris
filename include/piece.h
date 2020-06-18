#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "field.h"

#include "Colors.h"

using namespace sf;
using namespace std;


class piece{
    public:
        static Texture tileset;
        static vector<piece> pieces;
        static vector<Vector2i> colors;
        Sprite sprite;

        int x;
        int y;

        piece();

        void draw(RenderWindow* window);
        void setColor(Vector2i color);
    protected:

    private:
};

#endif // PIECE_H
