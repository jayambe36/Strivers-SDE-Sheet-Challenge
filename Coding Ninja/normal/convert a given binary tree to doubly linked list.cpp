void solve(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>* &prev){

    if(root==NULL) return;

    solve(root->left,head,prev);

    if(prev==NULL){

        head=root;

        prev=root;

    }else{

        prev->right=root;

        root->left=prev;

        prev=prev->right;

    }

    solve(root->right,head,prev);

}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {

    // Write your code here

    BinaryTreeNode<int>* head=NULL;

    BinaryTreeNode<int>* prev=NULL;

    solve(root,head,prev);

    return head;

}