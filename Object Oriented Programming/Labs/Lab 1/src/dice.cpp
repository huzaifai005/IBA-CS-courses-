#include "../headers/dice.hpp"
#include<cstdlib>
#include<ctime>

int dice::dicecount = 0;

dice::dice(int s) 
    : sides(s)  {
    dicecount++;
}

int dice::rolldice(){
    return rand() % sides + 1;
}

int dice::getSides() {
    return sides;
}

int dice::getCount() {
    return dicecount;
}
