## Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is a programming paradigm that revolves around the concept of objects. In OOP, objects are instances of classes that encapsulate both data (attributes) and the methods (functions) that operate on that data. OOP promotes the organization of code into reusable, modular units.

### 1. Encapsulation

Encapsulation is a fundamental principle in object-oriented programming that involves bundling data (attributes) and methods (functions) that operate on the data into a single unit called a class. This helps in organizing and structuring code, as well as controlling access to the data to ensure data integrity and security. Encapsulation also facilitates the concept of "information hiding," where the internal implementation details of a class are hidden from the outside world, and only a well-defined interface is exposed.

In C++, encapsulation is achieved using access specifiers like `public`, `private`, and `protected`. The `public` members of a class are accessible from anywhere, while the `private` members are only accessible within the class itself. The `protected` members are accessible within the class and its derived classes.

**Code Example:**

```cpp
class BankAccount {
private:
    double balance;
    int accountNumber;
    
public:
    BankAccount(int accNumber) {
        accountNumber = accNumber;
        balance = 0.0;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    double getBalance() {
        return balance;
    }
    
    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    BankAccount account(12345);
    account.deposit(1000);
    
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Current Balance: $" << account.getBalance() << endl;
    
    return 0;
}
```

**Output:**
```
Account Number: 12345
Current Balance: $1000
```

### 2. Inheritance

Inheritance is a core concept in object-oriented programming that allows one class (the derived class or subclass) to inherit the properties and behaviors (attributes and methods) of another class (the base class or superclass). This promotes code reusability and the creation of a hierarchical structure of classes.

In C++, inheritance is implemented using the `class` keyword followed by a colon and the access specifier, followed by the name of the base class. There are different types of inheritance, such as `public`, `private`, and `protected`, that determine the visibility of the inherited members in the derived class. 

**Code Example:**

```cpp
class Shape {
protected:
    double width;
    double height;
    
public:
    Shape(double w, double h) : width(w), height(h) {}
    
    double area() {
        return 0.0; // Base class does not have a concrete implementation
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}
    
    double area() {
        return width * height;
    }
};

int main() {
    Rectangle rectangle(5, 3);
    cout << "Rectangle Area: " << rectangle.area() << endl;
    
    return 0;
}
```

**Output:**
```
Rectangle Area: 15
```

In the given example, `Rectangle` is a subclass of `Shape`. The `Rectangle` class inherits the `width` and `height` attributes from the `Shape` class and provides its own implementation of the `area` method to calculate the area of a rectangle.

### 3. Single Inheritance

Single inheritance is a concept in object-oriented programming where a class can inherit properties and behaviors from only one parent class. In other words, a subclass (also known as derived class) can extend the functionality of a single base class. This promotes a linear hierarchy of classes, where each class has a unique parent.

**Code Example:**

```cpp
#include <iostream>

// Base class
class Shape {
public:
    void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

// Derived class inheriting from Shape
class Circle : public Shape {
public:
    void drawCircle() {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    Circle circle;
    circle.draw();         // Accessing the base class method
    circle.drawCircle();   // Accessing the derived class method
    return 0;
}
```

**Output:**
```
Drawing a shape.
Drawing a circle.
```

### 4. Multiple Inheritance

Multiple inheritance is a concept in object-oriented programming where a class can inherit properties and behaviors from more than one parent class. In this scenario, a subclass can inherit attributes and methods from multiple base classes. This allows for combining features from different sources into a single class.

**Code Example:**

```cpp
#include <iostream>

// First base class
class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

// Second base class
class Bird {
public:
    void fly() {
        std::cout << "Bird is flying." << std::endl;
    }
};

// Derived class inheriting from both Animal and Bird
class Eagle : public Animal, public Bird {
public:
    void hunt() {
        std::cout << "Eagle is hunting." << std::endl;
    }
};

int main() {
    Eagle eagle;
    eagle.eat();    // Accessing Animal's method
    eagle.fly();    // Accessing Bird's method
    eagle.hunt();   // Accessing Eagle's method
    return 0;
}
```

**Output:**
```
Animal is eating.
Bird is flying.
Eagle is hunting.
```

### 5. Hybrid Inheritance

Hybrid inheritance in C++ refers to a combination of multiple inheritance and hierarchical inheritance. It occurs when a class inherits from multiple base classes, some of which are derived from the same base class. This combination can lead to complex class hierarchies where a class has multiple paths to reach a common base class.

**Code Example:**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class display" << endl;
    }
};

class Derived1 : public Base {
public:
    void display() {
        cout << "Derived1 class display" << endl;
    }
};

class Derived2 : public Base {
public:
    void display() {
        cout << "Derived2 class display" << endl;
    }
};

class FinalDerived : public Derived1, public Derived2 {
public:
    void display() {
        cout << "FinalDerived class display" << endl;
    }
};

