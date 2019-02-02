class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0, big = 0;
        for(int i = prices.size()-1; i >= 0; i--){
            big = max(big, prices[i]);
            maxi = max(maxi, big - prices[i]);
        }
        return maxi;
    }
};
