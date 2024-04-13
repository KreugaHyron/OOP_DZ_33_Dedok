#include <iostream>
#include <vector>
using namespace std;
class Animal {
    public:
		virtual void voice() const = 0;
};
class Frog : public Animal {
	public:
		void voice() const override {
			cout << "Ribbit!" << endl;
		}
};
class Dog : public Animal {
	public:
		void voice() const override {
			cout << "Woof!" << endl;
		}
};
class Cat : public Animal {
	public:
		void voice() const override {
			cout << "Meow!" << endl;
		}
		void scratch(bool homework_done) {
			if (homework_done) {
				cout << "Scratch!" << endl;
			}
			else {
				cout << "Meow!" << endl;
			}
		}
		void purr() {
			cout << "Purr!" << endl;
		}
};
int main()
{
    vector<Animal*> animals;
	animals.push_back(new Frog());
	animals.push_back(new Dog());
	animals.push_back(new Cat());
	for (const auto& animal : animals) {
		animal->voice();
	}
	Cat* cat = dynamic_cast<Cat*>(animals[2]);
	if (cat) {
		cat->scratch(false);
		cat->purr();
	}
	for (const auto& animal : animals) {
		delete animal;
	}
	return 0;
}
