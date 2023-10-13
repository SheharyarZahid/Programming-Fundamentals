//                                                                                                         Works on larger screen
#include <iostream>
#include <windows.h>
using namespace std;

// Function prototypes
void gotoxy(int x, int y);
void erasesurfer();
void printsurfer();
void movesurferLeft();
void movesurferRight();
void movesurferup();
void movesurferdown();
void printWorld();
void moveEnemy();
void printEnemy();
void eraseEnemy();
void moveEnemy2();
void printEnemy2();
void eraseEnemy2();
char getCharAtxy(short int x, short int y);

// Variables
int pX = 3, pY = 30;
int eX = 89, eY = 25;
int ex = 110, ey=2;

main()
{
    system("cls");
    printWorld();
    printsurfer();

    while (true)
    {
        moveEnemy();
        moveEnemy2();
        if (GetAsyncKeyState(VK_LEFT))
        {
            movesurferLeft();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movesurferup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movesurferdown();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movesurferRight();
        }
        Sleep(50);
    }
}

// Move surfer left
void movesurferLeft()
{
    if (getCharAtxy(pX - 1, pY) == ' ')
    {
        erasesurfer();
        pX = pX - 2;
        printsurfer();
    }
}

void printWorld()
{
    cout << "######################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                                                    #" << endl;
    cout << "#                                                                                                                             ;`',                   #" << endl;
    cout << "#                                                                                                                             ',  ;    ,,-``==..,    #" << endl;
    cout << "#                                                                                                                              \\   ',''          \\   #" << endl;
    cout << "#                                                                                                                      ,-``'-., ;    '    __.-=``.;  #" << endl;
    cout << "#                                                                                                                    ,`` ,_     `V      _.``         #" << endl;
    cout << "#                                                                                                                    ;,'   `'-,         ``=--'_      #" << endl;
    cout << "#                                                                                                                          ,-`'    _  _       `,     #" << endl;
    cout << "#                                                                                                                         /   ,.-+(_)(_)'--.,   ;    #" << endl;
    cout << "#                                                                                                                        ,'  /   ; (_)       `\\ ,    #" << endl;
    cout << "#                                                                                                                        !,'     ;..;         ;/     #" << endl;
    cout << "#                                                                                                                         V'     ;  ;                #" << endl;
    cout << "#                                                                                                                                ;  ;                #" << endl;
    cout << "#                                                                                                                         __,.-- ;..;--.,            #" << endl;
    cout << "#                                                                                                                      ,'`       ;  ;    '`-,        #" << endl;
    cout << "#                                                                                                                    .-          ;  ;        ``      #" << endl;
    cout << "#                                                                                                                     ',                     ,'      #" << endl;
    cout << "#                                                                                                                      ``----..,_',,_'....-'         #" << endl;
    cout << "######################################################################################################################################################" << endl;
}
// Move surfer right
void movesurferRight()
{
    if (getCharAtxy(pX + 35, pY) == ' ' &&getCharAtxy(pX + 35, pY+7) == ' ' && getCharAtxy(pX + 35, pY+6) == ' ' && getCharAtxy(pX + 35, pY+5) == ' ' &&getCharAtxy(pX + 35, pY+4) == ' ' &&getCharAtxy(pX + 35, pY+3) == ' '&&getCharAtxy(pX + 35, pY+2) == ' ')
    {

        erasesurfer();
        pX = pX + 2;
        printsurfer();
    }
}
// Move surfer up
void movesurferup()
{
    if (getCharAtxy(pX, pY - 2) == ' ' && pY>=25)
    {

        erasesurfer();
        pY = pY - 2;
        printsurfer();
    }
}
// Move surfer down
void movesurferdown()
{
    if (getCharAtxy(pX, pY + 9) == ' ')
    {
        erasesurfer();
        pY = pY + 2;
        printsurfer();
    }
}

