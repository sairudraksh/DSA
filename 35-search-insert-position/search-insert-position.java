class Solution {
    public int searchInsert(int[] arr, int t) {
        
        int s = 0;
        int e = arr.length-1;
        int mid=0;
        while(s<=e){
             mid = s + (e-s)/2;

            if(arr[mid] == t){
                return mid;
            }
            else if(arr[mid] > t){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        
        return s;

    }
}