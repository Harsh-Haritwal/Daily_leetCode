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
    ListNode* rotateList(ListNode* &head, int k) {
        ListNode* tail = head;
        ListNode* prev = nullptr;
        int count = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            count++;
        }
        k = k%count;
        if(k == 0)return head;
        int actNode= count-k;

        ListNode* temp = head;
        while(actNode != 0){
            prev = temp;
            temp = temp->next;
            actNode--;
        }
        tail->next = head;
        prev->next = nullptr;
        head = temp;
        


        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        head = rotateList(head, k);
        return head;
    }
};