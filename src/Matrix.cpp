#include "Matrix.h"

Matrix::Matrix(int size) {
    m_size = size;
    m_mat.resize(size);
    for (int i = 0; i < size; i++) {
        m_mat[i].resize(size);
    }
}

Matrix::Matrix(std::vector<std::vector<int>>& mat) {
    m_size = mat.size();
    m_mat = mat; 
}

int& Matrix::operator()(int row, int col) {
    if (!bounds_check(row, col)) {
        exit(EXIT_FAILURE);
    }
    return m_mat[row][col];
}

int Matrix::operator()(int row, int col) const {
    if (!bounds_check(row, col)) {
        exit(EXIT_FAILURE);
    }
    return m_mat[row][col]; // Return the actual element, not (row, col)
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m_size);
    for (int row_index = 0; row_index < m_size; row_index++) {
        for (int col_index = 0; col_index < m_size; col_index++) {
            result(row_index, col_index) = (*this)(row_index, col_index) + other(row_index, col_index);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(m_size);
    for (int row_index = 0; row_index < m_size; row_index++) {
        for (int col_index = 0; col_index < m_size; col_index++) {
            result(row_index, col_index) = (*this)(row_index, col_index) - other(row_index, col_index);
        }
    }
    return result;
}

Matrix Matrix::operator*(int scalar) {
    Matrix result = *this; // Create a copy to modify
    for (int row_index = 0; row_index < m_size; row_index++) {
        for (int col_index = 0; col_index < m_size; col_index++) {
            result(row_index, col_index) *= scalar;
        }
    }
    return result;
}

int Matrix::getSize() const {
    return m_size;
}

bool Matrix::bounds_check(unsigned int row, unsigned int col) const {
    if (row >= m_size || col >= m_size) {
        std::cerr << "Out of bounds" << std::endl;
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    for (int row_index = 0; row_index < mat.getSize(); row_index++) {
        for (int col_index = 0; col_index < mat.getSize(); col_index++) {
            os << mat(row_index, col_index) << " "; // Add space between elements
        }
        os << "\n";
    }
    return os;
}