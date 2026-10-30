class Solution {
    public int[][] merge(int[][] intervals) {
        Deque<int[]>q=new LinkedList<>();
        int n=intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        for(int i=0;i<n;i++){

            if(q.size()==0){
                int[] arr1=new int[2];
                arr1[0]=intervals[i][0];
                arr1[1]=intervals[i][1];
                q.add(arr1);
            }
            else{
                
                int[] arr2=q.peekLast();
                q.pollLast();
                
                if(intervals[i][0] <= arr2[1]){
                    int[] arr1=new int[2];
                    arr1[0]=Math.min(intervals[i][0],arr2[0]);
                    arr1[1]=Math.max(intervals[i][1],arr2[1]);

                    q.add(arr1);
                }
                else{
                    q.add(arr2);
                    q.add(intervals[i]);
                }
            }
        }
        int[][] ans=new int[q.size()][2];
        int i=0;
        while(q.size()>0){
            ans[i]=q.poll();
            i++;
        }
        return ans;
    }
}