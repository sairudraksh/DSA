class Solution {
public:
    void fillsieve(vector<int>&sieve){
        int n=sieve.size();
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*2;j<n;j+=i){
                sieve[j]=0;
            }
        }
    }
    int countPrimes(int n) {
        int count=0;
        if(n<=2) return 0;
        n=n-1;
        vector<int>sieve(n+1,1);
        fillsieve(sieve);
        for(int i=2;i<=n;i++){
            if(sieve[i]==1) count++;
        }
        return count;
    }
};