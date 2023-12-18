#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <csignal>
#include <fstream>
using namespace std;
//                                             Functions
void gotoxy(int x, int y);
void login();
string information(int x, int y);
void user(string name, string type);
void ViewATM(string named, string card, string ccv, string status);
bool confirmpassword(string passwordcheck, string password);
void display();
void sendmoney(string &add_bank);
void signup();
void bankapp();
void thanku();
void optionsdisplay();
void signuplogin();
string option(int x, int y);
bool passworddisplay(string passwordcheck, string password, string passwordreturn);
void freeze(bool freeze, bool &num);
void userinfo(string name, string type, string cnic, string password);
void transfermoney(string name);
void accountinfo(string &name, string &cnic, string &combined, int &balance);
void addaccount(string &add_bank);
void bankadd(string bankholdername[], string banknumber[], string bankname[], string add_bank, int &x, int accountsindex[]);
void bankdetails(string bankdetail[], string variable, int &x);
void display(int x, int y);
void displaypasswordcheck(string passwordreturn);
void updateInformation(string &info, int x, int y,int index);
void displayFreezeScreen();
void displayUnfreezeScreen();
void admin(string &name, string &type);
void manageusers();
int isAlphabet(string value);
void search(int &fileindex);
void writeData(string names, string passwords, string cnic, string role);
string getField(string record, int field);
bool hasNoInteger(string &value);
void displaymoneymanage();
void displaymoneymanageadmin();
bool comma(string &field);
//                                                 array function
void readArrayFromFile(string bankholders[], string bankholder[], string banknumber[], string bankname[], int index[], int size, string name);
void printArrayToFile(string name, string bankholder[], string banknumber[], string bankname[], int index[], int size);
void readData(string names[], string passwords[], string cnic[], string role[], int &index);
void deleteuser(string name[], string cnic[], string role[], string passwordarray[], int index);
void viewRecords(string userNames[], string useraccount[], string role[]);
void deleteEntity(string bankholdername[], string banknumber[], string bankname[], int indexs[], int index);
void printArray(string bankholdername[], string banknumber[], string bankname[], int index[]);
int searchArray(string arr[], string object, int &indexCount);
bool log(string name, string password, string &cnic, string cnicarray[], string namearray[], string &role, string rolearray[], string passwordarray[], int &indexCount, int &data_index, int fileindex);
void sign_string(string name, string password, string cnic, string role, string namearray[], string passwordarray[], string rolearray[], string cnicarray[], int &indexCount);
void ATMoptions(string name, string type, string named, string card, string ccv, string passwordcheck, string password, int options, string passwordreturn, string &status);
void edit_string(string &name, string &cnic, string &password, string &role, string namearray[], string passwordarray[], string rolearray[], string cnicarray[], int &indexCount);

