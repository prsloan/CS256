// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>  // for rand and srand
#include <ctime>	//for the time function

using namespace std;


int main()
{	
	//variables
	int num1, num2, answer=0, choice = 0;
	 



	//get time for the seed 
	unsigned seed = time(0);

	//seed the random number generator
	srand(seed); 

	//give the numbers a random value
	num1 = rand() % 1000;
	num2 = rand() % 1000;

	//Display the menu until the user exits
	while (choice != 5)
	{
		cout << "Welcome to the Math Tutor \n" << endl;
		cout << "Choose from the following Options :\n" << endl;
		cout << " 1. Solve an addition problem. " << endl;
		cout << " 2. Solve a subtraction problem." << endl;
		cout << " 3. Solve a division problem." << endl;
		cout << " 4. Solve a multiplication problem" << endl;
		cout << " 5. Exit the program " << endl;
		cout << "\n Enter your choice :";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Solve the following problem : " << endl;
			cout << " " << num1 << " + " << num2 << " = " << endl;
			cout << "\nPlease enter the answer when ready : " << endl;
			cin >> answer;
			if (answer == (num1 + num2))
				cout << " Congratulations!" << endl;
			else
				cout << "\n Sorry, you were wrong. \n " << "The correct answer is : " << (num1 + num2) << "\n" << endl;
			cout << "Press [enter] to return to the main menu." << endl;
			cin.get();
		}
		else if (choice == 2)
		{
			cout << "Solve the following problem : " << endl;
			cout << " " << num1 << " - " << num2 << " = " << endl;
			cout << "\nPlease enter the answer when ready : " << endl;
			cin >> answer;
			if (answer == (num1 - num2))
				cout << " Congratulations!" << endl;
			else
				cout << "\n Sorry, you were wrong. \n " << "The correct answer is : " << (num1 + num2) << "\n" << endl;
			cout << "Press [enter] to return to the main menu." << endl;
			cin.get();
		}
		else if (choice == 3)
		{
			cout << "Solve the following problem : " << endl;
			cout << " " << num1 << " / " << num2 << " = " << endl;
			cout << "\nPlease enter the answer when ready : " << endl;
			cin >> answer;
			if (answer == (num1 / num2))
				cout << " Congratulations!" << endl;
			else
				cout << "\n Sorry, you were wrong. \n " << "The correct answer is : " << (num1 + num2) << "\n" << endl;
			cout << "Press [enter] to return to the main menu." << endl;
			cin.get();
		}
		else if (choice == 4)
		{
			cout << "Solve the following problem : " << endl;
			cout << " " << num1 << " * " << num2 << " = " << endl;
			cout << "\nPlease enter the answer when ready : " << endl;
			cin >> answer;
			if (answer == (num1 * num2))
				cout << " Congratulations!" << endl;
			else
				cout << "\n Sorry, you were wrong. \n " << "The correct answer is : " << (num1 + num2) << "\n" << endl;

			cout << "Press [enter] to return to the main menu." << endl;
			cin.get();

		}
		else if (choice == 5)
			choice = 5;
		else
			cout << "Invalid entry, please enter a valid choice! \n\n" << endl;

	}

	cout << " Good bye! " << endl;
	system("pause");

	return 0;
}

