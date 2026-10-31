/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode temp(0); 
        ListNode* curr = &temp;
        temp.next = head;
        
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete; 
            } else {
                curr = curr->next;
            }
        }
        
        return temp.next;
    }
};