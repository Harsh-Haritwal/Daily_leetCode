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

    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }else{
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }

        if(l1){
            tail->next = l1;
        }
        if(l2){
            tail->next = l2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(head2);

        ListNode* ans =  mergeSort(l1, l2);
        return ans;
    }
};