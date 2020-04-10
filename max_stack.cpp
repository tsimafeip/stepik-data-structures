#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int operations_count, element_to_add;
    cin >> operations_count;

    string operation;
    stack<int> st;
    vector<int> out;

    for (int i = 0; i < operations_count; i++) {
        cin >> operation;
        if (operation == "push") {
            cin >> element_to_add;
            st.push(st.empty() ? element_to_add : max(element_to_add, st.top()));
        }
        else if (operation == "pop") {
            st.pop();
        } else if (operation == "max") {
            out.push_back(st.top());
        }
    }
    copy(out.begin(), out.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}