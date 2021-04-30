#include <iostream>
#include "stack"

using namespace std;

class CQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    CQueue() = default;

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.empty()) {
            if (stack1.empty())return -1;
            int a;
            while (!stack1.empty()) {
                a = stack1.top();
                stack1.pop();
                stack2.push(a);
            }
        }
        int a = stack2.top();
        stack2.pop();
        return a;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
