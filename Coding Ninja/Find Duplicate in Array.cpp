#include <bits/stdc++.h>    

int findDuplicate(vector<int> &arr, int n)    // Defining function findDuplicate
{
	unordered_map<int, int> visited;    // Initialize an unordered_map data structure
	for(int i = 0 ; i < n ; i++)  visited[arr[i]] += 1 ;    // Loop through the array and map each element with its count
	for(auto it : visited)
	{
		if(it.second > 1)  return it.first ;    // Check for duplicate in map.
	}
	return 0 ;    // Return 0 if no duplicate found
}


==============


// LeetCode Link: https://leetcode.com/problems/find-the-duplicate-number/
// ---------------------------------------------------------------------

/* Approach:
1. The most easiest way to do the question is by using a frequency[] or visited array[] to keep track of the count of elements we have visited till now.
2. At the end, we traverse over the array and check which element has a count of 2 and we return the element.
3. Another approach using O(1) Space Complexity is using a Linked-List Cycle detection technique.
*/

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
	vector<int> visited(n , 0) ;

	for(int i = 0 ; i < n ; i++)  visited[arr[i]] += 1 ;

	for(int i = 1 ; i < n ; i++)
	{
		if(visited[i] > 1)  return i ;
	}

	return 0 ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)