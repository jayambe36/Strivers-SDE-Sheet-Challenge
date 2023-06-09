#include <bits/stdc++.h>   

int LongestSubsetWithZeroSum(vector < int > arr) {    // Defining function "LongestSubsetWithZeroSum"
  unordered_map<int,int> mp;    // Initialize a hash map (unordered_map)
  int maxi = 0;    // Initialize maxi with 0
  int sum = 0;    // Initialize sum with 0
  for(int i = 0; i < arr.size(); i++){    // Looping through all elements of "arr"
      sum += arr[i];    // Sum of all elements in "arr"
      if(sum == 0) maxi = i+1;    // maxi is size of "arr"
      else if(mp.find(sum) != mp.end()){    // if sum is found in "mp"
        maxi = max(maxi, i - mp[sum]);    // update maxi
      }else{
        mp[sum] = i;    // insert sum as key and i as value in "mp"
      }
  }

  return maxi;    // Return maxi

}
