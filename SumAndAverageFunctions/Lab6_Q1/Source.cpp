//Author: Ayush Das
//Creation Date: 2/21/2020
//Modification Date: 2/21/2020
//Purpose: To calculate the sum of 0 - n integers. 

#include <iostream>;
using namespace std;
//This function calculates the sum of 0-n integers.
int calculateSum(int n) {
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}
//This function calculates the average of 0 - n integers. 
float calculateAverage(int sum, int n) {
	return 1.0 * sum / n;
}
//Main code is a lot easier to read with functions 
int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	int sum = calculateSum(n);
	float avg = calculateAverage(sum, n);
	cout << "Sum = " << sum << endl;
	cout << "Average = " << avg << endl;
	return 0;
}
