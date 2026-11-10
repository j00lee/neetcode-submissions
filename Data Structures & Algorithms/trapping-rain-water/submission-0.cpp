class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        if (height.size() < 3) {
            return sum;
        }

        cerr << "before find_hills\n";

        vector<int> hills = find_hills(height);
        for (int i: hills) {
            printf("%d: ", i);
        }
        printf("\n");

        cerr << "after find_hills\n";

        // Compute the sum of each index
        for (int left_idx = 0; left_idx < hills.size()-1; left_idx++) {
            int left = hills[left_idx];
            int right = hills[left_idx + 1];
            sum += find_area(height, left, right);
        }

        return sum;
    }

    int find_area(vector<int>& height, int left, int right) {
        int area = 0;
        int h = min(height[left], height[right]);
        for (int i = left; i <= right; i++) {
            area += max(0, (h - height[i]));
        }
        return area;
    }

    vector<int> find_hills(vector<int>& height) {
        vector<int> hills = {0};
        int prev = height[0];
        int prev_hill = height[0];
        for (int i = 1; i < height.size()-1; i++) {
            int curr = height[i];
            int next = height[i+1];
            if (next <= curr and prev <= curr) {
                if (curr >= prev_hill) {
                    hills.push_back(i);
                    prev_hill = curr;
                }
            }
            // Update the prev
            prev = curr;
        } 

        cerr << "no seg fault during first pass\n";

        // Pick up from the other end
        vector<int> hills_rev = {};
        cerr << "during set up\n";
        cerr << "hills size:";

        int last_idx = hills[hills.size()-1];
        int prev_right = -1;
        int prev_hill_right = -1;

        cerr << "no seg fault setting up for loop";
        for (int i = height.size()-1; i > last_idx; i--) {
            int curr = height[i];
            int next = height[i-1];
            if (next <= curr and prev_right <= curr) {
                if (curr >= prev_hill_right) {
                    hills_rev.push_back(i);
                    prev_hill_right = curr;
                }
            }
            prev_right = curr;
        }

        // combine hills and hills_rev
        for (int i = hills_rev.size()-1; i >= 0; i--) {
            hills.push_back(hills_rev[i]);
        }

        return hills;
    }
};