void saveDataToFile(string usernames[], double balances[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_USERS, int &limit);
void loadDataFromFile(string usernames[], double balances[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_USERS, int &limit);
void viewAllUsers(string usernames[], double balances[], int MAX_USERS,string name,bool deposit);
void viewAllTransactions(string usernames[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_USERS, string type, string name);
void addTransaction(int userIndex, const string &description, double amount, string usernames[], double balances[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_DESCRIPTION_LENGTH, int MAX_USERS, int limit);
int findUserIndexByUsername(const string &username, string usernames[], int MAX_USERS);
// Color constants
string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}
int black = 0, blue = 1, green = 2, cyan = 3, red = 4, magenta = 5, brown = 6, lightwhite = 7, darkwhite = 8, lightblue = 9, lightgreen = 10, lightcyan = 11, lightred = 12, lightmagenta = 13, yellow = 14, white = 15;
BOOL CtrlHandler(DWORD ctrlType)
{
    switch (ctrlType)
    {
    case CTRL_C_EVENT:
        system("cls");
        thanku();
        gotoxy(30, 30);
        setcolor(lightgreen);
        cout << "Thank you for using our application";
        setcolor(15);
        exit(0);
        Sleep(1000);
        return TRUE;
    default:

        return FALSE;
    }
}

//                                                       Search Array
int searchArray(string arr[], string object, int &indexCount)
{
    for (int i = 0; i <= indexCount; i++)
    {
        system("cls");
        if (arr[i] == object)
        {

            return i;
        }
    }
    return -1;
}
//                                                  Main function
main()
{
    if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
    {

        return 1;
    }
    //                                                    Variables
    string name;
    bool num = true;
    bool check;
    string type;
    string passwordconfirm;
    string passwordcheck = "Enter password to proceed";
    string passwordreturn;
    string cnic;
    string password;
    string loginaction;
    string named = "************************";
    string card = "**************************";
    string ccv = "****";
    string status = "Neutral";
    int options = 6;
    int userCount = 0;
    int indexCount = 0;
    int dataIndex = 0;
    string options2 = "";
    string add_bank;
    int accountsindex[10];
    string bankholder[10];
    string banknumber[10];
    string bankname[10];
    string namearray[100];
    string passwordarray[100];
    string rolearray[100];
    string cnicarray[100];
    string bank_holders[100];
    int x = 0;
    int fileindex = 0;
    bool logincheck = false;
    int MAX_USERS = 10;
    int MAX_TRANSACTIONS = 10;
    int MAX_DESCRIPTION_LENGTH = 50;
    double balances[MAX_USERS];
    int limit = 10;
    int balance = 0;
    string transactionHistoriesUsernames[MAX_USERS];
    string transactionDescriptions[MAX_USERS][100];
    double transactionAmounts[MAX_USERS][100];
    int transactionCounts[MAX_USERS];

    for (int i = 0; i < 10; ++i)
    {
        if (i > 4)
        {
            bankholder[i] = "";
            banknumber[i] = "";
            bankname[i] = "";
            accountsindex[i] = i - 4;
        }
        else
        {
            bankholder[i] = "";
            banknumber[i] = "";
            bankname[i] = "";
            accountsindex[i] = 0;
        }
    }

    //                           ██████  ██   ██     ███████ ██      ███████ ███    ███ ███████ ███    ██ ████████ ███████ 
    //                          ██    ██ ██  ██      ██      ██      ██      ████  ████ ██      ████   ██    ██    ██      
    //                          ██    ██ █████       █████   ██      █████   ██ ████ ██ █████   ██ ██  ██    ██    ███████ 
    //                          ██    ██ ██  ██      ██      ██      ██      ██  ██  ██ ██      ██  ██ ██    ██         ██ 
    //                           ██████  ██   ██     ███████ ███████ ███████ ██      ██ ███████ ██   ████    ██    ███████ 

    //                                                     Display screen
    loadDataFromFile(namearray, balances, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_USERS, limit);
    if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
    {

        exit(0);
    }
    else
    {

        while (true)
        {

            // Display screen
            if (options == 6)
            {
                system("cls");
                readData(namearray, passwordarray, cnicarray, rolearray, fileindex);
                display();
                bankapp();
                signuplogin();
                optionsdisplay();
                options2 = option(72, 52);
                options = isAlphabet(options2);
            }

            // Exit
            else if (options == 4)
            {
                system("cls");
                thanku();
                gotoxy(30, 30);
                setcolor(lightgreen);
                cout << "Thank you for using our application";
                setcolor(15);
                Sleep(500);
                gotoxy(40, 31);
                setcolor(lightgreen);
                cout << "Exiting...";
                setcolor(15);
                Sleep(1000);
                exit(0);
            }

            // Sign up screen
            else if (options == 1)
            {
                system("cls");
                signup();
                
                setcolor(lightcyan);
                name = information(28, 29);
                setcolor(15);
                if (hasNoInteger(name)&& comma(name))
                {
                    if (name.length() > 10)
                    {
                        gotoxy(60, 52);
                        setcolor(4);
                        cout << "Username is too long";
                        setcolor(15);
                        options = 1;
                        Sleep(1000);
                    }
                    else
                    {
                        setcolor(lightcyan);
                        type = information(90, 29);
                        setcolor(15);
                        if (type != "admin" && type != "user" && type != "ADMIN" && type != "USER" && type != "Admin" && type != "User"&& !comma(type))
                        {
                            gotoxy(60, 52);
                            setcolor(4);
                            cout << "Invalid Role";
                            setcolor(15);
                            Sleep(500);
                        }
                        else
                        {
                            setcolor(lightcyan);
                            cnic = information(28, 35);
                            setcolor(15);

                            if (cnic.length() != 13&& comma(cnic))
                            {

                                gotoxy(60, 52);
                                setcolor(4);
                                cout << "Invalid CNIC";
                                setcolor(15);
                                Sleep(500);
                            }
                            else
                            {
                                setcolor(lightcyan);
                                password = information(28, 41);
                                passwordconfirm = information(81, 41);
                                setcolor(15);
                                if (password.length() < 8 || password.length() > 16)
                                {
                                    gotoxy(60, 52);
                                    setcolor(4);
                                    cout << "Password 8-16 characters long";
                                    setcolor(15);
                                    Sleep(500);
                                }
                                if (password.length() >= 8 && password.length() <= 16&& comma(password))
                                {
                                    if (searchArray(namearray, name, fileindex) == -1 && searchArray(cnicarray, cnic, fileindex) == -1)
                                    {
                                        if (password != passwordconfirm)
                                        {
                                            gotoxy(60, 52);
                                            setcolor(4);
                                            cout << "Password does not match";
                                            setcolor(15);
                                            Sleep(500);
                                        }
                                        else
                                        {
                                            sign_string(name, password, cnic, type, namearray, passwordarray, rolearray, cnicarray, indexCount);
                                            gotoxy(60, 52);
                                            setcolor(2);
                                            cout << "Successfully Registered";
                                            setcolor(15);
                                            Sleep(1000);
                                            writeData(name, password, cnic, type);
                                            options = 6;
                                        }
                                    }
                                }
                                else
                                {
                                    gotoxy(60, 52);
                                    setcolor(4);
                                    cout << "Username already exists";
                                    setcolor(15);
                                    options = 1;
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                }

                else
                {
                    gotoxy(59, 52);
                    setcolor(4);
                    cout << "Username has integer or comma";
                    setcolor(15);
                    options = 1;
                    Sleep(1000);
                }
            }

            // Login
            else if (options == 2)
            {
                login();
                setcolor(lightmagenta);
                name = information(50, 26);
                password = information(50, 32);
                setcolor(15);
                // Login check array
                bool login_check = log(name, password, cnic, cnicarray, namearray, type, rolearray, passwordarray, indexCount, dataIndex, fileindex);
                if (login_check)
                {
                    login();
                    gotoxy(60, 38);
                    setcolor(2);
                    cout << "Successfully! Logged In";
                    setcolor(15);
                    logincheck = true;
                    loginaction = "";
                    Sleep(1000);
                }
                else
                {
                    logincheck = false;
                    login();
                    gotoxy(48, 40);
                    setcolor(4);
                    gotoxy(60, 38);
                    cout << "Invalid Credentials! Try Again.";
                    setcolor(15);
                    Sleep(1000);
                    gotoxy(60, 38);
                    cout << "                                 ";
                }
            }

            else
            {
                gotoxy(70, 57);
                cout << "Select a valid option";
                options = 6;
                Sleep(1000);
            }

            // User menu

            if (logincheck)
            {
                while (true)
                {
                    //                                                   admin
                    if (type == "admin" || type == "ADMIN")
                    {
                        system("cls");
                        admin(name, type);
                        options2 = option(72, 52);
                        options = isAlphabet(options2);
                        if (options == 1)
                        {
                            system("cls");
                            while (true)
                            {
                                userinfo(name, type, cnic, password);
                                bankapp();
                                options2 = option(72, 52);
                                options = isAlphabet(options2);
                                if (options == 1)
                                {
                                    updateInformation(name, 28, 30,0);
                                }
                                else if (options == 2)
                                {
                                    updateInformation(cnic, 28, 36,1);
                                }
                                else if (options == 3)
                                {
                                    updateInformation(password, 28, 42,2);
                                }
                                else if (options == 0)
                                {
                                    edit_string(name, password, cnic, type, namearray, passwordarray, rolearray, cnicarray, dataIndex);
                                    break;
                                }
                                else
                                {
                                    gotoxy(70, 53);
                                    cout << "Select a valid option";
                                    Sleep(1000);
                                }
                            }
                        }
                        else if (options == 2)
                        {
                            string variable;
                            while (true)
                            {
                                string keys = "";
                                system("cls");
                                manageusers();
                                viewRecords(namearray, cnicarray, rolearray);
                                keys = option(72, 56);
                                int key = isAlphabet(keys);
                                //                                   edit account
                                if (key == 1)
                                {
                                    gotoxy(65, 55);
                                    cout << "Select Bank Number";
                                    gotoxy(72, 56);
                                    cout << " ";
                                    string indexst = "";
                                    indexst = option(72, 56);
                                    int index = isAlphabet(indexst);
                                    index -= 1;
                                    variable = information(28, 43);
                                    if(comma(variable)){

                                    bankdetails(namearray, variable, index);
                                    variable = information(28, 49);
                                    if(comma(variable)){
                                    bankdetails(cnicarray, variable, index);
                                    variable = information(90, 43);
                                    if(comma(variable)&& variable=="admin" && variable=="user" && variable=="ADMIN" && variable=="USER" && variable=="Admin" && variable=="User"){
                                    bankdetails(rolearray, variable, index);
                                    viewRecords(namearray, cnicarray, rolearray);
                                    }
                                    else{
                                        gotoxy(60, 52);
                                        cout<<"Invalid input";
                                        Sleep(1000);
                                    }


                                    }
                                    else{
                                        gotoxy(60, 52);
                                        cout<<"Invalid input";
                                        Sleep(1000);
                                    }
                                }
                                else{
                                    gotoxy(60, 52);
                                        cout<<"Invalid input";
                                        Sleep(1000);
                                }
                                }
                                //                                  back to admin page
                                if (key == 0)
                                {
                                    break;
                                }
                                //                                     delete account
                                if (key == 2)
                                {
                                    gotoxy(65, 55);
                                    cout << "Select Bank Number";
                                    gotoxy(72, 56);
                                    cout << " ";
                                    string key3 = option(72, 56);
                                    int index = isAlphabet(key3);
                                    index -= 1;
                                    deleteuser(namearray, cnicarray, rolearray, passwordarray, index);
                                    system("cls");
                                    manageusers();
                                    viewRecords(namearray, cnicarray, rolearray);
                                }
                                else
                                {
                                    gotoxy(90, 53);
                                    cout << "Select a valid option";
                                    Sleep(1000);
                                }
                            }
                        }
                        //                                          exit
                        else if (options == 4)
                        {
                            system("cls");
                            exit(0);
                            break;
                        }

                        //                                         logout
                        else if (options == 5)
                        {
                            options = 6;
                            logincheck = false;
                            break;
                        }
                        //                                        money management
                        else if (options == 3)
                        {
                             for (int i = 0; i < 10; i++)
                            {
                                if (namearray[i] == name)
                                {
                                    balance = balances[i];
                                }
                            }
                            string username;
                            system("cls");
                            displaymoneymanageadmin();
                            string optionss = option(72, 52);
                            options = isAlphabet(optionss);
                            while (true)
                            {
                            gotoxy(30,27);
                            cout<<"Balance: "<<balance;
                                if (options == 1)
                                        {
                                            viewAllUsers(namearray, balances, MAX_USERS,name,false);
                                            gotoxy(60, 49);
                                            cout << "                                    ";
                                            gotoxy(60, 49);
                                            cout << "Enter the username: ";
                                            gotoxy(72, 52);
                                            cin >> username;
                                            gotoxy(72, 52);
                                            cout << "                    ";
                                            int userIndex = findUserIndexByUsername(username, namearray, MAX_USERS);
                                            string description;
                                            if (userIndex != -1 && username != name)
                                            {
                                                gotoxy(60, 49);
                                                cout << "                                    ";
                                                gotoxy(60, 49);
                                                cout << "Enter the transaction description:  ";
                                                cin.ignore();
                                                gotoxy(72, 52);
                                                getline(cin, description);
                                                if(comma(description)){

                                                gotoxy(72, 52);
                                                cout << "                    ";
                                                double amount;
                                                string amounts;
                                                gotoxy(60, 49);
                                                cout << "                                    ";
                                                gotoxy(60, 49);
                                                cout << "Enter the transaction amount: ";
                                                gotoxy(72, 52);
                                                cin >> amounts;
                                                if(comma(amounts)){
                                                try {
                                                    amount =stod(amounts);
                                                     if(amount>0 && amount<=balance && balance-amount>=0){
                                                    balance-=amount;
                                                     for (int i = 0; i < 10; i++)
                            {
                                if (namearray[i] == name)
                                {
                                balances[i]=balance;
                                }
                            }
                                                gotoxy(72, 52);
                                                cout << "                    ";
                                                addTransaction(userIndex, description, amount, namearray, balances, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_DESCRIPTION_LENGTH, MAX_USERS, limit);
                                                options = 3;
                                                Sleep(1000);
                                                break;
                                                }
                                                else{
                                                    gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                options=3;
                                                break;
                                                }
                                                }
                                                 catch (const std::invalid_argument& e) {
                                                 gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                } 
                                                catch (const std::out_of_range& e) {
                                                      gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                }
                                               
                                                }
                                                else{
                                                 gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                }
                                                }
                                                else{
                                                 gotoxy(70, 52);
                                                cout << "Invalid description";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                }
                                            }
                                            else
                                            {
                                                gotoxy(70, 52);
                                                cout << "User not found.";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                ";
                                            }
                                        }

                                //             view transaction histories
                                else if (options == 3)
                                {
                                    viewAllTransactions(namearray, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_USERS, type, name);
                                    gotoxy(60, 52);
                                    cout << "                        ";
                                    gotoxy(60, 52);
                                    cout << "Press any key to go back";
                                    getch();
                                    break;
                                }
                                else if (options == 2)
                                {
                                    gotoxy(65, 34);
                                    cout << "Transaction Limits" << endl;
                                    gotoxy(60, 36);
                                    cout << "Current Transaction limit: " << limit;
                                    gotoxy(60, 38);
                                    cout << "Enter new limit: ";
                                    cin >> limit;
                                    gotoxy(55, 52);
                                    cout << "                           ";
                                    gotoxy(55, 52);
                                    cout << "Limit changed successfully.";
                                    saveDataToFile(namearray, balances, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_USERS, limit);
                                    Sleep(1000);
                                    options = 3;
                                    break;
                                }
                                else if (options == 4)
                                {
                                    system("cls");
                                    options = 3;
                                    break;
                                }

                                else
                                {
                                    gotoxy(90, 53);
                                    cout << "Select a valid option";
                                    Sleep(1000);
                                    break;
                                }
                            }
                        }
                    }
                    if (type == "user" || type == "USER")
                    {
                        system("cls");
                        user(name, type);
                        options2 = option(72, 52);
                        options = isAlphabet(options2);
                        //                                           User menu tabs
                        //                                        user info edit tab
                        if (options == 1)
                        {
                            system("cls");
                            while (true)
                            {
                                setcolor(lightcyan);

                                userinfo(name, type, cnic, password);
                                bankapp();
                                setcolor(15);
                                options2 = option(72, 52);
                                options = isAlphabet(options2);
                                if (options == 1)
                                {
                                    updateInformation(name, 28, 30,0);
                                   
                                }
                                else if (options == 2)
                                {
                                    updateInformation(cnic, 28, 36,1);
                                }
                                else if (options == 3)
                                {
                                    updateInformation(password, 28, 42,2);
                                }
                                else if (options == 0)
                                {
                                    edit_string(name, password, cnic, type, namearray, passwordarray, rolearray, cnicarray, fileindex);
                                    break;
                                }
                                else
                                {
                                    gotoxy(70, 53);
                                    cout << "Select a valid option";
                                    Sleep(1000);
                                }
                            }
                        }
                        else if (options == 2)
                        {
                            system("cls");
                            ViewATM(named, card, ccv, status);
                            ATMoptions(name, type, named, card, ccv, passwordcheck, password, options, passwordreturn, status);
                        }
                        else if (options == 4)
                        {
                            system("cls");
                            exit(0);
                            break;
                        }
                        //                                         logout
                        else if (options == 5)
                        {
                            options = 6;
                            logincheck = false;
                            break;
                        }
                        //                                       send money
                        else if (options == 3)
                        {
                            for (int i = 0; i < 10; i++)
                            {
                                if (namearray[i] == name)
                                {
                                    balance = balances[i];
                                }
                            }

                            system("cls");
                            while (true)
                            {

                                transfermoney(name);
                                options2 = option(72, 52);
                                options = isAlphabet(options2);
                                //                                   account info
                                if (options == 1)
                                {
                                    system("cls");
                                    string combined = name + cnic;
                                    accountinfo(name, cnic, combined, balance);
                                    gotoxy(120, 45);
                                    char key = getch();
                                }
                                //                               add receiving account
                                else if (options == 2)
                                {
                                    system("cls");
                                    addaccount(add_bank);
                                    readArrayFromFile(bank_holders, bankholder, banknumber, bankname, accountsindex, 5, name);
                                    printArray(bankholder, banknumber, bankname, accountsindex);
                                    string opton = option(72, 52);
                                    options = isAlphabet(opton);
                                    if (options == 1)
                                    {
                                        bankadd(bankholder, banknumber, bankname, add_bank, x, accountsindex);
                                        while (true)
                                        {
                                            printArray(bankholder, banknumber, bankname, accountsindex);
                                            gotoxy(72, 52);
                                            cout << " ";
                                            string keys = option(72, 52);
                                            int key = isAlphabet(keys);
                                            if (key == 1)
                                            {
                                                bankadd(bankholder, banknumber, bankname, add_bank, x, accountsindex);
                                            }
                                            //                        delete account
                                            if (key == 2)
                                            {
                                                gotoxy(65, 51);
                                                cout << "Select Bank Number";
                                                gotoxy(72, 52);
                                                cout << " ";
                                                string indexss = option(72, 52);
                                                int index = isAlphabet(indexss);
                                                index -= 1;
                                                deleteEntity(bankholder, banknumber, bankname, accountsindex, index);
                                                system("cls");
                                                addaccount(add_bank);
                                                printArray(bankholder, banknumber, bankname, accountsindex);
                                            }
                                            if (key == 3)
                                            {
                                                system("cls");
                                                printArrayToFile(name, bankholder, banknumber, bankname, accountsindex, 5);
                                                break;
                                            }
                                        }
                                    }
                                }

                                //                                     send money
                                else if (options == 3)
                                {
                                    string username;
                                    system("cls");
                                    displaymoneymanage();
                                    string optionss = option(72, 52);
                                    options = isAlphabet(optionss);
                                    while (true)
                                    {
                                        if (options == 1)
                                        {
                                            viewAllUsers(namearray, balances, MAX_USERS,name,false);
                                            gotoxy(60, 49);
                                            cout << "                                    ";
                                            gotoxy(60, 49);
                                            cout << "Enter the username: ";
                                            gotoxy(72, 52);
                                            cin >> username;
                                            gotoxy(72, 52);
                                            cout << "                    ";
                                            int userIndex = findUserIndexByUsername(username, namearray, MAX_USERS);
                                            string description;
                                            if (userIndex != -1 && username != name)
                                            {
                                                gotoxy(60, 49);
                                                cout << "                                    ";
                                                gotoxy(60, 49);
                                                cout << "Enter the transaction description:  ";
                                                cin.ignore();
                                                gotoxy(72, 52);
                                                getline(cin, description);
                                                if(comma(description)){

                                                gotoxy(72, 52);
                                                cout << "                    ";
                                                double amount;
                                                string amounts;
                                                gotoxy(60, 49);
                                                cout << "                                    ";
                                                gotoxy(60, 49);
                                                cout << "Enter the transaction amount: ";
                                                gotoxy(72, 52);
                                                cin >> amounts;
                                                if(comma(amounts)){
                                                try {
                                                    amount =stod(amounts);
                                                    balance-=amount;
                                                     if(amount>0 && amount<=balance && balance-amount>=0){
                                                for (int i = 0; i < 10; i++)
                                                   {
                                                       if (namearray[i] == name)
                                                       {
                                                       balances[i]=balance;
                                                       }
                                                   }
                                                gotoxy(72, 52);
                                                cout << "                    ";
                                                addTransaction(userIndex, description, amount, namearray, balances, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_DESCRIPTION_LENGTH, MAX_USERS, limit);
                                                options = 3;
                                                Sleep(1000);
                                                break;
                                                }
                                                else{
                                                    gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                options=3;
                                                break;
                                                }
                                                } catch (const std::invalid_argument& e) {
                                                 gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                } catch (const std::out_of_range& e) {
                                                      gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                }
                                               
                                                }
                                                else{
                                                 gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                }
                                                }
                                                else{
                                                 gotoxy(70, 52);
                                                cout << "Invalid description";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                }
                                            }
                                            else
                                            {
                                                gotoxy(70, 52);
                                                cout << "User not found.";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                ";
                                            }
                                        }

                                        //             view transaction histories
                                        else if (options == 3)
                                        {
                                            viewAllTransactions(namearray, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_USERS, type, name);
                                            gotoxy(60, 52);
                                            cout << "                        ";
                                            gotoxy(60, 52);
                                            cout << "Press any key to go back";
                                            getch();
                                            break;
                                        }
                                        else if (options == 2)
                                        {
                                            gotoxy(65, 34);
                                            cout << "                       " << endl;
                                            gotoxy(65, 34);
                                            cout << "Deposit Money" << endl;
                                            gotoxy(42, 38);
                                            cout << setw(26) << "Username" << setw(33) << "Balance" ;
                                            gotoxy(42, 40);
                                              cout << setw(26) <<name << setw(30) << fixed << setprecision(2) << balance << endl;
                                            gotoxy(42,45);
                                            cout<<"Press 1 to deposit 2 to back";
                                            gotoxy(72,52);
                                            cout<<"  ";
                                            string opton = option(72, 52);
                                            options = isAlphabet(opton);
                                            if (options == 1)
                                            {
                                                gotoxy(60, 49);
                                                cout << "                                    ";
                                                gotoxy(60, 49);
                                                cout << "Enter the amount: ";
                                                gotoxy(72, 52);
                                                string amounteds;
                                                cin >> amounteds;
                                                double amounted;
                                                try
                                                {
                                                amounted = stod(amounteds);
                                                 if(amounted>0){
                                                gotoxy(72, 52);
                                                cout << "                    ";
                                        for (int i = 0; i < 10; i++)
                                        {
                                          if (namearray[i] == name)
                                            {
                                         balances[i]=balance;
                                             }
                                               }
                                                addTransaction(findUserIndexByUsername(name, namearray, MAX_USERS), "Deposit", amounted, namearray, balances, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_DESCRIPTION_LENGTH, MAX_USERS, limit);
                                                
                                                Sleep(1000);
                                               break;
                                                }
                                                else{
                                                    gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                options=2;
                                                break;
                                                }
                                                }
                                                catch (const std::invalid_argument& e) {
                                                 gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                options=2;
                                                Sleep(1000);
                                                break;

                                                } catch (const std::out_of_range& e) {
                                                      gotoxy(70, 52);
                                                cout << "Invalid amount";
                                                Sleep(1000);
                                                gotoxy(70, 52);
                                                cout << "                     ";
                                                options=2;
                                                Sleep(1000);
                                                break;

                                                }
                                                
                                               
                                            }
                                            else if (options == 2)
                                            {
                                                system("cls");
                                                options = 3;
                                                break;
                                            }
                                            else
                                            {
                                                gotoxy(90, 53);
                                                cout << "Select a valid option";
                                                Sleep(1000);
                                                break;
                                            }
                                        }
                                        else if (options == 4)
                                        {
                                            system("cls");
                                            options = 3;
                                            break;
                                        }

                                        else
                                        {
                                            gotoxy(100, 53);
                                            cout << "Select a valid option";
                                            Sleep(1000);
                                            break;
                                        }
                                    }
                                }
                                //                                       exit
                                else if (options == 4)
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    gotoxy(90, 53);
                                    cout << "Select a valid option";
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                }
            }
        }
        system("cls");
        cout << "Ctrl+C pressed. Exiting..." << endl;
        Sleep(1000);
    }
}
//                                                          commma checker
bool comma(string &field)
{

    for (int i = 0; i <= field.length(); i++)
    {
        if (field[i] == ',')
        {
            return false;
        }
    }
    return true;
}

//                                                              read receiving account
void readArrayFromFile(string bankholders[], string bankholder[], string banknumber[], string bankname[], int index[], int size, string name)
{
    ifstream inputFile("bankdata.txt");

    if (inputFile.is_open())
    {
        // Read data from the file and populate the arrays
        for (int i = 0; i < size; i++)
        {
            getline(inputFile, bankholders[i]);
            if (bankholders[i] == name)
            {
                inputFile >> index[i];
                inputFile.ignore(); // Ignore the comma
                getline(inputFile, bankholder[i], ',');
                getline(inputFile, banknumber[i], ',');
                getline(inputFile, bankname[i]);
            }
            // Assuming your data is structured like "index,bankholder,banknumber,bankname"
        }

        inputFile.close();
        cout << "Data read from file successfully." << endl;
    }
    else
    {
        cout << "Error opening file for reading." << endl;
    }
}
//                                                    recieving accounts file handling
void printArrayToFile(string name, string bankholder[], string banknumber[], string bankname[], int index[], int size)
{
    ofstream outputFile("bankdata.txt", ios::app);

    if (outputFile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            if (index[i] != 0)
            {
                outputFile << name << endl;
                outputFile << index[i] << "," << bankholder[i] << "," << banknumber[i] << "," << bankname[i] << endl;
            }
        }

        outputFile.close();
        cout << "Data written to file successfully." << endl;
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}
//                                                             save data to file
void saveDataToFile(string usernames[], double balances[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_USERS, int &limit)
{
    ofstream file("userdata.txt");

    if (file.is_open())
    {
        file << limit << endl;
        for (int i = 0; i < MAX_USERS; ++i)
        {
            file << usernames[i] << "," << balances[i] << "," << transactionHistoriesUsernames[i] << "," << transactionCounts[i] << endl;

            for (int j = 0; j < transactionCounts[i]; ++j)
            {
                file << transactionDescriptions[i][j] << "," << transactionAmounts[i][j] << endl;
            }
            file << "---" << endl; // Separate user data
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadDataFromFile(string usernames[], double balances[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_USERS, int &limit)
{
    string limits;
    ifstream file("userdata.txt");

    if (file.is_open())
    {
        getline(file, limits);
        limit = stoi(limits);
        for (int i = 0; i < MAX_USERS; ++i)
        {
            getline(file, usernames[i], ',');
            file >> balances[i];
            file.ignore(); // Ignore the comma
            getline(file, transactionHistoriesUsernames[i], ',');
            file >> transactionCounts[i];
            file.ignore(); // Ignore the newline

            // Read transactions
            for (int j = 0; j < transactionCounts[i]; ++j)
            {
                getline(file, transactionDescriptions[i][j], ',');
                file >> transactionAmounts[i][j];
                file.ignore(); // Ignore the newline
            }

            getline(file, usernames[i]);
        }

        file.close();
    }
    else
    {
        cout << "File not found. Initializing with default data." << endl;
        // Initialize with default data if the file doesn't exist
        for (int i = 0; i < MAX_USERS; ++i)
        {
            usernames[i] = "user" + to_string(i + 1);
            balances[i] = 1000;
            transactionHistoriesUsernames[i] = usernames[i];
            transactionCounts[i] = 0;
        }
    }
}
//                                                list users
void viewAllUsers(string usernames[], double balances[], int MAX_USERS,string name,bool deposit)
{
    gotoxy(65, 34);
    cout << "All Users:" << endl;
    gotoxy(36, 36);
    cout << setw(40) << "Username" << setw(30) << "Balance" << endl;
    for (int i = 0; i < MAX_USERS; ++i)
    {
        if (usernames[i] != ""&& usernames[i]!=name)
        {
            gotoxy(36, 38 + i);
            cout << setw(40) << usernames[i] << setw(30) << fixed << setprecision(2) << balances[i] << endl;
        }
    }
    cout << endl;
}

void viewAllTransactions(string usernames[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_USERS, string type, string name)
{

    gotoxy(36, 36);
    cout << setw(30) << "Username" << setw(30) << "Description" << setw(20) << "Amount" << endl;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (type == "user" && usernames[i] == name)
        {
    gotoxy(60, 34);
    cout << "Transaction Reciving History of User" << endl;
            for (int j = 0; j < 10; ++j)
            {
                gotoxy(36, 37 + j);
                cout << setw(30) << transactionHistoriesUsernames[i] << setw(30) << transactionDescriptions[i][j]
                     << setw(20) << fixed << setprecision(2) << transactionAmounts[i][j] << endl;
            }
        }
        if (type == "admin")
        {
                gotoxy(60, 34);
    cout << "Transaction History for All Users:" << endl;
            for (int j = 0; j <10; ++j)
            {
                gotoxy(36, 37 + j);
                cout << setw(30) << transactionHistoriesUsernames[i] << setw(30) << transactionDescriptions[i][j]
                     << setw(20) << fixed << setprecision(2) << transactionAmounts[i][j] << endl;
            }
            break;
        }
    }
}

void addTransaction(int userIndex, const string &description, double amount, string usernames[], double balances[], string transactionHistoriesUsernames[], string transactionDescriptions[][100], double transactionAmounts[][100], int transactionCounts[], int MAX_DESCRIPTION_LENGTH, int MAX_USERS, int limit)
{
    // Check if there is space for a new transaction
    if (transactionCounts[userIndex] < limit)
    {
        transactionHistoriesUsernames[userIndex] = usernames[userIndex];
        transactionDescriptions[userIndex][transactionCounts[userIndex]] = description.substr(0, MAX_DESCRIPTION_LENGTH - 1);
        transactionAmounts[userIndex][transactionCounts[userIndex]] = amount;
        transactionCounts[userIndex]++;
        balances[userIndex] += amount;
        saveDataToFile(usernames, balances, transactionHistoriesUsernames, transactionDescriptions, transactionAmounts, transactionCounts, MAX_USERS, limit);
        gotoxy(60, 52);
        cout << "                                       " << endl;
        gotoxy(60, 52);
        cout << "Money sent successfully.";
    }
    else
    {
        gotoxy(60, 52);
        cout << "                                       " << endl;
        gotoxy(60, 52);
        cout << "Transaction limit reached for the user." << endl;
        Sleep(1000);
    }
}

int findUserIndexByUsername(const string &username, string usernames[], int MAX_USERS)
{
    for (int i = 0; i < MAX_USERS; ++i)
    {
        if (usernames[i] == username)
        {
            return i;
        }
    }
    return -1; // User not found
}

//                                                     Information edit
void updateInformation(string &info, int x, int y,int index)
{
    string infos="";
    gotoxy(x, y);
    cout << setw(31) << " ";
    infos = information(x, y);
    if(index==0){
        if (hasNoInteger(infos)&& comma(infos))
                {
                    if (infos.length() > 10)
                    {
                        
                        gotoxy(60, 52);
                        setcolor(4);
                        cout << "Username is too long";
                        setcolor(15);
                        Sleep(1000);
                    }
                    else{
                        info = infos;
                    }
                }
                else
                {
                    gotoxy(59, 52);
                    setcolor(4);
                    cout << "Username has integer or comma";
                    setcolor(15);
                    Sleep(1000);
                }
    }
    if(index==1){
        if (infos.length() != 13&& !comma(infos))
                            {

                                gotoxy(60, 52);
                                setcolor(4);
                                cout << "Invalid CNIC";
                                setcolor(15);
                                Sleep(500);
                            }
                            if(infos.length() == 13&& comma(infos))
                            {
                                info = infos;
                            }
    }
    if(index==2){
        if (infos.length() < 8 || infos.length() > 16)
                            {
                                gotoxy(60, 52);
                                setcolor(4);
                                cout << "Password 8-16 characters long";
                                setcolor(15);
                                Sleep(500);
                            }
                            if (infos.length() >= 8 && infos.length() <= 16&& comma(infos))
                            {
                                
                                        info = infos;
                         
                                
                            }
    }
              
}
//                                          #  #  #    ### # # ###  ## ### ###  #  ###  ##
//                                         # # # #     #   # # # # #    #   #  # # # # #
//                                         # # ##      ##  # # # # #    #   #  # # # #  #
//                                         # # # #     #   # # # # #    #   #  # # # #   #
//                                          #  #  #    #   ### # #  ##  #  ###  #  # # ##
//                                                   only string validator function
bool hasNoInteger(string &value)
{
    for (int i = 0; i < value.length(); ++i)
    {
        if (value[i] >= '0' && value[i] <= '9')
        {
            return false;
        }
    }
    return true;
}
//                                                        Filehandling
//                                                        edit array
void edit_string(string &name, string &cnic, string &password, string &role, string namearray[], string passwordarray[], string rolearray[], string cnicarray[], int &indexCount)
{
    system("cls");
    int dataIndex = searchArray(namearray, name, indexCount);
    if (dataIndex != -1)
    {
        // Modify the values in the arrays
        namearray[dataIndex] = name;
        passwordarray[dataIndex] = password;
        rolearray[dataIndex] = role;
        cnicarray[dataIndex] = cnic;
        // Open the file in write mode to clear its contents
        for (int i = 0; i < 10; i++)
        {
            cout << namearray[i] << "," << passwordarray[i] << "," << cnicarray[i] << "," << rolearray[i] << endl;
        }
    }
}
//                                                        file search
void search(int &fileindex)
{
    fstream file;
    string line = "";
    file.open("a.txt", ios::in);
    getline(file, line);
    if (line == "")
    {
        fileindex = 0;
    }
    else
    {
        while (!file.eof())
        {
            getline(file, line);
            fileindex++;
        }
    }
}
//                                                      option input
string option(int x, int y)
{
    setcolor(lightgreen);
    string options;
    gotoxy(x, y);
    cin >> options;
    return options;
    setcolor(15);
}
//                                                       option conversion
int isAlphabet(string value)
{
    try
    {

        int values = stoi(value);
        if (values == 1 || values == 2 || values == 4 || values == 5 || values == 6 || values == 0 || values == 3 || values == 8 || values == 7 || values == 9)
        {
            return values;
        }
        else
        {
            return 0;
        }
    }
    catch (invalid_argument)
    {
        return 0;
    }
    catch (out_of_range)
    {
        return 0;
    }
}

//                                                         write data
void writeData(string name, string password, string cnic, string role)
{
    fstream data;
    data.open("a.txt", ios::app);

    if (data.is_open())
    {
        data << name << "," << password << "," << cnic << "," << role << endl;
        data.close();
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}
//                                                          read data
void readData(string names[], string passwords[], string cnic[], string role[], int &index)
{
    string record;
    fstream data;
    data.open("a.txt", ios::in);
    if (!data.is_open())
    {
        data.open("a.txt", ios::out);
        data.close();
        data.open("a.txt", ios::in);
    }
    while (!(data.eof()))
    {
        getline(data, record);
        names[index] = getField(record, 1);
        passwords[index] = getField(record, 2);
        cnic[index] = getField(record, 3);
        role[index] = getField(record, 4);
        index++;
    }
}
//                                                           getfield
string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

//                                                          delete user
void deleteuser(string name[], string cnic[], string role[], string passwordarray[], int index)
{
    name[index] = "";
    cnic[index] = "";
    passwordarray[index] = "";
    role[index] = "";
}
//                                                          print users
void viewRecords(string userNames[], string userIDs[], string role[])
{
    int k = 1;
    for (int i = 0; i < 6; i++)
    {
        string accountNumber = userNames[i] + userIDs[i];
        if (userNames[i] != "")
        {
            gotoxy(27, 31 + i);
            cout << k;
            gotoxy(42, 31 + i);
            cout << userNames[i];
            gotoxy(72, 31 + i);
            cout << accountNumber;
            gotoxy(105, 31 + i);
            cout << role[i];
            k++;
        }
        else
            continue;
    }
}
//                                                         delete bank
void deleteEntity(string bankholdername[], string banknumber[], string bankname[], int indexs[], int index)
{
    indexs[index] = 0;
    bankholdername[index] = "";
    banknumber[index] = "";
    bankname[index] = "";
}
// display bank
void printArray(string bankholder[], string banknumber[], string bankname[], int index[])
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (index[i] != 0)
        {
            gotoxy(27, 42 + count);
            cout << count + 1;
            gotoxy(42, 42 + count);
            cout << bankholder[i];
            gotoxy(72, 42 + count);
            cout << banknumber[i];
            gotoxy(105, 42 + count);
            cout << bankname[i];
            count++;
        }
    }
}

//                                                       input bank
void bankadd(string bankholdername[], string banknumber[], string bankname[], string add_bank, int &x, int accountindex[])
{
    gotoxy(28, 30);
    cout << setw(27) << " ";
    add_bank = information(28, 30);
    if(comma(add_bank)){
    bankdetails(bankholdername, add_bank, x);
    }
    else{
        gotoxy(60, 52);
        cout << "Invalid bank holder name";
        Sleep(1000);
        gotoxy(60, 52);
        cout << "                           ";
        bankadd(bankholdername, banknumber, bankname, add_bank, x, accountindex);
    }

    gotoxy(28, 36);
    cout << setw(31) << " ";
    add_bank = information(28, 36);
    if(comma(add_bank)){
    bankdetails(banknumber, add_bank, x);
    }
    else{
        gotoxy(60, 52);
        cout << "Invalid bank number";
        Sleep(1000);
        gotoxy(60, 52);
        cout << "                           ";
        bankadd(bankholdername, banknumber, bankname, add_bank, x, accountindex);
    }
    gotoxy(90, 30);
    cout << setw(20) << " ";
    add_bank = information(90, 30);
    if(comma(add_bank)){
    bankdetails(bankname, add_bank, x);
    }
    else{
        gotoxy(60, 52);
        cout << "Invalid bank name";
        Sleep(1000);
        gotoxy(60, 52);
        cout << "                           ";
        bankadd(bankholdername, banknumber, bankname, add_bank, x, accountindex);
    }
    accountindex[x] = x + 1;
    x++;
}

//                                                        accounts function
void bankdetails(string bankdetail[], string variable, int &x)
{
    bankdetail[x] = variable;
}

//                                                        ATM Viewer
void ATMoptions(string name, string type, string named, string card, string ccv, string passwordcheck, string password, int options, string passwordreturn, string &status)
{
    bool isFrozen = true;
    while (true)
    {
        string creditoptionss = option(72, 43);
        int creditOption = isAlphabet(creditoptionss);
        bool check;
        bool freezes;
        if (creditOption == 1)
        {
            check = passworddisplay(passwordcheck, password, passwordreturn);
            if (check)
            {
                system("cls");
                named = name;
                card = "12345678943433434421496532";
                ccv = "440";
                ViewATM(named, card, ccv, status);
                named = "************************";
                card = "**************************";
                ccv = "****";
                status = "Un Freezed";
            }
            else
            {
                named = "************************";
                card = "**************************";
                ccv = "****";
                check = passworddisplay(passwordcheck, password, passwordreturn);
            }
        }
        if (creditOption == 0)
        {
            break;
        }

        if (creditOption == 2)
        {
            freezes = passworddisplay(passwordcheck, password, passwordreturn);

            if (freezes)
            {
                if (isFrozen)
                {
                    displayFreezeScreen();
                    isFrozen = false;
                    status = "Freezed";
                    ViewATM(named, card, ccv, status);
                }
                else
                {
                    isFrozen = true;
                    displayUnfreezeScreen();
                    status = "Un Freezed";
                    ViewATM(named, card, ccv, status);
                }
            }
        }
    }
}

//                                                      Gotoxy Function
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

bool passworddisplay(string passwordcheck, string password, string passwordreturn)
{
    system("cls");
    gotoxy(20, 10);
    displaypasswordcheck(passwordreturn);
    passwordcheck = information(70, 27);
    bool check = confirmpassword(passwordcheck, password);
    if (check)
    {
        passwordreturn = "Password confirmed successfully";
        system("cls");
        displaypasswordcheck(passwordreturn);
        Sleep(1000);
        return true;
    }
    else
    {
        passwordreturn = "Wrong password.Try again";
        displaypasswordcheck(passwordreturn);
        Sleep(1000);
        passworddisplay(passwordcheck, password, passwordreturn);
    }
}
bool confirmpassword(string passwordchecker, string password)
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
//                                              Login information input function
string information(int x, int y)
{
    string information;
    gotoxy(x, y);
    cin >> information;
    return information;
}

//                                                          login
bool log(string name, string password, string &cnic, string cnicarray[], string namearray[], string &role, string rolearray[], string passwordarray[], int &indexCount, int &data_index, int fileindex)
{

    data_index = searchArray(namearray, name, fileindex);
    if (data_index == -1)
    {
        return false;
    }
    if (name == namearray[data_index] && password == passwordarray[data_index])
    {
        role = rolearray[data_index];
        cnic = cnicarray[data_index];
        return true;
    }
    return false;
}
//                                                        sign up array
void sign_string(string name, string password, string cnic, string role, string namearray[], string passwordarray[], string rolearray[], string cnicarray[], int &indexCount)
{
    namearray[indexCount] = name;
    passwordarray[indexCount] = password;
    rolearray[indexCount] = role;
    cnicarray[indexCount] = cnic;
    indexCount++;
}

//                              ___  _ ____ ___  _    ____ _   _    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
//                              |  \ | [__  |__] |    |__|  \_/     |___ |  | |\ | |     |  | |  | |\ | [__
//                              |__/ | ___] |    |___ |  |   |      |    |__| | \| |___  |  | |__| | \| ___]

//                                                          thank you
void thanku()
{
    setcolor(magenta);
    gotoxy(20, 20);
    cout << R"(    ___________.__                   __                           )";
    gotoxy(20, 21);
    cout << R"(    \__    ___/|  |__ _____    ____ |  | __  ___.__. ____  __ __  )";
    gotoxy(20, 22);
    cout << R"(      |    |   |  |  \\__  \  /    \|  |/ / <   |  |/  _ \|  |  \ )";
    gotoxy(20, 23);
    cout << R"(      |    |   |   Y  \/ __ \|   |  \    <   \___  (  <_> )  |  / )";
    gotoxy(20, 24);
    cout << R"(      |____|   |___|  (____  /___|  /__|_ \  / ____|\____/|____/  )";
    gotoxy(20, 25);
    cout << R"(                \/     \/     \/     \/  \/                       )";
    setcolor(15);
}

//    Manage users screen
void manageusers()
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
    cout << "#----------------------------------------------- Bank Accounts -----------------------------------------#" << endl;
    gotoxy(20, 28);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 29);
    cout << "#   Bank No.        Account holder name            Account Number                  Account Type         #" << endl;
    gotoxy(20, 30);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 31);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 32);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 33);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 34);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 35);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 36);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 37);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 38);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 39);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 40);
    cout << "#   Account Holder's Name:                                          Account type:                       #" << endl;
    gotoxy(20, 41);
    cout << "#    ___________________________________________                    _________________________           #" << endl;
    gotoxy(20, 42);
    cout << "#   |                                           |                  |                         |          #" << endl;
    gotoxy(20, 43);
    cout << "#   |                                           |                  |                         |          #" << endl;
    gotoxy(20, 44);
    cout << "#   |___________________________________________|                  |_________________________|          #" << endl;
    gotoxy(20, 45);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 46);
    cout << "#   CNIC Number:                                                   Instructions:                        #" << endl;
    gotoxy(20, 47);
    cout << "#    _______________________________________                      1) Edit details                       #" << endl;
    gotoxy(20, 48);
    cout << "#   |                                       |                     2) Remove bank                        #" << endl;
    gotoxy(20, 49);
    cout << "#   |                                       |                     3) Press 0 to back to homepage        #" << endl;
    gotoxy(20, 50);
    cout << "#   |_______________________________________|                                                           #" << endl;
    gotoxy(20, 51);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 52);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 53);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 54);
    cout << "#                                     ______________________________                                    #" << endl;
    gotoxy(20, 55);
    cout << "#                                    |                              |                                   #" << endl;
    gotoxy(20, 56);
    cout << "#                                    |                              |                                   #" << endl;
    gotoxy(20, 57);
    cout << "#                                    |______________________________|                                   #" << endl;
    gotoxy(20, 58);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 59);
    cout << "#########################################################################################################";
}
//                                                        admin screen
void admin(string &name, string &type)
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
    cout << "#  1) View your Account                             ##    2) Manage users                               #" << endl;
    gotoxy(20, 24);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 25);
    cout << "#                     #####                         ##            ######          ######                #" << endl;
    gotoxy(20, 26);
    cout << "#                   #########                       ##           ##    ##  ##### ##    ##               #" << endl;
    gotoxy(20, 27);
    cout << "#                   #########                       ##          ##       #########      ##              #" << endl;
    gotoxy(20, 28);
    cout << "#                     #####                         ##            ###### ######### #####                #" << endl;
    gotoxy(20, 29);
    cout << "#                   ##     ##                       ##           ##    ##  #####  ##   ##               #" << endl;
    gotoxy(20, 30);
    cout << "#                  ##       ##                      ##          ##       ##     ##      ##              #" << endl;
    gotoxy(20, 31);
    cout << "#                                                   ##                  ##       ##                     #" << endl;
    gotoxy(20, 32);
    cout << "#    => View Account / Salary                       ##                                                  #" << endl;
    gotoxy(20, 33);
    cout << "#    => Manage Settings                             ##      => Manage Users                             #" << endl;
    gotoxy(20, 34);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 35);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 36);
    cout << "#                                                   ##                                                  #" << endl;
    gotoxy(20, 37);
    cout << "#  3) Money Transfer Management                     ##   4) Exit the application                        #" << endl;
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
    cout << "#    => Manage transactions                         ##                                                  #" << endl;
    gotoxy(20, 45);
    cout << "#    => View transaction histories                  ##    => Close the app / 5 for sign out             #" << endl;
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
}
//                                                         send money tab
void sendmoney(string &add_bank)
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
    cout << "#          ## ##   ### ###  ###  ##  ### ##            ##   ##   ## ##   ###  ##  ### ###  ##  ##       #" << endl;
    gotoxy(20, 18);
    cout << "#         ##   ##   ##  ##    ## ##   ##  ##            ## ##   ##   ##    ## ##   ##  ##  ##  ##       #" << endl;
    gotoxy(20, 19);
    cout << "#         ####      ##       # ## #   ##  ##           # ### #  ##   ##   # ## #   ##      ##  ##       #" << endl;
    gotoxy(20, 20);
    cout << "#          #####    ## ##    ## ##    ##  ##           ## # ##  ##   ##   ## ##    ## ##    ## ##       #" << endl;
    gotoxy(20, 21);
    cout << "#             ###   ##       ##  ##   ##  ##           ##   ##  ##   ##   ##  ##   ##        ##         #" << endl;
    gotoxy(20, 22);
    cout << "#         ##   ##   ##  ##   ##  ##   ##  ##           ##   ##  ##   ##   ##  ##   ##  ##    ##         #" << endl;
    gotoxy(20, 23);
    cout << "#          ## ##   ### ###  ###  ##  ### ##            ##   ##   ## ##   ###  ##  ### ###    ##         #" << endl;
    gotoxy(20, 24);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 25);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 26);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 27);
    cout << "#   Account Holder's Name:                                          Amount:                             #" << endl;
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
    cout << "#   Account Number:                                             Instructions:                           #" << endl;
    gotoxy(20, 34);
    cout << "#    _______________________________________                    1) Send money to send to users          #" << endl;
    gotoxy(20, 35);
    cout << "#   |                                       |                   2) Back to trading page                 #" << endl;
    gotoxy(20, 36);
    cout << "#   |   " << setw(27) << left << add_bank << "         |                   3) To send money to reciving accounts   #" << endl;
    gotoxy(20, 37);
    cout << "#   |_______________________________________|                   4) View transaction Histories           #" << endl;
    gotoxy(20, 38);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 39);
    cout << "#--------------------------------------------- Banks Available -----------------------------------------#" << endl;
    gotoxy(20, 40);
    cout << "#   Serial No.         Account holder name            Account Number               Bank Name            #" << endl;
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
}

