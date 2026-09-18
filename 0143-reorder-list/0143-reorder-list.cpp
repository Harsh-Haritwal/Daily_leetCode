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
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr) {
           ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        ListNode* t1 = head;
        ListNode* t2 = prev;

        while (temp2 != nullptr) {
            t1 = t1->next;
            t2 = t2->next;

            temp1->next = temp2;
            temp1 = t1;
            temp2->next = temp1;
            temp2 = t2;
        }
    }
};