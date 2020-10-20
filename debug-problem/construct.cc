#include <iostream>
#include <string>
#include <sstream>

class Person {
	friend std::string to_string(Person& p);
public:
	Person(int age, char sex)
		: age(age),
		sex(sex) {
	}
private:
	int age;
	const char sex;
};

std::string to_string(Person& p)
{
	std::ostringstream ss;

	ss << "age: " << p.age << std::endl;
	ss << "sex: " << p.sex << std::endl;
	return ss.str();
}

void foo()
{
	Person p(12, 'm');
	int age;

	std::cout << to_string(p) << std::endl;
}

int main()
{
	foo();
	foo();
	foo();
}
