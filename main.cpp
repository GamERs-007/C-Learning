#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;

    virtual void speak() {
        std::cout << "Animal sound\n";
    };
};

class Dog: public Animal {
    void speak() final override {
        std::cout << "Dog barks\n";
    }
};

// class BabyDog : public dog{}; //causing error cuz final

class Cat: public Animal {
    void speak() override {
        std::cout << "Cat meows\n";
    }
};

class Walker : virtual public Animal{

};

class Swimmer : virtual public Animal{

};

class Amphibian : public Walker, public Swimmer {
public:
    int age;
};



int main() {
    Animal* ptr1 = new Dog();
    Animal* ptr2 = new Cat();

    ptr1->speak();
    ptr2->speak();

    Amphibian a;
    a.age = 5;
    std::cout << a.age;

    return 0;
}