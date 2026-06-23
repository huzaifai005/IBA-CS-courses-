#pragma once

#ifndef _CIRCLE_H  
#define _CIRCLE_H
class circle {
public:
    circle(float r);
    
    void setRadius(float r);
    float getRadius();
    float circumference();

private:
    float radius;
};
#endif