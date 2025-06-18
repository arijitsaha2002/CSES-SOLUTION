#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define Matrix vector<vector<long>>

Matrix pow2(Matrix &matrix) {

    Matrix R (6, vector<long>(6, 0));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                R[i][j] += (matrix[i][k] * matrix[k][j]) % M;
                R[i][j] %= M;
            }
        }
    }

    return R;

}

Matrix multiply_matrix(Matrix &matrix1, Matrix &matrix2) {

    Matrix R (6, vector<long>(6, 0));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                R[i][j] += (matrix1[i][k] * matrix2[k][j]) % M;
                R[i][j] %= M;
            }
        }
    }

    return R;

}


void print_matrix(Matrix &m) {
    for (int i = 0; i < 6; i ++) {
        for (int j = 0; j < 6; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long n;
    cin >> n;

    Matrix matrix (6, vector<long>(6, 1));

    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            matrix[i][j] = ((i - 1) == j);
        }
    }

    Matrix R (6, vector<long>(6));


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            R[i][j] = (i == j);
        }
    }

    while (n) {

        if (n & 1) R = multiply_matrix(R, matrix);
        matrix = pow2(matrix);
        n >>= 1;
    }

    cout << R[0][0] << endl;

    return 0;
}