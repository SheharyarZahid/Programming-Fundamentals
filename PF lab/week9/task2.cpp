#include <iostream>
#include <string>

void displayStringInReverse(const std::string& inputString) {
    for (int i = inputString.length() - 1; i >= 0; i--) {
        std::cout << inputString[i];
    }
    std::cout << std::endl;
}

int main() {
    std::string inputString;
    
    std::cout << "Enter a string: ";
    std::cin >> inputString;
    
    std::cout << "Reversed String: ";
    displayStringInReverse(inputString);

    return 0;
}
