#include <bits/stdc++.h> 

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)

{

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<pair<int,vector<int>>> help; 

    for(int i=0;i<k;i++){

      help.push_back({0, kArrays[i]});

      pq.push({kArrays[i][0], i});

    }   

    vector<int> ans;

    while(!pq.empty()){

        pair<int,int> temp=pq.top();

        pq.pop();

        int arrnum=temp.second;

        ans.push_back(temp.first);

        vector<int> temp1=kArrays[arrnum];

        int index=help[arrnum].first+1;

        if(index>=temp1.size()){

            continue;

        }

        else{

            help[arrnum]={index,temp1};

            pq.push({temp1[index],arrnum});

        }

    }

    return ans;

    // Write your code here. 

}