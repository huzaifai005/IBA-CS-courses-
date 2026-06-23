#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include<chrono>
#include<iostream>

class stopwatch {
private:
std::chrono::steady_clock::time_point begin;
std::chrono::steady_clock::time_point end;

    public: 
    void start() {
        begin = std::chrono::steady_clock::now();
    }

    void stop() {
        end = std::chrono::steady_clock::now();
    }

    void reset() {
        begin = std::chrono::steady_clock::time_point{};
        end = std::chrono::steady_clock::time_point{};
    }

    double get_elapsed_time_seconds() {
        return std::chrono::duration<double>(end - begin).count();

    }

    double get_elapsed_time_milliseconds() {
        return std::chrono::duration<double, std::milli>(end - begin).count();
    }

};

#endif