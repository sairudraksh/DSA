class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        int maximum=-1;
        for(auto &x:map){
            if(x.second==x.first){
                maximum=max(maximum,x.second);
            }
        }
        return maximum;
    }
};