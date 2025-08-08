class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();

        vector<int>latest(26,-1);
        for(int i=0;i<n;i++){
            latest[s[i]-'a']=i;
        }

        vector<int>result;

        int i=0;
        while(i<n){
            int end=latest[s[i]-'a'];
            int j=i;
            
            while(j<end){
                end=max(end,latest[s[j]-'a']);
                j++;
            }
            result.push_back(j-i+1);
            i=j+1;
        }
        return result;
    }
};