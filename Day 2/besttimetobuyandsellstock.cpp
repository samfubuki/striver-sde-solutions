class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int price = INT_MAX;
       for(int i=0;i<prices.size();i++)
       {
           price = min(price,prices[i]);
           profit = max(profit,prices[i]-price);
       }
     return profit;
    }
};
