#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <fstream>
using namespace std;
//                                             Functions
void gotoxy(int x, int y);
void login(string &loginaction);
string information(int x, int y);
void user(string name, string type);
void ViewATM(string named, string card, string ccv, string status);
bool confirmpassword(string passwordcheck, string password);
void display();
void sendmoney(string &add_bank);
void signup();
string option(int x, int y);
bool passworddisplay(string passwordcheck, string password, string passwordreturn);
void freeze(bool freeze, bool &num);
void userinfo(string name, string type, string cnic, string password);
void transfermoney(string name);
void accountinfo(string &name, string &cnic, string &combined,int &balance);
void addaccount(string &add_bank);
void bankadd(string bankholdername[], string banknumber[], string bankname[], string add_bank, int &x, int accountsindex[]);
void bankdetails(string bankdetail[], string variable, int &x);
void display(int x, int y);
void displaypasswordcheck(string passwordreturn);
void updateInformation(string &info, int x, int y);
void displayFreezeScreen();
void displayUnfreezeScreen();
void admin(string &name, string &type);
void manageusers();
int isAlphabet(string value);
void search(int &fileindex);
void writeData(string names, string passwords, string cnic, string role);
string getField(string record, int field);
bool hasNoInteger(string& value);
void displaymoneymanage();
//                                                 array function
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

