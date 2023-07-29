#include <bits/stdc++.h> 

/*************************************************************

 

    Following is the Binary Tree node structure

 

    class BinaryTreeNode 

    {

    public : 

        T data;

        BinaryTreeNode<T> *left;

        BinaryTreeNode<T> *right;

 

        BinaryTreeNode(T data) {

            this -> data = data;

            left = NULL;

            right = NULL;

        }

    };

 

*************************************************************/

int help(BinaryTreeNode<int>* root){

    if(root == NULL){

        return 0;

    }

    int lh =help(root->left);

    int rh=help(root->right);

    if(lh == -1 || rh ==-1 || abs(lh-rh)>1){

        return -1;

    }

    return max(lh,rh)+1;

}

bool isBalancedBT(BinaryTreeNode<int>* root) {

    int ans =help(root);

    if(ans != -1){

        return true;

    }

    return false;

}