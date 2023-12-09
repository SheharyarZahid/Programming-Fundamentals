//                                                                                                         Works on larger screen
#include <iostream>
#include <windows.h>
#include<iomanip>
using namespace std;

// Function prototypes
void gotoxy(int x, int y);
void erasesurfer(int &pX, int &pY);
void printsurfer(int &pX, int &pY, string &rifle);
void movesurferLeft(int &pX, int &pY,string &rifle);
void movesurferRight(int &pX, int &pY, string &rifle, int &score);
void movesurferup(int &pX, int &pY, string &rifle);
void movesurferdown(int &pX, int &pY,string &rifle);
void moveBullet(int &ex,int &ey,int &eX,int &eY,int &score);
void printWorld();
char getCharAtxy(short int x, short int y);
void printEnemy(int &eX, int &eY);
void eraseEnemy(int &eX, int &eY);
void moveEnemy(int &eX, int &eY);
void moveEnemyBullet(int &ex, int &ey);
void printEnemy2(int &ex, int &ey);
void eraseEnemy2(int &ex, int &ey);
void moveEnemy2(int &ex, int &ey);
void generateCharacters();
void generateColors();
void removeEnemyBullet();
void moveBullet();
void shootBullet(int pX, int pY);
int bulletX = 0;
int prevBulletX=0;
int prevBulletY=0;
int bulletY = 0;
// int enemyBulletX = -1;
// int enemyBulletY = -1;
// bool enemyBulletActive = false;
int health=5;
int health1=5,health2=5,health3=5; 
void drawEnemyBullets();
void removeEnemyBullets();
void moveEnemyBullets(int &ex, int &ey);
const int MAX_ENEMY_BULLETS = 5; // Adjust the maximum number of enemy bullets

int enemyBulletX[MAX_ENEMY_BULLETS];
int enemyBulletY[MAX_ENEMY_BULLETS];
bool enemyBulletActive[MAX_ENEMY_BULLETS];
bool bulletActive = false;
    int i=0;
int count=0;
    void drawBullet() {
        if (bulletActive) {
        gotoxy(bulletX, bulletY);
        if(count==0){
        cout << '|';
        }
if(count==1){
        cout << '/';
        }
        if(count==2){
        cout << ">";
        }         
          prevBulletX = bulletX;
        prevBulletY = bulletY;
    }
    }
   void removeBullet() {
    if (bulletActive) {
        gotoxy(prevBulletX, prevBulletY);
        cout << ' ';
    }
}
bool active=true;

// Main function
main()
{
// Variables
string rifle = "||";
int score=0;
int pX = 3, pY = 20;
int eX = 120, eY = 20;
int ex = 126, ey = 6;
int fire=0;
    system("cls");

    printWorld();
    printsurfer(pX,pY,rifle);
while (true)
{
        if(health2>=0 && active){
    moveEnemy(eX, eY);
    if(ey<100){
    moveEnemyBullets(ex, ey);
    if(health2==0){
        eraseEnemy(eX,eY);
        active=false;
    }
    }
    }
    moveEnemy2(ex, ey);
    if (GetAsyncKeyState(VK_LEFT))
    {
        movesurferLeft(pX, pY,rifle);
    }
    if (GetAsyncKeyState(VK_UP))
    {
        movesurferup(pX, pY, rifle);
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        movesurferdown(pX, pY,rifle);

    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        movesurferRight(pX, pY, rifle, score);
    }
  if (GetAsyncKeyState(VK_SPACE))
        {
           shootBullet(pX,pY);
            
        }
   if(GetAsyncKeyState('F')){
    if(!bulletActive){

    if(count==0){
        rifle="//";
        count=1;
    }
    else if(count==1){
        rifle="==";
        count=2;
    }
    else if(count==2){
        rifle="||";
        count=0;
    }
    }
        printsurfer(pX,pY,rifle);
}
        moveBullet(ex,ey,eX,eY,score);
        drawBullet();
        Sleep(20);
        removeBullet();
        removeEnemyBullets();
    gotoxy(3,3);
    cout << "Score: " << score;
//       generateCharacters();
//   generateColors();
}

}



