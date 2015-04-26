// project2-2.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>


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

		else if ((menuChoice == 2) && (cols1 == cols2) && (rows1 == rows2))
			resultMatrix = addMatricies(matrix1, matrix2, rows1, cols1, rows2, cols2);
		else if (menuChoice == 2){
			cout << "Cannot Add Matricies, please make a different choice." << endl;
			system("pause");
		}

		else if ((menuChoice == 3) && (cols1 == cols2) && (rows1 == rows2))
			resultMatrix = subtractMatricies(matrix1, matrix2, rows1, cols1, rows2, cols2);
		else if (menuChoice == 3){
			cout << "Cannot Subtract Matricies, please make a different choice." << endl;
			system("pause");
		}

		else if ((menuChoice == 4)){
			system("cls");
			cout << " Chose a matrix :\n Matrix 1:";
			printMatrix(matrix1, rows1, cols1);
			cout << "Matrix 2:\n";
			printMatrix(matrix2, rows2, cols2);
			cout << "Enter Choice: ";
			int newChoice,temp;
			
			cin >> newChoice;
			if (newChoice == 1){
				resultMatrix = transpose(matrix1, cols1, rows1);
				matrix1 = resultMatrix;
				temp = cols1;
				cols1 = rows1;
				rows1 = temp;
			}
			else if (newChoice == 2){
				resultMatrix = transpose(matrix2, cols2, rows2);
				matrix2 = resultMatrix;
				temp = cols2;
				cols2 = rows2;
				rows2 = temp;
			}
		}
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
		else if (menuChoice == 6){
			system("cls");
			cout << "Thanks for using the matrix calculator!\n";
			system("pause");
		}
		printMatrix(resultMatrix, rows1, cols2);
		system("pause");
	}
	delete matrix1;
	delete matrix2;
	delete resultMatrix;

	return 0;
}





int** userInput(int rows, int cols){

	int **matrix;

	matrix = new int*[rows];

	for (int i = 0; i < rows; i++){
		cout << "Enter the values for row " << i+1 << " seperated by a space. There should be " << cols << ": " << endl;
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


void printMatrix(int **matrix, int rows, int cols){
	cout << "\n" << endl;
	for (int i = 0; i < rows; i++){
		cout << "\n";
		for (int j = 0; j < cols; j++){
			cout << "["<<**matrix<<"]\t ";
			if (j<cols - 1)
				*matrix++;
		}
		if (i<rows - 1)
			matrix++;
	}
}

int menu(){
	int selection;
	system("cls");
	cout << "Select an operation to perform :" << endl;
	cout << "\n\t 1. Multiply the matricies" << endl;
	cout << "\t 2.Add the maticies" << endl;
	cout << "\t 3. Subtract one matix from another" << endl;
	cout << "\t 4. Transpose a matrix" << endl;
	cout << "\t 5. Enter new matricies." << endl;
	cout << "\n Selection :" << endl;
	cin >> selection;

	return selection;
}

/********Set of Marix Operation Functions**********/

int** mutiplyMatricies(int ** matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2){
	int **product;
	int element=0;
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
	
	
	return product  ;

}

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

int** transpose(int **matrix, int cols, int rows){

	int** result;

	result = new int*[cols];
	
	for (int j = 0; j < cols; j++){
		for (int k = 0; k < rows; k++){
			*result = new int;
			**result = **matrix;
			if (k < rows - 1){
				*result++;
				matrix++;
			}
		}
 //place the pointer in the right space to continue the transposition
		if (j<cols - 1)
			*matrix++;
	}

	result--;
	result--;
	result--;
	result--;
	result--;
	result--;
	result--;
	result--;
	result--;

	return result;
}