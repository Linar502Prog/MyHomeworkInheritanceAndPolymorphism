class figure {
protected:
	int _sides_count = 0;
public:
	figure() {
	}
	int get_sides_count() {
		return _sides_count;
	}
	
};
class triangle : public figure{
public:
	triangle(){
		_sides_count = 3;
	}
};
class quadrangle : public figure {
public:
	quadrangle(){
		_sides_count = 4;
	}
};

#include<iostream>
#include"Windows.h"
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	figure Figure;
	triangle Triagle;
	quadrangle Reactangle;
	std::cout << "Количество сторон: " << std::endl << "Фигура: " << Figure.get_sides_count()
		<< std::endl << "Треугольник: " << Triagle.get_sides_count() << std::endl << "Четырехугольники: "
		<< Reactangle.get_sides_count() << std::endl;
	return EXIT_SUCCESS;
} 