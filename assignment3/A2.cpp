#include <iostream>
#include <vector>
//A2
using namespace std;

vector<vector<int>> getMatrix(int n,int m );

int main() {
    int n, m;
    (cin >> n >> m).get();

    if (cin.fail() || n <= 0 || m <= 0) {
        cout << "matrix row or column is invalid, exit" << endl;
        return 0;
    }

    vector<vector<int>> graph(n);

    graph = getMatrix(n,m);

    for ( int i =0;i<n;i++){
        for(int j =m-1;j>=0;j--){
            int data = graph[i][j];
            cout << data;
            int spaceCount = to_string(m * n).size() - to_string(data).size() + 1;
            for (int k = 0; k < spaceCount; k++) {
                cout << " ";
            }
        }
        cout<<endl;
    }

    return 0;
}
//matrix source from leetccode
vector<vector<int>> getMatrix(int n,int m ) {
    int num = 1;
    vector<vector<int>> matrix(n, vector<int>(m));
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    while (left <= right && top <= bottom) {
        for (int column = left; column <= right; column++) {
            matrix[top][column] = num;
            num++;
        }
        for (int row = top + 1; row <= bottom; row++) {
            matrix[row][right] = num;
            num++;
        }
        if (left < right && top < bottom) {
            for (int column = right - 1; column > left; column--) {
                matrix[bottom][column] = num;
                num++;
            }
            for (int row = bottom; row > top; row--) {
                matrix[row][left] = num;
                num++;
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return matrix;
}