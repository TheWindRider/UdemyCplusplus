//============================================================================
// Name        : Abstract&Virtual.cpp
// Author      : Chenguang Yang

// Description : Udemy exercise
//============================================================================

#include <iostream>

using namespace std;

class Animal {
    public:
    /* =0: subclass with methods implemented can be instantialized */
    virtual void speak()=0;
    virtual void run()=0;
};

class Dog: public Animal {
    public:
    virtual void speak() {
        cout << "Woof" << endl;
    }
};

class Bulldog: public Dog {
    public:
    virtual void run() {
        cout << "Run like a bull" << endl;
    }
};
/* similar to pointer, reference of abstract class works too */
bool doesSpeak(Animal &anAnimal) {
    anAnimal.speak();
    return true;
}

int main()
{
    /* First 2 lines won't complie */
//    Animal anAnimal;
//    Dog thisDog;
    Bulldog myDog;
    myDog.run();
    myDog.speak();

    /* Array of abstract class won't complie either */
//    Dog dogs[3];
    Bulldog myDogSquat[3];
    doesSpeak(myDogSquat[0]);
    /* But array of abstract class pointer works */
    Animal *animalGroup[3];
    animalGroup[0] = &myDogSquat[0];
    animalGroup[0] -> run();

    return 0;
}
