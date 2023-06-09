#include <bits/stdc++.h>    
using namespace std;    

int Merge(vector < int > & nums, int low, int mid, int high) {    // Defining function Merge 
  int total = 0;    // Initialize total variable with value 0
  int j = mid + 1;    // Initialize j with mid+1
  for (int i = low; i <= mid; i++) {    // for loop to traverse till mid
    while (j <= high && nums[i] > 2LL * nums[j]) {    // while loop to traverse till high
      j++;
    }
    total += (j - (mid + 1));    // Calculate total
  }

  vector < int > t;    // Create vector t
  int left = low, right = mid + 1;    // Initialize left and right with low and mid+1 respectively

  while (left <= mid && right <= high) {    // while loop to traverse till mid and high respectively

    if (nums[left] <= nums[right]) {    // Check if value of left is less than or equal to value of right
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {    // while loop to traverse till mid
    t.push_back(nums[left++]);
  }
  while (right <= high) {    // while loop to traverse till high
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;    // return value of total
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;    // Check if low is greater than or equal to high
  int mid = (low + high) / 2;    // Calculate mid
  int inv = MergeSort(nums, low, mid);    // Initialize inv with value returned by MergeSort function
  inv += MergeSort(nums, mid + 1, high);    // Add the value returned by MergeSort function
  inv += Merge(nums, low, mid, high);    // Add the value returned by Merge function
  return inv;
}
int reversePairs(vector < int > & arr, int n) {
  return MergeSort(arr, 0, n-1);    // return the value returned by MergeSort function
}

/*
time complexity : O(N logN)
space complexity : O(1)
*/