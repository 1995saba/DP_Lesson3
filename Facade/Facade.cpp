#include <iostream>
using namespace std;

class First {
public:
	void func() {
		cout << "First Function";
	}
	void show() {
		cout << "First Show";
	}
};

class Second {
public:
	void func() {
		cout << "Second Function";
	}
	void show() {
		cout << "Second Show";
	}
};

class Third {
public:
	void func() {
		cout << "Third Function";
	}
	void show() {
		cout << "Third Show";
	}
};

class Facade {
	First* first;
	Second* second;
	Third* third;
public:
	Facade() {
		first = new First;
		second = new Second;
		third = new Third;
	}
	void funcFirst() {
		return first->func();
	}
	void showFirst() {
		return first->show();
	}
	void funcSecond() {
		return second->func();
	}
	void showSecond() {
		return second->show();
	}
	void funcThird() {
		return third->func();
	}
	void showThird() {
		return third->show();
	}
};

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	Facade* facade = new Facade;

	facade->funcFirst();
	facade->funcSecond();
	facade->funcThird();

	facade->showFirst();
	facade->showSecond();
	facade->showThird();

	delete facade;
	cin.get();
}