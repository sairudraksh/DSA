class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;

        Stack<Integer>st=new Stack<>();
        int[] arr=new int[m];

        Arrays.fill(arr,-1);
        st.push(nums2[m-1]);

        for(int i=m-2;i>=0;i--){
            while(st.size()>0 && st.peek()<=nums2[i]){
                st.pop();
            }
            if(st.size()!=0) arr[i]=st.peek();

            st.push(nums2[i]);
        }

        HashMap<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            map.put(nums2[i],arr[i]);
        }
        int[] ans=new int[n];
        for(int i=0;i<n;i++){
            ans[i]=map.get(nums1[i]);
        }
        return ans;
    }
}