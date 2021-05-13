# Assignment3 Report
------
Name: 周民涛
SID: 11912725
envirment:VSCode WSL 

[toc]

## Part1 - Analysis
---

### Q1
1. 首先读取所有的输入,并检验读入的有效性,比如输入不能为非正值,输入的点不能出界,输入的方向必须为八个方向之一.
2. 然后在读取时,每读取一次点和方向,就调用一次填充,最后统计.

### Q2
1. 首先读入两个参数.得是正整数.
2. 然后调用函数得到矩阵，遇到边界就拐弯
3. 最后输出矩阵

### Q3
1. 设计unicode_block struct,根据Blocks.txt,需要四个变量string name;unsigned int start;unsigned int end;unsigned int char_count = 0;
2. 然后从Blocks.txt中读取内容,被注释的,行内容太少的都可以筛掉,之后用一个函数返回一个unicode_block的数组。
3. 最后计算count数，遍历数组,记下最大值,输出结果信息。


## Part2 - Code
---
### A1's code
```cpp
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

```
### A2's code
```cpp
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
```
### A3's code 
```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utf8.c"

using namespace std;

struct unicode_block {
    string name;
    unsigned int start;
    unsigned int end;
    unsigned int count = 0;
};

string trim(string str);

int findUTF8Length(unsigned char c);

unicode_block fill_block_inf(unicode_block block, string line);

vector<unicode_block> &read_file_blocks(const string filename);

void calu_block_count (vector<unicode_block> &blockList,unsigned char charList[10],char data,int len);
int main() {
    vector<unicode_block> &blockList = read_file_blocks("Blocks.txt");

    unsigned char charList[10];
    char data;
    int len;

    calu_block_count(blockList,charList,data,len);
    auto *maxBlocks = &(blockList[0]);

    for (int i = 0; i < blockList.size(); i++) {
        auto &block = blockList[i];
        if (block.count > maxBlocks->count) {
            maxBlocks = &block;
        }
    }

    cout << "Blocks name is " << maxBlocks->name << ", and has " << maxBlocks->count << " chars." << endl;
    return 0;
}

string trim(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

int findUTF8Length(unsigned char c) {
    int len = -1;
    if (c < 0xc0) {
        len = 1;
    } else if ((c & 0xe0u) == 0xc0) {
        len = 2;
    } else if ((c & 0xf0u) == 0xe0) {
        len = 3;
    } else if ((c & 0xf8u) == 0xf0) {
        len = 4;
    }
    return len;
}

unicode_block fill_block_inf(unicode_block block, string line) {
    int dots = line.find('.');
    int semicolon = line.find(';');

    block.start = stoi(line.substr(0, dots), nullptr, 16);
    block.end = stoi(line.substr(dots + 2, semicolon - dots - 2), nullptr, 16);
    block.name = line.substr(semicolon + 2);
    return block;
}

vector<unicode_block> &read_file_blocks(const string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Can not find Blocks.txt " << endl;
        file.close();
        exit(1);
    }

    string line;
    vector<unicode_block> &blockList = *(new vector<unicode_block>());

    while (getline(file, line)) {
        line = trim(line);
        if (line.size() <= 1 || line[0] == '#') {
            continue;
        }
        unicode_block block = fill_block_inf(block, line);
        blockList.push_back(block);
    }
    return blockList;
}


void calu_block_count (vector<unicode_block> &blockList,unsigned char charList[10],char data,int len){
     while ((data = cin.get()) != char_traits<char>::eof()) {
        len = findUTF8Length(data);
        charList[0] = data;
        for (int i = 1; i < len; ++i) {
            charList[i] = cin.get();
        }

        unsigned int index = utf8_to_codepoint(charList, &len);

        for (int i = 0; i < blockList.size(); i++) {
            auto &block = blockList[i];
            if (block.start <= index && index <= block.end) {
                block.count++;
            }
        }

        for (int i = 0; i < len; i++) {
            charList[i] = 0;
        }
    }

}


```

## Part 3 - Result & Verification
---
### Test case #1:
**input:**
```
0 2 4
```
**output:**
```
input is invalid, exit.
``` 

### Test case #2:
**input:**
```
3 4 5
1 1 1 -1
1 1 -1 1
0 3 1 0
0 2 1 0
0 0 -1 -1
```
**output:**
```
3
```
### Test case #3:
**input:**
```
6 9
```
**output:**
```
9  8  7  6  5  4  3  2  1  
10 33 32 31 30 29 28 27 26 
11 34 49 48 47 46 45 44 25 
12 35 50 51 52 53 54 43 24 
13 36 37 38 39 40 41 42 23 
14 15 16 17 18 19 20 21 22 
``` 

### Test case #4:
**input:**
```
-1 4
```
**output:**
```
matrix row or column is invalid, exit
``` 


### Test case #5:
**input:**
```
g++ A3.cpp -o a3.out &&./a3.out<sample.txt
```
**output:**
```
Blocks name is Armenian, and has 3230 chars.
```

### Test case #6:
**input:**
```
g++ A3.cpp -o a3.out &&./a3.out<sample2.txt
```
**output:**
```
Blocks name is Georgian, and has 1127 chars.
```

## Part 4 - Difficulties & Solutions
---
**difficultes**
不能使用ide进行调试
**solutions**
使用vscode进行g++测试
