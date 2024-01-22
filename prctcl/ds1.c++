#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// template function for linear search
template <typename T>
int linearSearch(const vector<T>& arr, const T& key) {
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == key) return i;
  }
  return -1;
}

// template function for binary search
template <typename T>
int binarySearch(const vector<T>& arr, const T& key) {
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// driver function
int main() {
  vector<int> arr = {5, 6, 7, 9, 2, 3, 2, 1, 8};
  int target;

  cout << "Enter the element to be searched: ";
  cin >> target;

  char choice;
  cout << "Choose search type (L for linear and B for binary): ";
  cin >> choice;

  switch (choice) {
    case 'L':
    case 'l':

    {
      int linearResult = linearSearch(arr, target);
      if (linearResult != -1) {
        cout << "Linear Search: Element found at index " << linearResult
             << endl;
      } else {
        cout << "Linear Search: Element not found" << endl;
      }
      break;
    }

    case 'B':
    case 'b': {
      sort(arr.begin(), arr.end());
      int binaryResult = binarySearch(arr, target);
      if (binaryResult != -1) {
        cout << "Binary Search: Element found at index " << binaryResult
             << endl;
      } else {
        cout << "Binary Search: Element not found" << endl;
      }
      break;
    }

    default:
      cout << "Invalid choice. Please choose either L or B." << std::endl;
      break;
  }
  return 0;
}