#include "controller.h"

controller::controller():
        s(), asideDelay(milliseconds(0)), downDelay(milliseconds(0)), rotateDelay(milliseconds(0)){

}

void controller::update(Time* t){
    if(!(Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Left))){
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(asideDelay.asMilliseconds() <= 0 && s.x + s.w < fParam::width && !s.isTouching(0, 1)) {
                s.moveRight();
                asideDelay = milliseconds(300);
            }
            else{
                asideDelay = milliseconds(asideDelay.asMilliseconds() - t->asMilliseconds());
            }
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)){
            //cout << s.x << endl;
            if(asideDelay.asMilliseconds() <= 0 && s.x > 0 && !s.isTouching(0, -1)) {

                s.moveLeft();
                asideDelay = milliseconds(300);
            }
            else{
                asideDelay = milliseconds(asideDelay.asMilliseconds() - t->asMilliseconds());
            }
        }
        else{
            asideDelay = milliseconds(0);
        }
    }

    if(Keyboard::isKeyPressed(Keyboard::Space)){
        if(rotateDelay.asMilliseconds() <= 0) {
            s.rotate();
            rotateDelay = milliseconds(300);
        }
        else{
            rotateDelay = milliseconds(rotateDelay.asMilliseconds() - t->asMilliseconds());
        }
    }
    else{
        rotateDelay = milliseconds(0);
    }

    /*if(Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Left)){
        s.setColor(RED);
    }
    else{
        s.setColor(ORANGE);
    }*/

    int downDelayContent = 600;
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        downDelayContent = 50;

        if(downDelay.asMilliseconds() > 50) downDelay = milliseconds(downDelayContent);
    }

    bool isTouching = s.isTouching(1, 0);

    if(downDelay.asMilliseconds() <= 0 && s.y + s.h < fParam::height && !isTouching) {
        s.moveDown();
        downDelay = milliseconds(downDelayContent);
    }
    else if(s.y + s.h >= fParam::height || isTouching){
        s.reshape();
    }
    else{
        downDelay = milliseconds(downDelay.asMilliseconds() - t->asMilliseconds());
    }
}
