#include <iostream>
#include <vector>
using namespace std;

// template function for insertion sort

template <typename T>
void insertionSort(vector<T>& arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    T key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// template function for bubble sort

template <typename T>
void bubbleSort(vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// template function for selection sort

template <typename T>
void selectionSort(vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

// template function to display elements

template <typename T>
void display(const vector<T>& arr) {
  for (const T& elem : arr) {
    cout << elem << " ";
  }
  cout << endl;
}

// driver function

int main() {
  vector<int> arr = {5, 6, 7, 9, 2, 3, 2, 1, 8};
  char choice;

  cout << "Choose sorting algorithm (I for Insertion, B for Bubble, S for "
          "Selection): ";
  cin >> choice;

  switch (choice) {
    case 'I':
    case 'i':
      insertionSort(arr);
      cout << "Insertion Sort: ";
      break;

    case 'B':
    case 'b':
      bubbleSort(arr);
      cout << "Bubble Sort: ";
      break;

    case 'S':
    case 's':
      selectionSort(arr);
      cout << "Selection Sort: ";
      break;

    default:
      cout << "Invalid choice. Please choose either I, B, or S." << endl;
      return 1;
  }

  display(arr);

  return 0;
}