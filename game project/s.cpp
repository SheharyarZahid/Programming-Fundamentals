#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);
void erasePlayer();
void printPlayer();
void drawBoard();
void printcoco() ;
char getCharAtxy(short int x, short int y);
void initiateBullet(char[][156]);
void moveBullet(char[][156]);
void eraseBullet(char[][156]);
void moveOpponent(char[][156], char, char);
bool checkWallCollision(char[][156]);
void moveOpponent(char [][156], char, char);
int getRandomNumber(int min, int max);

int eX = 2, eY = 2;
int pX = 20, pY = 20;
int cX=20,cY=20;
const int sheight=20,swidth=22;
const int playerHeight = 5;
const int playerWidth = 15;
const int boardHeight = 58, boardWidth = 156;
const int height=13,width=27;
    
char board[boardHeight][boardWidth] = {
    "###########################################################################################################################################################",
    "#                                                                              SHIP WARS                                                                  #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "###########################################################################################################################################################",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                     e                                                                   #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#              p                                  s                                                                                                       #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                   x                                     #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                          c                              #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                           *                                                                             #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "#                                                                                                                                                         #",
    "###########################################################################################################################################################",
        };
char stone[sheight][swidth]={
             "            .|+.     ",    
             "     .' |  '.        ",
             "    |   |    '.      ",
             "    |  .+.     '.    ",
             "    |_.'   '.   |'+  ",
             "      .+' .'|'._|+.' ",
             "        +| +         ",
             "        F|  |.       ",
             "-------J |   JL------",
             "      |  |   |-.     ",
             "      +._|  _,.+     ",
};
char player2D[playerHeight][playerWidth] = 
                        {"      /\\      ",
                        "   __/~~\\__   ",
                        " /   |  |   \\ ",
                        "=====.  .=====",
                        "     ||||     "
                        };
char  coconut[height][width]={
              "         ;',     .'''.   ",  
              "         \\  ', '     \\ ",
              "   ,-`'-., ;    ' =``.;  ",
              " ,``,_    `V    _`       ",
              " ;,'  `'-,     ``=-'_    ",
              "   ,-`'    _  _     `,   ",
              "  /   ,.-+(_)(_)'--., ;  ",
              "  ,' /   ; (_)        `\\",
              "  V'     ;  ;            ",
              "     _.--;..;--,         ",
              "  ,'     ;  ;   '`-,     ",
              ".-                 ``    ",
              "  `--..,_',,_'...-'      ",
};
int main() {
    bool bulletShot = false;

    system("cls");
    drawBoard();
    printPlayer();

    while (true) {
        printcoco();
        if (GetAsyncKeyState(VK_LEFT) && board[pX][pY - 1] == ' ') {
            erasePlayer();
            board[pX][pY] = ' ';
            pY = pY - 1;
            board[pX][pY] = 'p';
            printPlayer();
        }
if (GetAsyncKeyState(VK_RIGHT) && pY < boardWidth - 1 && 
    board[pX][pY + 1] == ' ' &&
    board[pX + 1][pY + 1] == ' ' &&
    board[pX + 2][pY + 1] == ' ' &&
    board[pX + 3][pY + 1] == ' ' &&
    board[pX + 4][pY + 1] == ' ' ) {
    erasePlayer();
    board[pX][pY] = ' ';
    pY = pY + 1;
    board[pX][pY] = 'p';
    printPlayer();
    cout << pY;
}
        if (GetAsyncKeyState(VK_UP) && board[pX - 1][pY] == ' ') {
            erasePlayer();
            board[pX][pY] = ' ';
            pX = pX - 1;
            board[pX][pY] = 'p';
            printPlayer();
        }
        if (GetAsyncKeyState(VK_DOWN) &&  board[pX + playerHeight][pY] == ' ') {
            erasePlayer();
            board[pX][pY] = ' ';
            pX = pX + 1;
            board[pX][pY] = 'p';
            printPlayer();
        }

if (GetAsyncKeyState(VK_SPACE))
        {
            if(!bulletShot)
            {
                initiateBullet(board);    
                // drawBoard();       
                bulletShot = true;
            }
        }
        if (bulletShot)  
        {
            if (checkWallCollision(board))
            {
                moveBullet(board);
                // drawBoard();
            }
            else
            {
                bulletShot = false;
                drawBoard();
            }
        }

        int randomDirection = getRandomNumber(0, 1);
        if (randomDirection == 0)
        {
            moveOpponent(board, 'e', 'r');
            moveOpponent(board, 'x', 'l');
            // drawBoard();
        }
        else
        {
            moveOpponent(board, 'e', 'l');
            moveOpponent(board, 'x', 'r');
            // drawBoard();
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        Sleep(100);
    }

    return 1;
}

void drawBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (board[i][j] == 'p') {
                pX = i;
                pY = j;
                printPlayer();
            } 
            if(board[i][j]=='c'){
                   cX = i;
                cY = j;
                printcoco();
            }
            else {
                gotoxy(j, i);
                cout << board[i][j];
            }
        }
    }
}


void erasePlayer() {
    for (int i = 0; i < playerHeight; i++) {
        for (int j = 0; j < playerWidth; j++) {
            gotoxy(pY + j, pX + i);
            cout << "               ";
        }
    }
}

void printPlayer() {
    for (int i = 0; i < playerHeight; i++) {
        for (int j = 0; j < playerWidth; j++) {
            gotoxy(pY + j, pX + i);
            cout << player2D[i][j];
        }
    }
}
void printcoco() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <width; j++) {
            gotoxy(cY + j, cX + i);
            cout << coconut[i][j];
        }
    }
}
int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void eraseBullet(char board[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = ' ';
                break;
            }
        }
    }
}

void moveOpponent(char board[][156], char opponentType, char move)
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (board[i][j] == opponentType)
            {
                if (move == 'r')
                {
                    if (board[i][j + 1] == ' ')
                    {
                        board[i][j] = ' ';
                        board[i][j + 1] = opponentType;
                        break;
                    }
                }
                else if (move == 'l')
                {
                    if (board[i][j - 1] == ' ' && board[i][j - 1] != '#')
                    {
                        board[i][j] = ' ';
                        board[i][j - 1] = opponentType;
                        break;
                    }
                }
            }
        }
    }
}


void moveBullet(char board[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = ' ';
                board[i - 1][j] = '.';
            }
        }
    }
}

void initiateBullet(char board[][156])
{
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 156; j++)
        {
            if (board[i][j] == 'p')
            {
                board[i - 1][j] = '.';
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
//                                                                  get charcter at x and y
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}



