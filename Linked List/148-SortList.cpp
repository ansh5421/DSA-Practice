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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* tempD = dummy;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                tempD->next = temp1;
                temp1 = temp1->next;
            }
            else {
                tempD->next = temp2;
                temp2 = temp2->next;
            }
            tempD = tempD->next;
        }
        if (temp1 == NULL) tempD->next = temp2;
        else tempD->next = temp1;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;

        head = sortList(head);
        head2 = sortList(head2);
        return mergeTwoLists(head, head2);
    }
};
