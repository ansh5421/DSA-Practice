class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> order(n);
        int idx = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        while (q.size() > 0) {
            order[idx++] = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        sort(deck.begin(), deck.end());
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[order[i]] = deck[i];
        }
        return ans;
    }
};
