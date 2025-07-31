

# new in C++ ( for my self )

**std::make_shared<>();** (cpp11)

In C++, std::make_shared() is a function that returns a shared pointer to the object of specific type after dynamically creating it. It offers a safer and more efficient way to create shared pointers, reducing the chances of errors and improving performance. The function is declared in the <memory> header file.

A **std::shared_pointer** is a smart pointer introduced in C++11 that manages the lifetime of a dynamically allocated object through reference counting. In this article, we will learn how to create a shared_pointer.

**bind and placeholder** (cpp11)  
https://www.geeksforgeeks.org/bind-function-placeholders-c/

std::placeholder::_1

This namespace declares an unspecified number of objects: _1, _2, _3,..., which are used to specify placeholders in calls to function bind.

When the function object returned by bind is called, an argument with placeholder _1 is replaced by the first argument in the call, _2 is replaced by the second argument in the call, and so on... For example:
1
2
3
using namespace std::placeholders;
auto bound_fn = std::bind (fn,100,_1);
bound_fn(5);  


**lambda expression** (Cpp11)  
https://www.geeksforgeeks.org/lambda-expression-in-c/
C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of code that are not going to be reused and therefore do not require a name. In their simplest form a lambda expression can be defined as follows: 
```c++
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
} 
```