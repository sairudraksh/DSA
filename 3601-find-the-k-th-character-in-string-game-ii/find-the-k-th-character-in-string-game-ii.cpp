class Solution {
public:
    int find(vector<int>& operations,long long k){
        if(k==1) return 'a';
        long long len=1;
        for(int i=0;i<operations.size();i++){
            len=len*2;
            if(len>=k){
                long long newk=k-(len/2);
                char ans=find(operations,newk);
                if(operations[i]==0) return ans;
                else if(operations[i]==1 && ans=='z') return 'a';
                else return ans+1;
            }
        }
        return 0;
    }
    char kthCharacter(long long k, vector<int>& operations) {
        return find(operations,k);
    }
};