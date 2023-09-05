/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   Node* copyRandomList(Node* head) {

       // brute force approach

        // map<Node*, Node*>m;
        // Node* temp= head;
        // while(temp){
        //     m[temp]= new Node(temp->val);
        //     temp= temp->next;
        // }
        // temp= head;
        // while(temp){
        //     m[temp]->next= m[temp->next];
        //     m[temp]->random= m[temp->random];
        //     temp= temp->next;
        // }
        // return m[head];


//step-1
         Node* temp= head;
         while(temp){
             Node* newNode= new Node(temp->val);
             newNode->next=temp->next;
             temp->next= newNode;
             temp= temp->next->next;
         }

       //step-2

       Node* ptr= head;
       while(ptr){
           if(ptr->random){
               ptr->next->random= ptr->random->next;
           }
           ptr=ptr->next->next;
       }  

       //step-3

       Node* dummy= new Node(0);
       ptr=head;
       temp= dummy;
       Node* fast;
       while(ptr){
           fast= ptr->next->next;
           temp->next= ptr->next;
           ptr->next= fast;
           temp= temp->next;
           ptr=fast;
       }
       return dummy->next;




    }
};