class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.length()==1) return true;
        bool found=false;

        int count=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                if(count==1 && found==false) return false;
                else{
                    count=1;
                    found=true;
                }
            }
            else{
                found=false;
            }
        }
        return true;
    }
};