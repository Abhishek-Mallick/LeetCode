class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b) -> (b-a));
        long total = 0;
        for(int index : target)
        {
            total += index;
            pq.add(index);
        }
        while(total>1 && pq.peek()>total/2)
        {
            int curr = pq.poll();
            total -= curr;
            if(total<=1)
                return total==0?false:true;
            pq.add(curr%(int)total);
            total += curr%total;
        }
        return total==target.length;
    }
}