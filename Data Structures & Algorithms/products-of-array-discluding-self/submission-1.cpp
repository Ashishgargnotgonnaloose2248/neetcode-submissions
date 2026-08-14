class Solution {
public:
    int multiply(vector<int>& nums){
        int product = 1;

        for(int x : nums){
            if(x!=0){
                product *= x;
            }
        }
        return product;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = multiply(nums);
        int zerocount = 0;

        for(int x: nums){
            if(x==0){
                zerocount++;
            }
        }

        for(int i = 0; i<nums.size(); i++){
            if(zerocount>1){
                nums[i]=0;
            }
            else if(zerocount==1){
                if(nums[i]==0){
                    nums[i]= product;
                }
                else{
                    nums[i] = 0;
                }
            }
            else{
                nums[i] = product/nums[i];
            }
        }
        return nums;
    }
};
