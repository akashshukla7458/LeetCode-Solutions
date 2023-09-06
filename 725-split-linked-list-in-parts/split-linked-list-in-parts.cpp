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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
     vector<ListNode*>ans(k, NULL);
     int len=0;
     ListNode* temp= head;
     while(temp){
         len++;
         temp= temp->next;
     }
     int partsize= len/k;
     int rem= len%k;
     ListNode* node= head;
     ListNode* prev= NULL;
     for(int i=0; node && i<k;i++){
         ans[i]= node;
         for(int j=0;j<partsize;j++){
             prev= node;
             node= node->next;

         }
         if(rem>0){
             prev = node;
             node= node->next;
             rem--;
         }
         prev->next= NULL;
     }
     return ans;
        
    }
};