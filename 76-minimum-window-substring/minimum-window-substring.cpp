class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n) return "";
        

        unordered_map<char,int>map;
        for(int i=0;i<t.length();i++){
            map[t[i]]++;
        }

        int i=0;
        int j=0;

        int minlength=INT_MAX;
        int minidx=0;
        int required=t.length();
        while(j<n){
            char ch=s[j];

            
            if(map[ch]>0) required--;
                
            map[ch]--;
            

            while(required==0){
                if(j-i+1<minlength){
                    minlength=j-i+1;
                    minidx=i;
                }
                map[s[i]]++;

                if(map[s[i]]>0) required++;
                i++;
            }
            j++;
        }
        if(minlength==INT_MAX) return "";
        return s.substr(minidx,minlength);
    }
};