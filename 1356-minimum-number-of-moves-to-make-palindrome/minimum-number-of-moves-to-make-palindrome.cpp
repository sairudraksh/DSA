class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        int count=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                int idx=-1;
                for(int k=j-1;k>i;k--){
                    if(s[k]==s[i]){
                        idx=k;
                        break;
                    }
                }
                if(idx!=-1){
                    for(int k=idx;k<j;k++){
                        swap(s[k],s[k+1]);
                        count++;
                    }
                    i++;
                    j--;
                }
                else{
                    swap(s[i],s[i+1]);
                    count++;
                }
            }
        }
        return count;
    }
};