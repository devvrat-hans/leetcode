// Last updated: 1/6/2026, 10:03:52 PM
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
        ListNode* temp = new ListNode();
        ListNode* mover = temp;
        ListNode* mover1 = l1;
        ListNode* mover2 = l2;
        int carry = 0;

        while(mover1 != nullptr || mover2 != nullptr || carry != 0){
            int sum = carry;

            if(mover1 != nullptr){
                sum += mover1->val;
                mover1 = mover1->next;
            }

            if(mover2 != nullptr){
                sum += mover2->val;
                mover2 = mover2->next;
            }

            carry = sum/10;
            mover->next = new ListNode(sum%10);
            mover = mover->next;
        }

        return temp->next;

    }
};