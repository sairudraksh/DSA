class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        int n=arr.size();
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        for(auto x:map){
            int key=x.first;
            int value=x.second;
            for(auto x1: map){
                if(x1.first==key) continue;
                else if(x1.second==value) return false;
            }
        }
        return true;
    }
};