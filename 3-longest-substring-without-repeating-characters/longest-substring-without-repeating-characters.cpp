class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        if(s.length()==1) return 1;
        int n=s.length();
        int maxcount=1;
        for(int i=0;i<n-1;i++){
            unordered_map<char,int>map;
            int count=0;
            for(int j=i;j<n;j++){
                if(map.find(s[j])!=map.end()){
                    break;
                }
                else{
                    map[s[j]]++;
                    count++;
                }
            }
            if(count>maxcount){
                maxcount=count;
            }

        }
        return maxcount;
    }
};