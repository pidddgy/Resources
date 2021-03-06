#pragma once
#include <bits/stdc++.h>
using namespace std;

// Computes the maximum value that can be obtained by items in a knapsack (from a selection of N items)
// that can hold a maximum of M weight, not allowing for repeated instances of items
// Time Complexity: O(NM)
// Space Complexity: O(N + M)
template <const int MAXN, const int MAXM, class value_type> struct ZeroOneKnapsack {
    int W[MAXN]; value_type V[MAXN], dp[MAXM];
    value_type solve(int N, int M) {
        fill(dp, dp + M + 1, 0);
        for (int i = 0; i < N; i++) for (int j = M; j >= W[i]; j--) dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        return dp[M];
    }
};

// Computes the maximum value that can be obtained by items in a knapsack (from a selection of N items)
// that can hold a maximum of M weight, not allowing for repeated instances of items,
// by turning the maximization problem into a minimization problem, with K as the sum of all values
// Time Complexity: O(NK)
// Space Complexity: O(N + K)
template <const int MAXN, const int MAXK, class weight_type> struct ZeroOneKnapsackDual {
    weight_type W[MAXN], dp[MAXK], INF; int V[MAXN];
    ZeroOneKnapsackDual(weight_type INF) : INF(INF) {}
    int solve(int N, weight_type M, int K) {
        fill(dp, dp + K + 1, INF); dp[0] = 0;
        for (int i = 0; i < N; i++) for (int j = K; j >= V[i]; j--) dp[j] = min(dp[j], dp[j - V[i]] + W[i]);
        for (int j = K; j >= 0; j--) if (dp[j] <= M) return j;
        assert(false); return -1;
    }
};
