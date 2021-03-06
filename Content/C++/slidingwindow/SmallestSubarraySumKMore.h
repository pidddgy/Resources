#pragma once
#include <bits/stdc++.h>
using namespace std;

// Computes the smallest subarray with a sum of K or more
// Time Complexity: O(N)
// Memory Complexity: O(N)
template <const int MAXN, class T> struct MaxSubarraySumK {
    T A[MAXN];
    int solve(int N, T K) {
        T curSum = 0; int minLen = N + 1;
        for (int l = 0, r = 0; r < N;) {
            while (curSum < K && r < N) curSum += A[r++];
            while (curSum >= K && l < N) { minLen = min(minLen, r - l); curSum -= A[l++]; }
        }
        return minLen;
    }
};
