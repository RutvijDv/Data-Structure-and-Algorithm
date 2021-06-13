string removePair(string s)
{
    stack<char> st;
    int n = s.length();
    string res;

    st.push(s[0]);
    for (int i = 1; i < n; i++)
    {
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    return res;
}