// ...

void drawEnemyBullets()
{
    for (int i = 0; i < MAX_ENEMY_BULLETS; ++i)
    {
        if (enemyBulletActive[i])
        {
            gotoxy(enemyBulletX[i], enemyBulletY[i]);
            cout <<"\\_/";
        }
    }
}

void removeEnemyBullets()
{
    for (int i = 0; i < MAX_ENEMY_BULLETS; ++i)
    {
        if (enemyBulletActive[i])
        {
            gotoxy(enemyBulletX[i], enemyBulletY[i]);
            cout << "   ";
        }
    }
}

void moveEnemyBullets(int &ex, int &ey)
{
    for (int i = 0; i < MAX_ENEMY_BULLETS; ++i)
    {
        if (rand() % 100 < 5 && !enemyBulletActive[i]) // Adjust the probability of firing
        {
            enemyBulletX[i] = ex;
            enemyBulletY[i] = ey;
            enemyBulletActive[i] = true;
        }

        if (enemyBulletActive[i])
        {
            removeEnemyBullets();

            enemyBulletY[i]++; // Adjust the speed and direction of enemy bullets

            if (enemyBulletY[i] >= 58) // Adjust the screen height
            {
                enemyBulletActive[i] = false;
            }

            drawEnemyBullets();
        }
    }
}

//                                                                    shoot bullet
void shootBullet(int pX, int pY) {
    if (!bulletActive) {
        bulletX = pX+23;
        bulletY = pY +3;
        bulletActive = true;
    }
}
//                                                                    move bullet

void moveBullet(int &ex, int &ey, int &eX, int &eY, int &score) {
    if(bulletActive){

        // Check if the bullet hit enemy 1
        if ( bulletX >= eX && bulletX <= eX + 29 && bulletY <= eY + 5 && active) {
            bulletActive = false;
            health2--;
            score += 10;
        }

        // Check if the bullet hit enemy 2
        if ( bulletX >= ex && bulletX <= ex + 10 && bulletY >= ey && bulletY <= ey + 7) {
            bulletActive = false;
            health1--;
            score += 20;
        }

        // Move horizontally and vertically
        if(count==1){
        bulletX++;
        bulletY--;
        } 
        if(count==0){
        bulletY--;
        }
        if(count==2){
            bulletX++;
        }

        if (bulletY <= 0 || getCharAtxy(bulletX, bulletY) != ' ') {
            bulletActive = false;
        }
    }

}

//                                                                   Move surfer up
void movesurferup(int &pX,int &pY,string &rifle)
{
    if (getCharAtxy(pX, pY - 2) == ' ' && pY >= 15)
    {

        erasesurfer(pX,pY);
        pY = pY - 2;
        printsurfer(pX,pY,rifle);
    }
}
//                                                        Move surfer left
void movesurferLeft(int &pX, int &pY,string &rifle)
{
    if (getCharAtxy(pX - 1, pY) == ' '  && getCharAtxy(pX -1, pY + 6) == ' ' && getCharAtxy(pX - 1, pY + 5) == ' ' && getCharAtxy(pX - 1, pY + 4) == ' ' && getCharAtxy(pX -1, pY + 3) == ' ' && getCharAtxy(pX - 1, pY + 2) == ' ')
    {
        erasesurfer(pX, pY);
        pX = pX - 2;
        printsurfer(pX, pY, rifle);
    }
}

//                                                         Move surfer right
void movesurferRight(int &pX, int &pY, string &rifle, int &score)
{
    if (getCharAtxy(pX + 25, pY) == '*' || getCharAtxy(pX + 25, pY + 6) == '*' ||
        getCharAtxy(pX + 25, pY + 5) == '*' || getCharAtxy(pX + 25, pY + 4) == '*' ||
        getCharAtxy(pX + 25, pY + 3) == '*' || getCharAtxy(pX + 25, pY + 2) == '*')
    {
        erasesurfer(pX, pY);
        score = score + 1;
        pX = pX + 2;
        printsurfer(pX, pY, rifle);
    }
    if (getCharAtxy(pX + 25, pY) == ' ' && getCharAtxy(pX + 25, pY + 6) == ' ' && getCharAtxy(pX + 25, pY + 5) == ' ' && getCharAtxy(pX + 25, pY + 4) == ' ' && getCharAtxy(pX + 25, pY + 3) == ' ' && getCharAtxy(pX + 25, pY + 2) == ' ')
    {

        erasesurfer(pX, pY);
        pX = pX + 2;
        printsurfer(pX, pY, rifle);
    }
}

