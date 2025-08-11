class Solution {
public:
    int M = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        vector<int>results;

        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                powers.push_back(pow(2,i));// this part will form powers array;
            }
        }

        for(auto & query : queries){
            int start=query[0];
            int end=query[1];
            long long product=1;
            for(int i=start;i<=end;i++){
                product=(product*powers[i])%M;// now juts solve wrt to queries
            }
            results.push_back(product);
        }
        return results;
    }
};