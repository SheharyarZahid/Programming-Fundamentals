#include <iostream>
#include <conio.h>
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
bool confirmpassword(string passwordcheck);
void display();
void signup();
int option(int x, int y);
bool passworddisplay();
void freeze(bool freeze);
void userinfo(string name);
void transfermoney(string name);
void accountinfo();
void addaccount();
void bankadd();
void bankdetails(string variable);
void display(int x, int y);
//                                           Global Varaibles
string name;
bool num = true;
bool check;
string type;
string passwordconfirm;
string passwordcheck = "Enter password to proceed";
string passwordreturn;
string cnic;
string password;
string named = "************************";
string card = "**************************";
string ccv = "****";
int options;
int userCount = 0;
string add_bank;
string bankdetail[100];
string userName[100];
int userPass[100];
string userRole[100];
int x = 0;
main()
{
    system("cls");
    display();
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
    cout << "#    => View Account /CNIC number                   ##     => View your cards                           #" << endl;
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
    cout << "#    => Watch Transaction History                   ##    => Close the app / 5 for sign out             #" << endl;
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
    if (options == 1)
    {
        system("cls");
        userinfo(name);
    }
    else if (options == 4)
    {
        system("cls");
        exit(0);
    }
    else if (options == 2)
    {
        ViewATM();
    }
    else if (options == 5)
    {
        system("cls");
        display();
    }
    else if (options == 3)
    {
        system("cls");
        transfermoney(name);
    }
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
            bool check = passworddisplay();
            if (check)
            {
                named = name;
                card = "12345678943433434421496532";
                ccv = "440";
            }
            else
            {
                named = "************************";
                card = "**************************";
                ccv = "****";
                check = passworddisplay();
            }
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
        else if (creditoption == 2)
        {
            check = passworddisplay();
            freeze(num);
        }
    }
}
//                                                freeze/unfreeZe
void freeze(bool freeze)
{
    if (freeze)
    {
        system("cls");
        gotoxy(20, 10);
        cout << "####################################################################################################################################" << endl;
        gotoxy(20, 11);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 12);
        cout << "#            ## ##     ##     ### ##   ### ##            ### ###  ### ##   ### ###  ### ###  ### ##   ### ###  ### ##              #" << endl;
        gotoxy(20, 13);
        cout << "#           ##   ##     ##     ##  ##   ##  ##            ##  ##   ##  ##   ##  ##   ##  ##  ##  ##    ##  ##   ##  ##             #" << endl;
        gotoxy(20, 14);
        cout << "#           ##        ## ##    ##  ##   ##  ##            ##       ##  ##   ##       ##         ##     ##       ##  ##             #" << endl;
        gotoxy(20, 15);
        cout << "#           ##        ##  ##   ## ##    ##  ##            ## ##    ## ##    ## ##    ## ##     ##      ## ##    ##  ##             #" << endl;
        gotoxy(20, 16);
        cout << "#           ##        ## ###   ## ##    ##  ##            ##       ## ##    ##       ##       ##       ##       ##  ##             #" << endl;
        gotoxy(20, 17);
        cout << "#           ##   ##   ##  ##   ##  ##   ##  ##            ##       ##  ##   ##  ##   ##  ##  ##  ##    ##  ##   ##  ##             #" << endl;
        gotoxy(20, 18);
        cout << "#            ## ##   ###  ##  #### ##  ### ##            ####     #### ##  ### ###  ### ###  # ####   ### ###  ### ##              #" << endl;
        gotoxy(20, 19);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 20);
        cout << "####################################################################################################################################" << endl;
        Sleep(2000);
        num = false;
        ViewATM();
    }
    if (!freeze)
    {
        system("cls");
        gotoxy(20, 10);
        cout << "####################################################################################################################################" << endl;
        gotoxy(20, 11);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 12);
        cout << "#       ## ##     ##     ### ##   ### ##       ##  ###  ###  ##    ### ###  ### ##   ### ###  ### ###  ### ##   ### ###  ### ##    #" << endl;
        gotoxy(20, 13);
        cout << "#      ##   ##     ##     ##  ##   ##  ##      ##   ##    ## ##     ##  ##   ##  ##   ##  ##   ##  ##  ##  ##    ##  ##   ##  ##   #" << endl;
        gotoxy(20, 14);
        cout << "#      ##        ## ##    ##  ##   ##  ##      ##   ##   # ## #     ##       ##  ##   ##       ##         ##     ##       ##  ##   #" << endl;
        gotoxy(20, 15);
        cout << "#      ##        ##  ##   ## ##    ##  ##      ##   ##   ## ##      ## ##    ## ##    ## ##    ## ##     ##      ## ##    ##  ##   #" << endl;
        gotoxy(20, 16);
        cout << "#      ##        ## ###   ## ##    ##  ##      ##   ##   ##  ##     ##       ## ##    ##       ##       ##       ##       ##  ##   #" << endl;
        gotoxy(20, 17);
        cout << "#      ##   ##   ##  ##   ##  ##   ##  ##      ##   ##   ##  ##     ##       ##  ##   ##  ##   ##  ##  ##  ##    ##  ##   ##  ##   #" << endl;
        gotoxy(20, 18);
        cout << "#       ## ##   ###  ##  #### ##  ### ##        ## ##   ###  ##    ####     #### ##  ### ###  ### ###  # ####   ### ###  ### ##    #" << endl;
        gotoxy(20, 19);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 20);
        cout << "####################################################################################################################################" << endl;
        Sleep(2000);
        num = true;
        ViewATM();
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
    //  cin.ignore();
    // getline(cin,information);
    return information;
}
//                                                   Sign up Screen
void signup()
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
    cout << "#                    #####   #######    #####     #    #         #      #    ######                     #" << endl;
    gotoxy(20, 18);
    cout << "#                   ##    #     #      ##    #    ###  #         #      #    #     #                    #" << endl;
    gotoxy(20, 19);
    cout << "#                    ###        #     #           # ## #         #      #    #     #                    #" << endl;
    gotoxy(20, 20);
    cout << "#                      ###      #     #     ###   #  ###         #      #    #####                      #" << endl;
    gotoxy(20, 21);
    cout << "#                   #    ##     #      ##    ##   #    #         ##    ##    #                          #" << endl;
    gotoxy(20, 22);
    cout << "#                    #####   #######     ####     #    #          ######     #                          #" << endl;
    gotoxy(20, 23);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 24);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 25);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 26);
    cout << "#   Name:                                                          Account Type:                        #" << endl;
    gotoxy(20, 27);
    cout << "#    ___________________________________________                    _________________________           #" << endl;
    gotoxy(20, 28);
    cout << "#   |                                           |                  |                         |          #" << endl;
    gotoxy(20, 29);
    cout << "#   |                                           |                  |                         |          #" << endl;
    gotoxy(20, 30);
    cout << "#   |___________________________________________|                  |_________________________|          #" << endl;
    gotoxy(20, 31);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 32);
    cout << "#   CNIC (without dashes):                                                                              #" << endl;
    gotoxy(20, 33);
    cout << "#    _______________________________________                                                            #" << endl;
    gotoxy(20, 34);
    cout << "#   |                                       |                                                           #" << endl;
    gotoxy(20, 35);
    cout << "#   |                                       |                                                           #" << endl;
    gotoxy(20, 36);
    cout << "#   |_______________________________________|                                                           #" << endl;
    gotoxy(20, 37);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 38);
    cout << "#    Password:                                            Confirm Password:                             #" << endl;
    gotoxy(20, 39);
    cout << "#     __________________________________                   __________________________________           #" << endl;
    gotoxy(20, 40);
    cout << "#    |                                  |                 |                                  |          #" << endl;
    gotoxy(20, 41);
    cout << "#    |                                  |                 |                                  |          #" << endl;
    gotoxy(20, 42);
    cout << "#    |__________________________________|                 |__________________________________|          #" << endl;
    gotoxy(20, 43);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 44);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 45);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 46);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 47);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 48);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 49);
    cout << "#------------------------------------------------ Action -----------------------------------------------#" << endl;
    gotoxy(20, 50);
    cout << "#                                     ______________________________                                    #" << endl;
    gotoxy(20, 51);
    cout << "#                                    |                              |                                   #" << endl;
    gotoxy(20, 52);
    cout << "#                                    |                              |                                   #" << endl;
    gotoxy(20, 53);
    cout << "#                                    |______________________________|                                   #" << endl;
    gotoxy(20, 54);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 55);
    cout << "#########################################################################################################";
    name = information(28, 29);
    type = information(90, 29);
    cnic = information(28, 35);
    password = information(28, 41);
    passwordconfirm = information(81, 41);
    if (type == "user")
    {
        system("cls");
        user(name, type);
    }
}
//                                               Login display function
void login()
{
    system("cls");
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
    // login();
    name = information(50, 26);
    password = information(50, 32);
    //  bool flag = signIn(name, password);
    //     showMessage(flag);
    type = information(74, 35);
    if (type == "user")
    {
        user(name, type);
    }
}
//                                                  DISPLAY SCREEN
void display()
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
    cout << "#                       ##   ##  ### ###  ####      ## ##    ## ##   ##   ##  ### ###                   #" << endl;
    gotoxy(20, 18);
    cout << "#                       ##   ##   ##       ##      ##       ##   ##  # ### #   ##                       #" << endl;
    gotoxy(20, 19);
    cout << "#                       ##   ##   ##  ##   ##      ##   ##  ##   ##   ## ##    ##  ##                   #" << endl;
    gotoxy(20, 20);
    cout << "#                       ## # ##   ## ##    ##      ##       ##   ##  ## # ##   ## ##                    #" << endl;
    gotoxy(20, 21);
    cout << "#                       # ### #   ##       ##      ##       ##   ##  ##   ##   ##                       #" << endl;
    gotoxy(20, 22);
    cout << "#                        ## ##    ##  ##   ##  ##  ##   ##  ##   ##  ##   ##   ##  ##                   #" << endl;
    gotoxy(20, 23);
    cout << "#                       ##   ##  ### ###  ### ###   ## ##    ## ##   ##   ##  ### ###                   #" << endl;
    gotoxy(20, 24);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 25);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 26);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 27);
    cout << "#              ##              ## ##     ####    ## ##   ###  ##  ##  ###  ### ##                       #" << endl;
    gotoxy(20, 28);
    cout << "#             ###             ##   ##     ##    ##   ##    ## ##  ##   ##   ##  ##                      #" << endl;
    gotoxy(20, 29);
    cout << "#              ##             ####        ##    ##        # ## #  ##   ##   ##  ##                      #" << endl;
    gotoxy(20, 30);
    cout << "#              ##              #####      ##    ##  ###   ## ##   ##   ##   ##  ##                      #" << endl;
    gotoxy(20, 31);
    cout << "#              ##                 ###     ##    ##   ##   ##  ##  ##   ##   ## ##                       #" << endl;
    gotoxy(20, 32);
    cout << "#              ##             ##   ##     ##    ##   ##   ##  ##  ##   ##   ##                          #" << endl;
    gotoxy(20, 33);
    cout << "#             ####             ## ##     ####    ## ##   ###  ##   ## ##   ####                         #" << endl;
    gotoxy(20, 34);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 35);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 36);
    cout << "#               ##            ####       ## ##    ## ##  ####   ###   ##                                #" << endl;
    gotoxy(20, 37);
    cout << "#             ## ##            ##       ##   ##  ##   ##   ##    ##   ##                                #" << endl;
    gotoxy(20, 38);
    cout << "#            ##  ##            ##       ##   ##  ##   ##   ##     ##  ##                                #" << endl;
    gotoxy(20, 39);
    cout << "#                ##            ##       ##   ##  ##        ##    # ##  #                                #" << endl;
    gotoxy(20, 40);
    cout << "#              ##              ##       ##   ##  ##  ###   ##    ##  ###                                #" << endl;
    gotoxy(20, 41);
    cout << "#            #   ##            ##   ##  ##   ##  ##   ##   ##    ##   ##                                #" << endl;
    gotoxy(20, 42);
    cout << "#            ######            ### ###   ## ##    ## ##  ####   ###   ##                                #" << endl;
    gotoxy(20, 43);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 44);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 45);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 46);
    cout << "#                                                                                                       #" << endl;
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
    cout << "#                                                                                    Press 4 to exit    #" << endl;
    gotoxy(20, 55);
    cout << "#########################################################################################################";
    options = option(72, 52);
    if (options == 4)
    {
        system("cls");
        exit(0);
    }
    if (options == 2)
    {
        system("cls");
        login();
    }
    if (options == 1)
    {
        system("cls");
        signup();
    }
}
//                                                  User information
void userinfo(string name)
{
    system("cls");
    while (true)
    {

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
        cout << "#     ####  ###  ##  ### ###   ## ##   ### ##   ##   ##    ##     #### ##   ####   ## ##   ###  ##      #" << endl;
        gotoxy(20, 18);
        cout << "#      ##     ## ##   ##  ##  ##   ##   ##  ##   ## ##      ##    # ## ##    ##   ##   ##    ## ##      #" << endl;
        gotoxy(20, 19);
        cout << "#      ##    # ## #   ##      ##   ##   ##  ##  # ### #   ## ##     ##       ##   ##   ##   # ## #      #" << endl;
        gotoxy(20, 20);
        cout << "#      ##    ## ##    ## ##   ##   ##   ## ##   ## # ##   ##  ##    ##       ##   ##   ##   ## ##       #" << endl;
        gotoxy(20, 21);
        cout << "#      ##    ##  ##   ##      ##   ##   ## ##   ##   ##   ## ###    ##       ##   ##   ##   ##  ##      #" << endl;
        gotoxy(20, 22);
        cout << "#      ##    ##  ##   ##      ##   ##   ##  ##  ##   ##   ##  ##    ##       ##   ##   ##   ##  ##      #" << endl;
        gotoxy(20, 23);
        cout << "#     ####  ###  ##  ####      ## ##   #### ##  ##   ##  ###  ##   ####     ####   ## ##   ###  ##      #" << endl;
        gotoxy(20, 24);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 25);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 26);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 27);
        cout << "#   Name:                                                          Account Type:                        #" << endl;
        gotoxy(20, 28);
        cout << "#    ___________________________________________                    _________________________           #" << endl;
        gotoxy(20, 29);
        cout << "#   |                                           |                  |                         |          #" << endl;
        gotoxy(20, 30);
        cout << "#   |   " << setw(27) << left << name << "             |                  |   " << setw(22) << left << type << "|          #" << endl;
        gotoxy(20, 31);
        cout << "#   |___________________________________________|                  |_________________________|          #" << endl;
        gotoxy(20, 32);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 33);
        cout << "#   CNIC:                                                                                               #" << endl;
        gotoxy(20, 34);
        cout << "#    _______________________________________                    ##################################      #" << endl;
        gotoxy(20, 35);
        cout << "#   |                                       |                   #                                #      #" << endl;
        gotoxy(20, 36);
        cout << "#   |   " << setw(27) << left << cnic << "         |                   #   Press 1 to edit name         #      #" << endl;
        gotoxy(20, 37);
        cout << "#   |_______________________________________|                   #                                #      #" << endl;
        gotoxy(20, 38);
        cout << "#                                                               #   Press 2 to edit cnic no.     #      #" << endl;
        gotoxy(20, 39);
        cout << "#    Password:                                                  #                                #      #" << endl;
        gotoxy(20, 40);
        cout << "#     __________________________________                        #   Press 3 to change Password   #      #" << endl;
        gotoxy(20, 41);
        cout << "#    |                                  |                       #                                #      #" << endl;
        gotoxy(20, 42);
        cout << "#    |  " << setw(31) << left << password << " |                       #  Press 0 to back to homepage   #      #" << endl;
        gotoxy(20, 43);
        cout << "#    |__________________________________|                       #                                #      #" << endl;
        gotoxy(20, 44);
        cout << "#                                                               ##################################      #" << endl;
        gotoxy(20, 45);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 46);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 47);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 48);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 49);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 50);
        cout << "#                                     ______________________________                                    #" << endl;
        gotoxy(20, 51);
        cout << "#                                    |                              |                                   #" << endl;
        gotoxy(20, 52);
        cout << "#                                    |                              |                                   #" << endl;
        gotoxy(20, 53);
        cout << "#                                    |______________________________|                                   #" << endl;
        gotoxy(20, 54);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 55);
        cout << "#########################################################################################################";
        options = option(72, 52);
        if (options == 1)
        {
            gotoxy(28, 30);
            cout << setw(27) << " ";
            name = information(28, 30);
        }
        else if (options == 2)
        {
            gotoxy(28, 36);
            cout << setw(27) << " ";
            cnic = information(28, 36);
        }
        else if (options == 3)
        {
            gotoxy(28, 42);
            cout << setw(31) << " ";
            password = information(28, 42);
        }
        else if (options == 0)
        {
            system("cls");
            user(name, type);
        }
    }
}
//                                                    Tranfer Money
void transfermoney(string name)
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
    cout << "#--------------------------------------------- MONEY TRANSFER ------------------------------------------#" << endl;
    gotoxy(20, 18);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 19);
    cout << "#    HI! " << setw(27) << left << name << "                                                                    #" << endl;
    gotoxy(20, 20);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 21);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 22);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 23);
    cout << "#  1) View your Account Balance                     ##    2) Add receiving account                      #" << endl;
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
    cout << "#    => View Account /IBAN number                   ##     => View your accounts                        #" << endl;
    gotoxy(20, 33);
    cout << "#    => Manage Settings                             ##     => Manage accounts                           #" << endl;
    gotoxy(20, 34);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 35);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 36);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 37);
    cout << "#  3) Send Money                                    ##   4) Back to homepage                            #" << endl;
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
    cout << "#    => Watch Transaction History                   ##    => Cancel money transfer                      #" << endl;
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
    if (options == 1)
    {
        system("cls");
        accountinfo();
    }
    else if (options == 2)
    {
        system("cls");
        addaccount();
    }
    else if (options == 3)
    {
    }
    else if (options == 4)
    {
        system("cls");
        user(name, type);
    }
}
//                                                 Account information
void accountinfo()
{

    system("cls");
    while (true)
    {
        string combined = name + cnic;
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
        cout << "#     ####  ###  ##  ### ###   ## ##   ### ##   ##   ##    ##     #### ##   ####   ## ##   ###  ##      #" << endl;
        gotoxy(20, 18);
        cout << "#      ##     ## ##   ##  ##  ##   ##   ##  ##   ## ##      ##    # ## ##    ##   ##   ##    ## ##      #" << endl;
        gotoxy(20, 19);
        cout << "#      ##    # ## #   ##      ##   ##   ##  ##  # ### #   ## ##     ##       ##   ##   ##   # ## #      #" << endl;
        gotoxy(20, 20);
        cout << "#      ##    ## ##    ## ##   ##   ##   ## ##   ## # ##   ##  ##    ##       ##   ##   ##   ## ##       #" << endl;
        gotoxy(20, 21);
        cout << "#      ##    ##  ##   ##      ##   ##   ## ##   ##   ##   ## ###    ##       ##   ##   ##   ##  ##      #" << endl;
        gotoxy(20, 22);
        cout << "#      ##    ##  ##   ##      ##   ##   ##  ##  ##   ##   ##  ##    ##       ##   ##   ##   ##  ##      #" << endl;
        gotoxy(20, 23);
        cout << "#     ####  ###  ##  ####      ## ##   #### ##  ##   ##  ###  ##   ####     ####   ## ##   ###  ##      #" << endl;
        gotoxy(20, 24);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 25);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 26);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 27);
        cout << "#   Account Holder's Name:                                                                              #" << endl;
        gotoxy(20, 28);
        cout << "#    ___________________________________________                                                        #" << endl;
        gotoxy(20, 29);
        cout << "#   |                                           |                                                       #" << endl;
        gotoxy(20, 30);
        cout << "#   |   " << setw(27) << left << name << "             |                                                       #" << endl;
        gotoxy(20, 31);
        cout << "#   |___________________________________________|                                                       #" << endl;
        gotoxy(20, 32);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 33);
        cout << "#   CNIC:                                                                                               #" << endl;
        gotoxy(20, 34);
        cout << "#    _______________________________________                                                            #" << endl;
        gotoxy(20, 35);
        cout << "#   |                                       |                                                           #" << endl;
        gotoxy(20, 36);
        cout << "#   |   " << setw(27) << left << cnic << "         |                                                           #" << endl;
        gotoxy(20, 37);
        cout << "#   |_______________________________________|                                                           #" << endl;
        gotoxy(20, 38);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 39);
        cout << "#    Account number / IBAN number:                                                                      #" << endl;
        gotoxy(20, 40);
        cout << "#     __________________________________                                                                #" << endl;
        gotoxy(20, 41);
        cout << "#    |                                  |                                                               #" << endl;
        gotoxy(20, 42);
        cout << "#    |  " << setw(31) << left << combined << " |                                                               #" << endl;
        gotoxy(20, 43);
        cout << "#    |__________________________________|                                                               #" << endl;
        gotoxy(20, 44);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 45);
        cout << "#                                                                 press any key to back to homepage     #" << endl;
        gotoxy(20, 46);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 47);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 48);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 49);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 50);
        cout << "#        Instructions:                                                                                  #" << endl;
        gotoxy(20, 51);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 52);
        cout << "#           1) Share your account number / IBAN to recieve money                                        #" << endl;
        gotoxy(20, 53);
        cout << "#           2) Don't share account informations to untrusted person                                     #" << endl;
        gotoxy(20, 54);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 55);
        cout << "#########################################################################################################";
        gotoxy(120, 45);
        char key = getch();
        if (key)
        {
            system("cls");
            transfermoney(name);
        }
    }
}
//                                                add recieving account
void addaccount()
{
    system("cls");
    while (true)
    {
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
        cout << "#     ##      ## ##    ## ##    ####   ##   ##  ###  ##  #### #    ####   ###  ##  ### ###   ## ##      #" << endl;
        gotoxy(20, 18);
        cout << "#     ##    ##   ##  ##   ##  ##   ##  ##   ##    ## ##  # ## ##    ##      ## ##   ##  ##  ##   ##     #" << endl;
        gotoxy(20, 19);
        cout << "#   ## ##   ##       ##       ##   ##  ##   ##   # ## #    ##       ##     # ## #   ##      ##   ##     #" << endl;
        gotoxy(20, 20);
        cout << "#   ##  ##  ##       ##       ##   ##  ##   ##   ## ##     ##       ##     ## ##    ## ##   ##   ##     #" << endl;
        gotoxy(20, 21);
        cout << "#   ## ###  ##       ##       ##   ##  ##   ##   ##  ##    ##       ##     ##  ##   ##      ##   ##     #" << endl;
        gotoxy(20, 22);
        cout << "#   ##  ##  ##   ##  ##   ##  ##   ##  ##   ##   ##  ##    ##       ##     ##  ##   ##      ##   ##     #" << endl;
        gotoxy(20, 23);
        cout << "#  ###  ##   ## ##    ## ##    ## ##    ## ##   ###  ##   ####     ####   ###  ##  ####      ## ##      #" << endl;
        gotoxy(20, 24);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 25);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 26);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 27);
        cout << "#   Account Holder's Name:                                          Bank Name:                          #" << endl;
        gotoxy(20, 28);
        cout << "#    ___________________________________________                    _________________________           #" << endl;
        gotoxy(20, 29);
        cout << "#   |                                           |                  |                         |          #" << endl;
        gotoxy(20, 30);
        cout << "#   |   " << setw(27) << left << add_bank << "             |                  |  " << setw(23) << left << add_bank << "|          #" << endl;
        gotoxy(20, 31);
        cout << "#   |___________________________________________|                  |_________________________|          #" << endl;
        gotoxy(20, 32);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 33);
        cout << "#   Account Number:                                                Instructions:                        #" << endl;
        gotoxy(20, 34);
        cout << "#    _______________________________________                      1) Add new bank                       #" << endl;
        gotoxy(20, 35);
        cout << "#   |                                       |                     2) Remove bank                        #" << endl;
        gotoxy(20, 36);
        cout << "#   |   " << setw(27) << left << add_bank << "         |                     3) Back to trading page               #" << endl;
        gotoxy(20, 37);
        cout << "#   |_______________________________________|                                                           #" << endl;
        gotoxy(20, 38);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 39);
        cout << "#----------------------------------------------- Bank Accounts -----------------------------------------#" << endl;
        gotoxy(20, 40);
        cout << "#   Bank No.        Account holder name            Account Number                 Bank Name             #" << endl;
        gotoxy(20, 41);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 42);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 43);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 44);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 45);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 46);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 47);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 48);
        cout << "#########################################################################################################" << endl;
        gotoxy(20, 49);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 50);
        cout << "#                                     ______________________________                                    #" << endl;
        gotoxy(20, 51);
        cout << "#                                    |                              |                                   #" << endl;
        gotoxy(20, 52);
        cout << "#                                    |                              |                                   #" << endl;
        gotoxy(20, 53);
        cout << "#                                    |______________________________|                                   #" << endl;
        gotoxy(20, 54);
        cout << "#                                                                                                       #" << endl;
        gotoxy(20, 55);
        cout << "#########################################################################################################";
        options = option(72, 52);
        if (options == 1)
        {
            int k = 1;
            bankadd();
                int i=0;
                int j=3;
            while (true)
            {
                int z = 0;
                gotoxy(25, 41 + k);
                cout << k;
                for (i ; i < j; i++)
                {
                    gotoxy(42 + z, 41 + k);
                    cout << bankdetail[i];
                    z += 30;
                }
                    j+=3;
                k = k + 1;
               char key = option(72, 52);
                if (key == 1)
                {
                    bankadd();
                }
                if (key == 3)
                {
                    system("cls");
                    transfermoney(name);
                }
            }
        }
        // else if (options == 2)
        // {

        // }
        else if (options == 3)
        {
            system("cls");
            transfermoney(name);
        }
    }
}
    //                                                     input bank
    void bankadd()
    {
        int j = 1;
        gotoxy(28, 30);
        cout << setw(27) << " ";
        add_bank = information(28, 30);
        bankdetails(add_bank);
        gotoxy(28, 36);
        cout << setw(31) << " ";
        add_bank = information(28, 36);
        bankdetails(add_bank);
        gotoxy(120, 30);
        cout << setw(27) << " ";
        add_bank = information(90, 30);
        bankdetails(add_bank);
        j++;
    }
    //                                                  Confirm password
    bool passworddisplay()
    {
        system("cls");
        gotoxy(20, 10);
        cout << "####################################################################################################################################" << endl;
        gotoxy(20, 11);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 12);
        cout << "#       ## ##   ### ###   ## ##   ##  ###  ### ##    ###  #### ##  ##  ##      ## ##   ###  ##  ### ###   ## ##   ##  ###          #" << endl;
        gotoxy(20, 13);
        cout << "#      ##   ##   ##  ##  ##   ##  ##   ##   ##  ##   ##   # ## ##  ##  ##     ##   ##   ##  ##   ##  ##  ##   ##  ##  ##           #" << endl;
        gotoxy(20, 14);
        cout << "#      ####      ##      ##       ##   ##   ##  ##   ##     ##     ##  ##     ##        ##  ##   ##      ##       ## ##            #" << endl;
        gotoxy(20, 15);
        cout << "#       #####    ## ##   ##       ##   ##   ## ##    ##     ##      ## ##     ##        ## ###   ## ##   ##       ## ##            #" << endl;
        gotoxy(20, 16);
        cout << "#          ###   ##      ##       ##   ##   ## ##    ##     ##       ##       ##        ##  ##   ##      ##       ## ###           #" << endl;
        gotoxy(20, 17);
        cout << "#      ##   ##   ##  ##  ##   ##  ##   ##   ##  ##   ##     ##       ##       ##   ##   ##  ##   ##  ##  ##   ##  ##  ##           #" << endl;
        gotoxy(20, 18);
        cout << "#       ## ##   ### ###   ## ##    ## ##   #### ##  ####   ####      ##        ## ##   ###  ##  ### ###   ## ##   ##  ###          #" << endl;
        gotoxy(20, 19);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 20);
        cout << "####################################################################################################################################" << endl;
        gotoxy(20, 21);
        cout << "#------------------------------------------------- Confirm Password to Proceed ----------------------------------------------------#" << endl;
        gotoxy(20, 22);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 23);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 24);
        cout << "#                                        Password:                                                                                 #" << endl;
        gotoxy(20, 25);
        cout << "#                                        __________________________________________                                                #" << endl;
        gotoxy(20, 26);
        cout << "#                                       |                                          |                                               #" << endl;
        gotoxy(20, 27);
        cout << "#                                       |                                          |                                               #" << endl;
        gotoxy(20, 28);
        cout << "#                                       |__________________________________________|                                               #" << endl;
        gotoxy(20, 29);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 30);
        cout << "#                                                                                 " << setw(33) << right << passwordreturn << "                #" << endl;
        gotoxy(20, 31);
        cout << "#                                                                                                                                  #" << endl;
        gotoxy(20, 32);
        cout << "####################################################################################################################################";
        passwordcheck = information(70, 27);
        bool check = confirmpassword(passwordcheck);
        if (check)
        {
            passwordreturn = "";
            Sleep(100);
            return true;
        }
        else
        {
            passwordreturn = "Wrong password.Try again";
            return false;
        }
    }
    bool confirmpassword(string passwordchecker)
    {
        if (password == passwordchecker)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //                                                  accounts function
    void bankdetails(string variable)
    {

        bankdetail[x] = variable;
        x++;
    }
    //                                                   Gotoxy Function
    void gotoxy(int x, int y)
    {
        COORD coordinates;
        coordinates.X = x;
        coordinates.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
    }

    // // Function to check if a user already exists
    // bool userExists(const string& name, int pass) {
    //     for (int i = 0; i < userCount; i++) {
    //         if (userName[i] == name || userPass[i] == pass) {
    //             return true; // User already exists
    //         }
    //     }
    //     return false; // User does not exist
    // }

    // // Function to validate and handle sign-up
    // void signUp() {
    //     string user;
    //     int pass;

    //     cout << "User Name: ";
    //     cin >> userName[userCount];
    //     cout << "User Pass: ";
    //     cin >> userPass[userCount];
    //     cout << "User Role: ";
    //     cin >> userRole[userCount];

    //     user = userName[userCount];
    //     pass = userPass[userCount];

    //     if (userExists(user, pass)) {
    //         cout << "Sorry, a user already exists with the same username or password." << endl;
    //     } else {
    //         cout << "Your account has been successfully created." << endl;
    //         userCount++;
    //     }
    // }

    // // Function to validate and handle sign-in
    // bool signIn(const string& name, string pass) {
    //     for (int i = 0; i < userCount; i++) {
    //         if (userName[i] == name && userPass[i] == pass) {
    //             return true; // Sign-in successful
    //         }
    //     }
    //     return false; // Invalid credentials
    // }

    // // void showMessage(bool flag) {
    //     if (flag) {
    //         cout << "Logged In" << endl;
    //     } else {
    //         cout << "Invalid credentials" << endl;
    //     }
    // }