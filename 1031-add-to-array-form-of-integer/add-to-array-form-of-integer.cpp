class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n=nums.size();

        int i=n-1;
        int carry=0;
        vector<int>v;
        while(i>=0){
            int currsum=nums[i]+carry+k%10;
            v.push_back(currsum%10);
            carry=currsum/10;
            k=k/10;
            i--;
        }
        while(k>0){
            int currsum=carry+k%10;
            v.push_back(currsum%10);
            carry=currsum/10;
            k=k/10;
        }
        if(carry>0) v.push_back(carry);
        reverse(v.begin(),v.end());
        return v;
    }
};