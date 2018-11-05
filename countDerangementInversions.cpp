/*
ThoughtSpot IITK 2018

Given n, find the sum of number of inversions over all derangements of length n.
As the number can be very large, print it modulo 1000000007.

Inversion in array A is a pair (i,j) where i < j and A[i] > A[j].
Derangement of length n is a permutation of 1..n such that A[i] != i for any i.

1 <= n <= 20

Formula taken from here - https://oeis.org/A216239
O(n)
*/
int countDerangementInversions(int n) {
	const int MOD = 1E9 + 7;
	const int inv12 = (MOD + 1) / 12;

	long long ans = 0;
	for (long long k = n - 1, v = n * (n - 1); k--; ) {
		long long x = v * (3 * n + k) * (n - k - 1) % MOD;
		if (k & 1) x = MOD - x;
		ans = (ans + x) % MOD;
		v = v * k % MOD;
	}
	return ans * inv12 % MOD;
}