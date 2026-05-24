class Solution {
public:
    string minWindow(string s, string t) {
        // If t is larger, impossible to form a valid window
        if (t.size() > s.size()) {
            return "";
        }

        // Stores required character frequencies from t
        unordered_map<char, int> need;

        // Stores character frequencies inside current window
        unordered_map<char, int> window;

        // Build frequency map for t
        for (char c : t) {
            need[c]++;
        }

        // Number of unique chars we need to satisfy
        int required = need.size();

        // Number of chars currently satisfied
        int formed = 0;

        // Left pointer of sliding window
        int l = 0;

        // Track minimum window
        int minLen = INT_MAX;
        int startIndex = 0;

        // Expand window using right pointer
        for (int r = 0; r < s.size(); r++) {

            char currChar = s[r];

            // Add current character to window
            window[currChar]++;

            // If frequency requirement is met for this char
            if (need.count(currChar) &&
                window[currChar] == need[currChar]) {
                formed++;
            }

            // Try shrinking window while it's valid
            while (formed == required) {

                // Update minimum answer if smaller window found
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                // Remove left character from window
                char leftChar = s[l];
                window[leftChar]--;

                // If requirement breaks, window becomes invalid
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                // Shrink window
                l++;
            }
        }

        // If no valid window found
        if (minLen == INT_MAX) {
            return "";
        }

        // Return smallest valid substring
        return s.substr(startIndex, minLen);
    }
};
