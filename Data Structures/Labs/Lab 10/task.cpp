#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Digraph {
    std::vector<std::forward_list<int>> _adj;
    std::vector<int> _indegree;
    std::vector<int> _outdegree;
    int _E;

public:
    Digraph(int n) : _adj(n), _indegree(n), _outdegree(n), _E{0} {}

    Digraph(std::istream& in) : _E{0} {
        int V, E;
        in >> V >> E;
        if (V < 0 || E < 0) 
            throw new std::invalid_argument("number of vertices and edges in a Graph must be non-negative");
        _adj.resize(V);
        _indegree.resize(V);
        _outdegree.resize(V);
        for (int i = 0; i < E; i++) {
            int v, w;
            in >> v >> w;
            validateVertex(v);
            validateVertex(w);
            addEdge(v, w);
        }
    }

    int V() const {
        return _adj.size();
    }
    
    int E() const {
        return _E;
    }

    void addEdge(int v, int w) {
        validateVertex(v);
        validateVertex(w);
        _adj[v].push_front(w);
        _outdegree[v]++;
        _indegree[w]++;
        _E++;
    }

    const std::forward_list<int>& adj(int v) const {
        validateVertex(v);
        return _adj[v];
    }

    int indegree(int v) const {
        validateVertex(v);
        return _indegree[v];
    }

    int outdegree(int v) const {
        validateVertex(v);
        return _outdegree[v];
    }

    std::string to_string() const {
        std::string s; 
        s.append(std::to_string(V()) + " vertices, " + std::to_string(_E) + " edges " + "\n");
        for (int v = 0; v < V(); v++) {
            s.append(std::to_string(v) + ": ");
            for (int w : _adj[v]) {
                s.append(std::to_string(w) + " ");
            }
            s.append("\n");
        }
        return s;
    }

    Digraph reverse() const {
        Digraph r(V());
        for(int v=0; v<V(); v++) {
            for(int w : adj(v)) {
                r.addEdge(w,v);
            }
        }
        return r;
    }

private:
    void validateVertex(int v) const {
        if (v < 0 || v >= V())
            throw new std::invalid_argument("vertex " + std::to_string(v) + " is not between 0 and " + std::to_string((V()-1)));
    }

};




class EulerianCycle {
private:
Digraph G; 
std::vector<int> next;
std::deque<int> cycle; 
std::vector<bool> marked;
std::vector<int> edgeTo;

public:
EulerianCycle(const Digraph& graph) : G(graph), next(graph.V(), 0), marked(graph.V(), false), edgeTo(graph.V(), -1) {
    for(int i = 0; i < G.V(); i++) {
        if(G.indegree(i) !=  G.outdegree(i)) {
            throw std::runtime_error("indegrees is not equal to outdegrees.");
        }
    }
    for(int j = 0; j < G.V(); j++) {
        if(G.outdegree(j) > 0) {
            recursivedfs(j);
            break;
        }
    }
}

void recursivedfs(int v) {
    marked[v] = true;       
    int adj_size = std::distance(G.adj(v).begin(), G.adj(v).end());
    while (next[v] < adj_size) {
        int w = *std::next(G.adj(v).begin(), next[v]);  
        next[v]++;  
        if (!marked[w]) {  
            recursivedfs(w); 
        }
    }
    cycle.push_back(v);
}
bool hasEulerianCycle() const {
    return !cycle.empty();
}
std::deque<int> getCycle() const {
    return cycle;
}
};


