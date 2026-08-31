//o(n)
class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        for(int x : nums){
            if(x<ans){
                ans = x;
            }
        }
        return ans;
    }
};
