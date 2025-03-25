#include "Matrix.h"
#include "Matrix.h"
#include "Matrix.h"
#include <string>


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

void Matrix::readUserMatrix(int size)
{
    m_size = size;
    std::string sizeStr = std::to_string(size);
    std::cout << "Enter a " + sizeStr + "x" + sizeStr + " matrix:\n";
    for (int i = 0; i < size; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < size; j++)
        {            
            std::cin >> m_mat[i][j];  
        }        
    }
    
    std::cout << std::endl;
}

void Matrix::transpose()
{
    for (int i = 0; i < m_size; i++)
    {
        for (int j = i + 1; j < m_size; j++)
        {
            // swap:
            int temp = m_mat[i][j];
            m_mat[i][j] = m_mat[j][i];
            m_mat[j][i] = temp;
        }
    }
}

void Matrix::printMatrix()
{
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            std::cout << m_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
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