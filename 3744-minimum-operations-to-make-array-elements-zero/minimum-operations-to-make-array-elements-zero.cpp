class Solution {
public:
    long long solve(int l,int r){
        long long L=1;
        long long s=1;
        long long result=0;
        while(L<=r){
            long long R=4*L-1;

            long long start=max(L,(long long)l);
            long long end=min(R,(long long)r);

            if(start<=end){
                result+=(end-start+1)*s;
            }

            s++;
            L=L*4;
        } 
        return result;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long result=0;
        for(auto &query:queries){
            int l=query[0];
            int r=query[1];

            long long a=solve(l,r);
            result+=(a+1)/2;
        }
        return result;
    }
};