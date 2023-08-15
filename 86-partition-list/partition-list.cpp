/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l= new ListNode(0);
        ListNode* r= new ListNode(0);
        ListNode* leftTail= l;
        ListNode* rightTail= r;
        while(head){
            if(head->val<x){
                leftTail->next= head;
                leftTail=leftTail->next;

            }
            else {
                rightTail->next=head;
                rightTail= rightTail->next;
            }
            head= head->next;
        }
        leftTail->next= r->next;
        rightTail->next= NULL;
        return l->next;

    }
};