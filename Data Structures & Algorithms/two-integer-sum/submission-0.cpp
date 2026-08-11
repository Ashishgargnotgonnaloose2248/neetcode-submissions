class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int curr = 0; curr<n ; curr++){
           for(int prev = curr+1; prev<n; prev++){
            if(nums[curr]+nums[prev]==target){
                return {curr,prev};
            }
           }
        }
        return {};
    }
};
