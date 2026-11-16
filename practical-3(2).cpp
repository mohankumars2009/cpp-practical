
#include <iostream>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    // Get matrix elements from user
    void getData()
    {
        cout << "Enter 4 elements of matrix:" << endl;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }

        return result;
    }

    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }

        return result;
    }

    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                out << m.data[i][j] << " ";
            }

            out << endl;
        }

        return out;
    }
};

int main()
{
    Matrix A, B;

    cout << "Enter Matrix A:" << endl;
    A.getData();

    cout << "Enter Matrix B:" << endl;
    B.getData();

    Matrix sum = A + B;
    Matrix product = A * B;

    cout << "\nMatrix A:" << endl;
    cout << A;

    cout << "\nMatrix B:" << endl;
    cout << B;

    cout << "\nAddition of Matrices:" << endl;
    cout << sum;

    cout << "\nMultiplication of Matrices:" << endl;
    cout << product;

    return 0;
}
