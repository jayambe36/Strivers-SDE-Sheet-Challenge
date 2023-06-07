from math import *    # Importing math library
from collections import *    # Importing collections library
from sys import *    # Importing sys library
from os import *    # Importing os library

def majorityElementII(arr):    # Defining function majorityElementII
	flo = floor(len(arr)/3)    # Store the floor value of length of array in flo
	freq = dict()    # Initialize empty dictionary "freq"
	outp = []    # Initialize empty list "outp"

	for i in range(0,len(arr)):    # Iterate over all elements of array
		if arr[i] in freq.keys():    # Check if element is already present in dictionary
			freq[arr[i]] += 1    # Increment count of element in dictionary
		else:
			freq[arr[i]] = 1    # Add new element to dictionary with count 1
	
	for i in freq.keys():    # Iterate over all keys in dictionary
		if freq[i] > flo:    # Check if count of element is greater than flo
			outp.append(i)    # Append element to list
	
	return outp    # Return list


"""
in cpp

// LeetCode Link: https://leetcode.com/problems/majority-element/
// ----------------------------------------------------------

/* Approach [ Bayer Moore's Majority Voting Algo ]:
1. If we need to find the element occurring > N / 2 times in O(N) Time and O(1) Space Complexity respectively, we need to follow this algorithm.
2. Bayer Moore's Majority Voting Algo is based on the Cancellation technique.
3. The idea is if we have an element occurring > N / 2 times, it won't be ever canceled by the rest of the elements combining together.
4. We need to do a manual check confirming that our majority element is right or not before returning it's value.
*/

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) 
{
	int majorEle = 0 ; int cnt = 0 ;

	for(int i = 0 ; i < n ; i++)
	{
		if(cnt == 0)  majorEle = arr[i] ;

		if(majorEle == arr[i])  cnt++ ;

		else  cnt-- ;
	}

	int freq = 0 ;

	for(int i = 0 ; i < n ; i++)
	{
		if(majorEle == arr[i])  freq += 1 ;
	}

	return freq * 2 > n  ? majorEle : -1 ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
"""