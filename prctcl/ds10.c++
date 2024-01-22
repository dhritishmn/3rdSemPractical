#include <iostream>
using namespace std;

// Node structure to represent a term in a polynomial
class Term {
 public:
  int coefficient;
  int exponent;
  Term* next;

  Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// Class to represent a polynomial using a linked list
class Polynomial {
 private:
  Term* head;

 public:
  Polynomial() : head(nullptr) {}

  // Function to insert a term into the polynomial
  void insertTerm(int coeff, int exp) {
    Term* newNode = new Term(coeff, exp);

    if (head == nullptr) {
      head = newNode;
      return;
    }

    Term* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  void addPolynomial(const Polynomial& other) {
    Term* temp1 = head;
    Term* temp2 = other.head;

    // Temporary head for the resultant polynomial
    Term* resultHead = new Term(0, 0);
    Term* currentResult = resultHead;

    while (temp1 != nullptr || temp2 != nullptr) {
      int coeff1 = (temp1 != nullptr) ? temp1->coefficient : 0;
      int exp1 = (temp1 != nullptr) ? temp1->exponent : 0;
      int coeff2 = (temp2 != nullptr) ? temp2->coefficient : 0;
      int exp2 = (temp2 != nullptr) ? temp2->exponent : 0;

      if (exp1 > exp2) {
        currentResult->next = new Term(coeff1, exp1);
        temp1 = temp1->next;
      } else if (exp1 < exp2) {
        currentResult->next = new Term(coeff2, exp2);
        temp2 = temp2->next;
      } else {
        // Add coefficients for the same exponent
        int sumCoeff = coeff1 + coeff2;
        if (sumCoeff != 0) {
          currentResult->next = new Term(sumCoeff, exp1);
          currentResult = currentResult->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
      }

      // Move to the next node in the resultant polynomial
      if (currentResult->next != nullptr) {
        currentResult = currentResult->next;
      }
    }

    // Update the head of the original polynomial
    head = resultHead->next;

    // Free memory for the temporary head
    delete resultHead;
  }

  // Function to display the polynomial
  void displayPolynomial() const {
    Term* temp = head;
    while (temp != nullptr) {
      cout << temp->coefficient << "x^" << temp->exponent;
      temp = temp->next;
      if (temp != nullptr) {
        cout << " + ";
      }
    }
    cout << endl;
  }

  // Destructor to free memory
  ~Polynomial() {
    Term* temp;
    while (head != nullptr) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  Polynomial poly1, poly2;

  // Build polynomial poly1: 3x^3 + 2x^2 + 5x + 1
  poly1.insertTerm(3, 3);
  poly1.insertTerm(2, 2);
  poly1.insertTerm(5, 1);
  poly1.insertTerm(1, 0);

  // Build polynomial poly2: 4x^2 + 2x + 7
  poly2.insertTerm(4, 2);
  poly2.insertTerm(2, 1);
  poly2.insertTerm(7, 0);

  cout << "Polynomial 1: ";
  poly1.displayPolynomial();

  cout << "Polynomial 2: ";
  poly2.displayPolynomial();

  poly1.addPolynomial(poly2);

  cout << "Resultant Polynomial: ";
  poly1.displayPolynomial();

  return 0;
}