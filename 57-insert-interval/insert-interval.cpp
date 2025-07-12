class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& intervals) {
        vector<vector<int>>res;
        int i=0;
        while(i<arr.size() && arr[i][1]<intervals[0]){
            res.push_back(arr[i]);
            i+=1;
        }
        while(i<arr.size() && arr[i][0]<=intervals[1]){
            intervals[0]=min(intervals[0],arr[i][0]);
            intervals[1]=max(intervals[1],arr[i][1]);
            i+=1;
        }
        res.push_back(intervals);
        while(i<arr.size()){
            res.push_back(arr[i]);
            i+=1;
        }
        return res;
    }
};