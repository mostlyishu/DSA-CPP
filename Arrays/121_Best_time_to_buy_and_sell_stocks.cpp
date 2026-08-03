class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiprofit = 0;
        int minprice = prices[0];

        for (int i =1 ; i<prices.size() ; i++){
            if (prices[i]<minprice){
                minprice = prices[i];
            }
            int today_profit = prices[i]-minprice;
            if (today_profit>maxiprofit){
                maxiprofit = today_profit;
            }
        }
        return maxiprofit;
    }
};