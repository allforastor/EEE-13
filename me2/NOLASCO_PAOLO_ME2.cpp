#include <iostream>

class Matrix
{
    double mat[4][4];

public:
    Matrix()            //default constructor
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                set(i, j, 1);
            }
        }
    }
    Matrix(double x)    //initialization constructor
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {   //identity matrix
                if(i == j)
                {
                    set(i, j, 1);
                }
                else
                {
                    set(i, j, 0);
                }
                //scalar multiplication
                set(i, j, get(i, j) * x);
            }
        }
    }
    Matrix(Matrix& src) //copy constructor
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                set(i, j, src.get(i, j));
            }
        }
    }
    void operator=(Matrix&& rhs)    //the double reference allows solving (see previous commit for issue)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                mat[i][j] = rhs.get(i, j);
            }
        }
    }

    double get(int i, int j);
    void set(int i, int j, double x);
    void print();
};

Matrix operator+(Matrix& add1, Matrix& add2)
{
    Matrix sum;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            sum.set(i, j, add1.get(i, j) + add2.get(i, j));
        }
    }
    return sum;
}
Matrix operator-(Matrix& min, Matrix& sub)
{
    Matrix diff;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            diff.set(i, j, min.get(i, j) - sub.get(i,j));
        }
    }
    return diff;
}
Matrix operator*(Matrix& orig, const double x)
{
    Matrix scal;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scal.set(i, j, orig.get(i, j) * x);
        }
    }
    return scal;
}
Matrix operator*(Matrix& muld, Matrix& mulr)
{
    Matrix prod;
    double sum;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            sum = 0;    //resets for every space in the matrix
            for(int k = 0; k < 4; k++)
            {
                sum = sum + (muld.get(i, k) * mulr.get(k, j));
            }
            prod.set(i, j, sum);
        }
    }
    return prod;
}

double Matrix::get(int i, int j)
{
    return mat[i][j];
}
void Matrix::set(int i, int j, double x)
{
    mat[i][j] = x;
}
void Matrix::print()
{
    for(int i = 0; i < 4; i++)
    {
        printf("| ");
        for(int j = 0; j < 4; j++)
        {
            printf("%.0lf ", mat[i][j]);    //limits printing to whole numbers
        }
        printf("|\n");
    }
    printf("\n\n");
}

int main()
{
    Matrix matrix1, matrix2(2), result(matrix2);
    matrix1.print();
    matrix2.print();
    result = matrix1 + matrix2;
    result.print();
    result = matrix1 - matrix2;
    result.print();
    result = matrix1 * 2;
    result.print();
    result = matrix1 * matrix2;
    result.print();

    return 0;
}

//REFERENCES:
/*
    EEE 13 Notes and Sample Codes
    https://www.justsoftwaresolutions.co.uk/cplusplus/core-c++-lvalues-and-rvalues.html
*/
