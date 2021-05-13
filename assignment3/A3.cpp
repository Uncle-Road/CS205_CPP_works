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

