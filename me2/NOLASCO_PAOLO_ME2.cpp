#include <iostream>

class Matrix
{
    double mat[4][4];

public:
    Matrix()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                set(i, j, 0);
            }
        }
    }
    Matrix(double x)    //initialization constructor
    {
        for(int i = 0; i < 4; i++)
        {
            set(i, i, 1);
            for(int j = 0; j < 4; j++)
            {
                set(i, j, get(i, j) * x);
            }
        }
    }
    Matrix(Matrix& src)  //copy constructor
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                set(i, j, src.get(i, j));
            }
        }
    }
    void operator=(Matrix& rhs)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                set(i, j, rhs.get(i, j));
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
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            prod.set(i, j, muld.get(i, j) * mulr.get(i, j));
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
            printf("%.0lf ", mat[i][j]);
        }
        printf("|\n");
    }
    printf("\n\n");
}

int main()
{
    Matrix matrix1, matrix2(1), result(matrix2);
    matrix1.print();
    matrix2.print();
    result = matrix1 + matrix2;
    result.print();
    /*result = matrix - matrix2;
    result.print();
    result = matrix1 * 3;
    result.print();
    result = matrix1 * matrix2;
    result.print();*/

    return 0;
}

//COMMENT:
/*
    Code won't compile due to
    "non-const lvalue reference of type 'Matrix&' to an rvalue of type 'Matrix'
*//*
    Stack Overflow results say that this is bypassed with a certain C++ compiler:
    stackoverflow.com/questions/18565167/non-const-lvalue-references
*/

//REFERENCES:
/*
    EEE 13 Notes and Sample Codes
*/
