#include "Matrix.h"

Matrix::Matrix(int size) {
	m_size = size;
	m_mat.resize(size);
	for (int i = 0; i < size; i++) {
		m_mat[i].resize(size);
	}
}

Matrix::Matrix(std::vector<std::vector<int>>& mat)
{
	m_size = mat.size();
	m_mat = mat;
}

int& Matrix::operator()(int row,int col)
{
	if (!bounds_check(row, col)) {
		exit(EXIT_FAILURE);
	}
	return m_mat[row][col];
}

int Matrix::operator()(int row, int col) const
{
	if (!bounds_check(row, col)) {
		exit(EXIT_FAILURE);
	}
	return m_mat[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const
{
	auto newMatrix = std::vector<std::vector<int>>();
	for (int row_index = 0; row_index < m_size; row_index++) {
		std::vector<int> row;
		for (int col_index = 0; col_index < m_size; col_index++) {
			int val = (*this)(row_index)(col_index);
			val += other(row_index)(col_index);
			row.push_back(val);
		}
		newMatrix.push_back(row);
	}
	return Matrix(newMatrix);
}

Matrix Matrix::operator-(const Matrix& other) const
{
	auto result = Matrix(other);
	result = result * -1;
	result = result + *this;
	return Matrix(result);
}

Matrix Matrix::operator*(int scalar)
{
	for (int row_index = 0; row_index < m_size; row_index++) {
		for (int col_index = 0; col_index < m_size; col_index++) {
			(row_index)(col_index) *= scalar;
		}
	}
	return Matrix(*this);
}

int Matrix::getSize() const
{
	return m_size;
}

bool Matrix::bounds_check(unsigned int row, unsigned int col) const
{
	if (row >= m_size || col >= m_size) {
		std::cerr << "Out of bounds" << std::endl;
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
	for (int row_index = 0; row_index < mat.getSize(); row_index++) {
		for (int col_index = 0; col_index < mat.getSize(); col_index++) {
			os << mat(row_index)(col_index);
		}
		os << " ";
	}
	os << "\n";
	return os;
}
