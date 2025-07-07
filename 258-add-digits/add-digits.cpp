class Solution {
public:
    int find(int num){
        int sum=0;
        while(num>0){
            int n=num%10;
            sum=sum+n;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>=10){
            num=find(num);
        }
        return num;
    }
};