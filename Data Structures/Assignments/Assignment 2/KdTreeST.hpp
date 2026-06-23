#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <limits>
#include <queue>
#include <utility> 
#include "Point2D.hpp"
#include "RectHV.hpp"

template <typename Value>
class KdTreeST {
private: 
    struct Node {
        Point2D p;
        Value val;
        RectHV rec;
        Node *leftbot;
        Node *righttop;

        Node(Point2D point, Value v, RectHV rect) 
            : p(point), val(v), rec(rect), leftbot(nullptr), righttop(nullptr) {}
    };

    Node *root;
    int sizeoftree;

public: 
    KdTreeST() : root(nullptr), sizeoftree(0) {};

    ~KdTreeST() {
        removeall(root);
    }

    bool empty() const {
        return sizeoftree == 0;
    }

    int size() const {
        return sizeoftree;
    }

private: 
    void removeall(Node* r) { 
        if(r == nullptr) {
            return;
        }
        removeall(r->leftbot);
        removeall(r->righttop);
        delete r;
    }

public: 
    Value &get(const Point2D &p) {
        return get(root, p, 0);
    }

private: 
    Value &get(Node *r, const Point2D &p, int direction) {
        if (r == nullptr) {
            throw std::runtime_error("Point not found");
        }
        if (p == r->p) {
            return r->val;
        }
        
        Node *next = nullptr;
        int next_direction = 1 - direction;

        if (direction == 0) { 
            if (p.x() < r->p.x()) {
                next = r->leftbot;
            } else {
                next = r->righttop;
            }
        } else {
            if (p.y() < r->p.y()) {
                next = r->leftbot;
            } else {
                next = r->righttop;
            }
        }
        return get(next, p, next_direction);
    }

public: 
    void put(const Point2D &p, const Value &val) {
        RectHV infplane(-std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity(), 
                        std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
        root = put(root, p, val, 0, infplane);
    }

private:
    Node *put(Node *r, const Point2D &p, const Value &val, int direction, const RectHV &rec) {
        if (r == nullptr) {
            sizeoftree++;
            return new Node(p, val, rec);
        }
        if (p == r->p) {
            r->val = val;
            return r;
        }
        
        int next_direction = 1 - direction;

        if (direction == 0) { 
            if (p.x() < r->p.x()) {
                RectHV left(rec.xmin(), rec.ymin(), r->p.x(), rec.ymax());
                r->leftbot = put(r->leftbot, p, val, next_direction, left); 
            } else {
                RectHV right(r->p.x(), rec.ymin(), rec.xmax(), rec.ymax());
                r->righttop = put(r->righttop, p, val, next_direction, right);
            }
        } else { 
            if (p.y() < r->p.y()) {
                RectHV bottom(rec.xmin(), rec.ymin(), rec.xmax(), r->p.y());
                r->leftbot = put(r->leftbot, p, val, next_direction, bottom);
            } else {
                RectHV top(rec.xmin(), r->p.y(), rec.xmax(), rec.ymax());
                r->righttop = put(r->righttop, p, val, next_direction, top);
            }
        }
        return r;
    }

public: 
    bool contains(const Point2D &p) const {
        return contains(root, p, 0);
    }

private: 
    bool contains(Node *r, const Point2D &p, int direction) const {
        if (r == nullptr) {
            return false;
        }
        if (p == r->p) {
            return true;
        }

        Node *next = nullptr;
        int next_direction = 1 - direction;

        if (direction == 0) { 
            if (p.x() < r->p.x()) {
                next = r->leftbot;
            } else {
                next = r->righttop;
            }
        } else { 
            if (p.y() < r->p.y()) {
                next = r->leftbot;
            } else {
                next = r->righttop;
            }
        }
        return contains(next, p, next_direction);
    }  

public:
    class iterator {
    private:
        std::queue<Node*> nodeQueue;

    public:
        iterator(Node *root = nullptr) {
            if (root) {
                nodeQueue.push(root);
            }
        }

    std::pair<Point2D, Value> operator*() const {
        if (nodeQueue.empty()) {
            throw std::runtime_error("queue is empty");
        }
        Node *curr = nodeQueue.front();
        return {curr->p, curr->val}; 
    }

    iterator &operator++() {
        if (nodeQueue.empty()) {
            throw std::runtime_error("queue is empty");
        }
        Node *curr = nodeQueue.front();
        nodeQueue.pop();
        if (curr->leftbot) {
            nodeQueue.push(curr->leftbot);
        }
        if (curr->righttop) {
            nodeQueue.push(curr->righttop);
        }
        return *this;
    }

    bool operator!=(const iterator &other) const {
        if (nodeQueue.empty() && other.nodeQueue.empty()) {
            return false;
        }
        return nodeQueue.empty() != other.nodeQueue.empty() || 
               (!nodeQueue.empty() && nodeQueue.front() != other.nodeQueue.front());
    }

    bool operator==(const iterator &other) const {
        return !(*this != other);
    }
    };

    iterator begin() const { 
        return iterator(root); 
    }

    iterator end() const {
        return iterator(); 
    }

    Value &operator[](const Point2D &p) {
        try {
            return get(p);
        }
        catch (const std::runtime_error &) {
            put(p, Value{});
            return get(p);
        }
    }

public:
    std::vector<Point2D> range(const RectHV &rect) const {
        std::vector<Point2D> points;
        range(root, rect, points);
        return points;
    }

private:
    void range(Node *r, const RectHV &rect, std::vector<Point2D> &v) const {
        if (r == nullptr) {
            return;
        }
        if (rect.contains(r->p)) {
            v.push_back(r->p);
        }
        if (r->leftbot && rect.intersects(r->leftbot->rec)) { 
            range(r->leftbot, rect, v);
        }
        if (r->righttop && rect.intersects(r->righttop->rec)) { 
            range(r->righttop, rect, v);
        }
    }

public:
    Point2D nearest(const Point2D &p) const {
        if (empty()) {
            throw std::runtime_error("map is empty!");
        }
        Point2D closest = root->p;
        double mindist = p.distanceSquaredTo(root->p);
        nearest(root, p, closest, mindist, 0);
        return closest;
    }

private:
    void nearest(Node* r, const Point2D &p, Point2D &champ, double &champdist, int direction) const {
        if (r == nullptr || r->rec.distanceSquaredTo(p) >= champdist) {
            return;
        }
        
        double currdist = p.distanceSquaredTo(r->p);
        if (currdist < champdist) {
            champ = r->p;
            champdist = currdist;
        }
        
        Node* first = nullptr;
        Node* second = nullptr;
        int next_direction = 1 - direction;
        if (direction == 0) { 
            if (p.x() < r->p.x()) {
                first = r->leftbot;
                second = r->righttop;
            } else {
                first = r->righttop; 
                second = r->leftbot;
            }
        } else { 
            if (p.y() < r->p.y()) {
                first = r->leftbot;
                second = r->righttop;
            } else {
                first = r->righttop;
                second = r->leftbot;
            }
        }
        nearest(first, p, champ, champdist, next_direction);
        nearest(second, p, champ, champdist, next_direction);

    }
};
