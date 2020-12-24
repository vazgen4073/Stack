#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <climits> 
using namespace std;


void STDIN(const int number, std::vector<int>& st)
{
    st.push_back(number);
}

void STDOUT(std::vector<int>& st, int& max)
{
    
    if (st.empty()) {
        return;
    }
    if (st[st.size() - 1] == max) {
        st.pop_back();
        max = INT_MIN;
        if(!st.empty())
            max = *std::max_element(st.begin(), st.end());
        return;
    }
    st.pop_back();
}

void STDOUT1(std::vector<int>& st, int& max)
{
    if (st.empty()) {
        return;
    }
    std::cout << max << "\n";
}

int main()
{
    std::vector<int> st;
    int n, type;
    std::cin >> n;
    
    int max = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        std::cin >> type;
        if (type == 3)
            STDOUT1(st, max);
        
        if (type == 1) {
            int number;
            
            std::cin >> number;
            if (number > max)
                max = number;
            STDIN(number, st);
        }
        
        if (type == 2) {
            STDOUT(st, max);
        }
    }
    
    return 0;
}

