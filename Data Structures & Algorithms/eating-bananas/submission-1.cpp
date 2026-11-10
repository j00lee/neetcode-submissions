class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Goal: O(n log m) time and O(1) space
        // Idea: k must be between 1 and m (max size of pile)
        // Perform a binary search over range (1,2,..m) to find min k
        int m = 0;
        for (int pile: piles) {
            if (pile > m) {
                m = pile;
            }
        }

        int l = 1, r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            int hours = hoursToEat(piles, mid);
            printf("l: %d, r: %d, mid: %d, hours: %d\n", l, r, mid, hours);
            if (h < hours) {
                // rate may be too low
                l = mid + 1;
            } else if (h >= hours) {
                r = mid - 1;
            }
        } 
        if (h < hoursToEat(piles, l) and l != m) {
            return l + 1;
        } else {
            return l;
        }
    }

    int hoursToEat(vector<int>& piles, int k) {
        // Computes the total hours required to eat piles at rate of k
        int hours = 0;
        for (int pile: piles) {
            hours += (pile / k);
            if (pile % k != 0) {
                hours += 1;
            } 
        }
        return hours;
    }
};
