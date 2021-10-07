//Author: Ayush Das
//Creation Date: 3/17/20
//Modification Date: 3/17/20
//Purpose: To run a simple calculator simulator in C++

#include <iostream>
#include <string>

using namespace std;

//Function prototypes
string WelcomeMessage();
int Menu();
float ComputeSum(float a, float b);
float ComputeSub(float a, float b);
float ComputeMul(float a, float b);
float ComputeDiv(float a, float b);
float ComputeRoot(float root, int index);
float ComputePower(float x, int n);
float ComputePerc(float a, float b);
int ComputeLCM(int a, int b);
int ComputeGCD(int a, int b);
int ComputeMod(int a, int b);
string ExitMessage();

//Welcome message

string WelcomeMessage() {

	return "WELCOME TO THE CALCULATOR PROJECT\n";
}

//Addition function


float ComputeSum(float a, float b) {

	return (a + b);
}

//Subtraction function 

float ComputeSub(float a, float b) {

	return (a - b);
}

//Multiplication function

float ComputeMul(float a, float b) {

	return (a * b);
}

//Division function

float ComputeDiv(float a, float b) {

	return (a / b);
}

//Root function

float ComputeRoot(float root, int index) {

	float tp, mid, low = 0.0, high = root;

	do {

		mid = (low + high) / 2;

		if (ComputePower(mid, index) > root)

			high = mid;

		else

			low = mid;

		mid = (low + high) / 2;

		tp = (ComputePower(mid, index) - root);

		if (tp < 0) { 

			tp = -tp;

		}

	}

	while (tp > .000005); 

	return mid;
}


//Power function

float ComputePower(float x, int n) {

	float numProduct = 1.0;

	int i;

	for (i = 0; i < n; i++)

		numProduct *= x;

	return numProduct;
}

//Percentage function 

float ComputePerc(float a, float b) {

	return (a * b / 100);
}


//Least common multiplier function

int ComputeLCM(int a, int b) {

	return ((a * b) / ComputeGCD(a, b));
}

//Greatest common divisor function

int ComputeGCD(int a, int b) {

	while (a != b) {

		if (a > b)

			a -= b;

		else

			b -= a;

	}

	return a;
}

//Modulus function 

int ComputeMod(int a, int b) {
	
	return (a % b);

}

//Displays function execution 

string ExitMessage() {

	return "EXIT. THANK YOU FOR USING SUPER FAST CALCULATOR\n";
}

//Displays menu 

