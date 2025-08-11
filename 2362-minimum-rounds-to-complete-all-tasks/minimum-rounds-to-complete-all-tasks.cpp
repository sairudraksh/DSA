class Solution {
public:
    int find(int num){
        int count=0;
        if(num%3==0) return num/3;
        else{
            int k=3;
            while(k<num-1){
                k=k+3;
                count++;
            }
            k=k-3;
            

        return count+(num-k)/2;
        }
    }
    int minimumRounds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int count=0;
        for(auto &x:map){
            if(x.second==1) return -1;
            else{
                count+=find(x.second);
            }
        }
        return count;
    }
};