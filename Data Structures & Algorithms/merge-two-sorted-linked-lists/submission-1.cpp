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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList;
        ListNode* head;
        if (!list1) return list2;
        if (!list2) return list1;
        // find first node
        if (list1->val <= list2->val) {
            newList = list1;
            list1 = list1->next;
        } else {
            newList = list2;
            list2 = list2->next;
        }
        head = newList;

        while (list1 || list2) {
            // if reached the end of any, just take the other one
            if (!list1) {
                newList->next = list2;
                list2 = list2->next;
                if (newList->next) newList = newList->next;
                continue;
            }
            if (!list2) {
                newList->next = list1;
                list1 = list1->next;
                if (newList->next) newList = newList->next;
                continue;
            }

            // if both still have nodes compare them
            if (list1->val <= list2->val) {
                newList->next = list1;
                list1 = list1->next;
            } else {
                newList->next = list2;
                list2 = list2->next;
            }
            if (newList->next) newList = newList->next;
        }
        return head;
    }
};

// compare list1 to list2, take smaller
// move whichever was smaller
// compare list1 to list2, take smaller
