class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qR;
        queue<int> qD;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') qR.push(i);
            else qD.push(i);
        }
        int idx = n;
        while (qR.size() > 0 && qD.size() > 0) {
            if (qR.front() < qD.front()) {
                qR.push(idx++);
            }
            else {
                qD.push(idx++);
            }
            qD.pop();
            qR.pop();
        }
        return (qR.size() == 0) ? "Dire" : "Radiant";
    }
};
