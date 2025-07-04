class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';
        long long len=1;
        long long opr=-1;
        long long newk=1;
        for(int i=0;i<operations.size();i++){
            len=len*2;
            if(len>=k){
                opr=i;
                newk=k-(len/2);
                break;
            }
        }
        char ch=kthCharacter(newk,operations);
        if(operations[opr]==0){
            return ch;
        }
        else if(ch=='z') return 'a';
        return ch+1;
    }
};