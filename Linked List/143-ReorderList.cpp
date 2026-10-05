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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;
        b = reverseList(b);

        ListNode* temp1 = a;
        ListNode* temp2 = b;
        ListNode* dummy = new ListNode(-1);;
        ListNode* tempD = dummy;

        while (temp1) {
            tempD->next = temp1;
            tempD = tempD->next;
            temp1 = temp1->next;
            
            
            tempD->next = temp2;
            tempD = tempD->next;
            if (temp2) temp2 = temp2->next;

        }
        head = dummy->next;
    }
};
