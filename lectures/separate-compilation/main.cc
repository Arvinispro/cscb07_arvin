//client code (main.cc)
import point;
import <iostream>;

int main() {
	Point p{1,2};
	std::cout << "p = (" << p.x << "," << p.y << ")" << std::endl;
	p = p + p;
	std::cout << "p + p = (" << p.x << "," << p.y << ")" << std::endl;
}
