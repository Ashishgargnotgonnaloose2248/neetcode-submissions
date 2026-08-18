//brute_force
class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for(char c:s){
            if(isalnum(c)){
                t += tolower(c);
            }
        }

        string rev = t;

        reverse(rev.begin(), rev.end());

        if(rev==t){
            return true;
        }
        return false;
    }
};