//                                                  Main function
main()
{
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
    int x = 0;
    int fileindex = 0;
    int balance=100;
    bool logincheck = false;
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

    while (true)
    {
        // Display screen
        if (options == 6)
        {
            system("cls");
            readData(namearray, passwordarray, cnicarray, rolearray, fileindex);
            display();
            options2 = option(72, 52);
            options = isAlphabet(options2);
        }

        // Exit
        else if (options == 4)
        {
            system("cls");
            exit(0);
        }

        // Sign up screen
        else if (options == 1)
        {
            system("cls");
            signup();
            name = information(28, 29);
            if(hasNoInteger(name)){
                            if(name.length()>10){
                    gotoxy(60, 52);
                    cout << "Username is too long";
                options = 1; 
                Sleep(1000);
            }
            else{

            type = information(90, 29);
            if (type != "admin" && type != "user" && type != "ADMIN" && type != "USER" && type != "Admin" && type != "User")
            {
                gotoxy(60, 52);
                cout << "Invalid Role";
                Sleep(500);
            }
            else
            {
                cnic = information(28, 35);
                if(cnic.length()!=13){
                    gotoxy(60, 52);
                    cout << "Invalid CNIC";
                    Sleep(500);
                }
                else{
                password = information(28, 41);
                passwordconfirm = information(81, 41);
                if(password.length()<8 || password.length()>16){
                    gotoxy(60, 52);
                    cout << "Password 8-16 characters long";
                    Sleep(500);
                }
                if(password.length()>=8 && password.length()<=16){
                if (searchArray(namearray, name, fileindex) == -1 || searchArray(cnicarray, cnic, fileindex) == -1)
                {
                    if (password != passwordconfirm)
                    {
                        gotoxy(60, 52);
                        cout << "Password does not match";
                    }
                    else
                    {
                        sign_string(name, password, cnic, type, namearray, passwordarray, rolearray, cnicarray, indexCount);
                        gotoxy(60, 52);
                        cout << "Successfully Registered";
                        Sleep(1000);
                        writeData(name, password, cnic, type);
                        options = 6;
                    }
            }
                }
                else
                {
                    gotoxy(60, 52);
                    cout << "Username already exists";
                options = 1;
                Sleep(1000);
                }
                }
            }
            }
            }

            else{
                    gotoxy(60, 52);
                    cout << "Username contains integer";
                options = 1; 
                Sleep(1000);

            }
        }

        // Login
        else if (options == 2)
        {
            login(loginaction);
            name = information(50, 26);
            password = information(50, 32);

            // Login check array
            bool login_check = log(name, password, cnic, cnicarray, namearray, type, rolearray, passwordarray, indexCount, dataIndex, fileindex);
            if (login_check)
            {
                loginaction = "Successfully! Logged In";
                login(loginaction);
                logincheck = true;
                loginaction = "";
                Sleep(1000);
            }
            else
            {
                logincheck = false;
                gotoxy(48, 40);
                loginaction = "Invalid Credentials! Try Again.";
                Sleep(1000);
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
                            options2 = option(72, 52);
                            options = isAlphabet(options2);
                            if (options == 1)
                            {
                                updateInformation(name, 28, 30);
                            }
                            else if (options == 2)
                            {
                                updateInformation(cnic, 28, 36);
                            }
                            else if (options == 3)
                            {
                                updateInformation(password, 28, 42);
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
                                bankdetails(namearray, variable, index);
                                variable = information(28, 49);
                                bankdetails(cnicarray, variable, index);
                                variable = information(90, 43);
                                bankdetails(rolearray, variable, index);
                                viewRecords(namearray, cnicarray, rolearray);
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
                                accountinfo(name, cnic, combined,balance);
                                gotoxy(120, 45);
                                char key = getch();
                            }
                            //                               add receiving account
                            else if (options == 2)
                            {
                                system("cls");
                                addaccount(add_bank);
                                printArray(bankholder, banknumber, bankname, accountsindex);
                                options2 = option(72, 52);
                                options = isAlphabet(options2);
                                if (options == 1)
                                {
                                    bankadd(bankholder, banknumber, bankname, add_bank, x, accountsindex);
                                    while (true)
                                    {
                                        printArray(bankholder, banknumber, bankname, accountsindex);
                                    }
                                }
                            }
                            else if (options == 4)
                            {
                                system("cls");
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
                    

                            userinfo(name, type, cnic, password);
                            options2 = option(72, 52);
                            options = isAlphabet(options2);
                            if (options == 1)
                            {
                                updateInformation(name, 28, 30);
                                if(name.length()>10){
                                    
                                }
                            }
                            else if (options == 2)
                            {
                                updateInformation(cnic, 28, 36);
                            }
                            else if (options == 3)
                            {
                                updateInformation(password, 28, 42);
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
                                accountinfo(name, cnic, combined,balance);
                                gotoxy(120, 45);
                                char key = getch();
                            }
                            //                               add receiving account
                            else if (options == 2)
                            {
                                system("cls");
                                addaccount(add_bank);
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
                                            break;
                                        }
                                    }
                                }
                            }
                            //                                     send money
                            else if (options == 3)
                            {
                                x = 5;
                                system("cls");
                                sendmoney(add_bank);

                                for (int i = 5; i < 10; i++)
                                {
                                    if (accountsindex[i] != 0)
                                    {
                                        gotoxy(27, 42 + i - 5);
                                        cout << accountsindex[i];
                                        gotoxy(42, 42 + i - 5);
                                        cout << bankholder[i];
                                        gotoxy(72, 42 + i - 5);
                                        cout << banknumber[i];
                                        gotoxy(105, 42 + i - 5);
                                        cout << bankname[i];
                                    }
                                }

                                string optionss = option(72, 52);
                                options = isAlphabet(optionss);
                                while (true)
                                {
                                    if (options == 1)
                                    {
                                        bankadd(bankholder, banknumber, bankname, add_bank, x, accountsindex);

                                        for (int i = 5; i < 10; i++)
                                        {
                                            if (accountsindex[i] != 0)
                                            {
                                                gotoxy(27, 42 + i - 5);
                                                cout << accountsindex[i];
                                                gotoxy(42, 42 + i - 5);
                                                cout << bankholder[i];
                                                gotoxy(72, 42 + i - 5);
                                                cout << banknumber[i];
                                                gotoxy(105, 42 + i - 5);
                                                cout << bankname[i];
                                            }
                                        }

                                        gotoxy(72, 52);
                                        cout << " ";
                                        string keys = option(72, 52);
                                        int key = isAlphabet(keys);
                                        if (key == 1)
                                        {
                                            bankadd(bankholder, banknumber, bankname, add_bank, x, accountsindex);
                                        }
                                    }
                                    else if (options == 2)
                                    {
                                        system("cls");
                                        options=3;
                                        break; // Exit the while loop and go back to the previous page
                                    }
                                    //           send money to receivnig accounts
                                    else if(options==3){
                                        printArray(bankholder, banknumber, bankname, accountsindex);
                                        int g=0;
                                        gotoxy(28, 30);
                                        cout << setw(27) << " ";
                                      string  abank = information(28, 30);
                                        gotoxy(28, 36);
                                        cout << setw(31) << " ";
                                       string bankno = information(28, 36);                                  
                                        gotoxy(90, 30);
                                        cout << setw(20) << " ";
                                       string banknaam = information(90, 30);
                                        for (int i = 5; i < 10; i++){

                                            if (accountsindex[i] != 0)
                                            {
                                                gotoxy(27, 42 + i - 5);
                                                cout << accountsindex[i];
                                                gotoxy(42, 42 + i - 5);
                                                cout << bankholder[i];
                                                gotoxy(72, 42 + i - 5);
                                                cout << banknumber[i];
                                                gotoxy(105, 42 + i - 5);
                                                cout << bankname[i];
                                                g++;
                                                cout<<g;
                                                getch();
                                            }
                                        } 
                                        if(searchArray(banknumber,bankno,g)!=-1&&!searchArray(bankholder,abank,g)!=-1&&!searchArray(bankname,banknaam,g)!=-1){
                                        gotoxy(90, 52);
                                        cout << "Money sent...       ";
                                        Sleep(1000);
                                        break;
                                        options=3;
                                        }
                                        else{
                                        gotoxy(90, 52);
                                        cout << "Details not match...";
                                        Sleep(1000);
                                        options=3;
                                        }
                                       
                                      
                                        gotoxy(72, 52);
                                        cout << " ";
                                        string keys = option(72, 52);
                                        int key = isAlphabet(keys);
                                         gotoxy(90, 52);
                                        cout << "                     ";
                                        }
                                        
                                    
                                    else
                                    {
                                        gotoxy(90, 53);
                                        cout << "Select a valid option";
                                        Sleep(1000);
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
}
//                                                     Information edit
void updateInformation(string &info, int x, int y)
{
    gotoxy(x, y);
    cout << setw(31) << " ";
    info = information(x, y);
}
//                                          #  #  #    ### # # ###  ## ### ###  #  ###  ##
//                                         # # # #     #   # # # # #    #   #  # # # # #
//                                         # # ##      ##  # # # # #    #   #  # # # #  #
//                                         # # # #     #   # # # # #    #   #  # # # #   #
//                                          #  #  #    #   ### # #  ##  #  ###  #  # # ##
//                                                   only string validator function
bool hasNoInteger(string& value)
 {
    for (int i = 0; i < value.length(); ++i) {
        if (value[i] >= '0' && value[i] <= '9') {
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
    string options;
    gotoxy(x, y);
    cin >> options;
    return options;
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
    for (int i = 0; i < 5; i++)
    {
        if (index[i] != 0)
        {
            gotoxy(27, 42 + i);
            cout << index[i];
            gotoxy(42, 42 + i);
            cout << bankholder[i];
            gotoxy(72, 42 + i);
            cout << banknumber[i];
            gotoxy(105, 42 + i);
            cout << bankname[i];
        }
    }
}

//                                                       input bank
void bankadd(string bankholdername[], string banknumber[], string bankname[], string add_bank, int &x, int accountindex[])
{
    gotoxy(28, 30);
    cout << setw(27) << " ";
    add_bank = information(28, 30);
    bankdetails(bankholdername, add_bank, x);
    gotoxy(28, 36);
    cout << setw(31) << " ";
    add_bank = information(28, 36);
    bankdetails(banknumber, add_bank, x);
    gotoxy(90, 30);
    cout << setw(20) << " ";
    add_bank = information(90, 30);
    bankdetails(bankname, add_bank, x);
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
//                                                       Search Array
int searchArray(string arr[], string object, int &indexCount)
{ // arr-->names and object---->username
    for (int i = 0; i <= indexCount; i++)
    {
        if (arr[i] == object)
        {
            return i;
        }
    }
    return -1;
}

//                              ___  _ ____ ___  _    ____ _   _    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
//                              |  \ | [__  |__] |    |__|  \_/     |___ |  | |\ | |     |  | |  | |\ | [__
//                              |__/ | ___] |    |___ |  |   |      |    |__| | \| |___  |  | |__| | \| ___]

//                                                       Manage users screen
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
void accountinfo(string &name, string &cnic, string &combined,int &balance)
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
    cout << "#   |   " << setw(27) << left << name << "             |               |  $ "<<setw(5)<<left<<balance<<"                  |           #" << endl;
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
    cout << "#   |_______________________________________|                     4) Your money automatically transfer  #" << endl;
    gotoxy(20, 38);
    cout << "#                                                                    to your receiving banks            #" << endl;
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
}
//                                                     User information
void userinfo(string name, string type, string cnic, string password)
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
}

//                                                        User  Screen
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
}
//                                                        Login Screen
void login(string &loginaction)
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
    cout << "#                                                           #" << endl;
    gotoxy(40, 36);
    cout << "#                                                           #" << endl;
    gotoxy(40, 37);
    cout << "#                                                           #" << endl;
    gotoxy(40, 38);
    cout << "#       " << setw(33) << left << loginaction << "                   #" << endl;
    gotoxy(40, 39);
    cout << "#                                                           #" << endl;
    gotoxy(40, 40);
    cout << "#############################################################";
}
//                                                      Sign up Screen
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
}
//                                                       DISPLAY SCREEN
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
    cout << "#             Instructions:                                                                             #" << endl;
    gotoxy(20, 56);
    cout << "#             1) To create account                                                                      #" << endl;
    gotoxy(20, 57);
    cout << "#             2) Login in your account                                                                  #" << endl;
    gotoxy(20, 58);
    cout << "#                                                                                                       #" << endl;
    gotoxy(20, 59);
    cout << "#########################################################################################################";
}
//                                                      admin money page
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
    gotoxy(20, 16);
    gotoxy(20, 17);
    gotoxy(20, 18);
    gotoxy(20, 19);
    gotoxy(20, 20);
    gotoxy(20, 21);
    gotoxy(20, 22);
    gotoxy(20, 23);
    gotoxy(20, 24);
    gotoxy(20, 25);
    gotoxy(20, 26);
    gotoxy(20, 27);
    gotoxy(20, 28);
    gotoxy(20, 29);
    gotoxy(20, 30);
    gotoxy(20, 31);
    gotoxy(20, 32);
    gotoxy(20, 33);
    gotoxy(20, 34);
    gotoxy(20, 35);
    gotoxy(20, 36);
    gotoxy(20, 37);
    gotoxy(20, 38);
    cout << "#########################################################################################################" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#          ## ##   ### ###  ###  ##  ### ##            ##   ##   ## ##   ###  ##  ### ###  ##  ##       #" << endl;
    cout << "#         ##   ##   ##  ##    ## ##   ##  ##            ## ##   ##   ##    ## ##   ##  ##  ##  ##       #" << endl;
    cout << "#         ####      ##       # ## #   ##  ##           # ### #  ##   ##   # ## #   ##      ##  ##       #" << endl;
    cout << "#          #####    ## ##    ## ##    ##  ##           ## # ##  ##   ##   ## ##    ## ##    ## ##       #" << endl;
    cout << "#             ###   ##       ##  ##   ##  ##           ##   ##  ##   ##   ##  ##   ##        ##         #" << endl;
    cout << "#         ##   ##   ##  ##   ##  ##   ##  ##           ##   ##  ##   ##   ##  ##   ##  ##    ##         #" << endl;
    cout << "#          ## ##   ### ###  ###  ##  ### ##            ##   ##   ## ##   ###  ##  ### ###    ##         #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#########################################################################################################" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#   Account Holder's Name:                                          Amount:                             #" << endl;
    cout << "#    ___________________________________________                    _________________________           #" << endl;
    cout << "#   |                                           |                  |                         |          #" << endl;
    cout << "#   |   " << setw(27) << left << add_bank << "             |                  |  " << setw(23) << left << add_bank << "|          #" << endl;
    cout << "#   |___________________________________________|                  |_________________________|          #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#   Account Number:                                             Instructions:                           #" << endl;
    cout << "#    _______________________________________                    1) Send money to send to users          #" << endl;
    cout << "#   |                                       |                   2) Back to trading page                 #" << endl;
    cout << "#   |   " << setw(27) << left << add_bank << "         |                   3) To send money to reciving accounts   #" << endl;
    cout << "#   |_______________________________________|                   4) View transaction Histories           #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#--------------------------------------------- Banks Available -----------------------------------------#" << endl;
    cout << "#   Serial No.         Account holder name            Account Number               Bank Name            #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#########################################################################################################" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#                                     ______________________________                                    #" << endl;
    cout << "#                                    |                              |                                   #" << endl;
    cout << "#                                    |                              |                                   #" << endl;
    cout << "#                                    |______________________________|                                   #" << endl;
    cout << "#                                                                                                       #" << endl;
    cout << "#########################################################################################################";
    gotoxy(20, 39);
    gotoxy(20, 40);
    gotoxy(20, 41);
    gotoxy(20, 42);
    gotoxy(20, 43);
    gotoxy(20, 44);
    gotoxy(20, 45);
    gotoxy(20, 46);
    gotoxy(20, 47);
    gotoxy(20, 48);
    gotoxy(20, 49);
    gotoxy(20, 50);
    gotoxy(20, 51);
    gotoxy(20, 52);
    gotoxy(20, 53);
    gotoxy(20, 54);
    gotoxy(20, 55);
}