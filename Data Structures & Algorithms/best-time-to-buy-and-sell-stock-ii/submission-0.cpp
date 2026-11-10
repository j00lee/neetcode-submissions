class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We will perform a transaction when we encounter a price which is 
        // lower than the current max price

        // low price <-- the buy price
        // high prive <-- the sell price
        // always index(low price) < index(high price)

        // Buy when prices start going up 
        // Sell when prices start going down

        // Sliding windowww
        prices.push_back(-1);

        int low = prices[0], high = prices[0];
        int profit = 0;
        for (int price: prices) {
            if (price < high) {
                profit += (high - low);
                low = price;
                high = price;
            } else if (price > high) {
                high = price;
            }
        }
        return profit;
    }
};