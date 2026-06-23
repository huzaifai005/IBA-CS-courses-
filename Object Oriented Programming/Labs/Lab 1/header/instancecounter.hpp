#pragma once

#ifndef _INSTANCECOUNTER_H  
#define _INSTANCECOUNTER_H
class instanceCounter {
private:
    static int count;

public:
    instanceCounter();

    static int getCount();
};
#endif