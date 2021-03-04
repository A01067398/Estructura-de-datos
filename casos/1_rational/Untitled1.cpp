#include <iostream>
using namespace std;

class Rect {
private:
	int x, y;
public:
	void set(int, int);
	int area();
};
void Rect::set(int a, int b) {
	x = a;
	y = b;
}
int Rect::area() {
	return (x * y);
}
int main() {
	Rect r;
	r.set(3,4);
	cout << "rect area = " << r.area();
	return 0;
}
