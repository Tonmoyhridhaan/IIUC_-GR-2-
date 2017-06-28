#include <bits//stdc++.h>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailX[100], tailY[100], ntail = 1;
enum direction {stop = 0, LEFT, RIGHT, UP, DOWN};
int level;
direction dir;
void fruit () { //get fruit randomly
    fruitx = rand() %width;
    fruity = rand() %height;
    if (fruitx == 0 || fruity == 0) fruit();
    for (int i = 0; i <= ntail; i++) {
        if (fruitx == tailX[i] && fruity == tailY[i]) {
            fruit();
        }
    }
}
void setup () {
    printf ("...1 for easy level\n...2 for medium level\n...3 for hard level\n");
    printf ("...[User Manual]\n...Press 'w' to move snake up\n");
    printf ("...Press 's' to move snake down\n");
    printf ("...Press 'a' to move snake left\n");
    printf ("...Press 'd' to move snake right\n");
    printf ("...Press 'g' to pause the game\n");
    printf ("...Press 'x' to stop the game\n");
    switch (_getch ()) { //set level
    case '1':
        level = 100;
        break;
    case '2':
        level = 10;
        break;
    case '3':
        level = 1;
        break;
    default:
        level = 1;
        break;
    }
    gameOver = false;
    dir = stop;
    x = width / 2; //starting position
    y = height / 2;
    fruit ();
    score  = 0;
}
void draw () {
    system ("cls");
    for (int i = 0; i < width; i++) cout << "#"; cout << "\n"; //wall
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width-1) cout << "#";
            else if (i == y && j == x) cout << "O"; //snake head
            else if (i == fruity && j == fruitx) cout << "F"; //fruit
            else {
                bool test = 1;
                for (int k = 1; k <= ntail; k++) {      //snake tail
                    if (i == tailY[k] && j == tailX[k]) {
                        cout << "o";
                        test = 0;
                    }
                }
                if (test) cout << " ";
            }
        }
        cout << "\n";
    }
    for (int i = 0; i < width; i++) cout << "#"; cout << "\n\n"; //wall
    cout << "Score: " << score << "\n";
}
void input () {
    if (_kbhit()) {   //key board input
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'g':
            system ("pause");
            break;
        default:
            break;
        }
    }
}
void logic () {
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case stop:
        break;
    default:
        break;
    }
//    if (x < 0 || x >= width || y < 0 || y > height) {
//        gameOver = true; //boundary touch means gameOver
//        return;
//    }
    //Boundary touch means no gameOver :D
    if (x >= width-1) x = 1; else if (x <= 0) x = width-2;
    if (y >= height) y = 0; else if (y < 0) y = height-1;
    for (int i = 1; i < ntail; i++) { //snake touch its tail
        if (x == tailX[i] && y == tailY[i]) {
            gameOver = true; //snake kill itself
            return;
        }
    }
    tailX[0] = x;
    tailY[0] = y;
    int pX = tailX[0], pY = tailY[0];
    int p2X, p2Y;
    for (int i = 1; i <= ntail; i++) {//snake move with tail
        p2X = tailX[i];
        p2Y = tailY[i];
        tailX[i] = pX;
        tailY[i] = pY;
        pX = p2X;
        pY = p2Y;
    }
    if (x == fruitx && y == fruity) {
        score += 10;
        fruit ();
        ntail++;
    }
}
void slow (int x) {
    for (int i = 0; i < 5000000 * x; i++);
}
int main ()
{
    setup ();
    while (gameOver == false) {
        draw();
        input();
        logic();
        slow(level);
    }
    system ("pause");
    return 0;
}
