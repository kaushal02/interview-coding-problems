/*
BNY Mellon IITK 2018

Given N, find the number of ordered pairs of positive integers (x,y) satisfying
the following relation:
1/x + 1/y = 1/N!

0 <= N <= 100000
time O(N * log log N)
space O(N)
*/
#include <iostream>
#include <vector>
using namespace std;
/*
 * Let k = N!. We solve for general 1/x + 1/y = 1/k
 * 
 * x, y > 0 hence x, y > k. Let
 *     p = #ordered pairs where x=y
 *     q = #ordered pairs where x<y
 *     r = #ordered pairs where x>y
 * 
 * Clearly, p = 1 and q = r. Our final answer becomes 1 + 2q. Let’s solve for q
 * 
 * Since x < y, we get x ∊ (k, 2k). Also, y = x * k / (x - k)
 * 
 * Let x’ = x - k. Then x’ ∊ (0, k) and y = (x’ + k) * k / x’ is an integer
 * greater than x. Hence, x’ divides k^2 and x ∊ (0, 2k) which is already true
 * 
 * It means there exists a pair of type (ii) corresponding to x’ ∊ (0, k)
 * whenever x’ divides k^2. Hence q = #divisors of k^2 less than k
 * 
 * Hence final answer becomes #divisors of k^2. Recall k = N!
 */
const int mod = 1E9 + 7;

int main() {
    int n; cin >> n;
    int ans = 1;
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i <= n; i++) {
        // check if prime
        if (isprime[i]) {
            // mark all multiples non-prime
            for (int imul = 2 * i; imul <= n; imul += i) {
                isprime[imul] = false;
            }
            // update ans
            int ncopy = n, ipower = 0;
            while (ncopy) ipower += ncopy /= i;
            ans = (1LL + 2 * ipower) * ans % mod;
        }
    }
    cout << ans;
    return 0;
}
