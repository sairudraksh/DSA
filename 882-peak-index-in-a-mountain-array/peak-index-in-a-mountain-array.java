class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int lo=0;
        int hi=arr.length-1;
        int n=arr.length;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid==0){
                if(arr[mid]>arr[mid+1]){
                    return mid;
                }
                else lo=mid+1;
            }
            else if(mid==n-1){
                if(arr[mid]>arr[mid-1]){
                    return mid;
                }
                else hi=mid-1;
            }
            else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]<arr[mid+1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
    }
}