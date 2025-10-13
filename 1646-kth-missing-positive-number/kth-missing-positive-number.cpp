class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>map;
        int n=arr.size();
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        int count=0;
        for(int i=1;i<=2001;i++){
            if(map.find(i)==map.end()){
                count++;
            }
            if(count==k) return i;
        }
        return -1;
    }
};