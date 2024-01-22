#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T arr[MAX_SIZE];
    int top; 

public:
    Stack() : top(-1) {}

    
    void push(const T& value) {
        if (top == MAX_SIZE - 1) {
            throw std::overflow_error("Stack overflow");
        }

        arr[++top] = value;
        std::cout << "Pushed: " << value << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        std::cout << "Popped: " << arr[top--] << std::endl;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();

    intStack.pop();
    intStack.display();

    intStack.pop();
    intStack.pop();
    intStack.display();

    
    Stack<double> doubleStack;

    
    doubleStack.push(3.14);
    doubleStack.push(2.718);
    doubleStack.display();

    return 0;
}
