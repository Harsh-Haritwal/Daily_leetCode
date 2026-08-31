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
    ListNode* rec(ListNode* &temp1, ListNode* &temp2, ListNode* &ansList, ListNode* &temp3) {
        if(temp1 == nullptr){
            ansList->next = temp2;
            return temp3;
        }else if (temp2 == nullptr){
            ansList->next = temp1;
            return temp3;
        }
        if (temp1->val <= temp2->val) {
            if (ansList == nullptr) {
                ansList = temp1;
                temp3 = ansList;
            } else {
                ansList->next = temp1;
                ansList = ansList->next;
            }
            temp1 = temp1->next;
        } else {
            if (ansList == nullptr) {
                ansList = temp2;
                temp3 = ansList;
            } else {
                ansList->next = temp2;
                ansList = ansList->next;
            }
            temp2 = temp2->next;
        }
        rec(temp1, temp2, ansList, temp3);
        return temp3;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return list1;
        else if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        ListNode* ansList = nullptr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp3;
        rec(temp1, temp2, ansList, temp3);
        return temp3;
    }
};