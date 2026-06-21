class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        long long sum=0;
        long long count=coins;
        for(int i=0;i<costs.size();i++){
            count-=costs[i];
            if(count>=0) sum++;
        }
        return sum;
    }
};