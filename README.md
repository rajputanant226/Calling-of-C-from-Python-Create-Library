# Integrating Python with C for Performance — Using ctypes

This guide demonstrates how to write C functions, compile them into a shared library, and use them inside Python using the ctypes module.
This allows Python to leverage the speed of compiled C code, especially useful in performance-heavy computations.

### What You Will Learn

How to write reusable C functions.

How to compile C code into a shared library (.dll / .so).

How to load and call C functions using Python's ctypes.

How data is passed between Python and C.

🧾 Step 1: Write the C Code

Create a file named Functions.c:

int lcm(int a,int b){
    int l;
    for(l = a > b ? a : b; l <= a*b; l++){
        if(l % a == 0 && l % b == 0){
            return l;
        }
    }
}

int fact(int n){
    int f = 1;
    for(int i=1; i<=n; i++){
        f = f * i;
    }
    return f;
}


This file contains two functions:

lcm(a, b) → Calculates Least Common Multiple.

fact(n) → Calculates factorial of a number.

🛠️ Step 2: Compile the C Code into a Shared Library
For Linux / Mac:
gcc -std=c11 -o customlib1.so --shared -fPIC Functions.c

For Windows (MinGW):
gcc -shared -o customlib1.dll Functions.c


After compiling, you will get:

customlib1.so (Linux/Mac)
or

customlib1.dll (Windows)

🐍 Step 3: Use the Library in Python

Create main.py:

from ctypes import *

# Load the shared library (update the path as needed)
c_file_path = r"D:\100 days\31th\customlib1.dll"
c_fun = CDLL(c_file_path)

# Call C functions
a = c_fun.lcm(4, 6)
b = c_fun.fact(5)

print("The LCM is:", a)
print("The Factorial is:", b)

⚡ Output
The LCM is: 12
The Factorial is: 120

🧠 Why Use C with Python?
Feature	Python	C
Ease of writing	✅ Easy	⚠️ Complex
Execution Speed	⏳ Slower	⚡ Very fast
Use Case	High-level logic, scripting	Heavy computation, algorithms

Using both together gives the best of both worlds.

### Conclusion

By integrating Python and C, you gain fast execution without losing Python’s simplicity.
This approach is widely used in AI, Game Engines, Data Processing, and System Tools.
