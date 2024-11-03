#include <iostream>
using namespace std;

const int SIZE = 4; // this is the global variable

class Matrix {
private:
    int data[SIZE][SIZE];

public:
    // read values from stdin into the matrix
    void readFromStdin() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // out matrix
    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // operator overloading for +
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // operator overloading for *
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // sum of matrix diaginol
    int sumOfDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += data[i][i];
            sum += data[i][SIZE - 1 - i];
        }
        // If the size value is odd then it will subtract the middle element added twice
        if (SIZE % 2 != 0) {

        }
        return sum;
    }

    // swaps matrix rows
    void swapRows(int row1, int row2) {
        if (row1 < 0 || row2 < 0 || row1 >= SIZE || row2 >= SIZE) {
            cout << "Invalid row indices." << endl;
            return;
        }
        for (int j = 0; j < SIZE; ++j) {
            swap(data[row1][j], data[row2][j]);
        }
    }
};

int main() {
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    int row1, row2;
    cout << "Enter two row indices to swap (0 to " << SIZE - 1 << "): ";
    cin >> row1 >> row2;
    mat1.swapRows(row1, row2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