// Move surfer down
void movesurferdown(int &pX, int &pY, string &rifle)
{
    if (getCharAtxy(pX, pY + 8) == ' ')
    {
        erasesurfer(pX, pY);
        pY = pY + 2;
        printsurfer(pX, pY, rifle);
    }
}


void printWorld()
{
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                              SHIP WARS                                                                  #" << endl;
    cout << "#                                                                                                                                   Health:  "<<setw(2)<<health<<"           #" << endl;
    cout << "#                                                                                                                             Enemy Health:  "<<setw(2)<<health1<<"           #" << endl;
    cout << "#                                                                                                                            Enemy2 Health:  "<<setw(2)<<health2<<"           #" << endl;
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                 .|+.                                                                                                    #" << endl;
    cout << "#                                               .' |  '.                                                                                                  #" << endl;
    cout << "#                                              |   |    '.                                                                                                #" << endl;
    cout << "#                                              |  .+.     '.                                                                                              #" << endl;
    cout << "#                                              |_.'   '.   |'+                                                                                            #" << endl;
    cout << "#                                                .+' .'|'._|+.'                                                                                           #" << endl;
    cout << "#                                                  +| +                                                                                                   #" << endl;
    cout << "#                                                  F|  |.                                                                                                 #" << endl;
    cout << "#                                          -------J |   JL------                                                                                          #" << endl;
    cout << "#                                                |  |   |-.                                                                                               #" << endl;
    cout << "#                                                +._|  _,.+                                                                                               #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                          ;',     ,=.,   #" << endl;
    cout << "#                                                                                                                                          \\  ', '     \\  #" << endl;
    cout << "#                                                                                                                                   ,-`'-., ;    ' =``.;  #" << endl;
    cout << "#                                                                                                                                 ,``,_    `V    _`       #" << endl;
    cout << "#                                                                                                                                 ;,'  `'-,     ``=-'_    #" << endl;
    cout << "#                                                                                                                                   ,-`'    _  _     `,   #" << endl;
    cout << "#                                                                                                                                  /   ,.-+(_)(_)'--., ;  #" << endl;
    cout << "#                                                                                                                                  ,' /   ; (_)        `\\,#" << endl;
    cout << "#                                                                           *                                                      V'     ;  ;            #" << endl;
    cout << "#                                                                                                                                     _.--;..;--,         #" << endl;
    cout << "#                                                                                                                                  ,'     ;  ;   '`-,     #" << endl;
    cout << "#                                                                                                                                .-                 ``    #" << endl;
    cout << "#                                                                                                                                  `--..,_',,_'...-'      #" << endl;
    cout << "###########################################################################################################################################################" << endl;
}  

//                                                                      erase player
void erasesurfer(int &pX,int &pY)
{
    gotoxy(pX, pY);
    cout << "                        ";
    gotoxy(pX, pY + 1);
    cout << "                        ";
    gotoxy(pX, pY + 2);
    cout << "                        ";
    gotoxy(pX, pY + 3);
    cout << "                        ";
    gotoxy(pX, pY + 4);
    cout << "                        ";
    gotoxy(pX, pY + 5);
    cout << "                        ";
    gotoxy(pX, pY + 6);
    cout << "                        ";
}
//                                                                     print player
void printsurfer(int &pX,int &pY,string &rifle)
{
    gotoxy(pX, pY);
    cout << "           # ( )        " << endl;
    gotoxy(pX, pY + 1);
    cout << "          _#__|_        " << endl;
    gotoxy(pX, pY + 2);
    cout << "        _ |____| _      " << endl;
    gotoxy(pX, pY + 3);
    cout << "     ==||.-----.||==  "<<setw(2)<<left<<rifle<<"  " << endl;
    gotoxy(pX, pY + 4);
    cout << " \\-----' .  .  . '----->" << endl;
    gotoxy(pX, pY + 5);
    cout << "   \\                 / " << endl;
    gotoxy(pX, pY + 6);
    cout << "    \\_________WWS___/  " << endl;
}
//                                                                      gotoxy function
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
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

