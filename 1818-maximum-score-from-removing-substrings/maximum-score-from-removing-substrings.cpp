class Solution {
public:
    int scoreStrings(string& s, string resString, int point)
    {
        int totalPoints = 0, n = s.size();
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            if(st.size() == 0)
                st.push(s[i]);
            else
            {
                if(s[i] == resString[1] && st.top() == resString[0]){
                    st.pop();
                    totalPoints += point;
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        s="";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return totalPoints;
    }
    int scoreStrings2(string& s, string resString, int point)
    {
        int totalPoints = 0, n = s.size();
        int writeIndex = 0;

        for(int readIndex=0;readIndex<n;readIndex++)
        {
            s[writeIndex++] = s[readIndex];
            if(writeIndex > 1 && s[writeIndex - 1] == resString[1] && s[writeIndex - 2] == resString[0])
            {
                writeIndex -= 2;
                totalPoints += point;
            }
        }
        s = s.substr(0,writeIndex);
        return totalPoints;
    }
    int maximumGain(string s, int x, int y) {
        /*
        cdbcbbaaabab
        cdbcbaabab -> 5
        cdbcabab -> 10
        cdbcab -> 15
        cdbc -> 19

        aabbaaxybbaabb
        abaaxybbaabb -> 5
        aaxybbaabb -> 10
        aaxybbab -> 15
        aaxybb -> 20
        */
        string s1 = "ab";
        string s2 = "ba";
        if(x < y)
            swap(x,y), swap(s1,s2);
        return scoreStrings2(s,s1,x) + scoreStrings2(s,s2,y);
    }
};