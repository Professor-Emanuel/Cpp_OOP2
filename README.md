# Cpp_OOP2
Independent Programs showcasing OOP Principles!

https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm

The main purpose of C++ programming is to add object orientation to the C programming language and classes are the central feature of C++ that supports object-oriented programming and are often called user-defined types.

A class is used to specify the form of an object and it combines data representation and methods for manipulating that data into one neat package. The data and functions within a class are called members of the class.

C++ Class Definitions
When you define a class, you define a blueprint for a data type. This doesn't actually define any data, but it does define what the class name means, that is, what an object of the class will consist of and what operations can be performed on such an object.

A class definition starts with the keyword class followed by the class name; and the class body, enclosed by a pair of curly braces. A class definition must be followed either by a semicolon or a list of declarations.

Define C++ Objects
A class provides the blueprints for objects, so basically an object is created from a class. We declare objects of a class with exactly the same sort of declaration that we declare variables of basic types.

Accessing the Data Members
The public data members of objects of a class can be accessed using the direct member access operator (.)

It is important to note that private and protected members can not be accessed directly using direct member access operator (.). We will learn how private and protected members can be accessed.


C++ Class Member Functions

A member function of a class is a function that has its definition or its prototype within the class definition like any other variable. It operates on any object of the class of which it is a member, and has access to all the members of a class for that object.

Member functions can be defined within the class definition or separately using scope resolution operator, : −. Defining a member function within the class definition declares the function inline, even if you do not use the inline specifier. So either you can define Volume() function as below −

class Box {
   public:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
   
      double getVolume(void) {
         return length * breadth * height;
      }
};

If you like, you can define the same function outside the class using the scope resolution operator (::) as follows −

double Box::getVolume(void) {
   return length * breadth * height;
}


C++ Class Access Modifiers

Data hiding is one of the important features of Object Oriented Programming which allows preventing the functions of a program to access directly the internal representation of a class type. The access restriction to the class members is specified by the labeled public, private, and protected sections within the class body. The keywords public, private, and protected are called access specifiers.

A class can have multiple public, protected, or private labeled sections. Each section remains in effect until either another section label or the closing right brace of the class body is seen. The default access for members and classes is private.

The public Members
A public member is accessible from anywhere outside the class but within a program. You can set and get the value of public variables without any member function

The private Members
A private member variable or function cannot be accessed, or even viewed from outside the class. Only the class and friend functions can access private members.

By default all the members of a class would be private, for example in the following class width is a private member, which means until you label a member, it will be assumed a private member −

class Box {
   double width;
   
   public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
};


Practically, we define data in private section and related functions in public section so that they can be called from outside of the class

The protected Members
A protected member variable or function is very similar to a private member but it provided one additional benefit that they can be accessed in child classes which are called derived classes.

C++ Class Constructor and Destructor

The Class Constructor
A class constructor is a special member function of a class that is executed whenever we create new objects of that class.

A constructor will have exact same name as the class and it does not have any return type at all, not even void. Constructors can be very useful for setting initial values for certain member variables.

Parameterized Constructor
A default constructor does not have any parameter, but if you need, a constructor can have parameters. This helps you to assign initial value to an object at the time of its creation

Using Initialization Lists to Initialize Fields
In case of parameterized constructor, you can use following syntax to initialize the fields −

Line::Line( double len): length(len) {
   cout << "Object is being created, length = " << len << endl;
}
Above syntax is equal to the following syntax −

Line::Line( double len) {
   cout << "Object is being created, length = " << len << endl;
   length = len;
}

If for a class C, you have multiple fields X, Y, Z, etc., to be initialized, then use can use same syntax and separate the fields by comma as follows −

C::C( double a, double b, double c): X(a), Y(b), Z(c) {
   ....
}

The Class Destructor
A destructor is a special member function of a class that is executed whenever an object of it's class goes out of scope or whenever the delete expression is applied to a pointer to the object of that class.

A destructor will have exact same name as the class prefixed with a tilde (~) and it can neither return a value nor can it take any parameters. Destructor can be very useful for releasing resources before coming out of the program like closing files, releasing memories etc.


C++ Copy Constructor

The copy constructor is a constructor which creates an object by initializing it with an object of the same class, which has been created previously. The copy constructor is used to −

