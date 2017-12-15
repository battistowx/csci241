#ifndef MATRIX_H
#define MATRIX_H

//*****************************************************************
// FILE:      Matrix.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  3/9/2017
// 
// PURPOSE:   Contains the declaration for the Matrix class.
//*****************************************************************

#include <ostream>

class Matrix {
	
	private:
		int matrixArray[2][2];
	
	public:
		//default constructor
		Matrix();
		//array initialization constructor
		Matrix(int[][2]);
		//finds determinant of the Matrix object
		int determinant() const;
		//operator that adds two matrices together
		Matrix operator+(const Matrix&) const;
		//operator that does scalar multiplication of the two matrices (right hand side)
		Matrix operator*(const int&) const;
		//operator that uses the matrix multiplication expression (left hand side)
		Matrix operator*(const Matrix&) const;
		//bool operator that tests if the elements of the left and right operands are equal
		bool operator==(const Matrix&) const;
		//bool operator that tests if the left operand does not equal the right operand
		bool operator!=(const Matrix&) const;
		//friend function for printing
		friend std::ostream& operator<<(std::ostream& output, const Matrix& beta);	
		//friend function for multiplying
		friend Matrix operator*(const int& operand, const Matrix& beta);
		
};	
	
#endif
