class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // if (arr.size() == 1) {
        //     arr[0] = -1;
        //     return arr;
        // }
        // int n = arr.size();
        // for (int i = 0; i < arr.size()-1; i++) {
        //     int currMax = 0;
        //     for (int j = i+1; j < arr.size(); j++) {
        //         currMax = max(currMax, arr[j]);
        //     }
        //     arr[i] = currMax;
        // }
        // arr[n-1] = -1;
        // return arr; O(n^2)

        int n = arr.size();
        int maxSoFar = -1;
        for (int i = n-1; i >= 0; i--) {
            int originalVal = arr[i];
            arr[i] = maxSoFar;
            maxSoFar = max(originalVal, maxSoFar);
        }
        return arr;
    }
};
