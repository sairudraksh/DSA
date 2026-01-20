class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>v=score;
        sort(v.begin(),v.end());
        unordered_map<int,int>map;
        int count=1;
        reverse(v.begin(),v.end());
        for(int i=0;i<score.size();i++){
            map[v[i]]=count;

            count++;
        }
        vector<string>ans;
        for(int i=0;i<score.size();i++){
            if(map[score[i]]==1){
                ans.push_back("Gold Medal");
            }
            else if(map[score[i]]==2){
                ans.push_back("Silver Medal");
            }
            else if(map[score[i]]==3){
                ans.push_back("Bronze Medal");
            }
            else{
                int num=map[score[i]];
                string s=to_string(num);
                ans.push_back(s);
            }
        }
        return ans;
    }
};