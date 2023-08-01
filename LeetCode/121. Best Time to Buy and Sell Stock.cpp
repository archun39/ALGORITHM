class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int ans = 0;

        for(int i = prices.size() - 1; i >= 0; i--){
            if(prices[i] > max){
                 max = prices[i];
            }
            else{
                int tmp = max - prices[i];
                if(tmp > ans){
                    ans = tmp;   
                } 
            }
        }
        return ans;
    }
};
