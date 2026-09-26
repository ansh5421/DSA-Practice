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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL or head->next == NULL) return head;
        int len = 0;
        ListNode* temp = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;

        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;
        temp = head;
        for (int i = 1; i <= len; i++) {
            if (i == len - k) a = temp;
            if (i == len - k+1) b = temp;
            if (i == len) c = temp;
            temp = temp->next;
        }
        a->next = NULL;
        c->next = head;
        return b;
    }
};
