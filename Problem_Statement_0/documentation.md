# 📝 Solution Documentation Template

## Problem Understanding
**What the problem is asking:** 
The ps0 was to make a simple calculator, which can perform operations like simple arithmetic as well as trignometric and exponential operations.

**Key concepts involved:** 
I used string, getline to take input, vectors are used to sort numbers from operations and binary search is used to calculate square root.i also used Taylor's expansion.

**My approach:** 
I took the expression as a string and split it into two separate vectors — one for numbers and another for operations. Using these vectors, I performed the calculations sequentially from left to right. I haven’t yet implemented BODMAS (still working on it). For square root computation, I replaced my initial O(n) linear search approach with an O(logn) binary search method, which significantly reduced runtime (idea inspired by a LeetCode problem). For ln(x) and e^x, I implemented Taylor series expansion for approximation. log(x) was computed via the identity logx=lnx/ln10. For exponentiation a^x, I used the transformation a^x = e^(x ln a).
##  Conceptual Learning

### **New Concepts I Discovered**


### **How I Applied These Concepts**
[Explain how you used the concepts to solve the problem]

### **Real-World Connections**
[Where might you see this problem or similar concepts in real applications?]



