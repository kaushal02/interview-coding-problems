/*
Goldman Sachs IITD 2018

We are given an array of size N, we can delete a subset b1b2b3...bk from the 
array if 2^b1 + 2^b2 + …..2^bk = 2^x for non-negative integer x where ^ is the
power operator. Find the minimum number of steps required to delete the 
complete array.

0 <= ai <= 1000000
1 <= N <= 1000000

Approach: The problem boils down to finding the number of set-bits in 
the summation 2^a0 + 2^a1 + 2^a2 + ... which can be done by counting the number
of ai's for each ai and then using the same logic as you do for adding up two 
decimal numbers but instead of base-10, use base-2

O(N + L + log L) where L is the upper bound on value of ai
*/
int minBin(vector<int> a) {
	const int L = 1E6; // max possible value of ai
	vector<int> cnt(L + 30);
	for (int ai : a) cnt[ai]++;

	int ans = (cnt[0] & 1);
	for (int i = 1; i < L + 30; i++) {
		cnt[i] += cnt[i - 1] >> 1;
		if (cnt[i] & 1) ans++;
	}
	return ans;
}