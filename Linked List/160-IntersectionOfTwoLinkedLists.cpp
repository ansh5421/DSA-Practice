/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != NULL) {
            tempA = tempA->next;
            lenA++;
        }
        while (tempB != NULL) {
            tempB = tempB->next;
            lenB++;
        }
        tempA = headA;
        tempB = headB;
        int n = max(lenA, lenB) - min(lenA, lenB);
        for (int i = 0; i < n; i++) {
            if (lenA > lenB) tempA = tempA->next;
            else tempB = tempB->next;
        }
        while (tempA != NULL || tempB != NULL) {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
