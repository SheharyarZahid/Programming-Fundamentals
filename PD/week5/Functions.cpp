//                task1
void myFunction()
{
	cout<<"The value of the x is: " << x << endl;
	int x = 20;
}
//               task2
float pyramidVolume(float length, float width, float height, string unit){
	float result =(length*width*height)/3;
	if(unit=="millimeters"){
	result=result*1000000000;
	}
	if(unit=="centimeters"){	
	result=result*1000000;
	}
	if(unit=="kilometers"){
	cout << result << endl;
	result=result/1000000000;
	}
	return result;
}
//                task3
float tax(char vehicletype,float price){
    float taxrate;
    if(vehicletype=='M'){
    taxrate=6;
    }
    if(vehicletype=='E'){
    taxrate=8;
    }
    if(vehicletype=='S'){
    taxrate=10;
    }
    if(vehicletype=='V'){
    taxrate=12;
    }
    if(vehicletype=='T'){
    taxrate=15;
    }
    float taxamount=price*(taxrate/100);
    price=price+taxamount;
    return price;
}
//                     task4
int projectTimeCalculation(int neededhours,int workers,int days){
    float remainig_hours=(days*10*workers);
    remainig_hours=remainig_hours-(remainig_hours*(0.1));
    return remainig_hours;
}
