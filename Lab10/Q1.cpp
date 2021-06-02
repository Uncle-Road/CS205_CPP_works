
#include <iostream>
#include "CandyBar.h"

int main() {
    CandyBar cb; 
    cb.setCandyBar();
    cb.showCandyBar();
    CandyBar cb2("Zhanche", 19.2f, 11); 
    CandyBar cb3(std::string("Yinzhe"), 11.4f, 19);
    CandyBar cb4(cb); 
    CandyBar cb5 = std::move(cb4); 
    CandyBar cb6 = cb5; 
    CandyBar cb7 = CandyBar("Diao DIao ren", 81.0f, 9); 
    CandyBar cb8 = std::move(CandyBar("Sum", 48.0f, 4));
    CandyBar cb9 = get_a_candyBar();
    CandyBar cb10;
    cb10 = std::move(cb9); 
    CandyBar cb11;
    cb11 = get_a_candyBar(); 
    return 0;
}
