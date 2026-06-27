#include<iostream>
#include"Windows.h"
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
class triangle : public figure {
protected:
	int a, b, c, A, B, C;	
public:
	triangle(int side_a = 5, int side_b = 6, int side_c = 7, int degree_A = 45, int degree_B = 65, int degree_C = 70) {
		a = side_a;
		b = side_b;
		c = side_c;
		A = degree_A;
		B = degree_B;
		C = degree_C;
		_sides_count = 3;

	}

	int get_degrees_A() {
		return A;
	}
	int get_degrees_B() {
		return B;
	}
	int get_degrees_C() {
		return C;
	}
	int get_sides_a() {
		return a;
	}
	int get_sides_b() {
		return b;
	}
	int get_sides_c() {
		return c;
	}
	void print_info(triangle* triangle) {
		std::cout << "Стороны: a = " << triangle->get_sides_a() << " b = " << triangle->get_sides_b()
			<< " c = " << triangle->get_sides_c() << std::endl;
		std::cout << "Углы : A = " << triangle->get_degrees_A() << " B = " << triangle->get_degrees_B()
			<< " C = " << triangle->get_degrees_C() << std::endl;
	}
};
class right_triangle : public triangle {
public:right_triangle(int a, int b, int c, int A, int B) : triangle(a,b,c,A,B,90) {
	}
};
class isosceles_triangle : public triangle {
public:isosceles_triangle(int a, int b, int c,int A, int B, int C)  {
	}
};
class equilateral_triangle : public triangle {
public:equilateral_triangle(int a, int A) {
	}
};
class quadrangle : public figure {
protected:
	int a = 10,b = 20,c = 30,d = 40,A = 50,B = 60,C = 70,D = 80;
public:
	quadrangle(int side_a = 10, int side_b = 20, int side_c = 30, int side_d = 40, int degree_A = 50, int degree_B = 60,
		int degree_C = 70, int degree_D = 80) {
		a = side_a;
		b = side_b;
		c = side_c;
		d = side_d;
		A = degree_A;
		B = degree_B;
		C = degree_C;
		D = degree_D;
		_sides_count = 4;
	}

	int get_degrees_A() {
		return A;
	}
	int get_degrees_B() {
		return B;
	}
	int get_degrees_C() {
		return C;
	}
	int get_degrees_D() {
		return D;
	}
	int get_sides_a() {
		return a;
	}
	int get_sides_b() {
		return b;
	}
	int get_sides_c() {
		return c;
	}
	int get_sides_d() {
		return d;
	}
	void print_info(quadrangle* quard) {
		std::cout << "Стороны: a = " << quard->get_sides_a() << " b = " << quard->get_sides_b()
			<< " c = " << quard->get_sides_c() << " d = " << quard->get_sides_d() << std::endl;
		std::cout << "Углы : A = " << quard->get_degrees_A() << " B = " << quard->get_degrees_B()
			<< " C = " << quard->get_degrees_C() << " D = " << quard->get_degrees_D() << std::endl;
	}
};
class rectangle :public quadrangle {
public:
	rectangle(int side_a, int side_b) : quadrangle(side_a, side_b, side_a, side_b, 90,90,90,90) {

	}
};
class square : public quadrangle {
public:
	square(int a) : quadrangle(a, a, a, a, 90, 90, 90, 90) {

	}
};
class parallelogram : public quadrangle {
public:
	parallelogram(int a, int b, int A, int B) : quadrangle(a,b,a,b,A,B,A,B){

	}
};
class rhombus : public quadrangle {
public: rhombus(int a, int A, int B) : quadrangle(a,a,a,a,A,B,A,B){

}
};
int main12() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	figure Figure;
	right_triangle RightTri(3,4,5,53,37);
	isosceles_triangle IsosTri(5, 5, 3, 70, 70, 40);
	equilateral_triangle EquiTri(5, 60);
	triangle Tri;
	quadrangle Quard;
	rectangle Rect(4, 8);
	square Square(7);
	parallelogram Paral(20, 25, 40, 50);
	rhombus Rhombus(35, 35, 65);
	std::cout << "Количество сторон: " << std::endl << "Фигура: " << Figure.get_sides_count()
		<< std::endl << "Треугольник: " << Tri.get_sides_count() << std::endl << "Четырехугольники: "
		<< Quard.get_sides_count() << std::endl << std::endl;
	std::cout << "Треугольник: " << std::endl;
	Tri.print_info(&Tri); std::cout << std::endl;
	std::cout << "Прямоугольный треугольник: " << std::endl;
	Tri.print_info(&RightTri); std::cout << std::endl;
	std::cout << "Равнобедренный треугольник " << std::endl;
	Tri.print_info(&IsosTri); std::cout << std::endl;
	std::cout << "Равносторонний треугольник " << std::endl;
	Tri.print_info(&EquiTri); std::cout << std::endl;
	std::cout << "Четырехугольник: " << std::endl;
	Quard.print_info(&Quard); std::cout << std::endl;
	std::cout << "Прямоугольник: " << std::endl;
	Rect.print_info(&Rect); std::cout << std::endl;
	std::cout << "Квадрат: " << std::endl;
	Square.print_info(&Square); std::cout << std::endl;
	std::cout << "Параллелограмм: " << std::endl;
	Paral.print_info(&Paral); std::cout << std::endl;
	std::cout << "Ромб: " << std::endl;
	Rhombus.print_info(&Rhombus); std::cout << std::endl;
	return EXIT_SUCCESS;
}