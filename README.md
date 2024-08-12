# Fraction Calculator

This C++ project features a `Rational` class designed to handle arithmetic operations on fractions. It supports addition, subtraction, multiplication, and division of rational numbers. The class also provides comparison operations and input/output functionalities using operator overloading.

## Features

- **Class Members**: Handles numerator and denominator privately.
- **Constructors**:
  - Default constructor initializes to 0/1.
  - Parameterized constructor initializes with specified numerator and denominator.
  - Copy constructor initializes with another `Rational` object.
- **Destructor**: Manages dynamic memory allocation (if needed).
- **Member Functions**:
  - Reduces the fraction to its simplest form.
- **Operator Overloading**:
  - Arithmetic Operators: +, -, *, /
  - Comparison Operators: ==, !=
  - Stream Operators: <<, >>

## Sample Usage

```cpp
Rational r1(1, 2); // Represents 1/2
Rational r2(1, 3); // Represents 1/3
Rational r3 = r1 + r2;
r3.display(); // Displays 5/6
Rational r4 = r1 - r2;
r4.display(); // Displays 1/6
Rational r5 = r1 * r2;
r5.display(); // Displays 1/6
Rational r6 = r1 / r2;
r6.display(); // Displays 3/2
cout << (r1 == r2) << endl; // Displays 0 (false)
cout << (r1 != r2) << endl; // Displays 1 (true)
