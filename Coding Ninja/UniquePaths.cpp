import java.util.* ;    // Import util library
import java.io.*;    // Import io library
public class Solution {    // Declaring class Solution
	public static int uniquePaths(int m, int n) {    // Declaring function uniquePaths
		// Write your code here.
		int[][] dp = new int[m][n];    // Initialize 2d-array dp
        for(int i=0;i<m;i++)
        {
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++)
        {
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
	}
}

