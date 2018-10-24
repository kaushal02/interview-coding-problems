/*
Nutanix IISc 2018
https://www.codechef.com/problems/CLKLZM

O(n + m log m)
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    // your code goes here
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cases; cin >> cases;
    while (cases--) {
        int n, m; cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<pair<int,int>,int>> b(m);
        for (int i = 0; i < m; i++) {
            int l, r, k; cin >> l >> r >> k;
            b[i] = {{l - 1, r - 1}, k};
        }
        sort(b.begin(), b.end(), [](pair<pair<int,int>,int> l, pair<pair<int,int>,int> r) {
            if (l.first.first == r.first.first) return l.first.second > r.first.second;
            return l.first.first < r.first.first;
        });

        vector<int> c(n);
        int j = 0, ext = 0, ans = 0, fl = 0;
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            a[i] -= ext;

            while (j < m and b[j].first.first <= i) {
                q.push({b[j].first.second, b[j].second});
                j++;
            }

            int r, k;
            while (a[i] > 0 and not q.empty()) {
                tie(r, k) = q.top(); q.pop();
                if (r < i) continue;
                
                if (k <= a[i]) {
                    ans += k;
                    ext += k;
                    c[r] += k;
                    a[i] -= k;
                }
                else {
                    ans += a[i];
                    ext += a[i];
                    c[r] += a[i];
                    q.push({r, k - a[i]});
                    a[i] = 0;
                }
            }

            if (a[i] > 0) {
                fl = 1;
                break;
            }
            ext -= c[i];
        }
        if (fl) cout << "NO";
        else cout << "YES " << ans;
        cout << '\n';
    }
    return 0;
}