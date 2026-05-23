class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minBuy = prices[0];
        for(int &sell : prices){
            ans = max(ans, sell- minBuy);
            minBuy = min(minBuy,sell);
        }
        return ans;
    }
};
