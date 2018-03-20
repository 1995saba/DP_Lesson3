#include <iostream>
using namespace std;

class Subject {
public:
	virtual void dolt() = 0;
	virtual ~Subject(){}
};

class RealSubject : public Subject {
public:
	void dolt() {
		cout << "Real Subject\n";
	}
};

class Proxy {
	RealSubject * realSubj;
public:
	Proxy() {
		realSubj = new RealSubject;
	}
	void dolt() {
		cout << "Proxy\n";
		return realSubj->dolt();
	}
};

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	Proxy* proxy = new Proxy;
	proxy->dolt();
	delete proxy;

	cin.get();
}