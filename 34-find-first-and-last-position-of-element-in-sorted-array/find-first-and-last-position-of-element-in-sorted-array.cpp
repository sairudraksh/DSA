class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v(2,-1);

        int lo=0;
        int hi=nums.size()-1;
       
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                v[0]=mid;
                for(int i=mid;i<n;i++){
                    if(nums[i]==target){
                        v[1]=i;
                    }
                    else break;
                }
                for(int i=mid;i>=0;i--){
                    if(nums[i]==target){
                        v[0]=i;
                    }
                    else break;
                }

                return v;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return v;
    }
};