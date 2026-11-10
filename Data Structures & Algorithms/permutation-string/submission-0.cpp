class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Make map of character counts for s1
        map<char, int> m1;
        map<char, int> m2;

        for (int i = (int)'a'; i <= (int)'z'; i++) {
            m1[(char)i] = 0;
            m2[(char)i] = 0;
        }
        for (char c: s1) {
            m1[c]++;
        }
        print_map(m1);

        for (int i = 0; i < s1.length()-1; i++) {
            char c = s2[i];
            m2[c]++;
        }

        for (int i = s1.length()-1; i < s2.length(); i++) {
            char c = s2[i];
            // add current character
            m2[c]++;
            // Check m1 and m2 equality
            print_map(m2);
            if (m1 == m2) {
                return true;
            }

            // Remove the last letter
            c = s2[i+1-s1.length()];
            m2[c]--;
        }
        return false;
    }

    void print_map(map<char,int>& m) {
        printf("{");
        for (auto [key, value]: m) {
            if (value != 0) {
                printf("(%c, %d), ", key, value);
            }
        }
        printf("}\n");
    }
};
