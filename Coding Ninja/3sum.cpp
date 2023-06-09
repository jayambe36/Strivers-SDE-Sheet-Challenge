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