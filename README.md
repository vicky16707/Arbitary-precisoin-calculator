# Arbitrary Precision Calculator (APC)

## 📌 Overview

The **Arbitrary Precision Calculator (APC)** is a calculator designed to perform arithmetic operations on very large numbers that cannot be handled by standard C data types such as `int`, `long`, or `long long`.

In this project, large numbers are represented using **doubly linked lists**, where each node stores a portion of the number. This allows the program to perform calculations on numbers with an arbitrary number of digits.

The calculator supports basic arithmetic operations such as:

* Addition
* Subtraction
* Multiplication
* Division

It also handles positive and negative numbers.

---

## 🎯 Objective

The main objective of this project is to implement arithmetic operations on numbers that exceed the storage capacity of standard data types.

For example, a normal `long long` variable cannot store extremely large numbers such as:

```text
1234567890123456789012345678901234567890
```

The APC overcomes this limitation by storing the number digit-by-digit using a linked list.

---

## ✨ Features

* Supports very large integers
* Addition of large numbers
* Subtraction of large numbers
* Multiplication of large numbers
* Division of large numbers
* Handles positive and negative numbers
* Uses linked lists for dynamic memory allocation
* Performs operations without using built-in large-number libraries
* Provides command-line based input and output

---

## 🛠️ Technologies Used

* **Language:** C
* **Data Structure:** Doubly Linked List
* **Concepts:** Dynamic Memory Allocation, Pointers, Linked Lists, Arithmetic Algorithms

---

## 🧠 Data Structure

Each number is stored using a linked list.

For example:

```text
Number: 123456

Linked List:

1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
```

Each node contains:

```text
+--------+------+
|  Data  | Next |
+--------+------+
```

A doubly linked list can also maintain a previous pointer:

```text
+------+------+------+
| Prev | Data | Next |
+------+------+------+
```

This makes it easier to perform operations from both ends of the number.

---

## ⚙️ How It Works

### 1. Input

The user enters two large numbers and the required arithmetic operator.

Example:

```text
Enter first number: 123456789123456789
Enter operator: +
Enter second number: 987654321987654321
```

### 2. Conversion

The input numbers are converted from strings into linked lists.

```text
123456789

↓
1 ↔ 2 ↔ 3 ↔ 4 ↔ 5 ↔ 6 ↔ 7 ↔ 8 ↔ 9
```

### 3. Operation

The appropriate arithmetic function is selected based on the operator.

```text
+  → Addition
-  → Subtraction
*  → Multiplication
/  → Division
```

### 4. Result

The resulting linked list is converted back into a readable number and displayed.

---

## ➕ Addition

Addition is performed digit-by-digit starting from the least significant digit.

Example:

```text
   999999
 + 123456
 --------
  1123455
```

The program handles carry values while moving through the linked lists.

---

## ➖ Subtraction

Subtraction is performed digit-by-digit while handling borrowing.

Example:

```text
   987654
 - 123456
 --------
   864198
```

The program also checks the signs of both numbers to determine the correct result.

---

## ✖️ Multiplication

Multiplication is performed using the individual digits of the two numbers.

Example:

```text
123 × 45
```

The program calculates the partial products and combines them to produce the final result.

```text
123 × 45 = 5535
```

Since linked lists can store numbers of arbitrary length, the same method can be applied to very large numbers.

---

## ➗ Division

Division is performed using repeated comparison and subtraction or a long-division approach, depending on the implementation.

Example:

```text
1000 / 25 = 40
```

The program also handles cases such as division by zero.

---

## 🔢 Negative Numbers

The calculator supports signed numbers.

Example:

```text
-100 + 50 = -50

100 - 150 = -50

-20 × 5 = -100
```

The sign of the result is determined based on the operands and the operation being performed.

---

## 📂 Project Structure

A typical project structure is:

```text
APC/
│
├── main.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── apc.h
├── validation.c
└── README.md
```

### File Description

| File               | Description                                              |
| ------------------ | -------------------------------------------------------- |
| `main.c`           | Handles user input and program execution                 |
| `addition.c`       | Performs addition                                        |
| `subtraction.c`    | Performs subtraction                                     |
| `multiplication.c` | Performs multiplication                                  |
| `division.c`       | Performs division                                        |
| `apc.h`            | Contains structure definitions and function declarations |
| `validation.c`     | Validates input and operators                            |

> Modify the file names above according to your actual project structure.

---

## ▶️ Compilation

Compile the project using GCC:

```bash
gcc *.c
```

Or:

```bash
gcc main.c addition.c subtraction.c multiplication.c division.c -o apc
```

---

## 🚀 Running the Program

On Linux/macOS:

```bash
./apc
```

On Windows:

```bash
apc.exe
```

---

## 💻 Sample Execution

```text
$ ./apc

Enter the first number: 123456789123456789
Enter the operator: +
Enter the second number: 987654321987654321

Result:
1111111111111111110
```

Another example:

```text
Enter the first number: 999999999999999999
Enter the operator: *
Enter the second number: 999999999999999999

Result:
999999999999999998000000000000000001
```

---

## 🧪 Test Cases

Some example test cases:

| Input         | Operation      | Expected Result |
| ------------- | -------------- | --------------- |
| `100 + 200`   | Addition       | `300`           |
| `500 - 200`   | Subtraction    | `300`           |
| `25 * 4`      | Multiplication | `100`           |
| `100 / 5`     | Division       | `20`            |
| `999999 + 1`  | Addition       | `1000000`       |
| `1000 - 2000` | Subtraction    | `-1000`         |
| `-50 + 100`   | Addition       | `50`            |
| `100 / 0`     | Division       | Error           |

---

## ⚠️ Error Handling

The program validates input and handles common errors such as:

* Invalid characters in numbers
* Invalid operators
* Division by zero
* Empty input
* Incorrect number format
* Negative number handling

Example:

```text
Enter operator: %

Invalid operator!
```

Division by zero:

```text
Enter: 100 / 0

Error: Division by zero is not allowed.
```

---

## 🧩 Concepts Used

This project demonstrates several important C programming and data-structure concepts:

* Structures
* Pointers
* Dynamic memory allocation
* Doubly linked lists
* String manipulation
* Function pointers
* Modular programming
* Memory management
* Arithmetic algorithms
* Input validation

---

## ⏱️ Advantages

The main advantage of APC is that it is not restricted by the maximum value supported by standard integer data types.

For example, instead of being limited to:

```text
9,223,372,036,854,775,807
```

the program can work with numbers containing hundreds or thousands of digits, depending on available memory and implementation.

---

## 🔮 Future Improvements

The project can be extended with additional features such as:

* Modulus (`%`)
* Power (`^`)
* Square root
* Factorial
* GCD and LCM
* Floating-point calculations
* Scientific notation
* Expression evaluation
* Improved division algorithm
* Interactive calculator interface
* GUI-based calculator

---

## 📚 Learning Outcomes

Through this project, we learn how to:

1. Represent numbers using linked lists.
2. Perform arithmetic without relying on built-in integer limits.
3. Work with dynamic memory allocation.
4. Handle large strings and numbers.
5. Implement arithmetic algorithms manually.
6. Manage pointers and linked-list operations.
7. Divide a large project into multiple source files.

---

## 👨‍💻 Author

Vignesh N

### Project

**Arbitrary Precision Calculator (APC)**

### Language

**C**

---

## 📄 License

This project is created for educational purposes.
