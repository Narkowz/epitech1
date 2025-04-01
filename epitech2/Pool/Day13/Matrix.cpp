/*
** EPITECH PROJECT, 2025
** Matrix.hpp
** File description:
** Matrix
*/

#include "Matrix.hpp"

template <unsigned int Rows, unsigned int Cols>
Matrix<Rows, Cols>::Matrix()
{
    for (unsigned int i = 0; i < Rows; ++i)
        for (unsigned int j = 0; j < Cols; ++j)
            data[i][j] = 0.0;
}

template <unsigned int Rows, unsigned int Cols>
double Matrix<Rows, Cols>::operator()(unsigned int row, unsigned int col) const
{
    if (row >= Rows || col >= Cols)
        throw std::out_of_range("Matrix indices out of range");
    return data[row][col];
}

template <unsigned int Rows, unsigned int Cols>
double& Matrix<Rows, Cols>::operator()(unsigned int row, unsigned int col)
{
    if (row >= Rows || col >= Cols)
        throw std::out_of_range("Matrix indices out of range");
    return data[row][col];
}

template <unsigned int Rows, unsigned int Cols>
template <unsigned int OtherCols>
Matrix<Rows, OtherCols> Matrix<Rows, Cols>::operator*(const Matrix<Cols, OtherCols>& other) const
{
    Matrix<Rows, OtherCols> result;
    for (unsigned int i = 0; i < Rows; ++i)
        for (unsigned int j = 0; j < OtherCols; ++j)
            for (unsigned int k = 0; k < Cols; ++k)
                result(i, j) += data[i][k] * other(k, j);
    return result;
}

template <unsigned int Rows, unsigned int Cols>
Matrix<Rows, Cols>& Matrix<Rows, Cols>::operator*=(const Matrix<Cols, Cols>& other)
{
    *this = *this * other;
    return *this;
}

template class Matrix<3, 1>;
template class Matrix<3, 3>;