void erasesurfer()
{
    gotoxy(pX, pY);
    cout << "                                 ";
    gotoxy(pX, pY + 1);
    cout << "                                 ";
    gotoxy(pX, pY + 2);
    cout << "                                 ";
    gotoxy(pX, pY + 3);
    cout << "                                 ";
    gotoxy(pX, pY + 4);
    cout << "                                 ";
    gotoxy(pX, pY + 5);
    cout << "                                 ";
    gotoxy(pX, pY + 6);
    cout << "                                 ";
    gotoxy(pX, pY + 7);
    cout << "                                 ";
}

void printsurfer()
{
    gotoxy(pX, pY);
    cout << "               #  ( )            " << endl;
    gotoxy(pX, pY + 1);
    cout << "             __#___|__           " << endl;
    gotoxy(pX, pY + 2);
    cout << "          _ |_________| _        " << endl;
    gotoxy(pX, pY + 3);
    cout << "       _===| |       | |===_     " << endl;
    gotoxy(pX, pY + 4);
    cout << "      ===| |.---------.| |====   " << endl;
    gotoxy(pX, pY + 5);
    cout << " \\------'  .  .  .  .  '-------->" << endl;
    gotoxy(pX, pY + 6);
    cout << "   \\                          / " << endl;
    gotoxy(pX, pY + 7);
    cout << "    \\_______________WWS______/  " << endl;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
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

//  print enemy
void printEnemy()
{
    gotoxy(eX, eY);
    cout << "                    / | [              " << endl;
    gotoxy(eX, eY + 1);
    cout << "                  !    | ||            " << endl;
    gotoxy(eX, eY + 2);
    cout << "                _/|  _/|-++'           " << endl;
    gotoxy(eX, eY + 3);
    cout << "             +------___[}-_==_.'__ /\\ " << endl;
    gotoxy(eX, eY + 4);
    cout << "  __--==/___]_|__[__\\=-___,----' .7   " << endl;
    gotoxy(eX, eY + 5);
    cout << " |                               BB-61/" << endl;
    gotoxy(eX, eY + 6);
    cout << "  \\_______________________________|   " << endl;
}
//  erase enemy
void eraseEnemy()
{
    gotoxy(eX, eY);
    cout << "                                       " << endl;
    gotoxy(eX, eY + 1);
    cout << "                                       " << endl;
    gotoxy(eX, eY + 2);
    cout << "                                       " << endl;
    gotoxy(eX, eY + 3);
    cout << "                                       " << endl;
    gotoxy(eX, eY + 4);
    cout << "                                       " << endl;
    gotoxy(eX, eY + 5);
    cout << "                                       " << endl;
    gotoxy(eX, eY + 6);
    cout << "                                       " << endl;
}
//           move enemy
void moveEnemy()
{
    eraseEnemy();    
        eY = eY + 1;
        eX =eX-1;
        if (eY == 50 )
        {
        eX= 89;
        eY = 25;
        }
    printEnemy();
    Sleep(50);
}
//  print enemy 2
void printEnemy2()
{
    gotoxy(ex, ey);
    cout << "              ..____" << endl;
    gotoxy(ex, ey + 1);
    cout << "               / /_/ " << endl;
    gotoxy(ex, ey + 2);
    cout << "              /    \\    /|" << endl;
    gotoxy(ex, ey + 3);
    cout << "        _____/_.___()|_/ |" << endl;
    gotoxy(ex, ey + 4);
    cout << "  _____/_|_]      '    |.|" << endl;
    gotoxy(ex, ey + 5);
    cout << "(  __             ____/" << endl;
    gotoxy(ex, ey + 6);
    cout << " '\\_____\\____\\---||" << endl;
    gotoxy(ex, ey + 7);
    cout << "             `\\ . \\" << endl;
    gotoxy(ex, ey + 8);
    cout << "              `\\__\\ " << endl;
}
//  erase enemy 2
void eraseEnemy2()
{
    gotoxy(ex, ey);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 1);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 2);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 3);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 4);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 5);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 6);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 7);
    cout << "                                       " << endl;
    gotoxy(ex, ey + 8);
    cout << "                                       " << endl;
}
//           move enemy 2
void moveEnemy2()
{
    eraseEnemy2();    
        ex = ex - 3;
        if (ex == 11 )
        {
        ex = 110;
        }
    printEnemy2();
    Sleep(50);
}                                                  
                                                     





