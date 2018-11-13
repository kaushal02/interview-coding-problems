/*	
Cohesity : IITD
Scientific_Farmer:

Harry Stine is one of the wealthiest farmers in the world (net worth of $3.5 billion). Stine is known as a math wiz
and adopts unique practices when planting seeds and harvesting crops. For instance, his fields are always arranged
in a circular layout to promote better pollination, e.g., if there are n fields, then the 1st field and the nth field are
adjacent to each other. Also, his crop harvester machines never harvest two adjacent fields on the same day to
minimize damage to standing crops. Each field produces a certain yield (value) of crops. Given a list of non-negative
integers representing the yield of each field, determine the maximum yield of crops that Harry can harvest in a day.

==> Maximum sum in circular array such that no two elements are adjacent
Solution Approach:
	recursive solution with memoization
	
	recurse(idx,prev,frst)
	we are at index = idx, we need to decice whether to take
	a[idx] or not. prev indicates a[idx - 1] is taken or not
	frst == 1 : a[1] is taken
	frst == 0 : a[1] is not taken

	few examples: from other sources:
	
	3
	4 2 3
	=> 4
	
	4
	1 2 3 1
	=> 4
	
	6
	1 2 3 4 5 1
	=> 9

*/

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100009][2][2];
int a[100009];

int recurse(int idx,bool prev,bool frst) {
	if(idx == n) {
		if(!prev and !frst) {
			return a[idx];
		}else {
			return 0;
		}
	}
	if(dp[idx][prev][frst] != -1) return dp[idx][prev][frst];	
	int res = 0;		// all numbers are non negative
	if(prev == false) {
		// take a[idx]
		res = max(res,recurse(idx+1,true,frst) + a[idx]);	
		// not take a[idx]
		res = max(res,recurse(idx+1,false,frst));
	}else {
		// not take a[idx]
		res = max(res,recurse(idx+1,false,frst));
	}
	return dp[idx][prev][frst] = res;
}

int main() {
	cin >> n;
	for(int idx = 1;idx<=n;idx++) {
		cin >> a[idx];
	}
	memset(dp,-1,sizeof dp);
	// call two times
	// once not taking the first element
	// once taking the first element
	int res = (recurse(2,false,false) , recurse(2,true,true) + a[1]);
	cout << res << endl;
}