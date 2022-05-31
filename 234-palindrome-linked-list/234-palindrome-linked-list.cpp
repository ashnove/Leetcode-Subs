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
        if(head == NULL) return NULL;
        if(head->next == NULL){
            return head;
        }
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast && fast->next == NULL){
            slow = slow->next;
        }
        ListNode* secondHalf = reverse(slow);

        while(secondHalf){
            if(secondHalf->val != head->val) return 0;
            secondHalf = secondHalf->next;
            head = head->next;
        }
        return 1;
        
    }
};