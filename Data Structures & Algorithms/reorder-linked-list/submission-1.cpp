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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = second;
        while(curr){
            ListNode* future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
       while(prev){
        ListNode* temp1 = head->next;
        ListNode* temp2 = prev->next;
        head->next = prev;
        prev->next = temp1;
        head = temp1;
        prev = temp2;
       }
    }
};
