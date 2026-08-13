class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for(string x : strs) {
            s += to_string(x.size()) + "#" + x;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while(i < s.size()) {

            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            j++;

            string ans = s.substr(j, len);

            result.push_back(ans);

            i = j + len;
        }

        return result;
    }
};