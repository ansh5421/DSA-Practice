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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int minR = 0, maxR = m-1;
        int minC = 0, maxC = n-1;
        ListNode* temp = head;

        while (temp != NULL) {
            for (int j = minC; j <= maxC; j++) {
                if (temp == NULL) break;
                ans[minR][j] = temp->val;
                temp = temp->next;
            }
            minR++;
            if (temp == NULL) break;
            for (int i = minR; i <= maxR; i++) {
                if (temp == NULL) break;
                ans[i][maxC] = temp->val;
                temp = temp->next;
            }
            maxC--;
            if (temp == NULL) break;
            for (int j = maxC; j >= minC; j--) {
                if (temp == NULL) break;
                ans[maxR][j] = temp->val;
                temp = temp->next;
            }
            maxR--;
            if (temp == NULL) break;
            for (int i = maxR; i >= minR; i--) {
                if (temp == NULL) break;
                ans[i][minC] = temp->val;
                temp = temp->next;
            }
            minC++;
            if (temp == NULL) break;
        }
        return ans;
    }
};
