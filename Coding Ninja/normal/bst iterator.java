import java.util.* ;
import java.io.*; 
/*
    Definition of Node class for reference

    class TreeNode<T> 
    {
        public T data;
        public TreeNode<T> left;
        public TreeNode<T> right;

        TreeNode(T data)
        {
            this.data = data;
            left = null;
            right = null;
        }
    }

*/
public class Solution {

    static class BSTIterator{
      ArrayList<Integer> yash=new ArrayList<>();
        int i;
        BSTIterator(TreeNode<Integer> root){
            helper(root);
        }
void helper(TreeNode<Integer> root){
    if(root==null){
        return;
    }
    helper(root.left);
    yash.add(root.data);
    helper(root.right);
    
}
        int next(){
           return yash.get(i++);
            
            // Write your code here
        }

        boolean hasNext(){
          if(i<yash.size()){
              return true;
          }
            else{
               return false;
            }
           
        }
    }
}

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator = new BSTIterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next()+" ");
    }
*/