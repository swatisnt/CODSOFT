#include<iostream>
using namespace std;
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero is not possible." << endl;
        return 0;
    }
}

int main() {
    char choice;
    double num1, num2;
cout<<"Simple Calculator ";
    do
    {
        cout << "\nSelect an operation (+, -, *, /) or 'e' to exit: ";
        cin >> choice;

        if (choice == 'e') {
            break; 
        }

        cout << "Enter 1st number: ";
        cin >> num1;

        cout << "Enter 2nd number: ";
        cin >> num2;

        switch (choice) {
            case '+':
                cout << "Addition is: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Subtraction is: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Multiplication is: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Division is: " << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                break;
            default:
                cout << "Error: Invalid operation." << endl;
        }

    } while (true);

    cout << "Calculator exited. Thank you!" << endl;

    return 0;
}