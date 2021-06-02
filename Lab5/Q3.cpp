#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

const int vn =5;
const char vowel[vn] = {'a','e','i','o','u'};

int main(){
    cout<< "Enter word (q to quit):" <<endl;
    int nVowel = 0;
    int nConsonant = 0;
    int nOther = 0;
    char word[30];

    while(cin>> word){
        
        if(isalpha(word[0])){
            if(strlen(word) == 1 && word [0] =='q'){
                break;
            }
            char x =tolower(word[0]);
            for(int i =0;i<5;i++){
                if(x == vowel[i]){ nVowel++;}

            }
        }
        else if(isdigit(word[0])){
            nOther++;
        }
        nConsonant++;
    }
    nConsonant=nConsonant-nVowel-nOther;

    cout << nVowel << " words beginning with vowels" <<endl;
    cout << nConsonant << " words beginning with consonants" << endl;
    cout << nOther << " others" <<endl;

    return 0;
    /*
    The 12 unverisities ocean ambled
    quietly Example 15 meters of lawm. q
    */
}