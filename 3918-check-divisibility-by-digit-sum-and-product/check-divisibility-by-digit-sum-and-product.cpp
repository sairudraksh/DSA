class Solution {
public:
    int sum=0;
    int product=1;
    void find(int n){
        while(n>0){
            int num=n%10;
            sum+=num;
            product*=num;
            n=n/10;
        }
    }
    bool checkDivisibility(int n) {
        find(n);
        int finalsum=sum+product;
        if(n%finalsum==0) return true;
        else return false;
    }
};