class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& nums, int x, int y, int k) {
        int top=x;
        int bottom=x+k-1;

        while(top<bottom){
            for(int col=y;col<y+k;col++){
                swap(nums[top][col],nums[bottom][col]);
            }
            top++;
            bottom--;
        }
        return nums;
    }
};