class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum-x;
        int maxlen=-1;
        int i=0;
        int j=0;
        int currsum=0;
        if(target==0) return n;
        while(i<n && j<n){
            currsum+=nums[j];

            if(currsum==target){
                int len=j-i+1;
                maxlen=max(maxlen,len);
            }
            else if(currsum>target){
                while(i<n && i<j && currsum>target){
                    currsum-=nums[i];
                    i++;
                }
                if(i==j && currsum>target){
                    currsum-=nums[i];
                    i++;
                }
                else if(i==j && currsum==target){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                    currsum-=nums[i];
                    i++;
                }
                else if(currsum==target){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
            }
            j++;
        }
        if(maxlen==-1) return -1;
        return n-maxlen;
    }
};