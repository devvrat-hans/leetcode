// Last updated: 3/27/2026, 5:27:19 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        ListNode *meetingPoint;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                meetingPoint = slow;
                break;
            }
        }

        if(meetingPoint == NULL) return NULL;
        else{
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }

        }

        return slow;
    }
};