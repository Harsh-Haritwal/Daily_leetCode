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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* l3 = nullptr;
        ListNode* temp = nullptr;
        while (temp1 != nullptr || temp2 != nullptr) {
            int val;
            if (temp1 == nullptr) {
                val = temp2->val + carry;
                temp2 = temp2->next;
            } else if (temp2 == nullptr) {
                val = temp1->val + carry;
                temp1 = temp1->next;
            } else {

                val = temp1->val + temp2->val + carry;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            carry = val / 10;
            ListNode* newNode = new ListNode(val%10);
            if (l3 == nullptr) {
                l3 = newNode;
                temp = newNode;
            }
            else {

                temp->next = newNode;
                temp = temp->next;
            }
        }
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = temp->next;
        }
        return l3;
    }
};