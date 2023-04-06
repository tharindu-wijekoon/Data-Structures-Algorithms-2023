#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

const int MAX_VALUE = 100;

class Stack {
    private:
        int arr[MAX_VALUE];
        int top;
    
    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == MAX_VALUE - 1;
        }

        void push(int value) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }

            top++;
            arr[top] = value;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }

            int value = arr[top];
            top--;
            return value;
        }

        int StackTop() {
            return top;
        }

        void Display() {
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
                return;
            }
            for (int i = top; i > -1; i--) {
                cout << arr[i] << ", ";
            }
            cout << endl;
        }
};

int main() {
    // srand(time(0));
    Stack s;
    cout << "Stack using an Array.\n";

    auto start = high_resolution_clock::now();

    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.Display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.Display();
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.push(rand()%100);
    s.Display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time taken is : " << duration.count() << " µs" << endl;
}