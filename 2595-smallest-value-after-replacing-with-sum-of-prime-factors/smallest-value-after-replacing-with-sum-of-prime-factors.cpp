class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        if(isprime(n)) return n;
        int sum=0;
        for(int i=1;i<sqrt(n);i++){
            if(n%i==0 && isprime(i)){
                int m=n;
                while(m%i==0){
                    sum=sum+i;
                    m=m/i;
                }
            }
        }
        for(int i=sqrt(n);i>=1;i--){
            if(n%i==0 && isprime(n/i)){
                int m=n;
                while(m%(n/i)==0){
                    sum=sum+(n/i);
                    m=m/(n/i);

                }
            }
        }
        if(sum==4) return n;
        return smallestValue(sum);
        
    }
};