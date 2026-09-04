class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        int m = nums1.size();
        int n = nums2.size();

        int left = 0, right = 0;

        while(left < m && right < n) {
            if(nums1[left] < nums2[right]) {
                result.push_back(nums1[left]);
                left++;
            }
            else {
                result.push_back(nums2[right]);
                right++;
            }
        }

        // Remaining elements of nums1
        while(left < m) {
            result.push_back(nums1[left]);
            left++;
        }

        // Remaining elements of nums2
        while(right < n) {
            result.push_back(nums2[right]);
            right++;
        }

        int z = result.size();

        if(z % 2 == 0) {
            return (result[z/2 - 1] + result[z/2]) / 2.0;
        }
        else {
            return result[z/2];
        }
    }
};