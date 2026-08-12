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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        int count = 0;
        int newCount = 0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        if(count == 1) return nullptr;
        temp = head;
        ListNode* prev = head;
        while(temp != nullptr && newCount != count-n){
            prev = temp;
            temp = temp->next;
            newCount++;
        }
        if(prev == temp) return temp->next;
        prev->next = temp->next;
        return head;
    }
};