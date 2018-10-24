/*
Flipkart IIT Kanpur 2018

Given a limited number of coins of denominations 1, 5, 10, and 25
as p, q, r, and s respectively, return the maximum number of coins 
which can be used to reach a target "price", if possible.

Your function should return a vector of length 4 representing the
number of coins used for the denominations 1, 5, 10, 25 respectively.
If no solution is possible, return a vector of 0s.

0 <= price, p, q, r, s <= 100000
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dummy(4);
vector<int> greedy(int price, int p, int q, int r, int s) {
    if (price <= p) return {price, 0, 0, 0};
    price -= p;

    if (price <= 5 * q) {
        if (price % 5 == 0) return {p, price / 5, 0, 0};
        return dummy;
    }
    price -= 5 * q;

    if (price <= 10 * r) {
        if (price % 10 == 0) return {p, q, price / 10, 0};
        return dummy;
    }
    price -= 10 * r;

    if (price <= 25 * s) {
        if (price % 25 == 0) return {p, q, r, price / 25};
        return dummy;
    }

    return dummy;
}

vector<int> getMaxCoins(int price, int p, int q, int r, int s) {
    // Max wastage: 1.. 25; 5.. 5; 10.. 3
    map<int, set<vector<int>>> mp;
    for (int i = 0; i <= 25; i++) {
        for (int j = 0; j <= 5; j++) {
            for (int k = 0; k <= 3; k++) {
                if (p >= i and q >= j and r >= k) {
                    auto counts = greedy(price, p - i, q - j, r - k, s);
                    if (counts != dummy) {
                        int count = 0;
                        for (int c : counts) {
                            count += c;
                        }
                        mp[-count].insert(counts);
                    }
                }
            }
        }
    }
    if (mp.empty()) return dummy;
    auto feasible = mp.begin()->second;
    if (feasible.empty()) return dummy;
    return *feasible.begin();
}

signed main() {
    int denominations[] = {1, 5, 10, 25};
    vector<int> counts = getMaxCoins(99, 98, 0, 0, 1);
    
    for (int i = 0; i < 4; i++) {
        cout << "Number of coins of denomination " << denominations[i] << " = " << counts[i] << '\n';
    }
    return 0;
}