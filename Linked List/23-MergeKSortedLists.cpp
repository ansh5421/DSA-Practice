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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = a;
        ListNode* temp2 = b;
        ListNode* temp = dummy;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1 == NULL) temp->next = temp2;
        else temp->next = temp1;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        vector<ListNode*> temp;

        while (temp.size() + lists.size() > 1) {
            while (lists.size() > 1) {
                ListNode* a = lists[lists.size()-1];
                lists.pop_back();
                ListNode* b = lists[lists.size()-1];
                lists.pop_back();
                ListNode* c = merge(a, b);
                temp.push_back(c);
            }
            while (temp.size() > 1) {
                ListNode* a = temp[temp.size()-1];
                temp.pop_back();
                ListNode* b = temp[temp.size()-1];
                temp.pop_back();
                ListNode* c = merge(a, b);
                lists.push_back(c);
            }
            if (lists.size() == 1 && temp.size() == 1) {
                temp.push_back(lists[0]);
                lists.pop_back();
            }
        }
        return (lists.size() != 0) ? lists[0] : temp[0];
    }
};
