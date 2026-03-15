class Solution {
public:

    int find(int n){
        int count=0;

        while(n>0){
            n=n/10;
            count++;
        }
        if(count<3) return 0;
        if(count%3==0) return count/3-1;
        return count/3;
    }

    int countCommas(int n) {
        int sum=0;

        for(int i=1;i<=n;i++){
            sum+=find(i);
        }

        return sum;
    }
};