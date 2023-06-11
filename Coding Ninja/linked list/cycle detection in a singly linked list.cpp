bool detectCycle(Node *head)    // Define a bool function to detect cycle
{
    if(head == NULL)  return false ;    // check if head is null or not

Node *slow = head, *fast = head;    // Initialize two variables "slow" and "fast" with head

    while(fast && fast->next)    // check if fast and fast->next are not null
    {
        fast = fast->next->next;    // fast = fast->next->next
        slow = slow->next;    // slow = slow->next
        if(slow == fast)  return true;    // check if slow and fast are equal or not
    }

return false;    // return false
}

==============================
// LeetCode Link: https://leetcode.com/problems/linked-list-cycle/
// -------------------------------------------------------------------

/* Approach 1 [Better Approach - using Hashing]
1. Use hashing and store all the nodes and check if we have visited a node two times. If so, we return true else we return false.

Approach [Optimal Approach - without using Hashing]
1. We use two dummy pointers- slow and fast pointers, each initialize with the head of the given LinkedList.
2. We move fast by two nodes and slow by a single node. If there's a cycle fast and slow will meet as Fast will eventually catch up with Slow.
3. If they didn't meet and Fast reaches NULL or Last Node of the given LinkedList, we return false indicating we have no cycle in the LinkedList.
*/

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

bool detectCycle(Node *head)
{
    if(head == NULL)  return false ;

    Node *slow = head ;  Node *fast = head ;

    while(fast != NULL && fast -> next != NULL)
    {
        
        fast = fast -> next -> next ;

        slow = slow -> next ;

        if(slow == fast)  return true ;
    }

    return false ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)