#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

void append(std::string& str, std::vector<int>& app)
{
    std::string temp_str;
    std::cin >> temp_str;
    app.push_back(temp_str.length());
    str += temp_str;
}

void del(std::string& str, std::vector<std::string>& undo_st)
{

    int k;
    std::cin >> k;
    std::string temp;

    for (int i = 0; i < k; i++) {
        temp.push_back(str[str.size() - 1]);
        str.pop_back();
    }
    undo_st.push_back(temp);
}

void print(std::string& str)
{
    int k;
    std::cin >> k;
    std::cout << str[k - 1] << "\n";
}

void undo(std::string& str, std::vector<int>& undo_st,
    std::vector<int>& app_st, std::vector<std::string>& del_st)
{
    int type = undo_st[undo_st.size() - 1];
    undo_st.pop_back();

    if (type == 1) {
        int size = app_st[app_st.size() - 1];
        for (int i = 0; i < size; i++) {
            if (!str.empty())
                str.pop_back();
        }
        app_st.pop_back();
        return;
    } else {

        std::string temp = del_st[del_st.size() - 1];
        del_st.pop_back();

        std::string rev;
        for (int i = temp.size() - 1; i >= 0; i--) {
            rev = rev.append(1, temp[i]);
        };
        str += rev;
    }
}

int main()
{
    int n;
    std::cin >> n;

    int i = 0;
    std::string str("");
    std::vector<std::string> del_st;
    std::vector<int> app_st;
    std::vector<int> undo_st;

    while (n > i) {
        i++;
        int number;
        std::cin >> number;

        if (number == 1) {
            append(str, app_st);
            undo_st.push_back(number);
        }

        if (number == 2) {
            del(str, del_st);
            undo_st.push_back(number);
        }

        if (number == 3) {
            print(str);
        }

        if (number == 4) {
            undo(str, undo_st, app_st, del_st);
        }
    }

    return 0;
}

