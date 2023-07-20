#include <bits/stdc++.h> 
class Queue {
   int itr;
   vector<int> v;
   int frontt;
public:
   Queue() {
       // Implement the Constructor
       itr=0;
       v.resize(0);
       frontt=0;
   }
   /*----------------- Public Functions of Queue -----------------*/
   bool isEmpty() {
       // Implement the isEmpty() function
       if(frontt>itr-1)
       return true;
       else return false;
   }
   void enqueue(int data) {
       // Implement the enqueue() function
       v.push_back(data);
       itr++;
   }
   int dequeue() {
       // Implement the dequeue() function
       if(frontt<=itr-1)
       {
       return v[frontt++];
       }
       else return -1;
   }
   int front() {
       // Implement the front() function
       if(frontt<=itr-1)
       return v[frontt];
       else return -1;
   }
};