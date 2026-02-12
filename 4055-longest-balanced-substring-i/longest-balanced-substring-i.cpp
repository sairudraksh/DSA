class Solution {
public:
    bool isBalanced(unordered_map<char,int>&map){
        int count=0;
        int val=0;
        for(auto &x:map){
            if(count==0){
                val=x.second;
                count++;
            }
            else if(x.second!=val){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.length();

        int maximum=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>map;
            for(int j=i;j<n;j++){
                map[s[j]]++;

                if(isBalanced(map)){
                    maximum=max(maximum,j-i+1);
                }
            }
        }
        return maximum;
    }
};