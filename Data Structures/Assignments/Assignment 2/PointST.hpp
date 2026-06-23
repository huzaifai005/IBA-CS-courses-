#pragma once

#include "Point2D.hpp"
#include "RectHV.hpp"
#include <iostream> 
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <limits>

template<typename Value>
class PointST {
private:
    std::map<Point2D, Value> STmap;

public: 
PointST() = default;

bool empty() const {
    return STmap.empty();
}

int size() const {
    return STmap.size();
}

Value& get(const Point2D& p) {
    auto it = STmap.find(p); 
    if (it == STmap.end()) {
        throw std::runtime_error("Point does not exist.");
    }
    return it->second;
}

bool contains(const Point2D& p) const {
    auto it = STmap.find(p);
    return it != STmap.end();
}

void put(const Point2D& p, const Value& val) {
    STmap[p] = val;
}

using iterator = typename std::map<Point2D, Value>::const_iterator;

PointST::iterator begin() const {
    return STmap.begin();
}

PointST::iterator end() const {
    return STmap.end();
}

Value& operator[](const Point2D& p) {
    return STmap[p];
}

std::vector<Point2D> range (const RectHV& rect) const {
    std::vector<Point2D> points;
    for(auto it = STmap.begin(); it != STmap.end(); it++) {
        if(rect.contains(it->first)) {
        points.push_back(it->first); 
        }
    }
    return points;
}

Point2D nearest(const Point2D& p) const {
    if(STmap.empty()) {
        throw std::runtime_error("map is empty.");
    }
    auto it_first = STmap.begin();
    Point2D closest = it_first->first; 
    double mindist = p.distanceSquaredTo(closest);
    for(auto it = it_first; it != STmap.end(); it++) {
        double currdist = p.distanceSquaredTo(it->first);
        if(currdist < mindist) {
            mindist = currdist;
            closest = it->first;
        }
    }
    return closest;
}
};
