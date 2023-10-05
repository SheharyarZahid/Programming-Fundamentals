#include<iostream>

using namespace std;

string OddishOrEvenish(int number);

main(){
	int firstNum, secondNum, thirdNum, fourthNum, fifthNum;
	int number, numberSum;

	cout << "Enter a five-digit number: ";
	cin >> number;
	
	secondNum=(number%10);
	number=number/10;
	
	firstNum=(number%10);
	number=(number/10);
	
	thirdNum=(number%10);
	number=number/10;
	
	fourthNum=(number%10);
	number=number/10;
	
	fifthNum=(number%10);

	numberSum= firstNum + secondNum + thirdNum + fourthNum + fifthNum;
	
	string result;
	result=OddishOrEvenish(numberSum);
	cout << result;

}

string OddishOrEvenish(int number){
	if(number % 2 != 0){
	return "Oddish";
	}

	if(number %2 == 0){
	return "Evenish";
	}

}