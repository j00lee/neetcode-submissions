class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Slidng window
        
        int profit = 0;

        int smallest = prices[0];
        int greatest = prices[0];
        for (int price: prices) {
            if (price > greatest) {
                greatest = price;
                profit = max(greatest - smallest, profit);
            } else if (price < smallest) {
                smallest = price;
                greatest = price;
            }
        }

        return profit;
    }
};
