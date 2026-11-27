class Solution {
public:
    void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) c[k++] = a[i++];
            else c[k++] = b[j++];
        }
        while (i < a.size()) c[k++] = a[i++];
        while (j < b.size()) c[k++] = b[j++];
    }

    void mergeSort(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;
        vector<int> a(n/2);
        vector<int> b(n-n/2);

        int idx = 0;

        for (int i = 0; i < a.size(); i++) {
            a[i] = arr[idx++];
        }
        for (int i = 0; i < b.size(); i++) {
            b[i] = arr[idx++];
        }

        mergeSort(a);
        mergeSort(b);
        merge(a, b, arr);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};
