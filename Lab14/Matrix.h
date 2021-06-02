//
// Created by HUAWEI on 2021/5/20.
//

#ifndef LAB14_MATRIX_H
#define LAB14_MATRIX_H
using namespace std;

const int MAXCOLS = 3;
const int MAXROWS = 2;
template<typename T>
class Matrix {
    T (*m)[MAXCOLS];
public:
    void setMatrix(T a[][MAXCOLS]) {
        m = a;
    }

    void printMatrix() {
        for (int i = 0; i < MAXROWS; i++) {
            for (int j = 0; j < MAXCOLS; ++j) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addMatrix(T a[][MAXCOLS]) {
        for (int i = 0; i < MAXROWS; i++) {
            for (int j = 0; j < MAXCOLS; ++j) {
                m[i][j] += a[i][j];
            }
        }
    }
};
#endif //LAB14_MATRIX_H
