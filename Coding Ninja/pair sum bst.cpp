#include <bits/stdc++.h>    
bool pairSumBst(BinaryTreeNode<int> *root, int k){    // Define bool function pairSumBst
    vector<int> arr;    // Define vector arr
    stack<BinaryTreeNode<int>*> s;    // Define stack of BinaryTreeNode
    auto *curr = root;    // initialize a pointer to root

    while (curr != NULL || !s.empty()){    // While loop to traverse BST in inorder.
        while (curr != NULL){    // While loop to traverse left subtree
            s.push(curr);    // Push the current node into stack
            curr = curr->left;    // Update the curr pointer by assigning curr->left
        }
        curr = s.top();    // Update the current pointer by assigning the top of stack
        s.pop();    // Pop the top element from stack
        arr.push_back(curr->data);    // Push the current node data into vector
        curr = curr->right;    // Update the curr pointer by assigning curr->right
    }

    int lo = 0, hi = arr.size()-1;    // Define two int variables lo=0, hi=arr.size()-1
    while (lo < hi){    // While loop to compare the array elements
        int sum = arr[lo] + arr[hi];    // Add the value of arr[lo] and arr[hi] and store in sum
        if (sum == k) return true;    // Check if sum is equal to k or not
        else if (sum < k) lo++;    // Check if sum greater than k or not
        else hi--;    // Decrement hi
    }
    
    return false;    // Return false if value not found
}
