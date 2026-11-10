class Solution {
public:
    int findMin(vector<int> &nums) {
        // Compare values from two indices that are halfway apart
        // Determine which half contains the "switch" point
        // Adjust the bounds accordingly

        int l = 0, r = nums.size()-1;
        // if (nums[r] > nums[0]) {
        //     return nums[0];
        // }

        while (l < r) {
            int m = (l+r)/2;
            int lnum = nums[l];
            int mnum = nums[m];
            int rnum = nums[r];
            // if (lnum < mnum and rnum < mnum) {
            //     printf("In the first conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
            //     // "Switch" point is in the second half
            //     l = m;
            // } else if (lnum > mnum) {
            //     printf("In the second conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
            //     // "Switch" point is in the first half
            //     r = m;
            // } else if (lnum < mnum) {
            //     printf("In the third conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
            //     return nums[l];
            // } else {
            //     printf("In the fourth conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
            //     // lnum == mnum (l == m)
            //     break;
            // }

            if (lnum == mnum and mnum < rnum) {
                printf("Here: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
                return nums[l];
            } else if (!(lnum < mnum)) { // left half is not sorted
                printf("In the first conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
                r = m;
            } else if (!(mnum < rnum)) { // right half is not sorted
                printf("In the second conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
                l = m;
            } else {
                printf("In the third conditional: lnum: %d, mnum: %d, rnum: %d\n", lnum, mnum, rnum);
                return nums[l];
            }
        }
        printf("l: %d\n", l);
        printf("(l+1) mod n: %d\n", (l+1)%nums.size());
        return nums[(l+1)%nums.size()];
    }
};
