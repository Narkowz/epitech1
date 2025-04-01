/*
** EPITECH PROJECT, 2025
** Matrix.hpp
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

template <unsigned int Rows, unsigned int Cols>
class Matrix {
private:
    double data[Rows][Cols];

public:
    Matrix();

    double operator()(unsigned int row, unsigned int col) const;

    double& operator()(unsigned int row, unsigned int col);

    template <unsigned int OtherCols>
    Matrix<Rows, OtherCols> operator*(const Matrix<Cols, OtherCols>& other) const;

    Matrix<Rows, Cols>& operator*=(const Matrix<Cols, Cols>& other);

    friend std::ostream& operator<<(std::ostream& os, const Matrix<Rows, Cols>& matrix)
    {
        os << "[";
        for (unsigned int i = 0; i < Rows; ++i) {
            os << "[";
            for (unsigned int j = 0; j < Cols; ++j) {
                os << matrix(i, j);
                if (j < Cols - 1)
                    os << ", ";
            }
            os << "]";
            if (i < Rows - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }
};

#endif /* !MATRIX_HPP_ */
