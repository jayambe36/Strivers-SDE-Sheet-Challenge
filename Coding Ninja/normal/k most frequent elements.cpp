#include <bits/stdc++.h>
typedef pair<int,int> pi;
class comp{
    public:
    bool operator()(pi &a,pi &b){
        return a.first>b.first;
    }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map <int,int> mp;
    for(int x:arr) mp[x]++;
    vector <pi> v;
    for(auto x:mp) v.push_back({x.second,x.first});
    comp c;
    sort(v.begin(),v.end(),c);
    vector <int> res;
    for(int i=0;i<k;i++) res.push_back(v[i].second);
    return res;
}