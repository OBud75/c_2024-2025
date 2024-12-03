#include <iostream>
#include <string>
using namespace std;

class Shape {
    public:
    	virtual int get_area() {
		return 0;
	};
};

class Rectangle : public Shape {
	int length;
	int height;

	public:
        Rectangle(int length, int height) : length(length), height(height) {};

		int get_area() override {
			return length * height;
		};
};

class Circle : public Shape {
	int rayon;

	public:
		Circle(int rayon): rayon(rayon) {};

		int get_area() override {
			return 3.14 * rayon * rayon;
		};
};

int get_area(Shape* shape) {
	return shape->get_area();
}

int main() {
	Rectangle rect(2, 4);
	Shape* rect_as_shape = &rect;
	cout << get_area(rect_as_shape) << endl;

	Circle circle(2);
	Shape* circle_as_shape = &circle;
	cout << get_area(circle_as_shape) << endl;
}
