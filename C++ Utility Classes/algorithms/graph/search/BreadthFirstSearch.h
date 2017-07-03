/*
 * BreadthFirstSearch.h
 *
 *  Created on: Jul 2, 2017
 *      Author: Wesley Leung
 */

#ifndef ALGORITHMS_GRAPH_SEARCH_BREADTHFIRSTSEARCH_H_
#define ALGORITHMS_GRAPH_SEARCH_BREADTHFIRSTSEARCH_H_

#include <bits/stdc++.h>
#include <datastructures/graph/Graph.h>

using namespace std;

bool *marked;
int *distTo;
int *edgeTo;

/**
 * Computes the shortest path between the source vertex {@code s}
 * and every other vertex in the graph {@code G}.
 * @param G the graph
 * @param s the source vertex
 */
void bfs(Graph *G, int s) {
    queue<int> q;
    marked = new bool[G->getV()];
    distTo = new int[G->getV()];
    edgeTo = new int[G->getV()];
    for (int v = 0; v < G->getV(); v++) {
        marked[v] = false;
        distTo[v] = INT_MAX;
        edgeTo[v] = -1;
    }
    distTo[s] = 0;
    marked[s] = true;
    q.push(s);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : G->adj(v)) {
            if (marked[w]) continue;
            edgeTo[w] = v;
            distTo[w] = distTo[v] + 1;
            marked[w] = true;
            q.push(w);
        }
    }
}

#endif /* ALGORITHMS_GRAPH_SEARCH_BREADTHFIRSTSEARCH_H_ */