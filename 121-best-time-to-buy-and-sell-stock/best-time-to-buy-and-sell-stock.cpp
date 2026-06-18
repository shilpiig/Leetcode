class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         int profit=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(prices[j]>prices[i]){
//                     profit=max(profit,prices[j]-prices[i]);
//                 }
//             }
//         }
//         return profit;
//     }
// };