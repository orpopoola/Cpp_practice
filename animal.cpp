#include <string>
#include <iostream>

using std::cout;

// Define base class Animal
class Animal{
    public:
    std::string color;
    std::string name;
    int age;
    
    private:
    int legs;
};

// Declare derived class Snake
class Snake: public Animal {
    public:
    int length;
    void MakeSound(std::string sound){
        cout<<"snake "<< name<< " of length "<<length<< "made sound " <<sound << "\n";
    }

};

// Declare derived class Cat
class Cat : public Animal {
    public:
    int height;    
    void MakeSound(std::string sound){
        cout<<"cat "<< name<< " of height "<<height<< " made sound " << sound << "\n";
    }

};

// Test in main()
int main(){
    Snake snake;
    snake.length = 12;
    snake.age = 1;
    snake.name = "snake";
    snake.MakeSound("pissssssss");
    Cat cat;
    cat.height = 3;
    cat.name = "Tom";
    cat.MakeSound("Meeoooow");

}