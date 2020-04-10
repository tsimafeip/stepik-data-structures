#include <iostream>
#include <queue>

using namespace std;

int main() {
    int elements_count, m;
    cin >> elements_count;
    int arr[elements_count];
    for (int i = 0; i < elements_count; i++){
        cin >> arr[i];
    }
    cin >> m;

    deque<int> q;
    for (int i = 0; i < elements_count; i++) {
        while (!q.empty() && q.back() < arr[i])
            q.pop_back();
        q.push_back(arr[i]);

        if (i >= m-1){
            if (i != m-1) {
                if (!q.empty() && q.front() == arr[i - m]) {
                    q.pop_front();
                }
            }
            cout << q.front() << " ";
        }
    }

    return 0;
}