int main() {
    bool allTestsPassed = true;  

    try {
        try {
            Digraph g1(1);  
            g1.addEdge(0, 0); 

            EulerianCycle eulerianCycle1(g1);
            std::cout << "Test Case 1: Single Vertex with Self-loop\n";
            std::cout << "Eulerian Cycle exists: " << eulerianCycle1.hasEulerianCycle() << "\n";
            std::cout << "Cycle: ";
            for (int v : eulerianCycle1.getCycle()) {
                std::cout << v << " ";
            }
            std::cout << "\n\n";
        } catch (const std::exception& e) {
            std::cout << "Test Case 1 Failed: " << e.what() << "\n";
            allTestsPassed = false;
        }
        try {
            Digraph g2(3);  
            g2.addEdge(0, 1);
            g2.addEdge(1, 2);
            g2.addEdge(2, 0);
            g2.addEdge(0, 2);
            g2.addEdge(1, 0);
            g2.addEdge(2, 1);

            EulerianCycle eulerianCycle2(g2);
            std::cout << "Test Case 2: Complete Graph with 3 Vertices\n";
            std::cout << "Eulerian Cycle exists: " << eulerianCycle2.hasEulerianCycle() << "\n";
            std::cout << "Cycle: ";
            for (int v : eulerianCycle2.getCycle()) {
                std::cout << v << " ";
            }
            std::cout << "\n\n";
        } catch (const std::exception& e) {
            std::cout << "Test Case 2 Failed: " << e.what() << "\n";
            allTestsPassed = false;
        }
        try {
            Digraph g3(3);  
            g3.addEdge(0, 1);
            g3.addEdge(1, 2);
            g3.addEdge(2, 0);
            g3.addEdge(0, 1);  
            g3.addEdge(1, 0);  

            EulerianCycle eulerianCycle3(g3);
            std::cout << "Test Case 3: Graph with Parallel Edges\n";
            std::cout << "Eulerian Cycle exists: " << eulerianCycle3.hasEulerianCycle() << "\n";
            std::cout << "Cycle: ";
            for (int v : eulerianCycle3.getCycle()) {
                std::cout << v << " ";
            }
            std::cout << "\n\n";
        } catch (const std::exception& e) {
            std::cout << "Test Case 3 Failed: " << e.what() << "\n";
            allTestsPassed = false;
        }

        
        try {
            Digraph g4(3);  
            g4.addEdge(0, 1);
            g4.addEdge(1, 2);
            g4.addEdge(2, 1);  

            EulerianCycle eulerianCycle4(g4);
            std::cout << "Test Case 4: Graph with No Eulerian Cycle (unequal degrees)\n";
            std::cout << "Eulerian Cycle exists: " << eulerianCycle4.hasEulerianCycle() << "\n";
            std::cout << "Cycle: ";
            for (int v : eulerianCycle4.getCycle()) {
                std::cout << v << " ";
            }
            std::cout << "\n\n";
        } catch (const std::exception& e) {
            std::cout << "Test Case 4 Failed: " << e.what() << "\n";
            allTestsPassed = false;
        }

        
        try {
            Digraph g5(7);  
            g5.addEdge(0, 1);
            g5.addEdge(1, 2);
            g5.addEdge(2, 3);
            g5.addEdge(3, 4);
            g5.addEdge(4, 5);
            g5.addEdge(5, 0);
            g5.addEdge(1, 6);
            g5.addEdge(6, 1);
            g5.addEdge(2, 5);
            g5.addEdge(3, 6);
            g5.addEdge(6, 2);

            EulerianCycle eulerianCycle5(g5);
            std::cout << "Test Case 5: Example Graph from the Problem\n";
            std::cout << "Eulerian Cycle exists: " << eulerianCycle5.hasEulerianCycle() << "\n";
            std::cout << "Cycle: ";
            for (int v : eulerianCycle5.getCycle()) {
                std::cout << v << " ";
            }
            std::cout << "\n\n";
        } catch (const std::exception& e) {
            std::cout << "Test Case 5 Failed: " << e.what() << "\n";
            allTestsPassed = false;
        }
        try {
            std::cout << "Validation checks:\n";
            Digraph testGraph(3);
            testGraph.addEdge(0, 1);
            testGraph.addEdge(1, 2);
            testGraph.addEdge(2, 0);

            EulerianCycle testCycle(testGraph);
            for (int v = 0; v < testGraph.V(); v++) {
                if (testGraph.indegree(v) != testGraph.outdegree(v)) {
                    std::cout << "Fail: indegree != outdegree for vertex " << v << "\n";
                    allTestsPassed = false;
                }
            }
            if (testCycle.getCycle().size() == testGraph.E()) {
                std::cout << "Pass: Cycle contains exactly " << testGraph.E() << " edges\n";
            } else {
                std::cout << "Fail: Cycle does not contain the correct number of edges\n";
                allTestsPassed = false;
            }

            if (testCycle.getCycle().front() == testCycle.getCycle().back()) {
                std::cout << "Pass: First and last vertices are identical\n";
            } else {
                std::cout << "Fail: First and last vertices are not identical\n";
                allTestsPassed = false;
            }

            std::vector<int> edgeCount(testGraph.V(), 0);
            for (int v : testCycle.getCycle()) {
                edgeCount[v]++;
            }
            for (int count : edgeCount) {
                if (count != 1) {
                    std::cout << "Fail: An edge appears more than once\n";
                    allTestsPassed = false;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Validation Check Failed: " << e.what() << "\n";
            allTestsPassed = false;
        }
    }
    catch (const std::exception& e) {
        std::cout << "General Error: " << e.what() << "\n";
        allTestsPassed = false;
    }
    if (allTestsPassed) {
        std::cout << "All tests passed successfully!" << std::endl;
    } else {
        std::cout << "Some tests failed!" << std::endl;
    }
}



