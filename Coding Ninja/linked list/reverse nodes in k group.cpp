#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
vector<Node*> reverse(Node* head,int b){

    if(!head)

          return {NULL, NULL, NULL};

    if(!head->next)return {head,NULL,head};

    Node* temp=NULL;

    Node* tail=head;

    Node* f=NULL;

    for(int i=b;i>=1 and head;i--)

    {

         f=head->next;

        head->next=temp;

        temp=head;

        head=f;

    }

        return {temp, f, tail};

}

 

Node *getListAfterReverseOperation(Node *head, int n, int b[]){

    // Write your code here.

    if(!head || !head->next)return head;

    int i=0;

    Node* dummy=new Node(0);

    Node* ans=dummy;

    while(i<n)

    {

        while(i<n and b[i]==0)i++;

        if(i>=n)break;

        vector<Node*> p;

        if(head)p=reverse(head,b[i]);

        else break;

        dummy->next=p[0];

        head=p[1];

        dummy=p[2];

        i++;

    }

    if(head)dummy->next=head;

    return ans->next;

 

}