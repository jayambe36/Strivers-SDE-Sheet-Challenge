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
