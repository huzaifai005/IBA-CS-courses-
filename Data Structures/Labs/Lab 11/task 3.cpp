#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "digraph.hpp"

using namespace std;

class topological {
private:
    const Digraph& G;
    vector<int> topologicalorder;      
    bool hascycle;

    void findtopologicalorder() {
        int V = G.V();
        vector<int> indegree(V);
        queue<int> q;
        for (int v = 0; v < V; v++) {
            indegree[v] = G.indegree(v);
        }
        for (int v = 0; v < V; v++) {
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            topologicalorder.push_back(v);
            count++;
            for (int w : G.adj(v)) {
                indegree[w]--;
                if (indegree[w] == 0) {
                    q.push(w);
                }
            }
        }
        hascycle = (count != V);
    }

public:
    topological(const Digraph& graph) : G(graph), hascycle(false) {
        findtopologicalorder();
    }

    bool validtopologicalorder() const {
        return !hascycle;
    }
    
    bool containscycle() const {
        return hascycle;
    }
    
    vector<int> order() const {
        return topologicalorder;
    }
    
    void printorder() const {
        if (hascycle) {
            cout << "no topological order as graph contains cycle" << endl;
            return;
        }
        cout << "Topological order: ";
        for (size_t i = 0; i < topologicalorder.size(); i++) {
            if (i > 0) cout << " ";
            cout << topologicalorder[i];
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Test Case 1: Sample DAG ===" << endl;
    Digraph G1(6);
    G1.addEdge(5, 2);
    G1.addEdge(5, 0);
    G1.addEdge(4, 0);
    G1.addEdge(4, 1);
    G1.addEdge(2, 3);
    G1.addEdge(3, 1);  
    cout << "Graph 1: " << G1.to_string() << endl;
    topological ts1(G1);
    cout << "Contains cycle: " << (ts1.containscycle() ? "true" : "false") << endl;
    ts1.printorder();
    cout << endl;
    
  
    cout << "=== Test Case 2: Linear DAG ===" << endl;
    Digraph G2(4);
    G2.addEdge(0, 1);
    G2.addEdge(1, 2);
    G2.addEdge(2, 3);
    cout << "Graph 2: " << G2.to_string() << endl;
    topological ts2(G2);
    cout << "Contains cycle: " << (ts2.containscycle() ? "true" : "false") << endl;
    ts2.printorder();
    cout << endl;
    

    cout << "=== Test Case 3: Graph with Cycle ===" << endl;
    Digraph G3(4);
    G3.addEdge(0, 1);
    G3.addEdge(1, 2);
    G3.addEdge(2, 3);
    G3.addEdge(3, 1);
    cout << "Graph 3: " << G3.to_string() << endl;
    topological ts3(G3);
    cout << "Contains cycle: " << (ts3.containscycle() ? "true" : "false") << endl;
    ts3.printorder();
    cout << endl;
    

    cout << "=== Test Case 4: Single Vertex ===" << endl;
    Digraph G4(1);
    cout << "Graph 4: " << G4.to_string() << endl;
    topological ts4(G4);
    cout << "Contains cycle: " << (ts4.containscycle() ? "true" : "false") << endl;
    ts4.printorder();
    cout << endl;
    

    cout << "=== Test Case 5: Multiple Valid Orders ===" << endl;
    Digraph G5(5);
    G5.addEdge(0, 2);
    G5.addEdge(0, 3);
    G5.addEdge(1, 2);
    G5.addEdge(1, 3);
    G5.addEdge(2, 4);
    G5.addEdge(3, 4);
    cout << "Graph 5: " << G5.to_string() << endl;
    topological ts5(G5);
    cout << "Contains cycle: " << (ts5.containscycle() ? "true" : "false") << endl;
    ts5.printorder();
    if (ts5.validtopologicalorder()) {
        cout << "Verifying topological order..." << endl;
        vector<int> order = ts5.order();
        vector<int> position(G5.V());
        for (size_t i = 0; i < order.size(); i++) {
            position[order[i]] = i;
        }
        bool valid = true;
        for (int u = 0; u < G5.V(); u++) {
            for (int v : G5.adj(u)) {
                if (position[u] >= position[v]) {
                    cout << "Invalid edge: " << u << "->" << v 
                         << " but " << u << " at position " << position[u] 
                         << ", " << v << " at position " << position[v] << endl;
                    valid = false;
                }
            }
        }
        
        if (valid) {
            cout << "Topological order is valid!" << endl;
        }
    }
}