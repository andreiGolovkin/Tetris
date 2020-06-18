#include "shape.h"

/*
0 =      1
        12
         1

1 =     1211

2 =     121
          1

3 =     11
        11

4 =     22       1
         11     22
                1
*/

vector< vector< vector<Vector2i> > > shape::type_state_list;

shape::shape():
        offsetY(0), offsetX(0), x(0), y(0), w(0), h(0), type(0), state(1), pieces(){

    srand(time(NULL));






    vector< vector<Vector2i> > shape1;

    vector<Vector2i> state1;
    vector<Vector2i> state2;
    vector<Vector2i> state3;
    vector<Vector2i> state4;

    state1.push_back(Vector2i(0, 0));
    state1.push_back(Vector2i(-1, 0));
    state1.push_back(Vector2i(0, 1));
    state1.push_back(Vector2i(1, 0));

    state2.push_back(Vector2i(0, 0));
    state2.push_back(Vector2i(0, -1));
    state2.push_back(Vector2i(-1, 0));
    state2.push_back(Vector2i(0, 1));

    state3.push_back(Vector2i(0, 0));
    state3.push_back(Vector2i(0, -1));
    state3.push_back(Vector2i(-1, 0));
    state3.push_back(Vector2i(1, 0));

    state4.push_back(Vector2i(0, 0));
    state4.push_back(Vector2i(0, -1));
    state4.push_back(Vector2i(0, 1));
    state4.push_back(Vector2i(1, 0));

    shape1.push_back(state1);
    shape1.push_back(state2);
    shape1.push_back(state3);
    shape1.push_back(state4);

    state1.clear();
    state1.shrink_to_fit();
    state2.clear();
    state2.shrink_to_fit();
    state3.clear();
    state3.shrink_to_fit();
    state4.clear();
    state4.shrink_to_fit();






    vector< vector<Vector2i> > shape2;

    state1.push_back(Vector2i(0, 0));
    state1.push_back(Vector2i(-1, 0));
    state1.push_back(Vector2i(1, 0));
    state1.push_back(Vector2i(2, 0));

    state2.push_back(Vector2i(0, 0));
    state2.push_back(Vector2i(0, -1));
    state2.push_back(Vector2i(0, 1));
    state2.push_back(Vector2i(0, 2));

    shape2.push_back(state1);
    shape2.push_back(state2);

    state1.clear();
    state1.shrink_to_fit();
    state2.clear();
    state2.shrink_to_fit();






    vector< vector<Vector2i> > shape3;

    state1.push_back(Vector2i(0, 0));
    state1.push_back(Vector2i(-1, 0));
    state1.push_back(Vector2i(1, 0));
    state1.push_back(Vector2i(1, 1));

    state2.push_back(Vector2i(0, 0));
    state2.push_back(Vector2i(0, -1));
    state2.push_back(Vector2i(0, 1));
    state2.push_back(Vector2i(-1, 1));

    state3.push_back(Vector2i(0, 0));
    state3.push_back(Vector2i(-1, 0));
    state3.push_back(Vector2i(-1, -1));
    state3.push_back(Vector2i(1, 0));

    state4.push_back(Vector2i(0, 0));
    state4.push_back(Vector2i(0, 1));
    state4.push_back(Vector2i(0, -1));
    state4.push_back(Vector2i(1, -1));

    shape3.push_back(state1);
    shape3.push_back(state2);
    shape3.push_back(state3);
    shape3.push_back(state4);

    state1.clear();
    state1.shrink_to_fit();


    vector< vector<Vector2i> > shape4;

    state1.push_back(Vector2i(0, 0));
    state1.push_back(Vector2i(1, 1));
    state1.push_back(Vector2i(1, 0));
    state1.push_back(Vector2i(0, 1));

    shape4.push_back(state1);

    state1.clear();
    state1.shrink_to_fit();

    state2.clear();
    state2.shrink_to_fit();


    vector< vector<Vector2i> > shape5;

    state1.push_back(Vector2i(0, 0));
    state1.push_back(Vector2i(1, 0));
    state1.push_back(Vector2i(1, 1));
    state1.push_back(Vector2i(2, 1));

    state2.push_back(Vector2i(0, 0));
    state2.push_back(Vector2i(1, 0));
    state2.push_back(Vector2i(1, -1));
    state2.push_back(Vector2i(0, 1));

    shape5.push_back(state1);
    shape5.push_back(state2);



    type_state_list.push_back(shape1);
    type_state_list.push_back(shape2);
    type_state_list.push_back(shape3);
    type_state_list.push_back(shape4);
    type_state_list.push_back(shape5);
}

bool compare(piece& p1, piece& p2){
    return p1.y > p2.y;
}

struct element{
	int key;
	element(int const &i): key(i) { }

	bool operator()(piece const &p){
		return (p.y == key);
	}
};

