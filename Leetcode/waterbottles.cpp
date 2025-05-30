class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remain = 0;
        int empty = 0;

        while (numBottles > 0){
            remain += numBottles;
            empty += numBottles;
            numBottles = empty/numExchange;
            empty = empty% numExchange;
        }
        return remain;
        
    }
};