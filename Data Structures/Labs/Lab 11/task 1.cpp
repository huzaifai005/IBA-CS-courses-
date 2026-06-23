#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <forward_list>
#include <stdexcept>
#include <iostream>
#include "digraph.hpp"
#include "directed-dfs.hpp"

using namespace std;

class CycleDetector {
private:
    const Digraph& G;           
    vector<int> state;          
    vector<int> parent;  
    
public:
    CycleDetector(const Digraph& G) : G(G), state(G.V(), 0), parent(G.V(), -1) {}
    bool detectCycle() {
        for (int v = 0; v < G.V(); v++) {
            if (state[v] == 0) {  
                if (cycledfs(v)) {
                    return true;  
                }
            }
        }
        return false;  
    }
    
private:
    bool cycledfs(int v) {
        state[v] = 1;  

        for (int w : G.adj(v)) {
            if (state[w] == 0) {  
                parent[w] = v;    
                if (cycledfs(w)) {  
                    return true;   
                }
            }
            else if (state[w] == 1) {  
                cout << "Cycle detected: ";
                cout << w << " ";  
                for (int x = v; x != w; x = parent[x]) {
                    cout << x << " ";  
                }
                cout << w << endl;  
                return true;  
            }
        }
        state[v] = 2;  
        return false;  
    }
};

int main() {
    Digraph G(4);
    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 1);
    CycleDetector cycleDetector(G);
    if (cycleDetector.detectCycle()) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
}