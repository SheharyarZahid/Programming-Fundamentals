
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MAX_USERS = 10;
const int MAX_TRANSACTIONS = 10;
const int MAX_DESCRIPTION_LENGTH = 50;

string usernames[MAX_USERS];
double balances[MAX_USERS];
string transactionHistoriesUsernames[MAX_USERS];
string transactionDescriptions[MAX_USERS][MAX_TRANSACTIONS];
double transactionAmounts[MAX_USERS][MAX_TRANSACTIONS];
int transactionCounts[MAX_USERS];

void saveDataToFile() {
    ofstream file("userdata.txt");

    if (file.is_open()) {
        for (int i = 0; i < MAX_USERS; ++i) {
            file << usernames[i] << " " << balances[i] << " " << transactionHistoriesUsernames[i] << " " << transactionCounts[i] << endl;

            for (int j = 0; j < transactionCounts[i]; ++j) {
                file << transactionDescriptions[i][j] << " " << transactionAmounts[i][j] << endl;
            }
            file << "---" << endl; // Separate user data
        }

        file.close();
        cout << "Data saved to file." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadDataFromFile() {
    ifstream file("userdata.txt");

    if (file.is_open()) {
        for (int i = 0; i < MAX_USERS; ++i) {
            file >> usernames[i] >> balances[i] >> transactionHistoriesUsernames[i] >> transactionCounts[i];

            // Read transactions
            for (int j = 0; j < transactionCounts[i]; ++j) {
                file >> transactionDescriptions[i][j] >> transactionAmounts[i][j];
            }
        }

        file.close();
        cout << "Data loaded from file." << endl;
    } else {
        cout << "File not found. Initializing with default data." << endl;
        // Initialize with default data if the file doesn't exist
        for (int i = 0; i < MAX_USERS; ++i) {
            usernames[i] = "user" + to_string(i + 1);
            balances[i] = 1000.0 * (i + 1);
            transactionHistoriesUsernames[i] = usernames[i];
            transactionCounts[i] = 0;
        }
    }
}

void viewAllUsers() {
    cout << "All Users:" << endl;
    cout << setw(15) << "Username" << setw(15) << "Balance" << endl;
    for (int i = 0; i < MAX_USERS; ++i) {
        cout << setw(15) << usernames[i] << setw(15) << fixed << setprecision(2) << balances[i] << endl;
    }
    cout << endl;
}

void viewAllTransactions() {
    cout << "Transaction History for All Users:" << endl;
    cout << setw(15) << "Username" << setw(15) << "Description" << setw(15) << "Amount" << endl;
    for (int i = 0; i < MAX_USERS; ++i) {
        for (int j = 0; j < transactionCounts[i]; ++j) {
            cout << setw(15) << transactionHistoriesUsernames[i]
                 << setw(15) << transactionDescriptions[i][j]
                 << setw(15) << fixed << setprecision(2) << transactionAmounts[i][j] << endl;
        }
    }
    cout << endl;
}

void addTransaction(int userIndex, const string& description, double amount) {
    // Check if there is space for a new transaction
    if (transactionCounts[userIndex] < MAX_TRANSACTIONS) {
        transactionHistoriesUsernames[userIndex] = usernames[userIndex];
        transactionDescriptions[userIndex][transactionCounts[userIndex]] = description.substr(0, MAX_DESCRIPTION_LENGTH - 1);
        transactionAmounts[userIndex][transactionCounts[userIndex]] = amount;
        transactionCounts[userIndex]++;
        balances[userIndex] += amount;
        saveDataToFile(); // Save data after adding transaction
        cout << "Transaction added successfully." << endl;
    } else {
        cout << "Transaction limit reached for user." << endl;
    }
}

int findUserIndexByUsername(const string& username) {
    for (int i = 0; i < MAX_USERS; ++i) {
        if (usernames[i] == username) {
            return i;
        }
    }
    return -1; // User not found
}


int main() {
    // Load data from file on startup
    loadDataFromFile();

    int choice = 0;  // Move the initialization outside the switch statement
    string username, description;
    double amount;

    while (true) {
        cout << "Money Management System - Admin Panel" << endl;
        cout << "1. View All Users" << endl;
        cout << "2. View All Transactions" << endl;
        cout << "3. Add Transaction to User" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
int userIndex =-1;
        switch (choice) {
            case 1:
                viewAllUsers();
                break;
            case 2:
                viewAllTransactions();
                break;
            case 3:
                cout << "Enter the username: ";
                cin >> username;
                  userIndex = findUserIndexByUsername(username);
                if (userIndex != -1) {
                    cout << "Enter the transaction description: ";
                    cin.ignore(); // Clear the buffer
                    getline(cin, description);
                    cout << "Enter the transaction amount: ";
                    cin >> amount;
                    addTransaction(userIndex, description, amount);
                } else {
                    cout << "User not found." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