int main() {
    FinalDerived obj;
    
    // Ambiguity due to multiple paths to Base class
    // obj.display();  // This line will result in a compilation error
    
    obj.Derived1::display();  // Calling display of Derived1
    obj.Derived2::display();  // Calling display of Derived2
    
    return 0;
}
```

**Output:**
```
Derived1 class display
Derived2 class display
```

### 6. Hierarchical Inheritance

Hierarchical inheritance in C++ involves a single base class being inherited by multiple derived classes. This forms a hierarchy where multiple classes inherit from the same base class, leading to a branching structure.

**Code Example:**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Circle circle;
    Square square;
    
    Shape* shape1 = &circle;
    Shape* shape2 = &square;
    
    shape1->draw();  // Drawing a circle
    shape2->draw();  // Drawing a square
    
    return 0;
}
```

**Output:**
```
Drawing a circle
Drawing a square
```

### 7. Polymorphism

Polymorphism is a fundamental concept in object-oriented programming that allows objects of different classes to be treated as objects of a common base class. It enables a single interface to be used for different data types or classes, providing flexibility and reusability in code.

Polymorphism can be achieved through method overriding and method overloading.

**Method Overriding:** In method overriding, a subclass provides a specific implementation for a method that is already defined in its parent class. This allows different subclasses to have their own versions of a method while adhering to a common interface.

**Method Overloading:** Method overloading allows a class to have multiple methods with the same name but different parameters. The compiler determines which version of the method to call based on the number and types of arguments passed.

**Code Example:**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

void drawShape(Shape* shape) {
    shape->draw();
}

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    drawShape(shape1);
    drawShape(shape2);

    delete shape1;
    delete shape2;

    return 0;
}
```

**Output:**
```
Drawing a circle.
Drawing a square.
```

In this example, the `Shape` class is the base class, and `Circle` and `Square` are its subclasses. The `draw` method is overridden in both subclasses to provide specific implementations. The `drawShape` function demonstrates polymorphism by accepting a pointer to the base class and calling the appropriate `draw` method based on the actual object type. The output shows that the correct `draw` method is called for each object.



### 8. Method Overriding

Method overriding is a concept in object-oriented programming where a subclass provides a specific implementation for a method that is already defined in its superclass. This allows the subclass to customize or extend the behavior of the inherited method. When a subclass overrides a method, it provides its own implementation while maintaining the same method signature (name, parameters, and return type) as the superclass.

**Code Example:**

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    Shape* shapePtr = new Circle();
    shapePtr->draw();
    delete shapePtr;

    return 0;
}
```

**Output:**
```
Drawing a circle.
```

### 9. Method Overloading

Method overloading is the practice of defining multiple methods in a class with the same name but different parameter lists. The parameters can differ in terms of their number, types, or both. The appropriate method to be called is determined based on the arguments provided during the method call. This allows for more flexibility in calling methods and handling different input scenarios.

**Code Example:**

```cpp
#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calculator;

    std::cout << "Sum of integers: " << calculator.add(5, 7) << std::endl;
    std::cout << "Sum of doubles: " << calculator.add(3.14, 2.71) << std::endl;

    return 0;
}
```

**Output:**
```
Sum of integers: 12
Sum of doubles: 5.85
```

### 10. Abstraction

Abstraction is a fundamental concept in object-oriented programming that involves simplifying complex reality by modeling classes based on their essential characteristics. It allows you to focus on the relevant details of an object while hiding unnecessary complexities. Abstraction helps in reducing complexity, improving efficiency, and making the code easier to understand and maintain.

**Code Example:**

```cpp
#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};

// Concrete classes
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape* shapePtr;

    shapePtr = &circle;
    shapePtr->draw();  // Output: Drawing a circle.

    shapePtr = &square;
    shapePtr->draw();  // Output: Drawing a square.

    return 0;
}
```

**Output:**
```
Drawing a circle.
Drawing a square.
```

### 11. Interfaces

An interface in C++ is a class that defines a contract for other classes to follow. It specifies a set of pure virtual functions that any class implementing the interface must provide definitions for. Interfaces are used to achieve multiple inheritance, as a class can inherit from multiple interfaces. They enable a way to achieve polymorphism by allowing objects of different classes to be treated uniformly if they adhere to the same interface.

**Code Example:**

```cpp
#include <iostream>
using namespace std;

// Interface definition
class Drawable {
public:
    virtual void draw() = 0;  // Pure virtual function
};

// Classes implementing the interface
class Circle : public Drawable {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Drawable {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Drawable* drawablePtr;

    drawablePtr = &circle;
    drawablePtr->draw();  // Output: Drawing a circle.

    drawablePtr = &square;
    drawablePtr->draw();  // Output: Drawing a square.

    return 0;
}
```

**Output:**
```
Drawing a circle.
Drawing a square.
```