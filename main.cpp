#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <time.h>

#include "field.h"
#include "controller.h"
#include "shape.h"
#include "piece.h"

using namespace std;
using namespace sf;

void asignColors(){
    piece::colors.push_back(LIGHT_BLUE);
    piece::colors.push_back(RED);
    piece::colors.push_back(LIGHT_GREEN);
    piece::colors.push_back(YELLOW);
    piece::colors.push_back(BLUE);
    piece::colors.push_back(ORANGE);
    piece::colors.push_back(PINK);
    piece::colors.push_back(PURPLE);
    piece::colors.push_back(WHITE);
    piece::colors.push_back(BLACK);
    piece::colors.push_back(BROWN);
    piece::colors.push_back(GREEN);
}

int main(){
    RenderWindow window(sf::VideoMode(800, 500), "SFML works!");

    asignColors();

    srand(time(NULL));

    //cout << piece::colors.size() << endl;

    field f;
    controller player;

    Clock clock;


    RectangleShape cell(Vector2f(20.f, 20.f));
    cell.setPosition(500, 20);
    cell.setFillColor(Color(255, 255, 255));

    player.s.reshape();
    //cout << global::pieces.size() << endl;

    while (window.isOpen()){
        //cout << field::m[1][18] << endl;
        Vector2i mouse = sf::Mouse::getPosition(window);

        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }

        Time t = clock.getElapsedTime();
        clock.restart();
        //t = t/800;

        //cout << t.asMilliseconds() << endl;
        player.update(&t);

        window.clear();

        f.draw(&window);
        //p.draw(&window);

        for(int n = 0; n < piece::pieces.size(); n++){
            piece::pieces[n].draw(&window);
        }

        window.draw(cell);
        window.display();
    }
    return 0;
}
