class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        // Frequency of characters required
        for(char c : t) {
            mp[c]++;
        }

        int left = 0;
        int right = 0;
        int count = t.length();

        int minLength = INT_MAX;
        int start = 0;

        while(right < s.length()) {

            // Take s[right] into the window
            if(mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;
            right++;

            // Window contains all characters of t
            while(count == 0) {

                // Update minimum window
                if(right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                // Remove s[left]
                mp[s[left]]++;

                if(mp[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if(minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};