class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int>map;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(!map[arr[i]+1]){
                ans+=arr[i]+1;
                if(arr[i]==0) continue;
                map[arr[i]+1]++;
            }

            else{
                map[arr[i]+1]++;
                int key=arr[i]+1;
                int val=map[arr[i]+1];
                if(key==val) map.erase(key);
            }

        }
        return ans;
        
    }
};