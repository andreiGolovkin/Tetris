#include "field.h"

vector< vector<int> > field::m;

field::field():
        cell(Vector2f(20.f, 20.f)){
    cell.setFillColor(Color(20, 20, 20));
    for(int x = 0; x < fParam::width; x++){
        vector<int> col;
        for(int y = 0; y < fParam::height; y++){
            col.push_back(0);
        }
        m.push_back(col);
    }
}

void field::draw(RenderWindow* window){
    for(int x = 0; x < m.size(); x++){
        for(int y = 0; y < m[x].size(); y++){
            if(m[x][y] == 0){
                cell.setPosition(getX(x), getY(y));
                window->draw(cell);
            }
        }
    }
}

double field::getX(int _x){
    return fParam::x + ((20 + fParam::gap) * _x);
}

double field::getY(int _y){
    return fParam::y + ((20 + fParam::gap) * _y);
}
