#pragma once

#include <vector>
#include <algorithm>
#include <limits>
#include "weighted-graph.hpp"
#include "union-find.hpp"

class BoruvkaMST {
private:
    std::vector<Edge> mst;
    double totalWeight;

public:
    BoruvkaMST(const EdgeWeightedGraph& G) : totalWeight(0.0) {
        UnionFind uf(G.V());
        int numComponents = G.V();
        while (numComponents > 1) {
            std::vector<const Edge*> cheapest(G.V(), nullptr);
            for (const Edge& e : G.edges()) {
                int v = e.either();
                int w = e.other(v);
                int compV = uf.find(v);
                int compW = uf.find(w);
                if (compV == compW) {
                    continue;
                }
                if (cheapest[compV] == nullptr || e.weight() < cheapest[compV]->weight()) {
                    cheapest[compV] = &e;
                }
                if (cheapest[compW] == nullptr || e.weight() < cheapest[compW]->weight()) {
                    cheapest[compW] = &e;
                }
            }
            bool addedAny = false;
            for (int comp = 0; comp < G.V(); comp++) {
               const Edge* e = cheapest[comp];
                if (e == nullptr) {
                    continue;
                }
                int v = e->either();
                int w = e->other(v);
                int compV = uf.find(v);
                int compW = uf.find(w);
                if (compV != compW) {
                    mst.push_back(*e);
                    totalWeight += e->weight();
                    uf.unify(compV, compW);
                    numComponents--;
                    addedAny = true;
                }
            }
            if (!addedAny) break;
        }
    }

    const std::vector<Edge>& edges() const {
        return mst;
    }

    double weight() const {
        return totalWeight;
    }

    bool isValid(const EdgeWeightedGraph& G) const {
        return mst.size() == G.V() - 1;
    }
};
