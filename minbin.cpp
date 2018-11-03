/*
Goldman Sachs IITD 2018

We are given an array of size N, we can delete a subset b1b2b3...bk from the 
array if 2^b1 + 2^b2 + …..2^bk = 2^x for non-negative integer x where ^ is the
power operator. Find the minimum number of steps required to delete the 
complete array.

0 <= ai <= 1000000
1 <= N <= 1000000

O(N + log N)
*/
int minBin(vector<int> a) {
	int n = max_element(a.begin(),a.end());
	vector<int> c(n + 30);
	for (int ai : a) c[ai]++;

	int ans = 0;
	for (int i = 0; i < n + 25; i++) {
		if (c[i] & 1) ans++;
		c[i + 1] += c[i] >> 1;
	}
	return ans;
}