//  print enemy
void printEnemy(int &eX, int &eY)
{
    gotoxy(eX, eY);
    cout << "            / | [            " << endl;
    gotoxy(eX, eY + 1);
    cout << "          +--__[ _-/         " << endl;
    gotoxy(eX, eY + 2);
    cout << "  __--==/_]___[_\\==_\\_='/* " << endl;
    gotoxy(eX, eY + 3);
    cout << " \\                    F-61/ " << endl;
    gotoxy(eX, eY + 4);
    cout << "  \\_____________________|   " << endl;
}
//                                                                        erase enemy
void eraseEnemy(int &eX, int &eY)
{
    gotoxy(eX, eY);
    cout << "                            " << endl;
    gotoxy(eX, eY + 1);
    cout << "                            " << endl;
    gotoxy(eX, eY + 2);
    cout << "                            " << endl;
    gotoxy(eX, eY + 3);
    cout << "                            " << endl;
    gotoxy(eX, eY + 4);
    cout << "                            " << endl;

}
//                                                                        move enemy
void moveEnemy(int &eX, int &eY)
{

    static bool patrol = true; 

    eraseEnemy(eX, eY);
    if (patrol)
    {
        eY = eY + 1;
        eX = eX - 1;
        if (eY == 32)
        {
            patrol = false;
        }
    }
    else
    {
        eY = eY - 1;
        eX = eX + 1;
        if (eY == 20)
        {
            patrol = true;
        }
    }

    printEnemy(eX,eY);
    Sleep(50); 
    }


//                                                                       print enemy 2
void printEnemy2(int &ex, int &ey)
{
    gotoxy(ex, ey);
    cout << "           ___      " << endl;
    gotoxy(ex, ey + 1);
    cout << "          /  \\   /|" << endl;
    gotoxy(ex, ey + 2);
    cout << "       __/__()|_/ |" << endl;
    gotoxy(ex, ey + 3);
    cout << "  ____/_|_]  '  |.|" << endl;
    gotoxy(ex, ey + 4);
    cout << "(  __       ____/  " << endl;
    gotoxy(ex, ey + 5);
    cout << " '\\____\\--||     " << endl;
    gotoxy(ex, ey + 6);
    cout << "        `\\__\\    " << endl;
}
//                                                                       erase enemy 2
void eraseEnemy2(int &ex,int &ey)
{
    gotoxy(ex, ey);
    cout << "                   " << endl;
    gotoxy(ex, ey + 1);
    cout << "                   " << endl;
    gotoxy(ex, ey + 2);
    cout << "                   " << endl;
    gotoxy(ex, ey + 3);
    cout << "                   " << endl;
    gotoxy(ex, ey + 4);
    cout << "                   " << endl;
    gotoxy(ex, ey + 5);
    cout << "                   " << endl;
    gotoxy(ex, ey + 6);
    cout << "                   " << endl;
}
//                                                                       move enemy 2
void moveEnemy2(int &ex,int &ey)
{
    if(health1>0){
    eraseEnemy2(ex,ey);
    ex = ex - 3;
    if (ex == 3)
    {
        ex = 126;
    }
    printEnemy2(ex,ey);
    Sleep(50);
    }
    else{
        eraseEnemy2(ex,ey);
        ex=-2;
        ey=-2;
    }
}
//                                                                    generate characters
void generateCharacters()
{
  char character;
  for (int x = 0; x < 256; x++)
  {
    // pick the characters combinations to make your players and enemies
    character = x;
    cout << x << " " << character << endl;
  }
}
//                                                                     generate colors
void generateColors()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for (int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " Learning is never done without errors and defeat!" << endl;
  }
}

         