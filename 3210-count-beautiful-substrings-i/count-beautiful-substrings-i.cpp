class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.length();
        vector<int>vovel(n,0);
        vector<int>consonent(n,0); 
        if(s[0]=='a' ||s[0]=='e' ||s[0]=='i' ||s[0]=='o' ||s[0]=='u'){
            vovel[0]=1;
        }
        else consonent[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                vovel[i]=vovel[i-1]+1;
                consonent[i]=consonent[i-1];
            }
            else{
                consonent[i]=consonent[i-1]+1;
                vovel[i]=vovel[i-1];
            }
        }
        int curr=0;
        for(int i=0;i<n;i++){
            int count1=0;
            int count2=0;
            for(int j=i;j<n;j++){
                if(s[j]=='a' ||s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u'){
                    count1++;
                }
                else count2++;

                if(count1==count2 && (count1*count2)%k==0) curr++;
            }
        }
        return curr;
    }
};