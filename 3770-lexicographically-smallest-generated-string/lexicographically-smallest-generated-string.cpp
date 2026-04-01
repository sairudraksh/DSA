class Solution {
public:
    bool isSame(string &s,string &str2,int i){
        int j=0;
        for(int k=i;k<i+str2.length();k++){
            if(str2[j]!=s[k]) return false;
            j++;
        }

        return true;
    }
    string generateString(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();

        int N=n+m-1;
        string s;
        s.resize(N,'$');
        vector<bool>canChange(N,0);

        for(int i=0;i<str1.length();i++){
            if(str1[i]=='T'){
                int j=i;
                for(int k=0;k<str2.length();k++){
                    if(s[j]!='$' && s[j]!=str2[k]){
                        return "";
                    }
                    s[j]=str2[k];
                    j++;
                }
            }
        }

        for(int i=0;i<N;i++){
            if(s[i]=='$'){
                canChange[i]=true;
                s[i]='a';
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                if(isSame(s,str2,i)){
                    bool changed=false;
                    for(int j=i+m-1;j>=i;j--){
                        if(canChange[j]==true){
                            changed=true;
                            s[j]='b';
                            canChange[j]=false;
                            break;
                        }
                    }
                    if(changed==false) return "";

                }
            }
        }
        return s;
    }
};