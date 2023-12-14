#include<iostream>
#include <windows.h>
using namespace std;

void displayGame(char[][156]);
void displayBorders(char[][156]);
void initiateBullet(char[][156]);
void moveBullet(char[][156]);
void eraseBullet(char[][156]);
void moveOpponent(char[][156], char, char);
bool checkWallCollision(char[][156]);
void moveOpponent(char [][156], char, char);
int getRandomNumber(int min, int max);
void gotoxy(int x, int y);
void erasePlayer();
void printPlayer();

const int playerHeight = 5;
const int playerWidth = 15;
int pX = 20, pY = 20;
int health1=5,health2=5,health3=5; 
    char gameBoard[58][156] = {
    
};
main()
{

        system("cls");
    bool bulletShot = false;

    displayGame(gameBoard);
            printPlayer();

    while(true)
    {
            if (GetAsyncKeyState(VK_LEFT)){
            erasePlayer();
            gameBoard[pX][pY]   = ' ';
            pY = pY - 1;
            gameBoard[pX][pY] = 'p';
            printPlayer();
                
        }
       
           if (GetAsyncKeyState(VK_RIGHT)){
            erasePlayer();
            gameBoard[pX][pY]   = ' ';
            pY = pY + 1;
            gameBoard[pX][pY] = 'p';
            printPlayer();
                
        }
           if (GetAsyncKeyState(VK_UP)){
            erasePlayer();
            gameBoard[pX][pY]   = ' ';
            pX = pX - 1;
            gameBoard[pX][pY] = 'p';
            printPlayer();
                
        }
           if (GetAsyncKeyState(VK_DOWN)){
            erasePlayer();
            gameBoard[pX][pY]   = ' ';
            pX = pX + 1;
            gameBoard[pX][pY] = 'p';
            printPlayer();
                
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            if(!bulletShot)
            {
                initiateBullet(gameBoard);    
                displayGame(gameBoard);       
                bulletShot = true;
            }
        }
        if (bulletShot)  
        {
            if (checkWallCollision(gameBoard))
            {
                moveBullet(gameBoard);
                displayGame(gameBoard);
            }
            else
            {
                bulletShot = false;
                displayGame(gameBoard);
            }
        }

        int randomDirection = getRandomNumber(0, 1);
        if (randomDirection == 0)
        {
            moveOpponent(gameBoard, 'e', 'r');
            moveOpponent(gameBoard, 'x', 'l');
            displayGame(gameBoard);
        }
        else
        {
            moveOpponent(gameBoard, 'e', 'l');
            moveOpponent(gameBoard, 'x', 'r');
            displayGame(gameBoard);
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
    }

    }






char player2D[playerHeight][playerWidth] = 
                        {"      /\\      ",
                        "   __/~~\\__   ",
                        " /   |  |   \\ ",
                        "=====.  .=====",
                        "     ||||     "
                        };
void erasePlayer()
{
    for(int i=0;i<playerHeight;i++){
        for(int j=0;j<playerWidth;j++) {
            gotoxy(pY+j,pX+i);
            cout<<"                ";
        }
    }
}
void printPlayer(){
    for(int i=0;i<playerHeight;i++){
        for(int j=0;j<playerWidth;j++) {
            gotoxy(pY+j,pX+i);
            cout<<player2D[i][j];
        }
    }

}
//                                                                      gotoxy function
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void eraseBullet(char gameBoard[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (gameBoard[i][j] == '.')
            {
                gameBoard[i][j] = ' ';
                break;
            }
        }
    }
}

void moveOpponent(char gameBoard[][156], char opponentType, char move)
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (gameBoard[i][j] == opponentType)
            {
                if (move == 'r')
                {
                    if (gameBoard[i][j + 1] == ' ')
                    {
                        gameBoard[i][j] = ' ';
                        gameBoard[i][j + 1] = opponentType;
                        break;
                    }
                }
                else if (move == 'l')
                {
                    if (gameBoard[i][j - 1] == ' ' && gameBoard[i][j - 1] != '#')
                    {
                        gameBoard[i][j] = ' ';
                        gameBoard[i][j - 1] = opponentType;
                        break;
                    }
                }
            }
        }
    }
}


void moveBullet(char gameBoard[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (gameBoard[i][j] == '.')
            {
                gameBoard[i][j] = ' ';
                gameBoard[i - 1][j] = '.';
            }
        }
    }
}

void initiateBullet(char gameBoard[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (gameBoard[i][j] == 'p')
            {
                gameBoard[i - 1][j] = '.';
            }
        }
    }
}

bool checkWallCollision(char arr[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (arr[i][j] == '.' && arr[i - 1][j] == '#')
            {
                arr[i][j] = ' ';
                return false;
            }
        }
    }
    return true;
}

void displayBorders(char gameBoard[][156])
{
    system("cls");
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (gameBoard[i][j] == '#' || gameBoard[i][j] == ' ')
                cout << gameBoard[i][j];
            else
                cout << ' ';
        }
        cout << endl;
    }   
}

void displayGame(char gameBoard[][156])
{
    string buffer = "";
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {

             if(gameBoard[i][j]=='p') {
                pX =i;pY=j;
                printPlayer();
            }
            else
            {
            gotoxy(j,i);
            cout<<gameBoard[i][j];
            }
}
}
}

