LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)    // function for reversing linked list
{
    LinkedListNode <int> *curr = head ;    // initialize current = head pointer
    LinkedListNode <int> *prev = NULL ;    // initialize previous pointer with null
    while(curr != NULL)    // loop till curr reaches to end of linked list
    {
        LinkedListNode <int> *next = curr->next;    // take next pointer of current
        curr->next = prev;    // reverse the link
        prev = curr;    // move previous pointer to current
        curr = next;    // move current pointer to next
    }
    return prev ;    // return previous pointer which is now head of reversed linked list
}
=========================

// LeetCode Link: https://leetcode.com/problems/reverse-linked-list/description/
// ----------------------------------------------------------------------

/* Approach:
1. Use 3-pointers curr, prev and last.
2. Initialise curr = head; prev = last = NULL.
3. Start a while loop till curr != NULL. Make last come to prev and prev come to curr,
4. Move curr to the next node.
5. To reverse the connection, we use this trick- prev -> next = last ;
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode <int> *curr = head ;
    LinkedListNode <int> *prev = NULL ; 
    LinkedListNode <int> *last = NULL ;

    while(curr != NULL)
    {
        last = prev ;  prev = curr ;

        curr = curr -> next ;

        prev -> next = last ;
    }

    return prev ;

}

// Time Complexity:  O(N)
// Space Complexity: O(1)