Initialize one object from another of the same type.
Copy an object to pass it as an argument to a function.
Copy an object to return it from a function.
If a copy constructor is not defined in a class, the compiler itself defines one.If the class has pointer variables and has some dynamic memory allocations, then it is a must to have a copy constructor. The most common form of copy constructor is shown here −

classname (const classname &obj) {
   // body of constructor
}
Here, obj is a reference to an object that is being used to initialize another object.

C++ Friend Functions

A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

A friend can be a function, function template, or member function, or a class or class template, in which case the entire class and all of its members are friends.

To declare a function as a friend of a class, precede the function prototype in the class definition with keyword friend as follows −

class Box {
   double width;
   
   public:
      double length;
      friend void printWidth( Box box );
      void setWidth( double wid );
};
To declare all member functions of class ClassTwo as friends of class ClassOne, place a following declaration in the definition of class ClassOne −

friend class ClassTwo;

C++ Inline Functions

C++ inline function is powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

Any change to an inline function could require all clients of the function to be recompiled because compiler would need to replace all the code once again otherwise it will continue with old functionality.

To inline a function, place the keyword inline before the function name and define the function before any calls are made to the function. The compiler can ignore the inline qualifier in case defined function is more than a line.

A function definition in a class definition is an inline function definition, even without the use of the inline specifier.

C++ this Pointer

Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions. Therefore, inside a member function, this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.

Pointer to C++ Classes

A pointer to a C++ class is done exactly the same way as a pointer to a structure and to access members of a pointer to a class you use the member access operator -> operator, just as you do with pointers to structures. Also as with all pointers, you must initialize the pointer before using it.

Static Members of a C++ Class

We can define class members static using static keyword. When we declare a member of a class as static it means no matter how many objects of the class are created, there is only one copy of the static member.

A static member is shared by all objects of the class. All static data is initialized to zero when the first object is created, if no other initialization is present. We can't put it in the class definition but it can be initialized outside the class as done in the following example by redeclaring the static variable, using the scope resolution operator :: to identify which class it belongs to.

#include <iostream>
 
using namespace std;

class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         
         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects.
   cout << "Total objects: " << Box::objectCount << endl;

   return 0;
}
  
Static Function Members
By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.

A static member function can only access static data member, other static member functions and any other functions from outside the class.

Static member functions have a class scope and they do not have access to the this pointer of the class. You could use a static member function to determine whether some objects of the class have been created or not.

https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
  
C++ Inheritance
   
One of the most important concepts in object-oriented programming is that of inheritance. Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application. This also provides an opportunity to reuse the code functionality and fast implementation time.

When creating a class, instead of writing completely new data members and member functions, the programmer can designate that the new class should inherit the members of an existing class. This existing class is called the base class, and the new class is referred to as the derived class.

The idea of inheritance implements the is a relationship. For example, mammal IS-A animal, dog IS-A mammal hence dog IS-A animal as well and so on.

Base and Derived Classes
A class can be derived from more than one classes, which means it can inherit data and functions from multiple base classes. To define a derived class, we use a class derivation list to specify the base class(es). A class derivation list names one or more base classes and has the form −

class derived-class: access-specifier base-class
Where access-specifier is one of public, protected, or private, and base-class is the name of a previously defined class. If the access-specifier is not used, then it is private by default.
   
Access Control and Inheritance
A derived class can access all the non-private members of its base class. Thus base-class members that should not be accessible to the member functions of derived classes should be declared private in the base class.

We can summarize the different access types according to - who can access them in the following way −

Access	         public	protected	private
Same class	      yes	   yes	      yes
Derived classes	yes	   yes	      no
Outside classes	yes	   no       	no
A derived class inherits all base class methods with the following exceptions −

Constructors, destructors and copy constructors of the base class.
Overloaded operators of the base class.
The friend functions of the base class.
Type of Inheritance
When deriving a class from a base class, the base class may be inherited through public, protected or private inheritance. The type of inheritance is specified by the access-specifier as explained above.

We hardly use protected or private inheritance, but public inheritance is commonly used. While using different type of inheritance, following rules are applied −

Public Inheritance − When deriving a class from a public base class, public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.

Protected Inheritance − When deriving from a protected base class, public and protected members of the base class become protected members of the derived class.

