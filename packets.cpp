#include <iostream>
#include <deque>

using namespace std;

class Buffer{
private:
    int size_;
    int proc_;
    deque<int> buff_;

    bool check(int time){
        if (buff_.empty())
            return true;

        while (!buff_.empty() && buff_.front() <= time){
            buff_.pop_front();
        }

        return buff_.size() < size_;
    }

    int push(int time, int duration){
        int readyToStart = buff_.empty()
                ? (proc_ > time ? proc_ : time)
                : (buff_.back() > time ? buff_.back() : time);

        buff_.push_back(readyToStart + duration);
        proc_ = buff_.back();

        return readyToStart;
    }
public:
    Buffer(int size){
        size_ = size;
    }

    int add_package(int time, int duration){
        return check(time) ? push(time, duration) : -1;
    }
};

int main() {
    int buf_size, packets_num;
    cin >> buf_size;
    cin >> packets_num;

    pair<int, int> cur_packet;
    auto buffer = Buffer(buf_size);
    for (int i = 0; i < packets_num; i++) {
        cin >> cur_packet.first;
        cin >> cur_packet.second;
        cout << buffer.add_package(cur_packet.first, cur_packet.second) << endl;
    }

    return 0;
}