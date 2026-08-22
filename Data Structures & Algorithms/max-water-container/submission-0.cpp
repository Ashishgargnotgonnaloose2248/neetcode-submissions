class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int n = heights.size();
        int h1=0,h2=n-1;
        
        while(h1<h2){
            int height = min(heights[h1],heights[h2]);
            int width = h2-h1;

            int area = height * width;

            ans = max(ans,area);

            if(heights[h1]<heights[h2]){
                h1++;
            }
            else{
                h2--;
            }
        }
        return ans;
    }
};
