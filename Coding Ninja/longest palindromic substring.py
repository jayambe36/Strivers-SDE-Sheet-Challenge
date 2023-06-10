def longestPalinSubstring(s):    # Defining function "longestPalinSubstring"
    n = len(s)    # Initialize variable "n" with length of "s" variable
    memo = [[None] * n for _ in range(n)]  # Memoization table to store results    
    
    def is_palindrome(start, end):    # Defining function "is_palindrome"
        if start >= end:    # Check if start is greater than end
            return True    # return true
        
        if memo[start][end] is not None:    # check if memo[start][end] is not null
            return memo[start][end]    # return memo[start][end]
        
        if s[start] == s[end] and is_palindrome(start + 1, end - 1):    # check if s[start] == s[end] and is_palindrome(start + 1, end - 1)
            memo[start][end] = True    # assign value true in memo[start][end]
            return True    # return true
        
        memo[start][end] = False    # assign value false in memo[start][end]
        return False    # return false
    
    longest = ''
    max_length = 0
    start = 0
    end = 0
    
    for i in range(n):    # iterate over n
        for j in range(i, n):    # iterate over n
            if is_palindrome(i, j) and j - i + 1 > max_length:    # check if is_palindrome(i, j) and j - i + 1 > max_length
                longest = s[i:j+1]    # assign value to longest
                max_length = j - i + 1    # assign value to max_length
                start = i    # assign value to start
                end = j    # assign value to end
    
    return s[start:end+1]    # return value
