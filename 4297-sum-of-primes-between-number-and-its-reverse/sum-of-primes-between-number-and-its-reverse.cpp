class Solution {
public:
    int find(int n){
        if(n==1) return 0;
        if(n==2) return n;
        for(int i=2;i<=n/2+1;i++){
            if(n%i==0) return 0;
        }
        return n;
    }
    int sumOfPrimesInRange(int n) {
        int num1=0;

        int num2=n;
        int sum=0;
        while(num2>0){
            int x=num2%10;
            num1=(num1*10)+x;
            num2=num2/10;
        }

        for(int i=min(num1,n);i<=max(num1,n);i++){
            int a=find(i);
            sum+=a;
        }
        return sum;
    }
};