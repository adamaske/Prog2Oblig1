#include <iostream>
#include <string>
//The base animal class
class Animal {
private:
    int Animal_ID = 0;
public:
	//Varialbles
    std::string name;
    std::string placeOfBirth;
	std::string voiceLine;
    int age = 0;
	//Virtual void the subclasses overrides
    virtual void Speak() const;
	//The animal constructor, sets the variables
	Animal(int id, std::string _name,std::string _placeOfBirth, int _age, std::string _voiceline){
		name = _name;
		placeOfBirth = _placeOfBirth;
		age = _age;
		voiceLine = _voiceline;
	};

	//Operator overloading an animal + animal, combines all their variables and returns a new animal
	Animal operator + (const Animal& obj) {
		std::string newName = this->name + obj.name;
		std::string newPoB = this->placeOfBirth + obj.placeOfBirth;
		std::string newVL = this->voiceLine + obj.voiceLine;
		int  newAge = this->age + obj.age;
		int newID = 30123;
		//Returns a Animal with the constructors 
		return Animal(newID, newName, newPoB, newAge, newVL);
	};
};

//A template class that returns the oldest animals of the 2 sent 
template <class Animal>
Animal oldest(Animal a, Animal b) {
	if (a.age > b.age) {
		return a;
	}
	else if (b.age >= a.age) {
		return b;
	}
}
//The subclasses from animal, 
class Dog : public Animal {
public:
	Dog(int id, std::string _name, std::string _placeOfBirth, int _age, std::string _voiceline) : Animal(id, _name, _placeOfBirth, _age, _voiceline) {
		name = _name;
		placeOfBirth = _placeOfBirth;
		age = _age;
		voiceLine = _voiceline;
	}
    virtual void Speak();
};

class Bird : public Animal {
public:
	Bird(int id, std::string _name, std::string _placeOfBirth, int _age, std::string _voiceline):Animal(id, _name, _placeOfBirth, _age, _voiceline) {
		name = _name;
		placeOfBirth = _placeOfBirth;
		age = _age;
		voiceLine = _voiceline;
	}
    virtual void Speak();
};
class Cat : public Animal {
public:
	Cat(int id, std::string _name, std::string _placeOfBirth, int _age, std::string _voiceline):Animal(id, _name, _placeOfBirth, _age, _voiceline) {
		name = _name;
		placeOfBirth = _placeOfBirth;
		age = _age;
		voiceLine = _voiceline;
	}
    virtual void Speak();
};

int main()
{
	//Creats pointers of dog cat and birds and initializes with the cosntructer and calls the speak  
    Dog* fido = new Dog(320, "Fido", "Arkansas", 11, "Woof Woof!");
	fido->Speak();
	Cat* kitty = new Cat(80, "Kitty", "Hamar", 4, "Moew Meow!");
	kitty->Speak();
	Bird* chripy = new Bird(3, "Peppo", "Paraguya", 1, "Chirp Chirp!");
	chripy->Speak();

	//Craeats the animal a and b, then uses the opereator overloader function to + them togeter and returns the merged ab in c
	Animal a{320, "Harald", "Kongeplassen", 99, "Hipp Hipp Hurra!"};
	Animal b{12, "Roar", "Frankia", 43, "Hei!" };
	Animal c = a + b;
	//C speaks, returns "Hipp Hipp Hurra!Hei!", the combination of a and b's c
	c.Speak();
	//Calls the template and prints the oldest's name 
	std::cout << std::endl << oldest(a, b).name << " is the oldest of the animals!";

	return 0;
}

void Dog::Speak()
{
    std::cout << voiceLine;
};
void Bird::Speak()
{
    std::cout << voiceLine;
}
void Cat::Speak()
{
    std::cout << voiceLine;
}
void Animal::Speak() const
{
	std::cout << voiceLine;
}

