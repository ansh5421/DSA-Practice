class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0);
        queue<int> q;

        for (int student : students) {
            q.push(student);
            if (student == 0) count[0]++;
            else count[1]++;
        }
        int i = 0;
        while (i < sandwiches.size()) {
            int sandwich = sandwiches[i];
            if (count[sandwich] == 0) return q.size();
            if (q.front() == sandwich) {
                count[sandwich]--;
                i++;
            }
            else q.push(q.front());
            q.pop();
        }
        return 0;
    }
};
