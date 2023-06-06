#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices)    // Defining function "maximumProfit"
{
    int n = prices.size() ;    // Initialize variable n and assign size of prices to it
    
    int costPrice = prices[0] ;    // Initialize variable costPrice and assign prices[0] to it
    
    int maxProfit = 0 ;    // Initialize variable maxProfit and assign 0 to it

    for(int i = 1 ; i < n ; i++)    // for loop from i=1 to i < n
    {
        if(costPrice <= prices[i] )  maxProfit = max(maxProfit , prices[i] - costPrice) ;

        else  costPrice = prices[i] ;
    }

    return maxProfit ;
}
