#include <iostream>
#include <stdexcept>

template <typename T>
class CircularQueue {
private:
    static const int MAX_SIZE = 5;
    T* arr;
    int front;
    int rear;

public:
    CircularQueue() : arr(new T[MAX_SIZE]), front(-1), rear(-1) {}

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return front == -1 && rear == -1;
    }

    bool isFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
        std::cout << "Enqueued: " << value << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        std::cout << "Dequeued: " << arr[front] << std::endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        do {
            std::cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue<int> intQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.display();

    intQueue.dequeue();
    intQueue.display();

    intQueue.enqueue(40);
    intQueue.enqueue(50);
    intQueue.display();

    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.dequeue(); 
    intQueue.display();

    CircularQueue<double> doubleQueue;

    doubleQueue.enqueue(3.14);
    doubleQueue.enqueue(2.718);
    doubleQueue.display();

    return 0;
}
