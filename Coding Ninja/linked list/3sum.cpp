#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {    //Defining function findTriplets
	// Write your code here.
	if(n<3)return {};    // check size of array

	vector<vector<int>> triplets;    // initialize an array of triplets

    sort(nums.begin(), nums.end());    // sort the array

	for(int i = 0; i<n-2; i++){    //iterate over array
        int start = i+1;    // initialize start variable
        int end = n-1;    // initialize end variable
        while(start<end){    // check if start is less than end
                
            int sum = nums[i] + nums[start] + nums[end];    //calculate sum
            if(sum == K){    // check if sum is equal to K
                triplets.push_back({nums[i], nums[start], nums[end]});    // push triplet in triplets array
                start++;    // increment start
                end--;    // decrement end
                while(start<n && nums[start] == nums[start-1]){    // check if start is less than n and if element at start and start-1 is equal
					start++;    //increment start
				}
					
                while(end>i && nums[end] == nums[end+1]){    // check if end is greater than i and if element at end and end+1 is equal
					end--;    //decrement end
				}	
            }
			else if(sum>K){    // check if sum is greater than K
                end--;    // decrement end
            } 
			else {    // else body
              start++;    // increment start
            }
        }
        while (i < n - 1 && nums[i] == nums[i + 1])    // check if i is less than n-1 and if element at i and i+1 is equal
          i++;    // increment i
    }
    return triplets;    // return triplets array
}


=========================


// LeetCode Link: 
// -----------------------------------------------------------

/* Approach:
1. Sort the array or vector nums[] and declare a 2D ans[][] vector.
2. Start a for loop from i = 0 till N
3. Use 2-pointers to get our target which is K - nums[i]
4. Low = i + 1 and High = n - 1 ;
5. If at any moment, our sum becomes equal to our target, we push the 3-numbers inside our ans [][] vector.
6. To skip duplicates we use, while(i + 1 < n && nums[i] == nums[i + 1) i++; 
*/

#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int> &arr, int n, int K) 
{
	sort(arr.begin() , arr.end() ) ;

	vector<vector<int>> ans ;

	for(int i = 0 ; i < n ; i++)
	{
		int target = K - arr[i] ;

		int low = i + 1 ; int high = n - 1 ;

		while(low < high)
		{
			int sum = arr[low] + arr[high] ;

			if(sum == target)
			{
				int a = arr[i] , b = arr[low] , c = arr[high] ;

				ans.push_back( {a , b , c} ) ;

				while(low < high && b == arr[low] ) low++ ;

				while(low < high && c == arr[high] ) high-- ;
			}

			else if(sum < target)  low++ ;

			else high-- ;
		}

		while(i + 1 < n && arr[i] == arr[i + 1] ) i++ ;
	}

	return ans ;
}

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(1)