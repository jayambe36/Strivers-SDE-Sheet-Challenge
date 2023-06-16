#include <bits/stdc++.h> 
void subsetSumHelper(int i, vector<int> &num, vector<int> &ans, int sum){    // Define the function subsetSumHelper
    if(i >= num.size()){    // Check if i is greater than size of number
        ans.push_back(sum);    // Add the sum to ans
        return;    // return nothing
    }
    //pick
    subsetSumHelper(i+1, num, ans, sum + num[i]);    // Pick current element and add to sum
    //not pick
    subsetSumHelper(i+1, num, ans, sum);    // Not pick current element and pass the sum
}

vector<int> subsetSum(vector<int> &num)    // Define the subsetSum function
{
    vector<int> ans;    // Initialize vector ans
    int i = 0;
    int sum = 0;
    subsetSumHelper(i, num, ans, sum);    // Call the subsetSumHelper function to perform computation
    sort(ans.begin(), ans.end());    // Sort the ans vector
    return ans;    // Return the ans vector
}