void shape::reshape(){
    state = 0;
    type = rand() % type_state_list.size();

    for(piece* n : pieces){
        field::m[n->x][n->y] = 1;
    }

    pieces.clear();
    pieces.shrink_to_fit();

    sort(piece::pieces.begin(), piece::pieces.end(), compare);

    /*for(int n = 0;n < piece::pieces.size(); n++){
        cout << piece::pieces[n].y << " ";
    }
    cout << endl;*/

    for(int y = 0; y < field::m[0].size(); y++){
        bool full = true;
        for(int x = 0; x < field::m.size(); x++){
            if(field::m[x][y] == 0){
                full = false;
                break;
            }
        }

        //cout << full << endl;

        if(full){
            for(int x = 0; x < field::m.size(); x++){
                field::m[x][y] = y - 1 < 0 ? 0 : field::m[x][y - 1];
            }

            for(int yy = y - 1; yy > 0; yy--){
                for(int xx = 0; xx < field::m.size(); xx++){
                    field::m[xx][yy] = yy - 1 < 0 ? 0 : field::m[xx][yy - 1];
                }
            }

            int mid = distance(piece::pieces.begin(), find_if(piece::pieces.begin(), piece::pieces.end(), element(y)));
            int start = mid;
            int finish = mid;

            while(start > 0 && piece::pieces[start - 1].y == y) start--;
            while(finish < piece::pieces.size() - 1 && piece::pieces[finish + 1].y == y) finish++;

            //cout << start - 1 << endl;

            for(int n = finish + 1; n < piece::pieces.size(); n++){
                //cout << piece::pieces[n].y << endl;
                piece::pieces[n].y++;
            }

            piece::pieces.erase(piece::pieces.begin() + start, piece::pieces.begin() + finish + 1);
        }
        //cout << piece::pieces.size() << endl;
    }

    //cout << endl;

    x = 5;
    y = -5;

    x += offsetX;
    y += offsetY;

    w = 0;
    h = 0;

    offsetX = 0;
    offsetY = 0;

    //cout << "asd" << endl;

    for(int n = 0; n < type_state_list[type][state].size(); n++){
        piece::pieces.push_back(piece());
    }

    for(int n = 0; n < type_state_list[type][state].size(); n++){
        pieces.push_back(&piece::pieces[piece::pieces.size()-1 - n]);

        pieces[pieces.size() - 1]->x = type_state_list[type][state][n].x;
        pieces[pieces.size() - 1]->y = type_state_list[type][state][n].y;

        if(type_state_list[type][state][n].x < offsetX) offsetX = type_state_list[type][state][n].x;
        if(type_state_list[type][state][n].y < offsetY) offsetY = type_state_list[type][state][n].y;

        if(type_state_list[type][state][n].y + 1 > h) h = type_state_list[type][state][n].y + 1;
        if(type_state_list[type][state][n].x + 1 > w) w = type_state_list[type][state][n].x + 1;
    }

    offsetX = abs(offsetX);
    offsetY = abs(offsetY);

    w += offsetX;
    h += offsetY;

    for(piece* n : pieces){
        n->x += x;
        n->y += y;
    }

    x -= offsetX;
    y -= offsetY;


    while(y + h != 0) moveDown();


    int index = rand() % piece::colors.size();
    //cout << index;
    Vector2i c = piece::colors[index];

    //cout << "    " << c.x << "  " << c.y << endl;

    setColor(c);

    //cout << x << "  " << y << endl;
}

void shape::rotate(){
    bool willTouch = false;

    int sampleX = x + offsetX;
    int sampleY = y + offsetY;

    int prevState = state;
    state++;
    if(state > type_state_list[type].size() - 1) state = 0;

    for(int n = 0; n < type_state_list[type][state].size(); n++){
        while(sampleX + type_state_list[type][state][n].x < 0){
            sampleX++;
        }
        while(sampleX + type_state_list[type][state][n].x > fParam::width - 1){
            sampleX--;
        }
        while(sampleY + type_state_list[type][state][n].y < 0){
            sampleY++;
        }
        while(sampleY + type_state_list[type][state][n].y > fParam::height - 1){
            sampleY--;
        }
    }

    for(int n = 0; n < type_state_list[type][state].size(); n++){
        if(field::m[sampleX + type_state_list[type][state][n].x][sampleY + type_state_list[type][state][n].y] == 1){
            willTouch = true;
            break;
        }
    }

    if(!willTouch){
        x += offsetX;
        y += offsetY;

        w = 0;
        h = 0;

        offsetX = 0;
        offsetY = 0;

        for(int n = 0; n < type_state_list[type][state].size(); n++){
            pieces[n]->x = type_state_list[type][state][n].x;
            pieces[n]->y = type_state_list[type][state][n].y;

            if(type_state_list[type][state][n].x < offsetX) offsetX = type_state_list[type][state][n].x;
            if(type_state_list[type][state][n].y < offsetY) offsetY = type_state_list[type][state][n].y;

            if(type_state_list[type][state][n].y + 1 > h) h = type_state_list[type][state][n].y + 1;
            if(type_state_list[type][state][n].x + 1 > w) w = type_state_list[type][state][n].x + 1;
        }

        offsetX = abs(offsetX);
        offsetY = abs(offsetY);

        w += offsetX;
        h += offsetY;

        for(piece* n : pieces){
            n->x += x;
            n->y += y;
        }

        x -= offsetX;
        y -= offsetY;

        while(x < 0) moveRight();
        while(x + w > fParam::width) moveLeft();
        while(y < 0) moveDown();
        while(y + h > fParam::height) moveUp();
    }
    else state = prevState;
}

void shape::moveLeft(){
    x--;

    for(piece* n : pieces){
        n->x--;
    }
}

void shape::moveRight(){
    x++;

    for(piece* n : pieces){
        n->x++;
    }
}

void shape::moveUp(){
    y--;

    for(piece* n : pieces){
        n->y--;
    }
}

void shape::moveDown(){
    y++;

    for(piece* n : pieces){
        n->y++;
    }
}

void shape::setColor(Vector2i color){
    for(piece* n : pieces){
        n->setColor(color);
    }
}

bool shape::isTouching(int vertical, int horizontal){
    bool ans = false;

    for(piece* n : pieces){
        if(field::m.size() > n->x + horizontal >= 0 && field::m[0].size() > n->y + vertical >= 0 && field::m[n->x + horizontal][n->y + vertical] == 1) {
            ans = true;
            break;
        }
    }

    return ans;
}
