/*
Walmart Labs IITG 2018

Following operations are defined:
1. X -> X + 1
2. X -> X - 1
Cost of operation 1 and 2 are cost_inc and cost_dec respectively. Given a number
N, find the minimum cost to reach a number M such that M can be represented as a
sum of two different single-digit odd prime numbers with positive powers.

O(k*logn) where k is very small. For n <= 1E8, there are less than 500 possible M
*/
#include <set>
int minCostOddPrimeSum(int n, int cost_dec, int cost_inc) {
    const int N = 1E6; // N represents the upper bound on input n. Adjust.
    const int LIM = 2 * N + 10;

    std::set<int> st;
    for (int p : {3, 5, 7}) {
        for (int q : {3, 5, 7}) {
            if (p <= q) continue;
            // p^i + q^j
            int pi = p;
            while (pi <= LIM) {
                int qj = q;
                while (pi + qj <= LIM) {
                    st.insert(pi + qj);
                    qj *= q;
                }
                pi *= p;
            }
        }
    }

    int lo = 0, hi;
    for (int x : st) {
        if (x == n) {
            return 0;
        }
        
        if (x < n) {
            lo = x;
        }
        else {
            hi = x;
            break;
        }
    }
    
    int ans = (hi - n) * cost_inc;
    int ans1 = (n - lo) * cost_dec;
    if (lo and ans > ans1) ans = ans1;
    return ans;
}