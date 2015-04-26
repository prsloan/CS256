/* project2-2.cpp : The Matrix calculator. It adds them, subtracts them, takes input from
/	the user or from a file.  Oh, and it can transpose them too.  All of this without the
/	need for cumbersome [] notations.  That's right, it allocates memory dynamically, like
/	a boss.  This thing is just awesome.
/
//*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int** userInput(int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
int menu();
int** mutiplyMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);
int** subtractMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);
int** addMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);
int** transpose(int **matrix, int cols, int rows);


int main()
{
	int rows1, cols1, rows2, cols2;
	int menuChoice = 0;;
	int** matrix1;
	int** matrix2;
	int** resultMatrix;
	int choice = 0;
	string fileName;
	ifstream input;
	string num;


	cout << "Welcome to the Matrix... Calculator" << endl;

	cout << "Chose:\n\t 1. to input the matricies with a file.\n" << "\t2.to input the matricies manually\n" << endl;
	cout << "Enter Choice :";
	cin >> choice;


	if (choice == 2){
		cout << "Enter the Number of rows in matrix 1 :";
		cin >> rows1;
		cout << "\nEnter the Number of columns in matrix 1 :";
		cin >> cols1;
		cout << "Enter the Number of rows in matrix 2 :";
		cin >> rows2;
		cout << "\nEnter the Number of columns in matrix 2 :";
		cin >> cols2;
		matrix1 = userInput(rows1, cols1);
		matrix2 = userInput(rows2, cols2);
	}

	///Input the matricies from a user specified file.
	else if (choice == 1){
		cout << " What is the name of the file :";
		
		cin >> fileName;
		input.open("array.txt");
		if (!input) {
			cout << "Error: Can't open the file named arrau.txt.\n";
			exit(1);
		}
		if (input.is_open()){
			
			input >> cols1;
			input >> rows1;
			matrix1 = new int*[rows1];
			//make matrix1
			for (int i = 0; i < rows1; i++){
				for (int j = 0; j < cols1; j++){
					*matrix1 = new int;
					input >> **matrix1;
					if (j<cols1 - 1)
						*matrix1++;
				}
				if (i<rows1 - 1)
					matrix1++;
			}
			matrix1 = matrix1 - (rows1*cols1) + 1;
			//make matrix2
			input >> cols2;
			input >> rows2;
			matrix2 = new int*[rows2];

			for (int i = 0; i < rows2; i++){
				for (int j = 0; j < cols2; j++){
					*matrix2 = new int;
					input >> **matrix2;
					if (j<cols2 - 1)
						*matrix2++;
				}
				if (i<rows2 - 1)
					matrix2++;
			}
			matrix2 = matrix2 - (rows2*cols2) + 1;

		}
		
	}

	printMatrix(matrix1, rows1, cols1);
	printMatrix(matrix2, rows2, cols2);
	system("pause");

	while (menuChoice != 6){
		menuChoice = menu();

		if ((menuChoice == 1) && (cols1 == rows2))
			resultMatrix = mutiplyMatricies(matrix1, matrix2, rows1, cols1, rows2, cols2);
		else if (menuChoice == 1){
			cout << "Cannot Multiply Matricies, please make a different choice." << endl;
			system("pause");
		}
		// ensure the matricies are the same size so that they can be added
		else if ((menuChoice == 2) && (cols1 == cols2) && (rows1 == rows2))
			resultMatrix = addMatricies(matrix1, matrix2, rows1, cols1, rows2, cols2);
		// otherwise, throw an error message and send the user back to the menu.
		else if (menuChoice == 2){
			cout << "Cannot Add Matricies, please make a different choice." << endl;
			system("pause");
		}
		//emsure the matricies are the same size so they can be subtracted
		else if ((menuChoice == 3) && (cols1 == cols2) && (rows1 == rows2))
			resultMatrix = subtractMatricies(matrix1, matrix2, rows1, cols1, rows2, cols2);
		//otherwise send the user back to the menu with an error message.
		else if (menuChoice == 3){
			cout << "Cannot Subtract Matricies, please make a different choice." << endl;
			system("pause");
		}
		//let the user chose which matrix to transpose
		else if ((menuChoice == 4)){
			system("cls");
			cout << " Chose a matrix :\n\n Matrix 1:";
			printMatrix(matrix1, rows1, cols1);
			cout << "Matrix 2:";
			printMatrix(matrix2, rows2, cols2);
			cout << "Enter Choice: ";
			int newChoice, temp;

			cin >> newChoice;
			if (newChoice == 1){
				resultMatrix = transpose(matrix1, cols1, rows1);
				matrix1 = resultMatrix;
				//swap the rows and colums
				temp = cols1;
				cols1 = rows1;
				rows1 = temp;
				printMatrix(resultMatrix, rows1, cols1);
				system("pause");
			}
			else if (newChoice == 2){
				resultMatrix = transpose(matrix2, cols2, rows2);
				matrix2 = resultMatrix;
				//swap the matricies
				temp = cols2;
				cols2 = rows2;
				rows2 = temp;
				printMatrix(resultMatrix, rows2, cols2);
				system("pause");
			}
		}
		//get new rows and columns for the matricies and call the userInput method to populate
		// the new matricies.
		else if (menuChoice == 5){
			system("cls");
			cout << "Enter the Number of rows in matrix 1 :";
			cin >> rows1;
			cout << "\nEnter the Number of columns in matrix 1 :";
			cin >> cols1;
			cout << "Enter the Number of rows in matrix 2 :";
			cin >> rows2;
			cout << "\nEnter the Number of columns in matrix 2 :";
			cin >> cols2;
			matrix1 = userInput(rows1, cols1);
			matrix2 = userInput(rows2, cols2);
		}
		//Exit the program
		else if (menuChoice == 6){
			system("cls");
			cout << "Thanks for using the matrix calculator!\n";
			system("pause");
		}
	}
	

	return 0;
}



/*******************************************
/  This method takes the user input for the matrix and returns
   it to the driver program.  The input is the rows and colomns
   given in the driver program.  
   *******************************************/

