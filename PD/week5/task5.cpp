#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
using namespace std;
//                                             Functions
void gotoxy(int x, int y);
void login();
string information(int x, int y);
void member(string name, string type);
void user(string name, string type);
void ViewATM();
int option(int x, int y);
//                                           Global Varaibles
string name;
string type;
string password;
string named = "************************";
string card = "**************************";
string ccv = "****";
int options;
main()
{
    system("cls");
    login();
    name = information(50, 26);
    password = information(50, 32);
    type = information(74, 35);
    if (type == "user")
    {
        user(name, type);
    }

    // if(type=="member"){
    //     member(name);
    // }
}
//                                             After login display screen
void user(string name, string type)
{
    system("cls");
    gotoxy(20, 5);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 6);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 7);
    cout << "#     #####       #####    #     #   #     #                  ####     #######     #######              #" << endl;
    gotoxy(20, 8);
    cout << "#     #    ##    ##   ##   ###   #   #   ##                 ##    ##   ##    ##    ##    ##             #" << endl;
    gotoxy(20, 9);
    cout << "#     #    ##    ##   ##   # ### #   # ##                  ##      ##  ##     ##   ##     ##            #" << endl;
    gotoxy(20, 10);
    cout << "#     #####      #######   #  ####   ##                    ##########  #### ##     ####  ##             #" << endl;
    gotoxy(20, 11);
    cout << "#     #    ##    ##   ##   #    ##   # ##                  ##      ##  ##          ##                   #" << endl;
    gotoxy(20, 12);
    cout << "#     #    ##    ##   ##   #     #   #  ##                 ##      ##  ##          ##                   #" << endl;
    gotoxy(20, 13);
    cout << "#     #####      ##   ##   #     #   #    #                ##      ##  ##          ##                   #" << endl;
    gotoxy(20, 14);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 15);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 16);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 17);
    cout << "#    HI! " << setw(27) << left << name << "                                                                    #" << endl;
    gotoxy(20, 18);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 19);
    cout << "#    Login Type: " << setw(27) << left << type << "                                                            #" << endl;
    gotoxy(20, 20);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 21);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 22);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 23);
    cout << "#  1) View your Account                             ##    2) CREDIT/DEBIT CARD MANAGEMENT               #" << endl;
    gotoxy(20, 24);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 25);
    cout << "#               #####                               ##      ######################                      #" << endl;
    gotoxy(20, 26);
    cout << "#             ##     ##                             ##      #  name:*****        #                      #" << endl;
    gotoxy(20, 27);
    cout << "#             ##     ##                             ##      #  ac no.******      #                      #" << endl;
    gotoxy(20, 28);
    cout << "#               #####                               ##      #  </>     ccv:****  #                      #" << endl;
    gotoxy(20, 29);
    cout << "#             ##     ##                             ##      ######################                      #" << endl;
    gotoxy(20, 30);
    cout << "#            ##       ##                            ##                                                  #" << endl;
    gotoxy(20, 31);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 32);
    cout << "#    => View Account Balance/IBAN number            ##     => View your cards                           #" << endl;
    gotoxy(20, 33);
    cout << "#    => Manage Settings                             ##     => Freeze/unFreeze your cards                #" << endl;
    gotoxy(20, 34);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 35);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 36);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 37);
    cout << "#  3) Money Transfer                                ##   4) Exit the application                        #" << endl;
    gotoxy(20, 38);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 39);
    cout << "#                 ___ #####                         ##     ######  ##    ##  ###### #######             #" << endl;
    gotoxy(20, 40);
    cout << "#               ____#########                       ##     ##       ##  ##     ##      #                #" << endl;
    gotoxy(20, 41);
    cout << "#                ___#########                       ##     #####      ##       ##      #                #" << endl;
    gotoxy(20, 42);
    cout << "#                   __#####                         ##     ##       ##  ##     ##      #                #" << endl;
    gotoxy(20, 43);
    cout << "#                                                   ##     ######  ##    ##  ######    #                #" << endl;
    gotoxy(20, 44);
    cout << "#    => Send/Recive Money                           ##                                                  #" << endl;
    gotoxy(20, 45);
    cout << "#    => Watch Transaction History                   ##    => Close the app                              #" << endl;
    gotoxy(20, 46);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 47);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 48);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 49);
    cout << "#--------------------------------------------SELECT AN OPTION ------------------------------------------#" << endl;
    gotoxy(20, 50);
    cout << "#                                         ______________________                                        #" << endl;
    gotoxy(20, 51);
    cout << "#                                        |                      |                                       #" << endl;
    gotoxy(20, 52);
    cout << "#                                        |                      |                                       #" << endl;
    gotoxy(20, 53);
    cout << "#                                        |______________________|                                       #" << endl;
    gotoxy(20, 54);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 55);
    cout << "#########################################################################################################";
    options = option(72, 52);
    if (options == 4)
    {
        system("cls");
        exit(0);
    }
    if (options == 2)
        ViewATM();
}
//                                             On selecting option 2 screen
void ViewATM()
{
    while (true)
    {
        system("cls");
        gotoxy(20, 5);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 6);
        cout << "#                                     CREDIT / DEBIT CARD MANAGEMENT                                    #" << endl;
        gotoxy(20, 7);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 8);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 9);
        cout << "#             ###########################################################################               #" << endl;
        gotoxy(20, 10);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 11);
        cout << "#             ##      Name:" << setw(26) << left << named << "                                  ##               #" << endl;
        gotoxy(20, 12);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 13);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 14);
        cout << "#             ##    IBAN number: PKNIBUET" << setw(26) << left << card << "2023                ##               #" << endl;
        gotoxy(20, 15);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 16);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 17);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 18);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 19);
        cout << "#             ##      Issue Date         Expiry Date                                   ##               #" << endl;
        gotoxy(20, 20);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 21);
        cout << "#             ##        3/21                4/27                                       ##               #" << endl;
        gotoxy(20, 22);
        cout << "#             ##                                               CCV: " << setw(18) << ccv << " ##               #" << endl;
        gotoxy(20, 23);
        cout << "#             ##                                                                       ##               #" << endl;
        gotoxy(20, 24);
        cout << "#             ###########################################################################               #" << endl;
        gotoxy(20, 25);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 26);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 27);
        cout << "#                                                   ##                                                  #" << endl;
        gotoxy(20, 28);
        cout << "#  1) Card Information                              ##   2) Freeze/unFreeze card                        #" << endl;
        gotoxy(20, 29);
        cout << "#                                                   ##                                                  #" << endl;
        gotoxy(20, 30);
        cout << "#              #################                    ##            ################                      #" << endl;
        gotoxy(20, 31);
        cout << "#              # NAME:John     #                    ##            #    Freeze    #                      #" << endl;
        gotoxy(20, 32);
        cout << "#              #               #                    ##            #      OR      #                      #" << endl;
        gotoxy(20, 33);
        cout << "#              #       CVV:440 #                    ##            #   UnFreeze   #                      #" << endl;
        gotoxy(20, 34);
        cout << "#              #################                    ##            ################                      #" << endl;
        gotoxy(20, 35);
        cout << "#                                                   ##                                                  #" << endl;
        gotoxy(20, 36);
        cout << "#        => Reveal Card Information                 ##    => Freeze/ Un freeze your card                #" << endl;
        gotoxy(20, 37);
        cout << "#                                                   ##                                                  #" << endl;
        gotoxy(20, 38);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 39);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 40);
        cout << "#--------------------------------------------SELECT AN OPTION ------------------------------------------#" << endl;
        gotoxy(20, 41);
        cout << "#                                         ______________________                                        #" << endl;
        gotoxy(20, 42);
        cout << "#                                        |                      |                                       #" << endl;
        gotoxy(20, 43);
        cout << "#                                        |                      |                                       #" << endl;
        gotoxy(20, 44);
        cout << "#                                        |______________________|                                       #" << endl;
        gotoxy(20, 45);
        cout << "#                                                                      Press 0 to back to Homepage      #" << endl;
        gotoxy(20, 46);
        cout << "#########################################################################################################";
        int creditoption = option(72, 43);
        if (creditoption == 1)
        {
            named = name;
            card = "12345678943433434421496532";
            ccv = "440";
        }
        else if (creditoption == 0)
        {
            named = "************************";
            card = "**************************";
            ccv = "****";
            user(name, type);
            options = option(72, 52);
            break;
        }
    }
}

