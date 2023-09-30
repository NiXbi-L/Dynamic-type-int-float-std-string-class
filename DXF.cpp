#include <iostream>
#include <typeinfo>
#include <string>


class dynamic {

	int* Int = nullptr;
	float* Float = nullptr;
	std::string* String = nullptr;

public:
	~dynamic() {
		if (this->Int != nullptr)delete this->Int;
		if (this->Float != nullptr)delete this->Float;
		if (this->String != nullptr)delete this->String;

	}
	// Перегрузка оператора присваивания для int
	dynamic& operator=(const int& other) {
		if (typeid(other) == typeid(int)) {
			delete Float;
			delete String;

			if (Int == nullptr) {
				Int = new int(other);
			}
			else {
				*Int = other;
			}
		}
		return *this;
	}

	// Перегрузка оператора присваивания для float
	dynamic& operator=(const float& other) {
		if (typeid(other) == typeid(float)) {
			delete Int;
			delete String;

			if (Float == nullptr) {
				Float = new float(other);
			}
			else {
				*Float = other;
			}
		}
		return *this;
	}

	// Перегрузка оператора присваивания для std::string
	dynamic& operator=(const std::string& other) {
		if (typeid(other) == typeid(std::string)) {
			delete Int;
			delete Float;

			if (String == nullptr) {
				String = new std::string(other);
			}
			else {
				*String = other;
			}
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const dynamic& c) {
		os << ((c.Int != nullptr) ? std::to_string(*c.Int) :
			(c.Float != nullptr) ? std::to_string(*c.Float) :
			(c.String != nullptr) ? *c.String : nullptr);
		return os;
	}
	auto getnum() {
		auto t = (this->Int != nullptr) ? *this->Int : *this->Float;
		return t;
	}
	auto getstr() {
		auto t = *this->String;
		return t;
	}
};

int main() {
	dynamic a;
	a = 213;
	std::cout << a;
}
