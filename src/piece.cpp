#include "piece.h"

Texture piece::tileset;
vector<piece> piece::pieces;
vector<Vector2i> piece::colors;

piece::piece():
        sprite(), x(0), y(0){
    tileset.loadFromFile(url);

    sprite.setTexture(tileset);
    sprite.setTextureRect(IntRect(ORANGE.x, ORANGE.y, 10, 10));
    sprite.setScale(Vector2f(2, 2));
    sprite.setPosition(field::getX(x), field::getY(y));
}

void piece::draw(RenderWindow* window){
    if(y >= 0){
        sprite.setPosition(field::getX(x), field::getY(y));
        window->draw(sprite);
    }
}

void piece::setColor(Vector2i color){
    sprite.setTextureRect(IntRect(color.x, color.y, 10, 10));
}
