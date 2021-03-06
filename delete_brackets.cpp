#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s)
{
  stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (s[i] == '}' && st.top() == '{') {
                st.pop();
                 continue;
            }
            if (s[i] == '}') {
                st.push(s[i]);
                 continue;
            }

            if (s[i] == ')' && st.top() == '(') {
                st.pop();
                 continue;
            }
            if (s[i] == ')') {
                st.push(s[i]);
                 continue;
            }

            if (s[i] == ']' && st.top() == '[') {
                st.pop();
                continue;
            }
            if (s[i] == ']') {
                st.push(s[i]);
                 continue;
            }
        }
    }
    if (st.size() == 0) {
        
        return "YES";
    } else {
        
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

