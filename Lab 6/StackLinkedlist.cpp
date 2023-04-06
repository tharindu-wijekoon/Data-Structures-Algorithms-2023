#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class Stack {
    public:
        Node* top;

        Stack() {
            this->top = nullptr;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (top == nullptr) {
                throw "Stack is empty.";
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        void Display() {
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << ", ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    // srand(time(0));
    Stack s;
    cout << "Stack using a Linkedlist.\n";

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