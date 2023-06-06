#include <bits/stdc++.h> 
using ll = long long int ;

long long maxSubarraySum(int arr[], int n)
{
    ll maxSum = 0 ;  ll currSum = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        currSum += arr[i] ;
        if(maxSum < currSum)  maxSum = currSum ;
        if(currSum < 0)  currSum = 0 ;
    }
    return maxSum ;
}
