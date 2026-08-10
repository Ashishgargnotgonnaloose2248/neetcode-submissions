class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int f = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0; i<f-1; i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};