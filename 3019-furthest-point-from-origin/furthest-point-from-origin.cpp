class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int count1=0;
        int count2=0;
        int count3=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L') count1++;
            else if(s[i]=='R') count2++;
            else{
                count3++;
            }
        }

        int ans=0;
        if(count1>count2){
            ans=(count1+count3)-count2;
        }
        else{
            ans=(count2+count3)-count1;
        }
        return ans;
    }
};