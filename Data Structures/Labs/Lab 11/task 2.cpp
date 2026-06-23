#include "graph.hpp"
#include<iostream>
#include<vector>
#include<queue>

class bipartite {
private:
std::vector<bool> marked;
std::vector<int> color;
bool isBipartite;

bool bfs(const Graph &G, int s) {
    std::queue<int> q;
    marked[s] = true;
    color[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                q.push(w);
                marked[w] = true;
                color[w] = 1 - color[v];
            }
            else if(color[w] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

public: 
bipartite(const Graph& G) : marked(G.V(), false), color(G.V(), -1), isBipartite(true) {
    for(int v = 0; v < G.V(); v++) {
        if(!marked[v]) {
            if(!bfs(G, v)) {
                isBipartite = false;
                return;
            }
        }
    }
}

bool checkBipartite() const {
    return isBipartite;
}

};

int main() {
    Graph G(4);
    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 0);
    bipartite bip(G);
    if (bip.checkBipartite()) {
        cout << "The graph is bipartite" << endl;
    }
    else {
        cout << "graph is not bipartite" << endl;
    }
}