//                                                  option input
int option(int x, int y)
{
    int options;
    gotoxy(x, y);
    cin >> options;
    return options;
}
//                                         Login information input function
string information(int x, int y)
{
    string information;
    gotoxy(x, y);
    cin >> information;
    return information;
}
//                                              Login display function
void login()
{
    gotoxy(40, 10);
    cout << "#############################################################" << endl;
    gotoxy(40, 11);
    cout << "#                                                           #" << endl;
    gotoxy(40, 12);
    cout << "#       #        ####       ####    #####  ##   #           #" << endl;
    gotoxy(40, 13);
    cout << "#       #       ##  ##    ##    ##    #    ###  #           #" << endl;
    gotoxy(40, 14);
    cout << "#       #       #    #   ##           #    #### #           #" << endl;
    gotoxy(40, 15);
    cout << "#       #       #    #  ##    ###     #    #  ###           #" << endl;
    gotoxy(40, 16);
    cout << "#       #       ##  ##   ##    ##     #    #   ##           #" << endl;
    gotoxy(40, 17);
    cout << "#       ######   ####     #####     #####  #    #           #" << endl;
    gotoxy(40, 18);
    cout << "#                                                           #" << endl;
    gotoxy(40, 19);
    cout << "#############################################################" << endl;
    gotoxy(40, 20);
    cout << "#                                                           #" << endl;
    gotoxy(40, 21);
    cout << "#-----------------------WELCOME BACK------------------------#" << endl;
    gotoxy(40, 22);
    cout << "#                                                           #" << endl;
    gotoxy(40, 23);
    cout << "#      UserName:                                            #" << endl;
    gotoxy(40, 24);
    cout << "#      __________________________________________           #" << endl;
    gotoxy(40, 25);
    cout << "#     |                                          |          #" << endl;
    gotoxy(40, 26);
    cout << "#     |                                          |          #" << endl;
    gotoxy(40, 27);
    cout << "#     |__________________________________________|          #" << endl;
    gotoxy(40, 28);
    cout << "#                                                           #" << endl;
    gotoxy(40, 29);
    cout << "#      Password:                                            #" << endl;
    gotoxy(40, 30);
    cout << "#      __________________________________________           #" << endl;
    gotoxy(40, 31);
    cout << "#     |                                          |          #" << endl;
    gotoxy(40, 32);
    cout << "#     |                                          |          #" << endl;
    gotoxy(40, 33);
    cout << "#     |__________________________________________|          #" << endl;
    gotoxy(40, 34);
    cout << "#                                                           #" << endl;
    gotoxy(40, 35);
    cout << "#      Are you (member / user)?:                            #" << endl;
    gotoxy(40, 36);
    cout << "#                                                           #" << endl;
    gotoxy(40, 37);
    cout << "#############################################################";
}
//                                                 Gotoxy Function
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}