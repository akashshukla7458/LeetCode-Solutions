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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* i= head;
        ListNode* j= head->next;
        while(j ){
       
            ListNode* temp= new ListNode(gcd(i->val,j->val));
            i->next= temp;
            temp->next=j;
            i= i->next->next;
            j= j->next;
        }
        return head;
    }
};