class Solution {
    public int minDeletions(String s) {
        int frequency[] = new int[26];
        for(int i=0;i<s.length();i++)
            frequency[s.charAt(i)-'a']++;
        Arrays.sort(frequency);
        
        int delCount = 0;
        int maxLimit = s.length();
        
        for(int i=25;i>=0 && frequency[i]>0;i--)
        {
            if(frequency[i] > maxLimit)
            {
                delCount += frequency[i]-maxLimit;
                frequency[i] = maxLimit;
            }
            maxLimit = Math.max(0,frequency[i]-1);
        }
        return delCount;
    }
}