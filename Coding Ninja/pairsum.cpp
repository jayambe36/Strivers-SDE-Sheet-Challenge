#include <bits/stdc++.h>   

vector<vector<int>> pairSum(vector<int> &arr, int s){    // Define function pairSum
   vector<vector<int>> pairs;    // Create empty vector pairs
   map<int,int> mp;    // Create empty map mp
   for(int n:arr){    // Loop through all elements of arr
      mp[n]++;    // Increment the count of element n
   }

   map<int,int>::iterator itr=mp.begin();    // itr points to first element of map
   while(itr!=mp.end()){    // Loop through all element of map
      int val=itr->first;    // val stores current element of map
      if(s-val<0 || val>(s-val)){    // if sum is negative or val is greater than (sum-val)
         break;    // break the loop
      }
      auto it=mp.find(s-val);    // search for (sum-val) in map
      if(it!=mp.end()){    // if (sum-val) is present in map
         int count=val==it->first ? (itr->second*(itr->second-1))/2 : itr->second*it->second;    // count the number of times (sum-val) is present
         for(int i=0;i<count;i++){    // loop for all occurences of (sum-val)
            pairs.push_back({val,it->first});    // push pair (val,(sum-val)) in pairs vector
         }
      }
      itr++;    // increment itr
   }
   
   return pairs;    // return pairs vector
}



 
