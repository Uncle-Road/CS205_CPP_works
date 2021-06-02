#include "candybar.h"

using namespace std;

int main(){
    CandyBar cb;
    setCandyBar(&cb);
    showCandyBar(&cb);
    setCandyBar(cb);
    showCandyBar(cb);
    return 0;
}
