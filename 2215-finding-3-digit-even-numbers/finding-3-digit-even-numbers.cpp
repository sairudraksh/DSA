class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        unordered_map<int,int>map1;
        vector<int>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            map1[arr[i]]++;
        }
        for(int i=100;i<=998;i+=2){
            unordered_map<int,int>map2;
            int nums=i;
            while(nums>0){
                int k=nums%10;;
                map2[k]++;
                if(map2[k]>map1[k]) break;
                nums=nums/10;
            }
            if(nums==0){
                v.push_back(i);
            }
        }   
        return v;
    }
};