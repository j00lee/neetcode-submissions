class Solution {
public:
    int characterReplacement(string s, int k) {
        // Continue extending window rightward until we exceed
        // k corrections
        // In which case retract window on left to undo a correction

        int l = 0;
        int max_length = 0, max_freq = 0;
        char max_char;

        map<char,int> mp;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (mp.find(c) == mp.end()) {
                mp[c] = 0;
            }
            mp[c] += 1;
            if (mp[c] > max_freq) {
                max_char = c;
                max_freq = mp[c];
            }

            // Ensure number of corrections <= k
            while (i-l+1-max_freq > k) {
                printf("i-l+1-max_freq: %d\n", i-l+1-max_freq);
                char h = s[l];
                mp[h] -= 1;
                printf("h: %c\n", h);
                printf("mp[h]: %d\n", mp[h]);
                // find the new max_char
                int max = 0;
                int ch;
                for (const auto& [key, value] : mp) { 
                    if (value > max) {
                        max = value;
                        ch = key;
                    }
                }
                max_char = ch;
                max_freq = max;
                l++;
                printf("max_char: %c, max_freq: %d\n", max_char, max_freq);
            }
            printf("i-l+1-max_freq: %d\n", i-l+1-max_freq);
            max_length = max(max_length, i-l+1);
            printf("l: %d, r: %d, length: %d, max_length: %d\n\n", l, i, i-l+1, max_length);
        }
        return max_length;
    }
};
