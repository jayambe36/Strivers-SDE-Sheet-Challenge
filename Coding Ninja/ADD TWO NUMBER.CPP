Node *addTwoNumbers(Node *num1, Node *num2)
{
    
    Node *res = new Node(-1);    // Initialize Node res with value -1
    Node *curr = res;    // Initialize Node curr with res
    int carry = 0;    // Initialize int variable carry with value 0
    int sum = 0;    // Initialize int variable sum with value 0
    while(num1 && num2){    // if num1 and num2 is not null
        sum = num1->data + num2->data + carry;    // Add the value of num1, num2 and carry and store it in sum
        Node *node = new Node(sum%10);    // Initialize Node node with sum modulus 10
        carry = sum/10;    // Assign the value of sum divided by 10 to carry
        curr->next = node;    // Add node after curr
        curr = curr->next;    // assign curr to curr->next
        num1 = num1->next;    // assign num1 to num1->next
        num2 = num2->next;    // assign num2 to num2->next
    }
    while(num1){    // if num1 is not null
        sum = num1->data + carry;    // Add the value of num1 and carry and store it in sum
        Node *node = new Node(sum%10);    // Initialize Node node with sum modulus 10
        carry = sum/10;    // Assign the value of sum divided by 10 to carry
        curr->next = node;    // Add node after curr
        curr = curr->next;    // assign curr to curr->next
        num1 = num1->next;    // assign num1 to num1->next
    }
    while(num2){    // if num2 is not null
        sum = num2->data + carry;    // Add the value of num2 and carry and store it in sum
        Node *node = new Node(sum%10);    // Initialize Node node with sum modulus 10
        carry = sum/10;    // Assign the value of sum divided by 10 to carry
        curr->next = node;    // Add node after curr
        curr = curr->next;    // assign curr to curr->next
        num2 = num2->next;    // assign num2 to num2->next
    }
    if(carry != 0){    // if carry is not equal to 0
        Node *node = new Node(carry);    // Initialize Node node with carry
        curr->next = node;    // Add node after curr
        curr = curr->next;    // assign curr to curr->next
    }
    return res->next;    // Return the value of res->next
}


=========

// LeetCode Link:  https://leetcode.com/problems/add-two-numbers/
// --------------------------------------------------------------------

/* Approach:
1. Use a dummy node to keep track of the new linked list we create. Tail pointer to create the Linked List and carry to keep track of the carry we have acquired during the addition.
2. Run a while loop till headA becomes NULL or headB becomes NULL or carry is still greater than 0.
3. We keep adding and forming the result LinkedList using the tail pointer.
4. At the end, we return dummy -> next pointing to the head of our resultant linkedList.
*/

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummy = new Node(-1) ;
    Node *tail = dummy ;

    Node *p = num1 ;  Node *q = num2 ;

    int carry = 0 ;

    while(p != NULL || q != NULL || carry > 0)
    {
        int sum = carry ;

        if(p != NULL)  
        {
            sum += p -> data ;  p = p -> next ;
        }

        if(q != NULL)  
        {
            sum += q -> data ; q = q -> next ;
        }

        Node *currNode = new Node(sum % 10) ;

        tail -> next = currNode ;  tail = currNode ;

        carry = sum / 10 ;
    }

    return dummy -> next ;
}

// Time Complexity:  O(M + M)
// Space Complexity: O(K) [ K is the length of the LinkedList we created after addition]