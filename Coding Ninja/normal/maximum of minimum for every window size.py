'''

 

    Time Complexity: O(N)

 

    Space complexity: O(N)

 

    Where 'N' is the number elements present in the given array.

 

'''

 

from sys import maxsize

 

# This function will return an array.

 

# Each ith position contains the index of previous smaller elements in the original array.

 

def previousSmaller(arr, n):

 

    prev = []

 

    s = []

 

    for i in range(n):

 

        while (len(s) != 0 and arr[s[-1]] >= arr[i]):

 

            s.pop()

 

        if (len(s) == 0):

 

            prev.append(-1)

 

        else:

 

            prev.append(s[-1])

 

        s.append(i)

 

    return prev

 

# This function will return an array.

 

# Each ith position contains the index of next smaller elements in the original array.

 

def nextSmaller(arr, n):

 

    s = []

 

    next = [0] * n

 

    for i in range(n-1, -1, -1):

 

        while (len(s) != 0 and arr[s[-1]] >= arr[i]):

 

            s.pop()

 

        if (len(s) == 0):

 

            next[i] = n

 

        else:

 

            next[i] = s[-1]

 

        s.append(i)

 

    return next

 

def maxMinWindow(arr, n):

 

    INT_MIN = -maxsize - 1

 

    answer = [INT_MIN] * n

 

    # Definition: next[i] will store the index of next smaller element which lie on the right hand side of 'i'.

 

    next = nextSmaller(arr, n)

 

    # Definition: prev[i] will store the index of previous smaller element which lie on the left hand side of 'i'.

 

    prev = previousSmaller(arr, n)

 

    for i in range(n):

 

        # Length of the window in which a[i] is minimum

 

        length = next[i] - prev[i] - 1

 

        # Update the answer[length-1] ( 0 based indexing )  with a[i]

 

        answer[length - 1] = max(answer[length - 1], arr[i])

 

    # Some entries in answer[] may not be filled yet.

 

    # We fill them by taking maximum element from suffix starting from 'i'.

 

    for i in range(n - 2, -1, -1):

 

        answer[i] = max(answer[i], answer[i + 1])

 

    return answer

 