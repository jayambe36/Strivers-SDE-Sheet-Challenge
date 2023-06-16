void addBoard(vector<vector<int>> &board, vector<vector<int>> &res){
    vector<int> temp;
    int n = board.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }

    res.push_back(temp);
}

void helper(int col, vector<vector<int>> &board, int n, vector<bool> &leftRow,
vector<bool> &leftUpperDiagonal, vector<bool> &leftLowerDiagonal, vector<vector<int>> &res){
    if(col == n){    // check if number of columns in board is equal to "n"
        addBoard(board, res);    // call addBoard() to add the current board to res
        return;
    }

    for(int row = 0; row < n; row++){    // Loop through rows
        if(!leftRow[row] && !leftLowerDiagonal[row+col] && !leftUpperDiagonal[n-1+col-row]){    // Check if current row is free
            board[row][col] = 1;    // Add queen on row and current column
            leftRow[row] = true;    // Mark current row as busy
            leftLowerDiagonal[row+col] = true;    // Mark left lower diagonal of current position as busy
            leftUpperDiagonal[n-1+col-row] = true;    // Mark left upper diagonal of current position as busy
            helper(col+1, board, n, leftRow, leftUpperDiagonal, leftLowerDiagonal, res);    // Call helper function for next column
            leftRow[row] = false;    // Mark current row as free
            leftLowerDiagonal[row+col] = false;    // Mark left lower diagonal of current position as free
            leftUpperDiagonal[n-1+col-row] = false;    // Mark left upper diagonal of current position as free
            board[row][col] = 0;    // Remove queen from current position
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<bool> leftRow(n, false);    // Define vector of "leftRow" of size n and initialise with false
    vector<bool> leftUpperDiagonal(2*n-1, false);    // Define vector of "leftUpperDiagonal" of size 2*n-1 and initialise with false
    vector<bool> leftLowerDiagonal(2*n-1, false);    // Define vector of "leftLowerDiagonal" of size 2*n-1 and initialise with false

    vector<vector<int>> res, board(n, vector<int> (n, 0));    // Define vector of vector res and board of size n*n and initialise with 0

    helper(0, board, n, leftRow, leftUpperDiagonal, leftLowerDiagonal, res);    // Call helper function with column 0

    return res;
}

//time complexity : O(n^2)
//space complexity : O(2*n)
