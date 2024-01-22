#include <iostream>

class SymmetricMatrix {
private:
    int size;
    int* array;

public:
    SymmetricMatrix(int n) : size(n) {
        array = new int[n * (n + 1) / 2]; 
    }

    ~SymmetricMatrix() {
        delete[] array;
    }

   
    void setValue(int row, int col, int value) {
        if (row < col) {
            std::swap(row, col);
        }

        
        int index = row * (row + 1) / 2 + col;
        array[index] = value;
    }

    
    int getValue(int row, int col) const {
        if (row < col) {
            std::swap(row, col);
        }

        
        int index = row * (row + 1) / 2 + col;
        return array[index];
    }

    
    void display() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << getValue(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n;

    
    std::cout << "Enter the size of the symmetric matrix: ";
    std::cin >> n;

    SymmetricMatrix symmetricMatrix(n);

    
    std::cout << "Enter the elements of the symmetric matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int value;
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> value;
            symmetricMatrix.setValue(i, j, value);
        }
    }

    
    std::cout << "Symmetric Matrix:" << std::endl;
    symmetricMatrix.display();

    return 0;
}
