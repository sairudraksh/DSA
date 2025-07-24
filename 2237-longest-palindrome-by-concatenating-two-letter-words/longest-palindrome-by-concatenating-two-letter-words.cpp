class Solution {
public:
    int longestPalindrome(vector<string>& nums) {
        int n=nums.size();
        unordered_map<string,int>map;
        bool flagg=false;
        int count=0;
        for(int i=0;i<n;i++){
            string s1=nums[i];
            reverse(s1.begin(),s1.end());
            if(map.find(s1)!=map.end()){
                count+=(s1.length()*2);
                map[s1]--;
                if(map[s1]==0){
                    map.erase(s1);
                }
            }
            else{
                map[nums[i]]++;
            }
        }
        for(auto x:map){
            string s1=x.first;
            reverse(s1.begin(),s1.end());
            if(s1==x.first){
                count+=2;
                break;
            }
        }
        return count;
    }
};