class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            res=res^nums[i];
        }
        int temp=res;
        int k=0;
        while(true){
            if((temp&1)==1){
                break;
            }
            k++;
            temp=temp>>1;
        }
        int retval;
        for(int i=0;i<n;i++){
            if(((nums[i]>>k) & 1)==1){
                retval=retval^nums[i];
            }
        }
        int ans=res^retval;
        v.push_back(ans);
        v.push_back(retval);
        return v;
    }
};