class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0;
        int temp = 1;
        int profit = 0;

        while(temp < n){
            if(prices[left] > prices[temp]){
                left = temp;
            }
            else{
                profit = max(profit, prices[temp] - prices[left]);
            }

            temp++;
        }

        return profit;
    }
};