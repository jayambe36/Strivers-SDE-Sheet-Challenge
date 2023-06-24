#include<stack>
#include<vector>
#include<bits/stdc++.h> 
vector<int> nextsmallerElement(vector<int> arr,int n)
{
  stack<int> s;
  vector<int> ans(n);
  s.push(-1);
  for(int i=n-1;i>=0;i--)
  {
    while(s.top() !=-1 && arr[s.top()] >= arr[i])
     s.pop();
    ans[i]=s.top();
    s.push(i);
  }
  return ans;
}
vector<int> prevsmallerElement(vector<int> arr,int n)
{
  stack<int> s;
  vector<int> ans(n);
  s.push(-1);
  for(int i=0;i<n;i++)
  {
    while(s.top() !=-1 && arr[s.top()] >= arr[i])
     s.pop();
    ans[i]=s.top();
    s.push(i);
  }
  return ans;
}

int largestRectangle(vector < int > & heights) {
  int n=heights.size();
  vector<int> next(n);
  next=nextsmallerElement(heights,n);

  vector<int> prev(n);
  prev=prevsmallerElement(heights,n);
  
  int area=INT_MIN;
  for(int i=0;i<n;i++)
  {
    int l=heights[i];
    if(next[i] == -1)
    {
      next[i]= n;
    }
    int b=next[i] - prev[i] -1;
    int newArea=l*b;
    area=max(area,newArea);
  }
  
   return area;
 
 }