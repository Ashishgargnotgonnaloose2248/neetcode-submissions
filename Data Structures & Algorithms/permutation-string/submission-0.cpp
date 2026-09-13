class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(char c : s1){
            mp1[c]++;
        }

        int n = s1.size();

        // First window
        for(int i = 0; i < n; i++){
            mp2[s2[i]]++;
        }

        if(mp1 == mp2){
            return true;
        }

        // Sliding window
        for(int i = n; i < s2.length(); i++){
            mp2[s2[i]]++;

            mp2[s2[i-n]]--;

            if(mp2[s2[i-n]] == 0){
                mp2.erase(s2[i-n]);
            }

            if(mp1 == mp2){
                return true;
            }
        }

        return false;
    }
};