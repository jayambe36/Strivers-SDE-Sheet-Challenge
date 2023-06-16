#include <bits/stdc++.h> // Include all standard C++ library

bool comparator(vector<int> j1, vector<int> j2)
{                                                               // comparator function to sort the jobs according to their profit
    return j1[1] > j2[1] || (j1[1] == j2[1] && j1[0] >= j2[0]); // sort according to profit and if profit is same then sort according to deadline
}

int jobScheduling(vector<vector<int>> &jobs)
{                                               // function to perform activity selection
    sort(jobs.begin(), jobs.end(), comparator); // sort array of jobs according to comparator function
    int maxDeadline = -1, profit = 0;           // Initialize maxDeadline and profit with -1 and 0
    for (int i = 0; i < jobs.size(); i++)
    {                                               // traverse the array of jobs
        maxDeadline = max(maxDeadline, jobs[i][0]); // find max deadline of all jobs
    }
    vector<int> dp(maxDeadline + 1, -1); // Create an array to store the profit of job
    for (int i = 0; i < jobs.size(); i++)
    {                       // traverse the array of jobs
        int d = jobs[i][0]; // store the deadline of the job in d
        for (int j = d; j > 0; j--)
        { // traverse the array from the deadline to 1
            if (dp[j] == -1)
            {                       // check if profit at that index is -1 or not
                dp[j] = jobs[i][1]; // if yes then store the profit of job at index j
                break;              // break the loop
            }
        }
    }
    for (int i = 1; i <= maxDeadline; i++)
    { // traverse the array
        if (dp[i] != -1)
        {                    // check if profit at that index is not -1 or not
            profit += dp[i]; // if yes then add the profit of job to profit
        }
    }
    return profit; // return profit
}