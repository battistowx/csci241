#include "Matrix.h"
#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>

//*****************************************************************
// FILE:      Matrix.cpp
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  3/9/2017
// 
// PURPOSE:   Contains the class implementation of Matrix.h
//*****************************************************************

using std::cout;
using std::endl;
using std::ostream;

/***************************************************************
Matrix()
Use: This is the default constructor of the Matrix class.  It 
sets all the parameters of the Matrix array to the identity matrix.
Parameters: None
Returns: Nothing
***************************************************************/
Matrix::Matrix() {
	matrixArray[0][0]=1;
	matrixArray[0][1]=0;
	matrixArray[1][0]=0;
	matrixArray[1][1]=1;
};

/***************************************************************
Matrix()
Use: This is the alternate constructor of the Matrix class.  It
sets the elements of the array to the corresponding elements
passed to the constructor.
Parameters: A 2-D array of ints.
Returns: Nothing
***************************************************************/	
Matrix::Matrix(int passedMatrix[][2]) {
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			matrixArray[i][j]=passedMatrix[i][j];
		}
	}
}

/***************************************************************
determinant()
Use: This method calculates and returns the integer determinant
of the Matrix object.
Parameters: None.
Returns: The integer determinant.
***************************************************************/	
int Matrix::determinant() const{
	int ad=matrixArray[0][0] * matrixArray[1][1];
	int bc=matrixArray[0][1] * matrixArray[1][0];
	return ad - bc;
}

/***************************************************************
operator+()
Use: This operator method returns a new Matrix of the sum of the 
matrix 
Parameters: None.
Returns: New matrix object of added matrices
***************************************************************/
Matrix Matrix::operator+(const Matrix& beta) const{
	Matrix mtrx;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++ ) {
			mtrx.matrixArray[i][j]=this->matrixArray[i][j] + beta.matrixArray[i][j];
		}
	}
	return mtrx;
}

/***************************************************************
operator*()
Use: This operator method returns the result of multiplying the
objects' operands as a new matrix object using an integer of the
right operand of scalar multiplication.
Parameters: int of right operand of scalar multiplication
Returns: New matrix object of multiplied values.
***************************************************************/
Matrix Matrix::operator*(const int& rightOperand) const{
	Matrix mtrx;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			mtrx.matrixArray[i][j] *= rightOperand;
		}
	}
	return mtrx;
}

/***************************************************************
operator*()
Use: This operator method returns the result of multiplying the
two matrices as a new matrix object.
Parameters: Matrix object to be multiplied
Returns: New matrix object of multiplied values.
***************************************************************/
Matrix Matrix::operator*(const Matrix& beta) const{
	Matrix mtrx;
	mtrx.matrixArray[0][0]=((this->matrixArray[0][0] * beta.matrixArray[0][0])+(this->matrixArray[0][1] * beta.matrixArray[1][0]));
	mtrx.matrixArray[0][1]=((this->matrixArray[0][0] * beta.matrixArray[0][1])+(this->matrixArray[0][1] * beta.matrixArray[1][1]));
	mtrx.matrixArray[1][0]=((this->matrixArray[1][0] * beta.matrixArray[0][0])+(this->matrixArray[1][1] * beta.matrixArray[1][0]));
	mtrx.matrixArray[1][1]=((this->matrixArray[1][0] * beta.matrixArray[0][1])+(this->matrixArray[1][1] * beta.matrixArray[1][1]));
	return mtrx;
}

/***************************************************************
operator==()
Use: This operator method returns true if the left and right 
operands are equal.
Parameters: Matrix object to be tested with.
Returns: Bool if elements are equal.
***************************************************************/	
bool Matrix::operator==(const Matrix& beta) const{
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			if (this->matrixArray[i][j]!=beta.matrixArray[i][j])
				return false;
			}
		}
	return true;
}

/***************************************************************
operator!=()
Use: This operator method returns true if the left and right 
operands are not equal.
Parameters: Matrix object to be tested with.
Returns: Bool if elements are not equal.
***************************************************************/	
bool Matrix::operator!=(const Matrix& beta) const{
        for (int i=0; i<2; i++) {
                for (int j=0; j<2; j++) {
                        if (this->matrixArray[i][j]==beta.matrixArray[i][j])
                                return false;
                        }
                }
        return true;
}

/***************************************************************
operator<<()
Use: This operator function prints out the matrix passed to it.
Parameters: Matrix object to be printed
Returns: Printed Matrix object.
***************************************************************/
ostream& operator<<(ostream& output, const Matrix& beta) {
	int a=beta.matrixArray[0][0];
	int b=beta.matrixArray[0][1];
	int c=beta.matrixArray[1][0];
	int d=beta.matrixArray[1][1];
	output<<"[["<<a<<", "<<b<<"], ["<<c<<", "<<d<<"]]"<<endl;
	return output;
}

/***************************************************************
operator*()
Use: This operator function multiplies a left hand integer to
the passed matrix and returns a new matrix of the result.
Parameters:  int left operand, matrix object passed
Returns: New matrix object
***************************************************************/
Matrix operator*(const int& operand, const Matrix& beta) {
	Matrix mtrx;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			mtrx.matrixArray[i][j]=operand * beta.matrixArray[i][j];
		}
	}
	return mtrx;
}		 