Private Inheritance − When deriving from a private base class, public and protected members of the base class become private members of the derived class.

   
Multiple Inheritance
A C++ class can inherit members from more than one class and here is the extended syntax −

class derived-class: access baseA, access baseB....
Where access is one of public, protected, or private and would be given for every base class and they will be separated by comma as shown above
   
   
https://www.geeksforgeeks.org/inheritance-in-c/
   

The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming. 

Inheritance is a feature or a process in which, new classes are created from the existing classes. The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”. The derived class now is said to be inherited from the base class.

When we say derived class inherits the base class, it means, the derived class inherits all the properties of the base class, without changing the properties of base class and may add new features to its own. These new features in the derived class will not affect the base class. The derived class is the specialized class for the base class.

Sub Class: The class that inherits properties from another class is called Subclass or Derived Class. 
Super Class: The class whose properties are inherited by a subclass is called Base Class or Superclass. 
   
1. Why and when to use inheritance?
2. Modes of Inheritance
3. Types of Inheritance
   
Why and when to use inheritance?
Consider a group of vehicles. You need to create classes for Bus, Car, and Truck. The methods fuelAmount(), capacity(), applyBrakes() will be the same for all three classes. If we create these classes avoiding inheritance then we have to write all of these functions in each of the three classes.

You can clearly see that the above process results in duplication of the same code 3 times. This increases the chances of error and data redundancy. To avoid this type of situation, inheritance is used. If we create a class Vehicle and write these three functions in it and inherit the rest of the classes from the vehicle class, then we can simply avoid the duplication of data and increase re-usability. 
   
Using inheritance, we have to write the functions only one time instead of three times as we have inherited the rest of the three classes from the base class (Vehicle).
Implementing inheritance in C++: For creating a sub-class that is inherited from the base class we have to follow the below syntax. 

Derived Classes: A Derived class is defined as the class derived from the base class.
Syntax: 

class  <derived_class_name> : <access-specifier> <base_class_name>
{
        //body
}
Where
class      — keyword to create a new class
derived_class_name   — name of the new class, which will inherit the base class
access-specifier  — either of private, public or protected. If neither is specified, PRIVATE is taken as default
base-class-name  — name of the base class
Note: A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.

Example:
1. class ABC : private XYZ              //private derivation
            {                }
2. class ABC : public XYZ              //public derivation
            {               }
3. class ABC : protected XYZ              //protected derivation
            {              }
4. class ABC: XYZ                            //private derivation by default
{            }
   
   
Note:
o When a base class is privately inherited by the derived class, public members of the base class becomes the private members of the derived class and therefore, the public members of the base class can only be accessed by the member functions of the derived class. They are inaccessible to the objects of the derived class.
o On the other hand, when the base class is publicly inherited by the derived class, public members of the base class also become the public members of the derived class. Therefore, the public members of the base class are accessible by the objects of the derived class as well as by the member functions of the derived class.
   
   
Modes of Inheritance: There are 3 modes of inheritance.

Public Mode: If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.

Protected Mode: If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become protected in the derived class.

Private Mode: If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become Private in the derived class.
   
Types Of Inheritance:
   
1.Single inheritance
2.Multilevel inheritance
3.Multiple inheritance
4.Hierarchical inheritance
5.Hybrid inheritance
   
   
1. Single Inheritance: In single inheritance, a class is allowed to inherit from only one class. i.e. one subclass is inherited by one base class only.
   
2. Multiple Inheritance: Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one subclass is inherited from more than one base class.
   
3. Multilevel Inheritance: In this type of inheritance, a derived class is created from another derived class
   
4. Hierarchical Inheritance: In this type of inheritance, more than one subclass is inherited from a single base class. i.e. more than one derived class is created from a single base class.
   
5. Hybrid (Virtual) Inheritance: Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple Inheritance.
   
6. A special case of hybrid inheritance: Multipath inheritance: 
A derived class with two base classes and these two base classes have one common base class is called multipath inheritance. Ambiguity can arise in this type of inheritance. 
   
https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

C++ Overloading (Operator and Function)
   
C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).

When you call an overloaded function or operator, the compiler determines the most appropriate definition to use, by comparing the argument types you have used to call the function or operator with the parameter types specified in the definitions. The process of selecting the most appropriate overloaded function or operator is called overload resolution.

