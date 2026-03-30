class Solution {
public:
    int n;
    string formString(vector<string>& words,int &maxlen,int i,int j,int &per,int &extra){
        string ans="";
        for(int k=i;k<j;k++){
        
            ans+=words[k];

            if(k==j-1){
                continue;
            }

            for(int l=0;l<per;l++){
                ans+=" ";
            }

            if(extra>0){
                ans+=" ";
                extra--;
            }
            
        }
        while(ans.length()!=maxlen) ans+=" ";
        
        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxlen) {
        n=words.size();

        int i=0;

        vector<string>ans;

        while(i<n){
            int no_of_text=0;
            int no_of_spaces=0;
            int no_per_spaces=0;
            int no_of_extra=0;

            int j=i+1;
            int curr=words[i].length();
            int cnt=0;
            while(j<n && curr+words[j].length()+cnt+1<=maxlen){
                curr+=words[j].length();
                cnt++;
                j++;
            }
            no_of_spaces=maxlen-curr;
            if(cnt==0) no_per_spaces=0;
            else no_per_spaces=no_of_spaces/cnt;

            if(cnt<=0) no_of_extra=0;
            else no_of_extra=no_of_spaces%cnt;
            if(j==n){
                no_of_extra=0;
                no_per_spaces=1;
            }
            string a=formString(words,maxlen,i,j,no_per_spaces,no_of_extra);
            ans.push_back(a);
            i=j;
        }


        return ans;

    }
};