//                                                         Freeze/ Un Freeze
void displayFreezeScreen()
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
}

void displayUnfreezeScreen()
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
    cout << "#       ######################                      ##             /----\\                               #" << endl;
    gotoxy(20, 26);
    cout << "#       #  name:*****        #                      ##            /      \\                              #" << endl;
    gotoxy(20, 27);
    cout << "#       #  ac no.******      #                      ##          /__________\\                            #" << endl;
    gotoxy(20, 28);
    cout << "#       #  </>     ccv:****  #                      ##            || || ||                              #" << endl;
    gotoxy(20, 29);
    cout << "#       ######################                      ##            || || ||                              #" << endl;
    gotoxy(20, 30);
    cout << "#                                                   ##          (----------)                            #" << endl;
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
    cout << "#                 ___ #####                         ##      ##    #    ##  #  #                         #" << endl;
    gotoxy(20, 40);
    cout << "#               ____#########                       ##      # #  # #  #    # #                          #" << endl;
    gotoxy(20, 41);
    cout << "#                ___#########                       ##      ##   ###  #    ##                           #" << endl;
    gotoxy(20, 42);
    cout << "#                   __#####                         ##      # #  # #  #    # #                          #" << endl;
    gotoxy(20, 43);
    cout << "#                                                   ##      ##   # #   ##  #  #                         #" << endl;
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
}
//                                                   Account information
void accountinfo(string &name, string &cnic, string &combined, int &balance)
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
    cout << "#   Account Holder's Name:                                       Account Balance:                       #" << endl;
    gotoxy(20, 28);
    cout << "#    ___________________________________________                 ___________________________            #" << endl;
    gotoxy(20, 29);
    cout << "#   |                                           |               |                           |           #" << endl;
    gotoxy(20, 30);
    cout << "#   |   " << setw(27) << left << name << "             |               |  $ " << setw(5) << left << balance << "                  |           #" << endl;
    gotoxy(20, 31);
    cout << "#   |___________________________________________|               |___________________________|           #" << endl;
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
}

