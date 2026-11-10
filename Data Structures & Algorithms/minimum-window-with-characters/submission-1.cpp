class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m;
        for (int i = (int)'a'; i <= (int)'z'; i++) {
            m[(char)i] = 0;
        }
        for (int i = (int)'A'; i <= (int)'Z'; i++) {
            m[(char)i] = 0;
        }
        
        // Set up the frequency count map with counts from t preset
        for (char c: t) {
            m[c]--;
        }
        int match = 0;
        for (auto& [key, value]: m) {
            if (value >= 0) {
                match++;
            }
        }
        printf("Value of match: %d\n", match);

        int start = 0;
        pair<int,int> res = pair(0,s.length()-1);
        for (int i = 0; i < s.length(); i++) {
            printf("At index: %d, char: %c\n", i, s[i]);
            char c = s[i];
            m[c]++;
            if (m[c] == 0) {    // increment count of c
                match++;                
                printf("incremented match: %d\n", match);
            }

            if (match == 52) {
                printf("found substring containing t\n");
                // found a substring containing t
                // try shrinking the window
                while (m[s[start]] > 0) {
                    m[s[start]]--;
                    start++;
                }

                if ((i - start + 1) < (res.second - res.first + 1)) {
                    res = pair(start, i);
                    printf("start: %d, end: %d\n", res.first, res.second);
                }
            }
        }
        printf("res: first: %d, second: %d\n", res.first, res.second);
        return match == 52 ? s.substr(res.first, res.second-res.first+1) : "";
    }
};
