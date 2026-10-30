class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());

        for(int i=0;i<stones.length;i++){
            pq.add(stones[i]);
        }
        
        int n=stones.length;

        while(pq.size()>1){
            int x=pq.poll();
            int y=pq.poll();

            pq.add(Math.abs(x-y));
        }

        return pq.peek();

    }
}