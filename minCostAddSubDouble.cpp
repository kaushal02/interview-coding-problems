/*
Walmart Labs IIT Dhanbad 2018

For a given number A, following operations are allowed:
1. A -> A + 1
2. A -> A - 1 (provided A > 0)
3. A -> 2 * A
Cost of operation 1 and 2 is equal to A and cost of operation 2 is B.
Find the minimum cost to reach X starting from 0.

1 <= X <= 100000
0 <= A, B <= 1000000
O(X)
*/
inline void Min(int &a, int b) {
    if (a > b) a = b;
}
int find_min_cost(int A, int B, int X) {
    vector<int> ans(4 * X, -1);
    ans[0] = 0;
    for (int i = 1; i <= X; i++) {
        ans[i] = ans[i - 1] + A;
        
        if (i & 1) Min(ans[i], ans[i >> 1] + B + A);
        else Min(ans[i], ans[i >> 1] + B);
        
        if (ans[i + 1] != -1) Min(ans[i], ans[i + 1] + A);
        ans[i << 1 | 1] = ans[i] + B + A;
        ans[i << 1] = ans[i] + B;
    }
    return ans[X];
}