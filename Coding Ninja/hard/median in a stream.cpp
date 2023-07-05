//Time Complexity: O(N*N)
//Space Complexity: O(N)

 

#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	// Approach 1: Using Insert Sort
	// Intuition: an the kth iteration the array from 0 index
	// to kth index will be sorted in increasing order.
	// Time Complexity: O(N*N)
	// Space Complexity: O(N)
	vector<int> ans;
	for(int i = 0; i < n; i++){
		int j = i;
		while(j > 0 && arr[j] < arr[j - 1]){
			swap(arr[j], arr[j - 1]);
			j--;
		}
		if(i & 1){
			ans.push_back(0.5*(arr[(i+1)/2] + arr[i/2]));
		}
		else{
			ans.push_back(arr[i/2]);
		}
	}
	return ans;
}