Function Overloading in C++
You can have multiple definitions for the same function name in the same scope. The definition of the function must differ from each other by the types and/or the number of arguments in the argument list. You cannot overload function declarations that differ only by return type.
   
https://www.geeksforgeeks.org/function-overloading-c/
   
Function overloading is a feature of object-oriented programming where two or more functions can have the same name but different parameters. When a function name is overloaded with different jobs it is called Function Overloading. In Function Overloading “Function” name should be the same and the arguments should be different. Function overloading can be considered as an example of a polymorphism feature in C++.
   
Function Overriding (achieved at run time)
It is the redefinition of base class function in its derived class with same signature i.e return type and parameters. 
   
https://www.geeksforgeeks.org/function-overloading-vs-function-overriding-in-cpp/?ref=rp
   
Function Overloading VS Function Overriding:

1. Inheritance: Overriding of functions occurs when one class is inherited from another class. Overloading can occur without inheritance.
2. Function Signature: Overloaded functions must differ in function signature ie either number of parameters or type of parameters should differ. In overriding, function signatures must be same.
3. Scope of functions: Overridden functions are in different scopes; whereas overloaded functions are in same scope.
4. Behavior of functions: Overriding is needed when derived class function has to do some added or different job than the base class function. Overloading is used to have same name functions which behave differently depending upon parameters passed to them.
5. Execution: Function overloading takes place at compile time so known as compile time polymorphism and Function Overriding occurs at run time so known as run time polymorphism.
   
https://www.geeksforgeeks.org/difference-between-inheritance-and-polymorphism/?ref=rp
   
https://www.geeksforgeeks.org/runtime-polymorphism-in-various-types-of-inheritance-in-c/?ref=rp
   

Operators Overloading in C++
You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

Box operator+(const Box&);
declares the addition operator that can be used to add two Box objects and returns final Box object. Most overloaded operators may be defined as ordinary non-member functions or as class member functions. In case we define above function as non-member function of a class then we would have to pass two arguments for each operand as follows −

Box operator+(const Box&, const Box&);
Following is the example to show the concept of operator over loading using a member function. Here an object is passed as an argument whose properties will be accessed using this object, the object which will call this operator can be accessed using this operator 
   
 
Overloadable/Non-overloadableOperators
Following is the list of operators which can be overloaded −

+	-	*	/	%	^
&	|	~	!	,	=
<	>	<=	>=	++	--
<<	>>	==	!=	&&	||
+=	-=	/=	%=	^=	&=
|=	*=	<<=	>>=	[]	()
->	->*	new	new []	delete	delete []
Following is the list of operators, which can not be overloaded −

::	.*	.	?:
   

Unary Operators Overloading in C++
   
The unary operators operate on a single operand and following are the examples of Unary operators −

The increment (++) and decrement (--) operators.
The unary minus (-) operator.
The logical not (!) operator.
The unary operators operate on the object for which they were called and normally, this operator appears on the left side of the object, as in !obj, -obj, and ++obj but sometime they can be used as postfix as well like obj++ or obj--.
   
Binary Operators Overloading in C++
   
The binary operators take two arguments and following are the examples of Binary operators. You use binary operators very frequently like addition (+) operator, subtraction (-) operator and division (/) operator.
   

Relational Operators Overloading in C++
   
There are various relational operators supported by C++ language like (<, >, <=, >=, ==, etc.) which can be used to compare C++ built-in data types.

You can overload any of these operators, which can be used to compare the objects of a class.
   
   
Input/Output Operators Overloading in C++
   
C++ is able to input and output the built-in data types using the stream extraction operator >> and the stream insertion operator <<. The stream insertion and stream extraction operators also can be overloaded to perform input and output for user-defined types like an object.

Here, it is important to make operator overloading function a friend of the class because it would be called without creating an object.
   
Overloading Increment ++ & Decrement --
   
The increment (++) and decrement (--) operators are two important unary operators available in C++.
   
   
Assignment Operators Overloading in C++
   
You can overload the assignment operator (=) just as you can other operators and it can be used to create an object just like the copy constructor.
   
   
Function Call Operator () Overloading in C++
   
