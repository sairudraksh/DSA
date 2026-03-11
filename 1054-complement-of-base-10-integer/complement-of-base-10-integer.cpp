class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int count=0;
        int ans=0;
        while(n>0){
            int r=n%2;// this is bit

            ans+=pow(2,count)*!r;//!r means bit is flipped
            n=n/2;
            count++;
        }

        return ans;
    }
};