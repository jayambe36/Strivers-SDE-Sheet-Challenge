optimistic code

#include <bits/stdc++.h>   
#include <vector>    
#include <unordered_set> 
using namespace std;    

void setZeros(vector<vector<int>>& matrix) {    // Define the setZeros() function
    int rows = matrix.size();    // Get the number of rows
    int cols = matrix[0].size();    // Get the number of columns

    bool row_flag = false;    // Define a flag variable row_flag
    bool col_flag = false;    // Define a flag variable col_flag

    // Identify the rows and columns containing zeros
    for (int i = 0; i < rows; i++) {    // iterate through every row
        for (int j = 0; j < cols; j++) {    // iterate through every column
            if (matrix[i][j] == 0) {    // check if the matrix[i][j] is equal to zero
                matrix[0][j] = 0;    // Make the first row of column j as zero
                matrix[i][0] = 0;    // Make the first column of row i as zero
                if (i == 0) row_flag = true;    // If i is equal to zero then set row_flag as true
                if (j == 0) col_flag = true;    // If j is equal to zero then set col_flag as true
            }
        }
    }

    // Set rows and columns to zero
    for (int i = 1; i < rows; i++) {    // iterate through every row
        for (int j = 1; j < cols; j++) {    // iterate through every col
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {    // check if the first column of a row or the first row of a column is equal to zero
                matrix[i][j] = 0;    // Make the matrix[i][j] as zero
            }
        }
    }

    // Set first row and column to zero
    if (row_flag) {    // check if row_flag is true
        for (int j = 0; j < cols; j++) {    // iterate through every column
            matrix[0][j] = 0;    // Make the first row of column j as zero
        }
    }

    if (col_flag) {    // check if col_flag is true
        for (int i = 0; i < rows; i++) {    // iterate through every row
            matrix[i][0] = 0;    // Make the first column of row i as zero
        }
    }
}


===========================

simple code 

#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
using namespace std;

void setZeros(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    unordered_set<int> zero_rows;
    unordered_set<int> zero_cols;

    // Identify the rows and columns containing zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    // Set rows and columns to zero
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (zero_rows.count(i) || zero_cols.count(j)) {
                matrix[i][j] = 0;
            }
        }
    }
}

