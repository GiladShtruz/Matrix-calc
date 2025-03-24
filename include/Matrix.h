#pragma once
#include <iostream>
#include <vector>
#include <iostream>

class Matrix {
public:
	Matrix(int size);
	Matrix(std::vector<std::vector<int>>& mat);
	int& operator()(int row, int col);
	int operator()(int row, int col) const;
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(int scalar);
	int getSize() const;
private:
	bool bounds_check(unsigned int row, unsigned int col) const;
	std::vector<std::vector<int>> m_mat;
	unsigned int m_size;
};

std::ostream& operator<<(std::ostream& os, const Matrix& mat);

