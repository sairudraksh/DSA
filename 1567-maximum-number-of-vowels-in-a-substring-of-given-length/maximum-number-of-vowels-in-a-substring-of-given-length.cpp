class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0;
        int j=k-1;
        int count=0;

        for(int l=0;l<=j;l++){
            if(s[l]=='a' || s[l]=='e' ||s[l]=='i' ||s[l]=='o' ||s[l]=='u'){
                count++;
            }
        }
        int maxcount=0;

        while(j<n){
            maxcount=max(maxcount,count);
            
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                count--;
            }
            
            i++;
            j++;
            if(j<n){
                if(s[j]=='a' || s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u'){
                    count++;
                }
            }
        }
        return maxcount;
    }
};