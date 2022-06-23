class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses,(a,b) -> a[1]-b[1]);
        PriorityQueue<Integer> queue = new PriorityQueue<>((a,b)->b-a);
        int time=0;
        for(int course[] : courses)
        {
            if(time+course[0]<=course[1])
            {
                queue.offer(course[0]);
                time+=course[0];
            }
            else if(!queue.isEmpty() && queue.peek()>course[0])
            {
                time+=course[0]-queue.poll();
                queue.offer(course[0]);
            }
        }
        return queue.size();
    }
}