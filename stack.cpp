#include <iostream>
#include <vector>

using namespace std;

class MyStack {
private:
    int* arr;
    int stackLength;
    int capacity;
    
    void checkException() {
        if (stackLength == 0) {
            throw "Stacl length = 0, error";
        }
    }

public:
    MyStack() {
        stackLength = 0;
        capacity = 10; // standert length
        arr = new int[capacity]; // TODO: make capacity for stack
    }
    
    void push(int x) {
        if (stackLength == capacity) {
            int prevCapacity = capacity;
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < prevCapacity; i++) {
                newArr[i] = arr[i];
            }

            delete arr;
            arr = newArr;
        }
        arr[stackLength++] = x;
    }
    
    
    void push(const vector <int> &elems) {
        for (int x: elems) {
            push(x);
        }
    }
    
    int top() {
        checkException();
        int x = arr[stackLength - 1];
        return x;
    }
    
    bool isEmpty() {
    if (stackLength == 0) {
        return true;
    } 
    return false;
    }
    
    int length() {
        return stackLength;
    }
    
    void pop() {
        checkException();
        stackLength--;
    }
};

int main() {

    MyStack stack = MyStack();
    // usage example
    stack.push(3);
    cout << "The last elemnt in stack - " << stack.top() << "\n";
    stack.push(4);
    cout << "The last elemnt in stack - " << stack.top() << "\n";
    stack.push(5);
    cout << "The last elemnt in stack - " << stack.top() << "\n";
    stack.pop();
    stack.pop();
    if (stack.isEmpty()) {
        cout << "stack is empty";
    } else {
        cout << "The stack length = " << stack.length() << "\n";
    }
    cout << "The last elemnt in stack - " << stack.top() << "\n";
    stack.pop();
    
    stack.push({1, 2, 3, 4, 5, 6, 7, 8});
    cout << stack.length();
};