int** userInput(int rows, int cols){

	int **matrix;

	matrix = new int*[rows];

	for (int i = 0; i < rows; i++){
		cout << "Enter the values for row " << i + 1 << " seperated by a space. There should be " << cols << ": " << endl;
		for (int j = 0; j < cols; j++){
			*matrix = new int;
			cin >> **matrix;
			if (j<cols - 1)
				*matrix++;
		}
		if (i<rows - 1)
			matrix++;
	}
	matrix = matrix - (rows*cols) + 1;

	return matrix;

}

/***************************************
	This method tales in some matrix and
	prints it out.  It also needs the number
	of rows and columns in order to print it 
	correctly.
	***************************************/
void printMatrix(int **matrix, int rows, int cols){           
	cout << "\n" << endl;
	for (int i = 0; i < rows; i++){					  //Cycle through the rows
		cout << "\n";
		for (int j = 0; j < cols; j++){				  //Cycle through the columns
			cout << "[" << **matrix << "]\t ";
			if (j<cols - 1)
				*matrix++;								//Advance the inner array
		}
		if (i<rows - 1)
			matrix++;									//Advance to the next row
	}
	cout << "\n\n";
}
/*****************************************
	This is the main menu.  It will take 
	the user's selection and return it
	as an int to the program.
	***************************************/
int menu(){
	int selection;
	system("cls");
	cout << "Select an operation to perform :" << endl;
	cout << "\n\t 1. Multiply the matricies" << endl;
	cout << "\t 2. Add the matricies" << endl;
	cout << "\t 3. Subtract one matix from another" << endl;
	cout << "\t 4. Transpose a matrix" << endl;
	cout << "\t 5. Enter new matricies." << endl;
	cout << "\t 6. Exit the program."<<endl;
	cout << "\n Selection :" << endl;
	cin >> selection;

	return selection;
}

/********Set of Marix Operation Functions**********/

int** mutiplyMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2){
	int **product;
	int element = 0;
	int **A, **B;

	//


	A = matrix1;
	B = matrix2;

	//create secondary pointers
	product = new int*[rows1];

	for (int j = 0; j < rows1; j++){
		//populate the array :
		for (int k = 0; k < cols2; k++){
			*product = new int;
			**product = 0;
			for (int x = 0; x < cols1; x++)
				**product += (**(A + x))*(**(B + cols2*x));
			if (k < cols2 - 1)
				B++;
			if (k < cols2 - 1)
				*product++;
		}
		B -= cols2 - 1;
		A += cols1;
		if (j<rows1 - 1)
			product++;
	}

	product = product - (rows1*cols2) + 1;


	return product;

}
/*********************************
	Add the matricies together
	
************************************/
int** addMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2){
	int **sumMatrix;
	int **A, **B;

	A = matrix1;
	B = matrix2;

	sumMatrix = new int*[rows1];
	for (int j = 0; j < rows1; j++){
		//populate the array :
		for (int k = 0; k < cols1; k++){
			*sumMatrix = new int;
			**sumMatrix = **A + **B;
			A++;
			B++;
			if (k < cols2 - 1)
				*sumMatrix++;
		}
		if (j<rows1 - 1)
			sumMatrix++;
	}

	sumMatrix = sumMatrix - (rows1*cols2) + 1;




	return sumMatrix;
}
/**************************************
        Subtract the Matricies
		
***************************************/
int** subtractMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2){
	int **difMatrix;
	int **A, **B;

	A = matrix1;
	B = matrix2;

	//create secondary pointers
	difMatrix = new int*[rows1];

	for (int j = 0; j < rows1; j++){
		//populate the array :
		for (int k = 0; k < cols1; k++){
			*difMatrix = new int;
			**difMatrix = **A - **B;
			A++;
			B++;
			if (k < cols2 - 1)
				*difMatrix++;
		}
		if (j<rows1 - 1)
			difMatrix++;
	}

	difMatrix = difMatrix - (rows1*cols2) + 1;

	return difMatrix;
}
/************************************************
	Transpose a given matrix.
	
***********************************************/
int** transpose(int **matrix, int cols, int rows){

	int** result;
	int **base = matrix;
	result = new int*[rows];

	//make the columns
	for (int j = 0; j < cols; j++){
		for (int i = 0; i < rows; i++){
			*result = new int;
			**result = **matrix;
			if (i < rows - 1){
				result++;
				matrix += cols;
			}
		}
		matrix = base;
		matrix += j+1;
		if (j<cols-1)
			result++;
	}

	result -= ((rows*cols) - 1);

	return result;
}