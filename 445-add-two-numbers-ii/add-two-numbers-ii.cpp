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
ListNode* reverse(ListNode* head){
    ListNode* curr= head;
    ListNode* prev= NULL;
    ListNode* nextptr;
    while(curr){
        nextptr= curr->next;
        curr->next= prev;
        prev= curr;
        curr= nextptr;

    }
    return prev;
}
ListNode* helper(ListNode* l1, ListNode* l2) {
    long long ans = 0, carry = 0; // Change data type to long long
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while (l1 || l2 || carry) {
        if (l1) {
            ans += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            ans += l2->val;
            l2 = l2->next;
        }
        ans += carry;
        carry = ans / 10;
        ListNode* node = new ListNode(ans % 10);
        temp->next = node;
        temp = temp->next;
        ans = 0; // Reset ans after each iteration
    }
    return dummy->next;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1= reverse(l1);
        l2= reverse(l2);
        ListNode* ans= helper(l1,l2);
        return reverse(ans);
    }
};