//                                                   add recieving account
void addaccount(string &add_bank)
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
    cout << "#   |_______________________________________|                     4)                                    #" << endl;
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
}

//                                                      password display
void displaypasswordcheck(string passwordreturn)
{
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
}
//                                                         View ATM
void ViewATM(string named, string card, string ccv, string status)
{
    system("cls");
    setcolor(lightcyan);
    gotoxy(20, 5);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 6);
    cout << "#                                     CREDIT / DEBIT CARD MANAGEMENT                                    #" << endl;
    gotoxy(20, 7);
    cout << "#########################################################################################################" << endl;
    setcolor(white);
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
    cout << "#             ##      Issue Date         Expiry Date          Card Status              ##               #" << endl;
    gotoxy(20, 20);
    cout << "#             ##                                                                       ##               #" << endl;
    gotoxy(20, 21);
    cout << "#             ##        3/21                4/27                " << setw(22) << left << status << " ##               #" << endl;
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
    setcolor(lightmagenta);
    cout << "#  1) Card Information                              ##   2) Freeze/unFreeze card                        #" << endl;
    setcolor(white);
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
    setcolor(lightcyan);
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
    setcolor(white);
}
//                                                     User information
void userinfo(string name, string type, string cnic, string password)
{
    setcolor(lightcyan);
    system("cls");
    gotoxy(20, 5);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 6);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 7);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 8);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 9);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 10);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 11);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 12);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 13);
    cout << "#                                                                                                       #" << endl;
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
    setcolor(15);
}