The function call operator () can be overloaded for objects of class type. When you overload ( ), you are not creating a new way to call a function. Rather, you are creating an operator function that can be passed an arbitrary number of parameters.
   
Subscripting [] Operator Overloading in C++
   
The subscript operator [] is normally used to access array elements. This operator can be overloaded to enhance the existing functionality of C++ arrays.
   
   
Class Member Access Operator (->) Overloading in C++
   
The class member access operator (->) can be overloaded but it is bit trickier. It is defined to give a class type a "pointer-like" behavior. The operator -> must be a member function. If used, its return type must be a pointer or an object of a class to which you can apply.

The operator-> is used often in conjunction with the pointer-dereference operator * to implement "smart pointers." These pointers are objects that behave like normal pointers except they perform other tasks when you access an object through them, such as automatic object deletion either when the pointer is destroyed, or the pointer is used to point to another object.

The dereferencing operator-> can be defined as a unary postfix operator. That is, given a class −

class Ptr {
   //...
   X * operator->();
};
Objects of class Ptr can be used to access members of class X in a very similar manner to the way pointers are used. For example −

void f(Ptr p ) {
   p->m = 10 ; // (p.operator->())->m = 10
}
The statement p->m is interpreted as (p.operator->())->m.
   
   
https://www.geeksforgeeks.org/operator-overloading-c/
   
   
In C++, we can make operators work for user-defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +. Other example classes where arithmetic operators may be overloaded are Complex Numbers, Fractional Numbers, Big Integer, etc.

Operator overloading is a compile-time polymorphism. It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.
   
class A
{

};

int main()
{
      A   a1,a2,a3;

      a3= a1 + a2;

      return 0;
}

In this example, we have 3 variables “a1”, “a2” and “a3” of type “class A”. Here we are trying to add two objects “a1” and “a2”, which are of user-defined type i.e. of type “class A” using the “+” operator. This is not allowed, because the addition operator “+” is predefined to operate only on built-in data types. But here, “class A” is a user-defined type, so the compiler generates an error. This is where the concept of “Operator overloading” comes in. 
Now, if the user wants to make the operator “+” to add two class objects, the user has to redefine the meaning of the “+” operator such that it adds two class objects. This is done by using the concept “Operator overloading”. So the main idea behind “Operator overloading” is to use c++ operators with class variables or class objects. Redefining the meaning of operators really does not change their original meaning; instead, they have been given additional meaning along with their existing ones.
   
  
What is the difference between operator functions and normal functions? 
Operator functions are the same as normal functions. The only differences are, that the name of an operator function is always the operator keyword followed by the symbol of the operator and operator functions are called when the corresponding operator is used.
   
   
Can we overload all operators? 
Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded. 

sizeof
typeid
Scope resolution (::)
Class member access operators (.(dot), .* (pointer to member operator))
Ternary or conditional (?:)
   
Why can’t the above-stated operators be overloaded?

1. sizeof – This returns the size of the object or datatype entered as the operand. This is evaluated by the compiler and cannot be evaluated during runtime. The proper incrementing of a pointer in an array of objects relies on the sizeof operator implicitly. Altering its meaning using overloading would cause a fundamental part of the language to collapse.

2. typeid: This provides a CPP program with the ability to recover the actual derived type of the object referred to by a pointer or reference. For this operator, the whole point is to uniquely identify a type. If we want to make a user-defined type ‘look’ like another type, polymorphism can be used but the meaning of the typeid operator must remain unaltered, or else serious issues could arise.

3. Scope resolution (::): This helps identify and specify the context to which an identifier refers by specifying a namespace. It is completely evaluated at runtime and works on names rather than values. The operands of scope resolution are note expressions with data types and CPP has no syntax for capturing them if it were overloaded. So it is syntactically impossible to overload this operator.

4. Class member access operators (.(dot), .* (pointer to member operator)): 
   
5. Ternary or conditional (?:): The ternary or conditional operator is a shorthand representation of an if-else statement. In the operator, the true/false expressions are only evaluated on the basis of the truth value of the conditional expression. 

conditional statement ? expression1 (if statement is TRUE) : expression2 (else)

A function overloading the ternary operator for a class say ABC using the definition

ABC operator ?: (bool condition, ABC trueExpr, ABC falseExpr);

