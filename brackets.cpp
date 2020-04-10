#include <iostream>
#include <stack>
#include <string>
#include <map>

int main() {
    std::string input_str;
    std::cin >> input_str;
    std::stack <std::pair<char, std::pair<ulong,ulong>> > st;
    char current_char;
    std::pair<bool, ulong> failed = std::make_pair(false, -1);

    std::map<char, char> brackets = {
            { '(', ')' },
            { '{', '}' },
            { '[', ']' }
    };

    for (std::string::size_type i = 0; i < input_str.size(); i++){
        current_char = input_str[i];
        switch(current_char) {
            case '(':
            case '{':
            case '[':
                if(st.empty())
                    st.push(std::make_pair(current_char, std::make_pair(i+1, i+1)));
                else
                    st.push(std::make_pair(current_char, std::make_pair(i+1,  st.top().second.second)));
                break;
            case '}':
            case ']':
            case ')':
                if (!st.empty() && current_char == brackets[st.top().first])
                    st.pop();
                else
                    failed = std::make_pair(true, i+1);
                break;
            default:
                continue;
        }

        if (failed.first) {
            break;
        }
    }

    if (st.empty() && !failed.first){
        std::cout << "Success" << std::endl;
    }
    else {
        if (failed.first)
            std::cout << failed.second << std::endl;
        else
            std::cout << st.top().second.second << std::endl;
    }
    return 0;
}