Задание №2
Используя механизм множественного наследования разработайте класс “Автомобиль”.Должны быть классы “Колеса», «Двигатель», «Двери» и т.д.


#include <iostream>
using namespace std;

class Wheels
{
protected:
	int A; // радиус
public:
	Wheels() : A(0) {	}
	Wheels(int a) : A(a) {}
	void Print() { cout << "Radius = " << A << endl; }
	~Wheels() { 	}
};

class Engine {
protected:
	int B; // объем двигатель автомобиля 
public:
	Engine() :B(0) {	}
	Engine(int b) { B = b; }
	void Print() { cout << "Obem dvigatelya = " << B << endl; }
	~Engine() {	}
};

class Doors {
protected:
	char* C; // цвет
public:
	Doors() :C(0) {	}
	Doors(const char* c) { C = _strdup(c); }
	void Print() { cout << "Color = " << C << endl; }
	~Doors() { delete[] C; }
};

class Car :public Wheels, public Engine, public Doors {
	char* MODEL;
public:
	Car() :MODEL(0) {	}
	Car(const char* model) { MODEL = _strdup(model); }
	Car(int a, int b, const char* c, const char* model) : Wheels(a), Engine(b), Doors(c) { MODEL = _strdup(model); }
	void Print() {
		Wheels::Print();
		Engine::Print();
		Doors::Print();
		cout << "MODEL = " << MODEL << endl;
	}
	~Car() { delete[] MODEL; }
};

int main() {
	Car A(18, 2500, "Black", "Dodge Challenger");
	A.Print();
}
