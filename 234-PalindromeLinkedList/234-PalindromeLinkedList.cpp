// Last updated: 3/27/2026, 5:27:03 PM
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
    ListNode* reverseLinkedList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLinkedList(head->next);
        ListNode* front = head->next;

        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;    
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second = reverseLinkedList(slow);

        while(second){
            if(first->val != second->val){
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};