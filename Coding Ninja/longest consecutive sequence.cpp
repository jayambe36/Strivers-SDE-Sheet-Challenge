#include <bits/stdc++.h>    

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)    // Define a function to get length of longest consecutive sequence
{
    unordered_set<int> hashSet ;    // Create a hash table to store the values of array

    int maxCnt = 1 ;    // Initialize maxCnt with 1

    for(int nums : arr)  hashSet.insert(nums) ;    // Insert all the elements of array in hash table

    for(int i = 0 ; i < n ; i++)    // Iterate over all the elements of array
    {
        int val = arr[i] ;    // take value of ith element of array

        if(hashSet.find(val - 1) == hashSet.end() )    // Check if the value is not present in previous index
        {
            int cnt = 1 ;    // Initialize count with 1

            while(hashSet.find(val + 1) != hashSet.end() )    // Iterate till next value is present in hash table
            {
                cnt++ ;    // increment count

                hashSet.erase(val) ;  val += 1 ;    // Delete the value from hash table and increment value by 1
            }

            maxCnt = max(maxCnt , cnt) ;    // Update the maximum length
        }
    }

    return maxCnt ;    // Return maxCnt
}


========================

// LeetCode Link: https://leetcode.com/problems/longest-consecutive-sequence/
// ----------------------------------------------------------------------------------------------

/* Approach:
1. Make sure we use a unordered_set and not an ordered_set to avoid TLE.
2. First we put all our elements into our hashSet.
3. Now we need to ensure that we count any consecutive sequence only once. To do that, we first check if (nums[i] - 1) is present inside our hashSet or not. This proves that this is the starting and no other element could be the starting of the sequence as (val - 1) is not present in our hashSet.
3. Now, we initialize our cnt = 1 and run a while loop which runs till our hashSet is not empty and (nums[i] + 1) is present inside our hashSet. If so, we increment our cnt by 1 and erase the current element nums[i] from our hashSet.
4. This is done to ensure we don't count the same consecutive set again and again. It means if we have covered the sequence (1,2,3,4,5) then there's no point counting for (3,4,5) again.
5. This small optimization helps us to reduce our Time Complexity to O(N) instead of O(N * Log N) by using custom sort or ordered_set.
*/

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) 
{
    unordered_set<int> hashSet ;

    int maxCnt = 1 ;  

    for(int nums : arr)  hashSet.insert(nums) ;

    for(int i = 0 ; i < n ; i++)
    {
        int val = arr[i] ;

        if(hashSet.find(val - 1) == hashSet.end() )
        {
            int cnt = 1 ;

            while(!hashSet.empty() && hashSet.find(val + 1) != hashSet.end() )
            {
                cnt++ ;  

                hashSet.erase(val) ;  val += 1 ;
            }

            maxCnt = max(maxCnt , cnt) ;
        }
    }

    return maxCnt ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)