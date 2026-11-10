class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        vector<int> b;
        if (nums1.size() < nums2.size()) {
            a = nums1;
            b = nums2;
        } else {
            a = nums2;
            b = nums1;
        }

        if (a.size() == 0 and b.size() == 0) {
            return 0;
        } else if (a.size() == 0) {
            return ((float)b[b.size()/2] + (float)b[(b.size()-1)/2])/2;
        }

        int l = 0, r = a.size(); // number selected from a
        int half = (a.size() + b.size() + 1) / 2 - 1; // number of elements needed
        int m;
        while (l <= r) {
            m = (l+r)/2;
            // perhaps add conditional checking if m == 0 or m == a.size()
            // if (l == r) {
            //     return 
            // }
            

            int from_a = m;
            int from_b = half - from_a;

            // max element of both left partitions are not greater than 
            // min element of both right partitions
            if (max(a[m-1], b[from_b-1]) <= min(a[m], b[from_b])) {
                if ((a.size() + b.size()) % 2 == 0) {
                    return ((float)a[m] + (float)b[from_b]) / 2;
                } else {
                    if (a[m] < b[from_b]) {
                        return a[m];
                    } else {
                        return b[from_b];
                    }
                }
            } else if (b[from_b - 1] < a[m]) {
                // Want less elements from a
                r = m - 1;
            } else if (a[m - 1] < b[from_b]) {
                // Want more elements from a
                l = m + 1;
            }
        }
        // return 
        return -1;
    }
};
