#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void search(int &fileindex);
void writeData(string names, string passwords, string cnic,string role);
void readData(string names[], string passwords[], string cnic[],string role[] , int &index);
void edit_string(string &name, string &cnic, string &password, string &role, string namearray[], string passwordarray[], string rolearray[], string cnicarray[], int &indexCount);
string getField(string record, int field);
int searchArray(string arr[], string object, int &indexCount);
void writeUpdatedData(string namearray[], string passwordarray[], string cnicarray[], string rolearray[], int indexCount);
main(){
    string namefile[100];
    string passwordfile[100];
    string cnicfile[100];
    string role[100];
    int fileindex=0;
    search(fileindex);
    readData(namefile,passwordfile,cnicfile,role,fileindex); // Read data into arrays
    string name,password,cnic,roles;
    cin>>name>>password>>cnic>>roles;
    edit_string(name,cnic,password,roles,namefile,passwordfile,role,cnicfile,fileindex);
    writeUpdatedData(namefile, passwordfile, cnicfile, role, fileindex);
    readData(namefile,passwordfile,cnicfile,role,fileindex);
    fileindex--;
    cout<<"\t"<<fileindex<<endl;
    for(int i=0;i<fileindex;i++){
        cout<<"\t"<<namefile[i]<<endl;
        cout<<"\t"<<passwordfile[i]<<endl;
        cout<<"\t"<<cnicfile[i]<<endl;
        cout<<"\t"<<role[i]<<endl;
    }
}
void writeUpdatedData(string namearray[], string passwordarray[], string cnicarray[], string rolearray[], int indexCount) {
    fstream data;
    data.open("a.txt", ios::out); 

    if (data.is_open())
    {
        for (int i = 0; i < indexCount; i++) {
            data << namearray[i] << "," << passwordarray[i] << "," << cnicarray[i] << "," << rolearray[i] << endl;
        }
        data.close();
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}
//                                                       edit string
void edit_string(string &name, string &cnic, string &password, string &role, string namearray[], string passwordarray[], string rolearray[], string cnicarray[], int &indexCount)
{
    system("cls");
    int dataIndex = searchArray(namearray, name, indexCount);
    cout<<dataIndex<<endl;
    if (dataIndex != -1) {
        // Modify the values in the arrays
        namearray[dataIndex] = name;
        passwordarray[dataIndex] = password;
        rolearray[dataIndex] = role;
        cnicarray[dataIndex] = cnic;
        // Write the updated data to the file
        writeUpdatedData(namearray, passwordarray, cnicarray, rolearray, indexCount);
    }
    getch();
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
//                                            search
void search(int &fileindex){
    fstream file;
    string line="";
    file.open("a.txt",ios:: in);
    getline(file,line);
    if(line==""){
        fileindex=0;
    }
    else{
        while(!file.eof()){
            getline(file,line);
            fileindex++;
        }
    }
}
//                                             write data
void writeData(string name,  string password,  string cnic, string role)
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
//                                             read data
void readData(string names[], string passwords[], string cnic[],string role[], int &index)
{
string record;
fstream data;
data.open("a.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
names[index] = getField(record, 1);
passwords[index] = getField(record, 2);
cnic[index] = getField(record, 3);
role[index] = getField(record, 4);
index ++;
}
}
//                                                getfield
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



