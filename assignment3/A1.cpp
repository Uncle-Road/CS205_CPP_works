#include <iostream>
#include <cmath>
//A1
using namespace std;

int main() {
    int n, m, k;
    (cin >> n >> m >> k).get();
    if(cin.fail()||n<=0||m<=0||k<0){
        cout<<"input is invalid, exit."<<endl;
        return 0;
    }

    int arr[k][4];

    using line = int[n];
    int *array = new int[n * m]();
    line * graph= reinterpret_cast<line *>(array);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
            if(cin.fail()){
                cout<<"input is invalid, exit."<<endl;
                return 0;
            }
        }
        if (arr[i][0] < 0 || arr[i][0] >= n || arr[i][1] < 0 || arr[i][1] >= m) {
            cout << "Not in screen, exit" << endl;
            return 0;
        }

        if (abs(arr[i][2]) > 1 || abs(arr[i][3]) > 1) {
            cout << "direction is invalid, exit" << endl;
            return 0;
        }
        int x1 = arr[i][0];
        int y1 = arr[i][1];
        int x2 = arr[i][2];
        int y2 = arr[i][3];
        while(x1>=0&&x1<n&&y1>=0&&y1<m){
            graph[y1][x1] = 1;
            x1 = x1 + x2;
            y1 = y1 + y2;
        }
    }

    int ans = 0;
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(graph[i][j] ==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
