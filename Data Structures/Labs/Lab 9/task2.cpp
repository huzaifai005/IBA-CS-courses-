#include<iostream>
#include<vector>
#include <random> 
#include <chrono> 
#include <algorithm> 

class maze {
private: 
    std::vector<std::vector<bool>> north;
    std::vector<std::vector<bool>> south;
    std::vector<std::vector<bool>> east;
    std::vector<std::vector<bool>> west;
    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<bool>> solvedvisited;
    std::vector<std::vector<bool>> path;
    int size;
    bool solved;

    std::mt19937 generator;

    void dfs(int x, int y) {
        visited[x][y] = true;
        std::vector<int> dx = {0, 1, 0, -1};
        std::vector<int> dy = {1, 0, -1, 0};
        std::vector<int> directions = {0, 1, 2, 3};
        std::shuffle(directions.begin(), directions.end(), generator);
            for(int i : directions) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                    if (nx >= 1 && nx <= size && ny >= 1 && ny <= size && !visited[nx][ny]) {
                        if(i==0) {
                            north[x][y] = false;
                            south[nx][ny] = false;
                        }
                        else if(i==1) {
                            east[x][y] = false;
                            west[nx][ny] = false;
                        }
                        else if(i==2) {
                            south[x][y] = false;
                            north[nx][ny] = false;
                        }
                        else {
                            west[x][y] = false;
                            east[nx][ny] = false;
                        }
                        dfs(nx, ny);
                }
            }
    }

    bool explore(int x, int y) {
        if(x==size && y==size) {
            path[x][y] = true;
            return true;
        }

        solvedvisited[x][y] = true;
        std::vector<int> dx = {0, 1, 0, -1};
        std::vector<int> dy = {1, 0, -1, 0};

        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= size && ny >= 1 && ny <= size) {
                if(!solvedvisited[nx][ny]) {
                    if(i == 0 && north[x][y] == false) {
                        if(explore(nx, ny)) {
                        path[x][y] = true;
                        return true;
                        }
                    }
                    else if(i == 1 && east[x][y] == false) {
                        if(explore(nx, ny)) {
                        path[x][y] = true;
                        return true;
                        }
                    }
                    else if(i == 2 && south[x][y] == false) {
                        if(explore(nx, ny)) {
                        path[x][y] = true;
                        return true;
                        }
                    }
                    else if(i == 3 && west[x][y] == false) {
                        if(explore(nx, ny)) {
                        path[x][y] = true;
                        return true;
                        }  
                    }
                }
            } 
        }
        return false;
    }

public:
    maze(int n) : size(n), solved(false) {
        north = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, true));
        south = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, true));
        east = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, true));
        west = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, true));
        visited = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, false));
        solvedvisited = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, false));
        path = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, false));
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }

    void generate() {
        dfs(1, 1);
    }

    void solve() {
        solved = explore(1, 1);
    }

    void print() {
    if (solved) {
        std::cout << "STATUS: Solved! A path was found from (1, 1) to (" << size << ", " << size << ")." << std::endl;
    } else {
        std::cout << "STATUS: No solution found." << std::endl;
    }
    std::cout << std::endl;

    for (int x = 1; x <= size; ++x) {
        std::cout << "+";
        std::cout << (north[x][size] ? "---" : "   ");
    }
    std::cout << "+" << std::endl; 
    for (int y = size; y >= 1; --y) {
        std::cout << "|"; 
        for (int x = 1; x <= size; ++x) {
            std::cout << "   ";
            std::cout << (east[x][y] ? "|" : " ");
        }
        std::cout << std::endl;
        for (int x = 1; x <= size; ++x) {
            std::cout << "+";
            std::cout << (south[x][y] ? "---" : "   ");
        }
        std::cout << "+" << std::endl;
    }
}

};


int main(int argc, char* argv[]) {
    int n;
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <N>" << std::endl;
        return 1;
    }
    try {
        n = std::stoi(argv[1]);
        if (n <= 0) {
            std::cerr << "Error: N must be a positive integer." << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid argument for N. Please provide an integer." << std::endl;
        return 1;
    }
    maze a(n);
    a.generate();
    a.solve();
    a.print();
}