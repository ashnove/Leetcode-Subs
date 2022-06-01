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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int l1Size = size(l1);
        int l2Size = size(l2);
        ListNode* finalHead = NULL;
        ListNode* itr = NULL;
        while(l1 != NULL || l2 != NULL){
            
            int a = 0, b = 0;
            if(l1Size >= l2Size){
                a = (l1 ? l1->val : 0);
                l1Size--;
                l1 = l1->next;
            }
            
            if(l2Size >= l1Size + 1){
                b = (l2 ? l2->val : 0);
                l2Size--;
                l2 = l2->next;
            }
            
            itr = new ListNode(a + b);
            itr->next = finalHead;
            finalHead = itr;
        }
        
        int carry = 0;
        finalHead = NULL;
        while(itr){
            itr->val += carry;
            
            if(itr->val >= 10){
                carry = itr->val / 10;
                itr->val %= 10;
            }
            else {
                carry = 0;
            } 
            ListNode* temp = itr->next;
            itr->next = finalHead;
            finalHead = itr;
            itr = temp;
            
        }
        if(carry){
            ListNode* additional = new ListNode(carry);
            additional->next = finalHead;
            finalHead = additional;
        }
        return finalHead;
    }
    
    int size(ListNode* l1){
        int sz = 0;
        while(l1){
            sz++;
            l1 = l1->next;
        }
        return sz;
    }
};