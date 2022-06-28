class Solution {
    public int minDeletions(String s) {
        int frequency[] = new int[26];
        for(int i=0;i<s.length();i++)
            frequency[s.charAt(i)-'a']++;
        int delCount = 0;
        HashSet<Integer> seen = new HashSet<>();
        for(int i=0;i<26;i++)
        {
            while(frequency[i]>0 && seen.contains(frequency[i]))
            {
                frequency[i]--;
                delCount++;
            }
            seen.add(frequency[i]);
        }
        return delCount;
    }
}