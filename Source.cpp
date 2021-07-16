#include<iostream>
#include<random>
#include<conio.h>



bool gameOver;
int width = 20;
int height = 20;

int x, y, foodx, foody, score;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

eDirection dir;

/*
setup
draw
input
logic
*/
void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    foodx = rand() % width;
    foody = rand() % height;

    score = 0;


}

void Draw()
{
    system("cls");

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << "\n";

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                std::cout << "#";

            if (i == y && j == x)
                std::cout << "O";

            else
                std::cout << " ";

            if (j == width - 1)
                std::cout << "#";
            if (i == foody && j == foodx)
                std::cout << "(@)";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < width; i++)
    {
        std::cout << "#";
    }

}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }

}

void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;

       
    }

    if (x < 0 || x > width || y<0 || y > height)
    {
        gameOver = true;
    }


    if (x == foodx && y == foody)
    {
        score += 10;
        foodx = rand() % width;
        foody = rand() % height;
    }
}

int main()
{


    setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;
}
