class Solution {
public:
    double find(double x,long n){
        if(n==0) return 1;

        if(n<0) return find(1/x,-n);

        if(n%2==0) return find(x*x,n/2);
        else return x*find(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        return find(x,(long)n);
    }
};