//                                                        User  Screen
void user(string name, string type)
{
    system("cls");
    setcolor(white);
    gotoxy(20, 5);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 6);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 7);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 8);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 9);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 10);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 11);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 12);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 13);
    cout << "#                                                                                                       #" << endl;
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
    cout <<"# "<<setcolor(lightcyan)<<" 1) View your Account                             ##    2) CREDIT/DEBIT CARD MANAGEMENT               #" << endl;
    setcolor(white);
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
    setcolor(lightcyan);
    cout << "#  3) Money Transfer                                ##   4) Exit the application                        #" << endl;
    setcolor(white);
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
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 50);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 51);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 52);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 53);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 54);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 55);
    cout << "#########################################################################################################";
    bankapp();
    optionsdisplay();
    setcolor(white);
}
//                                                        Login Screen
void login()
{
    setcolor(lightcyan);
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
    cout << "#                                                           #" << endl;
    gotoxy(40, 36);
    cout << "#                                                           #" << endl;
    gotoxy(40, 37);
    cout << "#                                                           #" << endl;
    gotoxy(40, 38);
    cout << "#                                                           #" << endl;
    gotoxy(40, 39);
    cout << "#                                                           #" << endl;
    gotoxy(40, 40);
    cout << "#############################################################";
    setcolor(white);
}
//                                                      Sign up Screen
void signup()
{

    system("cls");
    setcolor(white);
    gotoxy(20, 5);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 6);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 7);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 8);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 9);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 10);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 11);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 12);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 13);
    cout << "#                                                                                                       #" << endl;
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
    bankapp();
}
//                                                        displaytext
void bankapp()
{
    setcolor(lightgreen);
    gotoxy(21, 7);
    cout << "      #####       #####    #     #   #     #                  ####     #######     #######             " << endl;
    gotoxy(21, 8);
    cout << "      #    ##    ##   ##   ###   #   #   ##                 ##    ##   ##    ##    ##    ##            " << endl;
    gotoxy(21, 9);
    cout << "      #    ##    ##   ##   # ### #   # ##                  ##      ##  ##     ##   ##     ##           " << endl;
    gotoxy(21, 10);
    cout << "      #####      #######   #  ####   ##                    ##########  #### ##     ####  ##            " << endl;
    gotoxy(21, 11);
    cout << "      #    ##    ##   ##   #    ##   # ##                  ##      ##  ##          ##                  " << endl;
    gotoxy(21, 12);
    cout << "      #    ##    ##   ##   #     #   #  ##                 ##      ##  ##          ##                  " << endl;
    gotoxy(21, 13);
    cout << "      #####      ##   ##   #     #   #    #                ##      ##  ##          ##                  " << endl;
    setcolor(white);
}
void signuplogin()
{
    setcolor(lightcyan);
    gotoxy(21, 27);
    cout << "               ##              ## ##     ####    ## ##   ###  ##  ##  ###  ### ##                      " << endl;
    gotoxy(21, 28);
    cout << "              ###             ##   ##     ##    ##   ##    ## ##  ##   ##   ##  ##                     " << endl;
    gotoxy(21, 29);
    cout << "               ##             ####        ##    ##        # ## #  ##   ##   ##  ##                     " << endl;
    gotoxy(21, 30);
    cout << "               ##              #####      ##    ##  ###   ## ##   ##   ##   ##  ##                     " << endl;
    gotoxy(21, 31);
    cout << "               ##                 ###     ##    ##   ##   ##  ##  ##   ##   ## ##                      " << endl;
    gotoxy(21, 32);
    cout << "               ##             ##   ##     ##    ##   ##   ##  ##  ##   ##   ##                         " << endl;
    gotoxy(21, 33);
    cout << "              ####             ## ##     ####    ## ##   ###  ##   ## ##   ####                        " << endl;
    gotoxy(21, 34);
    cout << "                                                                                                       " << endl;
    gotoxy(21, 35);
    cout << "                                                                                                       " << endl;
    gotoxy(21, 36);
    cout << "                ##            ####       ## ##    ## ##  ####   ###   ##                               " << endl;
    gotoxy(21, 37);
    cout << "              ## ##            ##       ##   ##  ##   ##   ##    ##   ##                               " << endl;
    gotoxy(21, 38);
    cout << "             ##  ##            ##       ##   ##  ##   ##   ##     ##  ##                               " << endl;
    gotoxy(21, 39);
    cout << "                 ##            ##       ##   ##  ##        ##    # ##  #                               " << endl;
    gotoxy(21, 40);
    cout << "               ##              ##       ##   ##  ##  ###   ##    ##  ###                               " << endl;
    gotoxy(21, 41);
    cout << "             #   ##            ##   ##  ##   ##  ##   ##   ##    ##   ##                               " << endl;
    gotoxy(21, 42);
    cout << "             ######            ### ###   ## ##    ## ##  ####   ###   ##                               " << endl;
    setcolor(white);
}
//                                                       DISPLAY SCREEN
void display()
{
    setcolor(white);
    system("cls");
    gotoxy(20, 5);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 6);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 7);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 8);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 9);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 10);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 11);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 12);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 13);
    cout << "#                                                                                                       #" << endl;
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
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 28);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 29);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 30);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 31);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 32);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 33);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 34);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 35);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 36);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 37);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 38);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 39);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 40);
    cout << "#                                                                                                       #" << endl;
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
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 48);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 49);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 50);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 51);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 52);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 53);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 54);
    cout << "#                                                                                    Press 4 to exit    #" << endl;
    gotoxy(20, 55);
    cout << "#             Instructions:                                                                             #" << endl;
    gotoxy(20, 56);
    cout << "#             1) To create account                                                                      #" << endl;
    gotoxy(20, 57);
    cout << "#             2) Login in your account                                                                  #" << endl;
    gotoxy(20, 58);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 59);
    cout << "#########################################################################################################";
    setcolor(white);
}
//                                                       options display
void optionsdisplay()
{
    setcolor(lightcyan);
    gotoxy(21, 49);
    cout << "--------------------------------------------SELECT AN OPTION ------------------------------------------";
    gotoxy(21, 50);
    cout << "                                        ______________________                                         ";
    gotoxy(21, 51);
    cout << "                                       |                      |                                        ";
    gotoxy(21, 52);
    cout << "                                       |                      |                                        ";
    gotoxy(21, 53);
    cout << "                                       |______________________|                                        ";
    setcolor(white);
}
//                                                      admin money manage
//                                                      admin money page
void displaymoneymanageadmin()
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
    cout << "#                               ##   ##   ## ##   ###  ##  ### ###  ##  ##                              #" << endl;
    gotoxy(20, 18);
    cout << "#                                ## ##   ##   ##    ## ##   ##  ##  ##  ##                              #" << endl;
    gotoxy(20, 19);
    cout << "#                               # ### #  ##   ##   # ## #   ##      ##  ##                              #" << endl;
    gotoxy(20, 20);
    cout << "#                               ## # ##  ##   ##   ## ##    ## ##    ## ##                              #" << endl;
    gotoxy(20, 21);
    cout << "#                               ##   ##  ##   ##   ##  ##   ##        ##                                #" << endl;
    gotoxy(20, 22);
    cout << "#                               ##   ##  ##   ##   ##  ##   ##  ##    ##                                #" << endl;
    gotoxy(20, 23);
    cout << "#                               ##   ##   ## ##   ###  ##  ### ###    ##                                #" << endl;
    gotoxy(20, 24);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 25);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 26);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 27);
    cout << "#                                                  Instructions                                         #" << endl;
    gotoxy(20, 28);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 29);
    cout << "#                                 1)  Press 1 to transfer to other accounts                             #" << endl;
    gotoxy(20, 30);
    cout << "#                                 2)  Press 2 to increase transaction limits                            #" << endl;
    gotoxy(20, 31);
    cout << "#                                 3)  Press 3 to view transaction histories                             #" << endl;
    gotoxy(20, 32);
    cout << "#                                 4)  Press 4 to back                                                   #" << endl;
    gotoxy(20, 33);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 34);
    cout << "#----------------------------------------                       ----------------------------------------#" << endl;
    gotoxy(20, 35);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 36);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 37);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 38);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 39);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 40);
    cout << "#                                                                                                       #" << endl;
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
    cout << "#                             ________________________________________________                          #" << endl;
    gotoxy(20, 51);
    cout << "#                            |                                                 |                        #" << endl;
    gotoxy(20, 52);
    cout << "#                            |                                                 |                        #" << endl;
    gotoxy(20, 53);
    cout << "#                            |_________________________________________________|                        #" << endl;
    gotoxy(20, 54);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 55);
    cout << "#########################################################################################################";
}
//                                                      user money page
void displaymoneymanage()
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
    cout << "#          ## ##   ### ###  ###  ##  ### ##            ##   ##   ## ##   ###  ##  ### ###  ##  ##       #" << endl;
    gotoxy(20, 18);
    cout << "#         ##   ##   ##  ##    ## ##   ##  ##            ## ##   ##   ##    ## ##   ##  ##  ##  ##       #" << endl;
    gotoxy(20, 19);
    cout << "#         ####      ##       # ## #   ##  ##           # ### #  ##   ##   # ## #   ##      ##  ##       #" << endl;
    gotoxy(20, 20);
    cout << "#          #####    ## ##    ## ##    ##  ##           ## # ##  ##   ##   ## ##    ## ##    ## ##       #" << endl;
    gotoxy(20, 21);
    cout << "#             ###   ##       ##  ##   ##  ##           ##   ##  ##   ##   ##  ##   ##        ##         #" << endl;
    gotoxy(20, 22);
    cout << "#         ##   ##   ##  ##   ##  ##   ##  ##           ##   ##  ##   ##   ##  ##   ##  ##    ##         #" << endl;
    gotoxy(20, 23);
    cout << "#          ## ##   ### ###  ###  ##  ### ##            ##   ##   ## ##   ###  ##  ### ###    ##         #" << endl;
    gotoxy(20, 24);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 25);
    cout << "#########################################################################################################" << endl;
    gotoxy(20, 26);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 27);
    cout << "#                                                  Instructions                                         #" << endl;
    gotoxy(20, 28);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 29);
    cout << "#                                 1)  Press 1 to transfer to other accounts                             #" << endl;
    gotoxy(20, 30);
    cout << "#                                 2)  Press 2 to deposit money                                          #" << endl;
    gotoxy(20, 31);
    cout << "#                                 3)  Press 3 to view transaction histories                             #" << endl;
    gotoxy(20, 32);
    cout << "#                                 4)  Press 4 to back                                                   #" << endl;
    gotoxy(20, 33);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 34);
    cout << "#----------------------------------------                       ----------------------------------------#" << endl;
    gotoxy(20, 35);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 36);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 37);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 38);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 39);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 40);
    cout << "#                                                                                                       #" << endl;
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
    cout << "#                             ________________________________________________                          #" << endl;
    gotoxy(20, 51);
    cout << "#                            |                                                 |                        #" << endl;
    gotoxy(20, 52);
    cout << "#                            |                                                 |                        #" << endl;
    gotoxy(20, 53);
    cout << "#                            |_________________________________________________|                        #" << endl;
    gotoxy(20, 54);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 55);
    cout << "#########################################################################################################";
}