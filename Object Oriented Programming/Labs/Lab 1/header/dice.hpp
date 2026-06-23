#pragma once

#ifndef _DICE_H  
#define _DICE_H
class dice {
private:
    static int dicecount;
    int sides;

public:
    dice(int s);

    static int getCount();
    int rolldice();
    int getSides();
    
};
#endif