int Menu() {

	float x, y; //Two variables that are in the functions 

	char Input; //Menu input

	//Displaying the menu

	while (true) {


		cout << " A. Addition" << endl;

		cout << " B. Substraction" << endl;

		cout << " C. Multiplication" << endl;

		cout << " D. Division" << endl;

		cout << " E. Root" << endl;

		cout << " F. Power" << endl;

		cout << " G. Percentage" << endl;

		cout << " H. LCM" << endl;

		cout << " I. GCD"<< endl;

		cout << " J. Modulus" << endl;

		cout << " K. Quit" << endl;

		cout << "*******************************************************************************" << endl;

		cout << "Please select an operation: "; //Asks user for menu option		


		cin >> Input; //User inputs menu option

		switch (Input) {

		case 'A':
			
			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;




			cout << "Operation: " << x << " + " << y << " = " << ComputeSum(x, y); 

			cout << endl;

			break;

		case 'B':

			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;


			cout << "Operation: " << x << " - " << y << " = "

				<< ComputeSub(x, y); //call a computeSubstraction function to handle this option.

			cout << endl;

			break;

		case 'C':

			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;




			cout << "Operation: " << x << " x " << y << " = "

				<< ComputeMul(x, y); //call a computeMul function to handle this option.

			cout << endl;

			break;



		case 'D':

			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;




			//checking for the zero value in second value

			//If it is zero, then we will ask the user to input a value that is greater than 0. 

			while (y == 0) {

				cout << "We cannot divide anything by 0, please enter another value that is greater than 0: ";

				cin >> y;

			}

			cout << "Operation: " << x << " / " << y << " = "

				<< ComputeDiv(x, y); //Call a function to handle this operation. 

			cout << endl;

			break;

		case 'E':

			cout << "Please provide the number you want to take the root of: ";

			cin >> x;

			cout << "Please provide the root degree: ";

			cin >> y;




			//Here we are checking for the values to be positive since we can't perform root on negative values.

			//If it is negative then we will ask the user to enter a positive number.

			while (y < 0) {

				cout << "We can not perform Root operation with negative values, please enter first value greater than 0: ";

				cin >> y;

			}

			//Here we are checking for the values to be positive since we can't perform root on negative values.

			//If it is negative then we will ask the user to enter a positive number.

			while (x < 0) {

				cout << "We can not perform Root operation with negative values, please enter a root degree that is greater than 0: ";

				cin >> x;

			}

			//Here, y is the root degree and x is the base value. 

			cout << "Operation:  " << y << " root of " << x << " = " << ComputeRoot(x, y); //Call a function to handle this operation.

			cout << endl;

			break;

		case 'F':

			cout << "Please provide the base number: ";

			cin >> x;

			cout << "Please provide the exponent: ";

			cin >> y;

			//Here we are checking for the values to be positive since we can't perform power on negative values.

			//If it is negative then we will ask the user to enter a positive number

			while (y < 0) {

				cout << "We can not perform Root operation with negative values, please enter an exponent greater than 0: ";

				cin >> y;

			}

			//Here we are checking for the values to be positive since we can't perform power on negative values.

			//If it is negative then we will ask the user to enter a positive number.

			while (x < 0) {

				cout << "We can not perform Root operation with negative values, please enter a base number greater than 0: ";

				cin >> x;

			}

			cout << "Operation: " << x << "^" << y << " = " << ComputePower(x, y); //Call a function to handle this operation.

			cout << endl;

			break;

		case 'G':
			cout << "Please provide the percent: ";

			cin >> x;

			cout << "Please provide the number you want to take the percentage of: ";

			cin >> y;

			//While statements that asks the users to enter a positive number if a negative number is entered. 

			while (y < 0) {
				cout << "We cannot perform the percentage operation with negative values, please enter second number greater than 0: " << endl;
				cin >> y;

				break;
			}

			while (x < 0) {
				cout << "We cannot perform the percentage operation with negative values, please enter a percentage greater than 0: " << endl;
				cin >> x;

				break;
			}

			cout << "Operation: "  << x << " % " << y << " = "

				<< ComputePerc(x, y);  
			
			cout << endl;

			break;

		case 'H':

			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;
			
			//While statements that asks the users to enter a positive number if a negative number is entered. 
			while (x < 0) {
				cout << "The LCM operation shall not work with negative numbers, please enter first number greater than 0: " << endl;
				cin >> x;
				break;
			}

			while (y < 0) {
				cout << "The LCM operation shall not work with negative numbers, please enter second number greater than 0: " << endl;
				cin >> y;
				break;
			}
			cout << "Operation: The LCM of " << x << " and " << y << " is : " << ComputeLCM(x, y); 

			cout << endl;

			break;

		case 'I':

			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;

			//While statements that asks the users to enter a positive number if a negative number is entered. 
			while (x < 0) {
				cout << "The GCD operation shall not work with negative numbers, please enter first number greater than 0: " << endl;
				cin >> x;
				break;
			}

			while (y < 0) {
				cout << "The GCD operation shall not work with negative numbers, please enter second number greater than 0: " << endl;
				cin >> y;
				break;
			}


			cout << "Operation: The GCD of " << x << " and " << y << " is : " << ComputeGCD(x, y); //Call the ComputeGCD() function to handle this operation.

			cout << endl;

			break;

		case 'J':
			cout << "Please provide the first number: ";

			cin >> x;

			cout << "Please provide the second number: ";

			cin >> y;

			
			cout << "The modulus of " << x << " and " << y << " is : " << ComputeMod(x, y); //Using ComputeMod() function to handle this operation. 
			cout << endl;
			break;


		case 'K':

				cout << "*******************************************************************************" << endl;

				//Using getExitMessage() function to display the exit message.

				cout << "\t\t" << ExitMessage();

				cout << "*******************************************************************************" << endl;

				return 0;

				break;

		
		default:

			//The user is asked to enter another input if they enterd a wrong menu option. 
			cout << "invalid input" << endl;
			cout << "Please enter a valid menu option." << endl;
	


			break;

		}

		

	}


}

//Main function 

int main() {

	cout << "*******************************************************************************" << endl;

	

	cout << "\t\t" << WelcomeMessage(); //This function is called to present the welcome message

	cout << "*******************************************************************************" << endl << endl;
	return Menu();
	return 0;

}
