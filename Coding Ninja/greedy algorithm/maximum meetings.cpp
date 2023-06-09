
#include <bits/stdc++.h>    // Include all the libraries

typedef struct meetings    // Defining a struct meetings
{
    int start ;  int end ; int pos ;

} meeting ;

static bool cmp(meeting &A , meeting &B)    // Defining a static boolean compare function
{
    return A.end < B.end;    // Compare end time of meeting A and B
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)    // Defining a function maximumMeetings
{
    int n = start.size() ;    // Initialize variable n with number of meetings
    
    meetings *room = new meetings[n] ;    // Create a pointer variable of type meetings and allocate memory
    
    for(int i = 0 ; i < n ; i++)
    {
        room[i].start = start[i] ;  room[i].end = end[i] ;  room[i].pos = i + 1 ;    // Assign start time, end time and position of meeting
    }
    
    sort(room , room + n , cmp) ;    // Sort the meetings according to end time
    
    vector<int> ans ;  ans.push_back(room[0].pos) ;    // Push the first meeting in ans vector
    
    int endTime = room[0].end ;    // Initialize endTime with the end time of first meeting

    for(int i = 1 ; i < n ; i++)
    {
        if(room[i].start <= endTime)  continue ;    // Check if the start time of meeting is less than endTime
        
        ans.push_back(room[i].pos) ; endTime = room[i].end ;    // Push the meeting and update endTime
    }

    return ans ;
}


===========================


// GFG Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// ------------------------------------------------------------------------------------------

/* Approach [Greedy Approch]
1. We use a vector to store all the {start, end} times and sort them based on the end time.
2. This is done because our goal is to have as many meetings inside a room as possible. For this, we prefer to have the meetings starting earlier at the earliest positions.
3. If the current meetings startTime <= maxEndTime, it means we cannot have that meeting so we continue.
4. Else we increment our maxCnt by 1 and update our maxEndTime as the current meeting's endTime.
*/

#include <bits/stdc++.h> 

typedef struct meetings
{
    int start ;  int end ; int pos ;

} meeting ;

static bool cmp(meeting &A , meeting &B)
{
    if(A.end < B.end)  return true ;
    
    else if (A.end == B.end && A.pos < B.pos)  return true ;

    return false ;    
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) 
{
    int n = start.size() ;
    
    meetings *room = new meetings[n] ;
    
    for(int i = 0 ; i < n ; i++)
    {
        room[i].start = start[i] ;  room[i].end = end[i] ;  room[i].pos = i + 1 ;
    }
    
    sort(room , room + n , cmp) ;
    
    vector<int> ans ;  ans.push_back(room[0].pos) ;
    
    int endTime = room[0].end ;

    for(int i = 1 ; i < n ; i++)
    {
        if(room[i].start <= endTime)  continue ;
        
        ans.push_back(room[i].pos) ; endTime = room[i].end ; 
    }

    return ans ;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N) 