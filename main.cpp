#include<iostream>
#include<random>

bool gameOver;
static  int width = 20;
static  int height = 20;

int x , y , foodx, foody, score;

enum eDirection { STOP = 0 , LEFT, RIGHT , UP, DOWN};

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
    x = width/2;
    y = height/2;

    foodx = rand()%width;
    foody = rand()%height;

    score = 0;

}

void Draw()
{
    system("cls");

    for(int i = 0 ; i< width ; i++)
        std::cout<<"#";
    
    for(int i = 0 ; i < height ; i++)
    {
        
        for(int j=0; j<width ; j++)
        {
            if(j == 0  )
            {
                std::cout<<"#";
                std::cout<<" \t\t ";
            }

            if(j == width-1)
            {
                std::cout<<"#";
            }
            
        }
        std::cout<<"\n";
    }

    for(int i = 0 ; i < width ; i++)
    {
        std::cout<<"#";
    }

}

void Input()
{

}

void Logic()
{

}

int main()
{


    setup();

    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
 
    return 0;
}
