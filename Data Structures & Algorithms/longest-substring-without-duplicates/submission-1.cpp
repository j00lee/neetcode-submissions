class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map the (char) -> index of appearance
        // Whenever we encounter a character which is already in the active window, 
        // reset the size of window (set window start = map[char])

        map<char, int> indices;
        
        int max_length = 0;
        int window_start = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            printf("At index: %d, c: %c\n", i, c);
            if (indices.find(c) == indices.end()) {
                printf("window_start: %d, max_length: %d\n", window_start, max_length);
                max_length = max(i - window_start + 1, max_length);
                indices[c] = i;
            } else {
                if (indices[c] >= window_start) {
                    max_length = max(i - window_start, max_length);
                    window_start = indices[c] + 1;
                }
                indices[c] = i;
            }
        }
        return max_length;
    }
};
