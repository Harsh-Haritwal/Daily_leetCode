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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* nex = nullptr;

        ListNode* head2 = nullptr;
        ListNode* tail2 = nullptr;

        int count = 1;
        while(temp != nullptr){
            if(count == left-1){
                prev = temp;
            }
            if(count == left){
                head2 = temp;
            }
            if(count == right){
                tail2 = temp;
            }
            if(count == right+1){
                nex = temp;
            }
            temp = temp->next;
            count++;
        }
        ListNode* p = nullptr;
        ListNode* c = head2;
        ListNode* n = nullptr;
        while(c != nex){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head2->next = nex;
        if(left == 1){
            return tail2;
        }
        prev->next = p;
        return head;



    }
};