# **Java**

## **Basics of JAVA**
Extension: .java (ex: helloWorld.java)

```mermaid
flowchart TD
id[.java file] --> id1[java compiler]-->|provides|id3[".class file called byte code"]-->|pass to java virtual machine|id4[JVM]-->|produces|id5["machine understandable code(.exe file)"]
id4
```

- Java support cross platform operating system.


### **Difference Between JDK, JRE & JVM**
 Java Development kit (JDK) | Java Runtime Environment (JRE) | Java Virtual Machine (JVM)
 -|-|-
 A group of softwares, which is required to compile and develop as well as executes java program and application | It used for user's to run application, means it used for the execution only | It is a virtual machine to run java program, JRE consist of Library files, Byte Code verifier and Class Loaders
---
```mermaid
---
title: JRE Diagram
---
flowchart TD
id[JVM]---|+|id1[Library files]
id---|+|id3[ByteCode Verifier]---|+|id4[Class Loaders]
 ```
---
```mermaid
---
title: JDK Diagram
---
flowchart TD
id[JRE]---|+|id1[Development tools]
id---|+|id3[java Compiler]
 ```

### **Installation of Java**
- [System Requirements](https://www.java.com/en/download/help/sysreq.html)
- [Installating java on Windows](https://www.java.com/en/download/help/windows_manual_download.html)

### **Running Program in JDK**
NOTE: Naviate to the parent folder of your program in the CMD.
```java
> javac helloworld.java
```
It produces the classname.class file, you can see the output from .class file using the below command
```java
> java classname
```
- When you run the program program execution will start from main method
- It will execute code one by one
### Simple Programs
#### **Print the string**
```java
class greet
{
    public static void main(String args[])
    {
        System.out.println("Hello World");
    }
}
```
#### **Scan the element in Java and add two numbers**
```java
import java.util.Scanner;

public class demo
{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter 2 numbers");
        int a=scan.nextInt();
        int b=scan.nextInt();
        int c=a+b;
        System.out.println("Addition of the number is "+c);
    }
}
```
#### **Java Prgram to perform arithmetic operation on two numbers**

```java
import java.util.Scanner;

class Arithmatic
{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter 2 numbers");
        int a=scan.nextInt();
        int b=scan.nextInt();
        System.out.println("Addition of the number is "+(a+b));
        System.out.println("subration of the number is "+(a-b));
        System.out.println("multiplication of the number is "+(a*b));
        System.out.println("Division of the number is "+(a/b));
    }
}
```
output:
```output
Enter 2 numbers
6 6
Addition of the number is 12    
subration of the number is 0    
multiplication of the number is 36
Division of the number is 1     
```

### **Control Structure**
#### **If-Else**
```java
import java.util.Scanner;

class demo{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter 1:");
        int a=scan.nextInt();
        if(a==1)
        {
            System.out.println("You Pressed 1");
        }
        else
        {
            System.out.println("You are not pressed 1");
        }
    }
}
```
Output:

case 1:
```output
Enter 1:
1
You Pressed 1
```
case 2:
```output
Enter 1:
2
You are not pressed 1
```

#### **if-else if-else**
```java
//Here in the below if not use angular backet for if, because if there there is one statement in if condition, it is not compulsory to put angular bracket, if there is two statement then angular backet is compulsory.
if(num==1)
    System.out.println("1 pressed ");
else if(num==2)
{
    System.out.println("2 pressed ");
    System.out.println("try to press 1");
}
else if(num>=3 && num<10)
    System.out.println("you pressed the number between 3 and 10");
else
    System.out.println("you should press number less than 10");
```

#### **Switch - Case**
It works same as the if-else if-else  
ex:
```java
import java.util.Scanner;
class Main
{
public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        switch(a)
        {
            case 1:
                System.out.println("pressed 1");
                break; //if break is not suppose a=1, then it print all the cases from, to avoid this we use break.
            case 2:
                System.out.println("pressed 2");
                break;
            case 3:
                System.out.println("pressed 3");
                
                System.out.println("hello1");
                break;
            default:
                System.out.println(" press 1 or 2 or 3");
        }
    }
}
```

### **Primitive Data Types in Java**
1. Integer Data type
     Data Type | Size | Range | Example
     -|-|-|-
     byte| 1byte | $\frac{2^8}{2}$ to $\frac{2^8}{2}-1$ | byte age=35;
     short | 2bytes | $\frac{2^{2*8}}{2}$ to $\frac{2^{2*8}}{2}-1 $ | short year=2023;
     int | 4bytes |  $\frac{2^{4*8}}{2}$ to $\frac{2^{4*8}}{2}-1 $ | int sal=365000;
     long | 8 bytes |$\frac{2^{8*8}}{2}$ to $\frac{2^{8*8}}{2}-1 $ | long pop=99999999999999l; //note `small L` in last.

2. Decimal Data type
    Data Type | Size |Example
     -|-|-
    float | 4 bytes | float g=9.8f;
    double |8 bytes | double pi=3.14159265359;

3. character
    Data Type | Size | Example
     -|-|-
     char | 2bytes | char gen = 'M';

4. Boolean
    Data Type | Size | Example
     -|-|-
     Boolean | 1bit | boolean isMarried=false;


#### **Typecasting**
implicit typecasting
```java
int salary=365000;
double dupSalary=salary; //this is known as type casting
```
explicit typecasting
```java
double pi=3.14;
int dupPi = (int)pi;
 //if not put (int), it shows error because size of double is more than int
```
#### **dividing 2 integer**
Suppose you want to divide two number and try to store it in double, you write code as below
```java
int a=16;
double b=a/3; //b=5.0
```
The above code is wrong it store 5.0 in b. if we need to get a accurate decimal value, the numerator or denominator must be an float number
```java
int a=16;
double b=a/3.0; //b=5.3333333333
```
#### **Scanner in Java**
```java
import java.util.Scanner;
class scan_java
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        int a=scan.nextInt(); //get integer
        byte b= scan.nextByte(); //get byte
        float c=scan.nextFloat(); //get float number
        String d=scan.nextLine(); //get the string
        char e=scan.next().charAt(0); //get the character
        long f=scan.nextLong(); //get the long value
        double g=scan.nextDouble(); //get the double value
    }
}
```

<div style="background-color:#AB7B7B; color:white; padding: 20px;">
<b>Note:</b> If you scan string, after the scan of integer, you need to use Scan.nextLine(); function before using String name=Scan.nextLine();

<details><summary>Example</summary>

```java
Scanner scan = new Scanner(System.in);
int age = scan.nextInt();
scan.nextLine(); // If we scan string after the integer we need to use this
int name = scan.nextLine();
```

</details>
</div>

### **Looping in java**
loops available in java
- for
- do
- while

**for**  
syntax
```java
for(initialization; condition; increment/decrement)
{
    statement;
}
```
```java
int a=10;  
for(int b=1;b<=10;b++)
{
    System.out.println("Hi"); //Prints hello 5 times
}
```
```output
Hi
Hi
Hi
Hi
Hi
Hi
Hi
Hi
Hi
Hi
```

**while**\
syntax:
```java
initialization;
while(condition)
{
    statement;
    increment/decrement;
}
```

**do-while**
```java
// The difference between while and do-while is that while checks the condition first and executes the code, but the do-while executes the statements inside do and then checks the condition.
initialization;
do{
    statements;
    increment/decrement;
}while(condition);
```
**Note:** `Break;` is the keyword used to take the control out of the loop


<details>
<summary>  
<b>Nested loop</b>
</summary>

```java
for(int i=0; i<5; i++)
{
    for(int j=0; j<=i; j++)
    {
        System.out.print(j+" ");
    }
    System.out.print('\n');
}
```
Output:
```output
0 
0 1 
0 1 2 
0 1 2 3 
0 1 2 3 4 
```
</details>

### **Object Oriented Programming**
- It is used to solve real-world problems
- object is the real world entity like pen, car, person, animal... etc
- Class name should always start with Capital Letter
```Java
//class program
class Car
{
    String brand; //state or property
    String color; //state or property
    int price; //state or property
    void accelerate() //behavior or action performed or methods
    {
        System.out.println("A car accelerates");
    }
}
class CarApp
{
    public static void main(String args[])
    {
        Car c=new Car(); //c is the object of car class.
        c.brand="maruthi";
        c.color="red";
        c.price=1200000;
        System.out.println(c.brand);
        System.out.println(c.color);
        System.out.println(c.price);
        c.accelerate();
    }
}
```
Output:
```output
maruthi
red
1200000
A car accelerates
```

#### **Constructor**
- Constructor is the one first get executed when you create an objet for an class.
- Name of the constructor is always same as the name of the class.
- We can use the constructor to initialize the variable, when an object is create.
```java
class Teacher
{
    String name;
    String sub;
    int sal;
    void teach()
    {
        System.out.println("A teacher teaches");
    }
    Teacher(String name, String sub, int sal)
    {
        this.name=name;
        this.sub=sub;
        this.sal=sal;
    }
}
class TeacherApp
{
    static void main(String[] args)
    {
        Teacher t1=new Teacher("saranya","aptitude",50000);
        System.out.println(t1.name+" "+t1.sub+" "+t1.sal);
    }
}
```
```output
saranya aptitude 50000
```

### **Array**
- An array is a collection of items of same data type stored at contiguous memory locations. It makes easy to access the element.
- An index of the array always start from zero (0).

Example of declaration of array in java
```java
int marks[]=new int[5]; //declaration of array
marks[0]=99; //initializing the array
marks[1]=95; //initializing the array
marks[2]=96; //initializing the array
marks[3]=90; //initializing the array
marks[4]=79; //initializing the array
System.out.println(marks[0]+","+marks[1]+","+marks[2]+","+marks[3]+","+marks[4]+","+); //Printing the values in array.
```
Functions in array
```java
array_name.length // it gives the size of array

```
Other ways of declaring array
```java
int arr[] = new int[5];
int[] arr = new int[5];
int arr[] = {1,2,3,4,5};// array creation by intialization;
```
**2D Array**
```java
String name[][]=new String[2][2];
name[0][0]="hin";
name[0][1]="abu";
name[1][0]="33hin";
name[1][1]="aeebu";
System.out.println(name[0][0]+','+name[1][1]+','+name[0][1]+','+name[1][0]+'\n'+name.length+'\n'+name[0].length);
```output
hin,aeebu,abu,33hin
2
2
```
**Drawbacks of Array**
- it only store the homogeneous data (data of same data type)
- it size remains fixed.
- it always work in continuous memory.