would not be able to guarantee that only one of the expressions was evaluated. Thus, the ternary operator cannot be overloaded.
   
Important points about operator overloading 
1) For operator overloading to work, at least one of the operands must be a user-defined class object.
2) Assignment Operator: Compiler automatically creates a default assignment operator with every class. The default assignment operator does assign all members of the right side to the left side and works fine in most cases (this behaviour is the same as the copy constructor). See this for more details. 
3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type. 
   
Overloaded conversion operators must be a member method. Other operators can either be the member method or the global method.
4) Any constructor that can be called with a single argument works as a conversion constructor, which means it can also be used for implicit conversion to the class being constructed. 
   

   
https://www.geeksforgeeks.org/smart-pointers-cpp/
   
   
C++ STL Tutorial

https://www.tutorialspoint.com/cplusplus/cpp_stl_tutorial.htm
   
The C++ STL (Standard Template Library) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

At the core of the C++ Standard Template Library are following three well-structured components −

Sr.No	Component & Description
1	
Containers

Containers are used to manage collections of objects of a certain kind. There are several different types of containers like deque, list, vector, map etc.

2	
Algorithms

Algorithms act on containers. They provide the means by which you will perform initialization, sorting, searching, and transforming of the contents of containers.

3	
Iterators

Iterators are used to step through the elements of collections of objects. These collections may be containers or subsets of containers.

We will discuss about all the three C++ STL components in next chapter while discussing C++ Standard Library. For now, keep in mind that all the three components have a rich set of pre-defined functions which help us in doing complicated tasks in very easy fashion.

Let us take the following program that demonstrates the vector container (a C++ Standard Template) which is similar to an array with an exception that it automatically handles its own storage requirements in case it grows 
   
   
https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
   
Sort in C++ Standard Template Library (STL)
https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
   
Sorting is one of the most basic functions applied to data. It means arranging the data in a particular fashion, which can be increasing or decreasing. There is a builtin function in C++ STL by the name of sort(). 
This function internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time, it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort. 
   
Binary Search in C++ Standard Template Library (STL)
https://www.geeksforgeeks.org/binary-search-algorithms-the-c-standard-template-library-stl/
   
Binary search is a widely used searching algorithm that requires the array to be sorted before search is applied. The main idea behind this algorithm is to keep dividing the array in half (divide and conquer) until the element is found, or all the elements are exhausted.
It works by comparing the middle item of the array with our target, if it matches, it returns true otherwise if the middle term is greater than the target, the search is performed in the left sub-array. 
If the middle term is less than the target, the search is performed in the right sub-array.
   
   
https://www.youtube.com/watch?v=vohuRrwbTT4&ab_channel=ReelLearning
   
   
Algorithm Library | C++ Magicians STL Algorithm
https://www.geeksforgeeks.org/c-magicians-stl-algorithms/
   
   
For all those who aspire to excel in competitive programming, only having a knowledge about containers of STL is of less use till one is not aware what all STL has to offer. 
STL has an ocean of algorithms, for all < algorithm > library functions : Refer here: https://www.geeksforgeeks.org/algorithms-library-c-stl/
Some of the most used algorithms on vectors and most useful one’s in Competitive Programming are mentioned as follows :

Non-Manipulating Algorithms

1.sort(first_iterator, last_iterator) – To sort the given vector.
2.sort(first_iterator, last_iterator, greater<int>()) – To sort the given container/vector in descending order
3.reverse(first_iterator, last_iterator) – To reverse a vector. ( if ascending -> descending  OR  if descending -> ascending)
4.*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
5.*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
6.accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements
7.count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
8. find(first_iterator, last_iterator, x) – Returns an iterator to the first occurrence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
9. binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not.
10. lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which         has a value not less than ‘x’.
11. upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last)                  which has a value greater than ‘x’.    
   

Some Manipulating Algorithms

1.arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
2.arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.
3. next_permutation(first_iterator, last_iterator) – This modified the vector to its next permutation.
4. prev_permutation(first_iterator, last_iterator) – This modified the vector to its previous permutation. 
5. distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function               is very useful while finding the index.    
   
   
Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and iota)
https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/
   
   
std::partition in C++ STL
https://www.geeksforgeeks.org/stdpartition-in-c-stl/
   
   

   
