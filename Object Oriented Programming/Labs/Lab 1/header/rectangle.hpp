#pragma once

#ifndef _RECTANGLE_H  
#define _RECTANGLE_H
class rectangle {
public: 
rectangle(const int len,const int wid);

    int length;
    int width;

    int area();
};
#endif