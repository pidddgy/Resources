#pragma once
#include <bits/stdc++.h>
using namespace std;

// Computes the strongly connected components of a directed graph using
//   Tarjan's algorithm
// Vertices are 0-indexed
// Constructor Arguments:
//   G: a generic directed graph structure
//     Required Functions:
//       operator [v] const: iterates over the adjacency list of vertex v
//         (which is a list of ints)
//       size() const: returns the number of vertices in the graph
//   condensationEdges: a reference to a vector of pairs that will store the
//     edges in the condensation graph when all vertices in an scc are
//     condensed into a single vertex (with an index equal to its scc id),
//     and it is guaranteed that this list of edges is sorted by the first
//     element in the pair in non decreasing order
// Fields:
//   id: a vector of the index of the scc each vertex is part of
//   components: a vector of vectors containing the vertices in each scc and
//     is sorted in reverse topological order
// In practice, has a moderate constant, faster than Kosaraju
// Time Complexity:
//   constructor: O(V + E)
// Memory Complexity: O(V)
// Tested:
//   Stress Tested
//   https://judge.yosupo.jp/problem/scc
//   https://dmoj.ca/problem/acc2p2
//   https://ecna18.kattis.com/problems/watchyourstep
struct SCC {
  int ind, top; vector<int> id, low, stk; vector<vector<int>> components;
  template <class Digraph> void dfs(const Digraph &G, int v) {
    id[stk[top++] = v] = -1; int mn = low[v] = ind++; for (int w : G[v]) {
      if (id[w] == -2) dfs(G, w);
      mn = min(mn, low[w]);
    }
    if (mn < low[v]) { low[v] = mn; return; }
    int w; components.emplace_back(); do {
      id[w = stk[--top]] = components.size() - 1; low[w] = INT_MAX;
      components.back().push_back(w);
    } while (w != v);
  }
  template <class Digraph> SCC(const Digraph &G)
      : ind(0), top(0), id(G.size(), -2), low(G.size()), stk(G.size()) {
    for (int v = 0; v < int(G.size()); v++) if (id[v] == -2) dfs(G, v);
  }
  template <class Digraph>
  SCC(const Digraph &G, vector<pair<int, int>> &condensationEdges) : SCC(G) {
    vector<int> last(components.size(), -1);
    for (auto &&comp : components) for (int v : comp)
      for (int w : G[v]) if (id[v] != id[w] && last[id[w]] != id[v])
        condensationEdges.emplace_back(last[id[w]] = id[v], id[w]);
  }
};
