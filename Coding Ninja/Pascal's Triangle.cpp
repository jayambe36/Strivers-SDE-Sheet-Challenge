#include <bits/stdc++.h>
using ll = long long int ;

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<ll>> ans ;
    ans.push_back({1}) ; // We make our First Row ready

    if(n == 1)  return ans ; // If N = 1, we directly return our ans ;

    ans.push_back({1 , 1}) ; // We make our Second Row ready

    if(n == 2)  return ans ;

    for(int ind = 2 ; ind < n ; ind++)
    {
        vector<ll> currRow ; currRow.push_back(1) ; // Starting and ending  of all the Pascal Rows contains the value 1
        int len = ans[ind - 1].size() ;

        for(int i = 0 ; i < len - 1 ; i++)
        {
            ll a = ans[ind - 1][i] ; ll b = ans[ind - 1][i + 1] ;
            ll val = a + b ;
            currRow.push_back(val) ;
        }
        
        currRow.push_back(1) ;  ans.push_back(currRow) ; // At the end of each iteration, we push our currRow into our ans[][] vector
    }

    return ans ;
}