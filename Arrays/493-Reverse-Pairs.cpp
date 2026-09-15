class Solution {
public:
    int count;

    void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) c[k++] = a[i++];
            else c[k++] = b[j++];
        }
        while (i < a.size()) c[k++] = a[i++];
        while (j < b.size()) c[k++] = b[j++];
    }

    int inversion(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0, cnt = 0;
        while (i < a.size() && j < b.size()) {
            if ((long long)(a[i]) > 2*(long long)(b[j])) {
                cnt += (a.size() - i);
                j++;
            }
            else i++;
        }
        return cnt;
    }

    void mergeSort(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return;
        vector<int> a(n/2);
        vector<int> b(n-n/2);
        int idx = 0;

        for(int i = 0; i < n/2; i++) {
            a[i] = arr[idx++];
        }
        for(int i = 0; i < n-n/2; i++) {
            b[i] = arr[idx++];
        }

        mergeSort(a);
        mergeSort(b);
        count += inversion(a,b);
        merge(a,b,arr);
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums);
        return count;
    }
};
