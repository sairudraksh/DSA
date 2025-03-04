class Solution {
public:
    void fillsieve(vector<int>&sieve){//to fill sieve and find all primes less than greatest
        int n=sieve.size();
        for(int i=2;i<n;i++){
            for(int j=i*2;j<n;j+=i){
                sieve[j]=0;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n=nums.size();
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(nums[i],mx);
        }
        vector<int>sieve(mx+1,1);
        if(mx+1>0) sieve[0]=0;
        if(mx+1>1) sieve[1]=0;
        fillsieve(sieve);
        vector<int>primes;
        for(int i=2;i<=mx;i++){
            if(sieve[i]==1) primes.push_back(i);//put primes in new arrray
        }
        vector<int>taken(primes.size(),0);
        for(int i=0;i<n;i++){
            for(int j=0;j<primes.size();j++){
                if(primes[j]>nums[i]) break;
                if(nums[i]%primes[j]==0) taken[j]=1;//put 1 in taken for those elements that are % 
            }
        }  
        int count=0;
        for(int i=0;i<taken.size();i++){
            if(taken[i]==1) count++;//find the count of unique factor as  taken contain only unique elements
        }
        return count;
    }
};