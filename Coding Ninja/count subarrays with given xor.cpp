#include <bits/stdc++.h>   

int subarraysXor(vector<int> &arr, int k)    // define function subarraysXor with 2 parameters
{
    int n = arr.size() ;    // define n as the size of array
    int ans = 0 ;  int prefXOR = 0 ;    // initialize ans, prefXOR
    unordered_map<int , int> hashMap ;  hashMap[0] = 1 ;    // initialize hashmap with key=0 and value=1
    for(int i = 0 ; i < n ; i++)
    {
        prefXOR ^= arr[i] ;    // xor with previous value stored in prefXOR
        ans += hashMap[prefXOR ^ k] ;    // add value of the key stored in hashmap
        hashMap[prefXOR] += 1 ;    // increase the value of the key stored in hashmap
    }
    return ans ;    // return ans
}


===============


// Link: https://www.interviewbit.com/problems/subarray-with-given-xor/
// ----------------------------------------------------------------------

/* Approach [Exactly same as Subarray Sum Equals K]
1. The approach to the problem remains exactly the same as finding the Max Length of the subarray whose sum is K.
2. Instead of using prefixSum. we would be using prefXOR here. 
3. We just need to increment our ans by hashMap[prefXOR ^ K] if we have it inside our hashMap and increment the count of hashMap[prefXOR] by 1 at every stage.
*/

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    int n = arr.size() ;

    int ans = 0 ;  int prefXOR = 0 ;

    unordered_map<int , int> hashMap ;  hashMap[0] = 1 ;

    for(int i = 0 ; i < n ; i++)
    {
        prefXOR ^= arr[i] ;

        int key = prefXOR ^ k ;

        if(hashMap.find(key) != hashMap.end() )  ans += hashMap[key] ;

        hashMap[prefXOR] += 1 ;
    }

    return ans ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N)