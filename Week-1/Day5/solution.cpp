class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int startIndex = 0;
        int totalProfit = 0;
        int n = prices.size();
        
        if( n < 2 ) return 0;
        
        for(int i=1; i<n; i++) {
            if( prices[i] < prices[i-1] ) {
                //cout << "here is break " << i << endl; 
                //cout << "here is min = " << prices[startIndex] << " and mx = " << prices[i-1] << endl;
                totalProfit += prices[i-1] - prices[startIndex];
                startIndex = i;
            }
        }
        
        totalProfit += prices[n-1] - prices[startIndex];
        
        return totalProfit;
    }
};