#include<iostream>
#include<deque>
#include<string>

using namespace std;

int n, x;
deque<int> dq;
string s;

int main() {
    for (cin >> n; n--;) {
        cin >> s;
        if (s == "push_back") {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "push_front") {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "empty") 
            cout << dq.empty() << endl;
        else if (s == "size")
            cout << dq.size() << endl;
        else if (dq.empty()) 
            cout << "-1\n";
        else {
            if (s == "front" || s == "pop_front") 
                cout << dq.front() << endl;
            else 
                cout << dq.back() << endl;
            if (s == "pop_front") 
                dq.pop_front();
            else if (s == "pop_back") 
                dq.pop_back();
        }
    }
    return 0;
}