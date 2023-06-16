#include <bits/stdc++.h>
void helper(string &s, unordered_set<string> &str_dict,vector<string> &ans, int n, int location,string temp){    // helper function
    if(location==n){    // if condition
        ans.push_back(temp);    // push the value of temp in ans
        return ;    // return
    }

    for(int i=location; i<n; i++)
    {
        string x = s.substr(location,i-location+1);    // string x = substring of s from location to i
        if(str_dict.find(x) != str_dict.end()){    // x is present in dictionary
            helper(s,str_dict,ans,n,i+1,temp+x+" ");    // recursive call
        }
    }

}

vector<string> wordBreak(string &s, vector<string> &dictionary)    // wordBreak function
{
    unordered_set<string> str_dict(dictionary.begin(), dictionary.end());    // str_dict is a set containing all the values of dictionary
    vector<string> ans;    // ans is a vector
    int n = s.length();    // get the length of s

    helper(s,str_dict,ans, n, 0,"");    // calling helper function
    return ans;    // return ans

}