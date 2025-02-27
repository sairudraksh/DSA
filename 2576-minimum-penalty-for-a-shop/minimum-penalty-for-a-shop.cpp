class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int>pre(n+1,0);
        vector<int>suf(n+1,0);
        pre[0]=0;
        for(int i=0;i<n;i++){
            int count=0;
            if(customers[i]=='N') count++;
            pre[i+1]=pre[i]+count;
        }
        suf[n]=0;
        for(int i=n-1;i>=0;i--){
            int count=0;
            if(customers[i]=='Y') count++;
            suf[i]=suf[i+1]+count;
        }
        int minpen=n;
        for(int i=0;i<=n;i++){
            pre[i]+=suf[i];
            int pen=pre[i];
            minpen=min(minpen,pen);
        }
        for(int i=0;i<=n;i++){
            int pen=pre[i];
            if(pen==minpen) return i;
        }
        return n;

    }
};