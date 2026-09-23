class Solution {
public:
    string smallestString(string s) {
        int n=s.length();

        int i=0;
        string str="";
        bool found=false;

        while(i<n && s[i]=='a'){
            str+='a';
            i++;
        }
        int idx=n;
        for(;i<n;i++){
            if(s[i]=='a'){
                idx=i;
                break;
            }
            int curr=int(s[i]);

            if(curr==97){
                curr=122;
            }
            else curr--;

            char ch=char(curr);
            str+=ch;
            found=true;
        }
        if(found==false){
            s[n-1]='z';
            return s;
        }
        else{
            for(int j=idx;j<n;j++){
                str+=s[j];
            }
            return str;
        }

    }
};