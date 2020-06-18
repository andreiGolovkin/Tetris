#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "shape.h"

using namespace sf;
using namespace std;


class controller{
    public:
        shape s;
        Time asideDelay;
        Time downDelay;
        Time rotateDelay;

        controller();

        void update(Time* t);
    protected:

    private:
};

#endif // CONTROLLER_H
