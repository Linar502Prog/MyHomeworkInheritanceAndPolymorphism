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
	virtual bool check() {
		if (get_sides_count()==0) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void print_info(figure* Figure) {
		std::cout << "Ôèãóðà: " << std::endl;
		if (check() == true) {
			std::cout << "Ïðàâèëüíàÿ" << std::endl;
		}
		else {
			std::cout << "Íåïðàâèëüíàÿ " << std::endl;
		}
		std::cout << "Êîëè÷åñòâî ñòîðîí: " << Figure->get_sides_count() << std::endl << std::endl;
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
	bool check() override {
			return get_sides_count() == 3 &&
				get_degrees_A() + get_degrees_B() + get_degrees_C() == 180;
	}
	void print_info(triangle* triangle) {
		if (triangle->check() == true) {
			std::cout << "Ïðàâèëüíàÿ " << std::endl;
		}
		else {
			std::cout << "Íåïðàâèëüíàÿ " << std::endl;
		}
		std::cout << "Êîëè÷åñòâî ñòîðîí: " << triangle->get_sides_count() << std::endl;
		std::cout << "Ñòîðîíû: a = " << triangle->get_sides_a() << " b = " << triangle->get_sides_b()
			<< " c = " << triangle->get_sides_c() << std::endl;
		std::cout << "Óãëû : A = " << triangle->get_degrees_A() << " B = " << triangle->get_degrees_B()
			<< " C = " << triangle->get_degrees_C() << std::endl;
	}
};
class right_triangle : public triangle {
public:right_triangle(int a, int b, int c, int A, int B, int C) : triangle(a, b, c, A, B, C){

	}
	  bool check() override {
		  return triangle::check() &&  C == 90;
	  }
};
class isosceles_triangle : public triangle {
public:isosceles_triangle(int a, int b, int c, int A, int B, int C) : triangle(a, b, c, A, B, C) {
}
	  bool check() override {
		  return triangle::check() && a == b && A == B;
	  }
};
class equilateral_triangle : public triangle {
public:equilateral_triangle(int a, int b, int c, int A, int B, int C) : triangle(a, b, c, A, B, C) {
}
	  bool check() override {
		  return triangle::check() && a == b && b == c && A == B && B == C;
	  }
};
class quadrangle : public figure {
protected:
	int a = 10, b = 20, c = 30, d = 40, A = 50, B = 60, C = 70, D = 80;
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
	bool check() override {
		return get_sides_count() == 4 &&
			get_degrees_A() + get_degrees_B() + get_degrees_C() + get_degrees_D() == 360;
	}
	void print_info(quadrangle* quard) {
		if (quard->check() == true) {
			std::cout << "Ïðàâèëüíàÿ " << std::endl;
		}
		else {
			std::cout << "Íåïðàâèëüíàÿ" << std::endl;
		}
		std::cout << "Êîëè÷åñòâî ñòîðîí: " << quard->get_sides_count() << std::endl;
		std::cout << "Ñòîðîíû: a = " << quard->get_sides_a() << " b = " << quard->get_sides_b()
			<< " c = " << quard->get_sides_c() << " d = " << quard->get_sides_d() << std::endl;
		std::cout << "Óãëû : A = " << quard->get_degrees_A() << " B = " << quard->get_degrees_B()
			<< " C = " << quard->get_degrees_C() << " D = " << quard->get_degrees_D() << std::endl;
	}
};
class rectangle :public quadrangle {
public:
	rectangle(int side_a, int side_b, int side_c, int side_d, int degree_A, int degree_B, int degree_C, int degree_D) : 
		quadrangle(side_a, side_b, side_c, side_d,degree_A,degree_B,degree_C,degree_D) {
	}
	bool check() override {
		return quadrangle::check() && a == c && b == d && A == B && B == C && C == D && D == 90;
	}
};
class square : public quadrangle {
public:
	square(int side_a, int side_b, int side_c, int side_d, int degree_A, int degree_B, int degree_C, int degree_D) :
		quadrangle(side_a, side_b, side_c, side_d, degree_A, degree_B, degree_C, degree_D) {
	}
	bool check() override {
		return quadrangle::check() && a == b && b == c && c == d && A == B && B == C && C== D;
	}
};
class parallelogram : public quadrangle {
public:
	parallelogram(int side_a, int side_b, int side_c, int side_d, int degree_A, int degree_B, int degree_C, int degree_D) :
		quadrangle(side_a, side_b, side_c, side_d, degree_A, degree_B, degree_C, degree_D) {
	}
	bool check() override {
		return quadrangle::check() && a == c && b == d && A == C && B == D;
	}

};
class rhombus : public quadrangle {
public: rhombus(int side_a, int side_b, int side_c, int side_d, int degree_A, int degree_B, int degree_C, int degree_D) :
	quadrangle(side_a, side_b, side_c, side_d, degree_A, degree_B, degree_C, degree_D) {
}
	  bool check() override {
		  return quadrangle::check() && a == b && b == c && c == d && A == C && B == D;
	  }
};
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	figure Figure;
	right_triangle RightTri(3, 4, 5, 50, 60,90);
	isosceles_triangle IsosTri(5, 5, 3, 70, 70, 41);
	equilateral_triangle EquiTri(5, 5, 5, 60, 60, 60);
	triangle Tri;
	quadrangle Quard;
	rectangle Rect(4, 8,4,8,90,90,90,90);
	square Square(7,7,7,7,90,90,90,90);
	parallelogram Paral(20, 25,20,25,100, 80, 55, 125);
	rhombus Rhombus(30, 30, 30,30,50,50,50,50);
	Figure.print_info(&Figure);
	std::cout << "Òðåóãîëüíèê: " << std::endl;
	Tri.print_info(&Tri); std::cout << std::endl;
	std::cout << "Ïðÿìîóãîëüíûé òðåóãîëüíèê: " << std::endl;
	Tri.print_info(&RightTri); std::cout << std::endl;
	std::cout << "Ðàâíîáåäðåííûé òðåóãîëüíèê " << std::endl;
	Tri.print_info(&IsosTri); std::cout << std::endl;
	std::cout << "Ðàâíîñòîðîííèé òðåóãîëüíèê " << std::endl;
	Tri.print_info(&EquiTri); std::cout << std::endl;
	std::cout << "×åòûðåõóãîëüíèê: " << std::endl;
	Quard.print_info(&Quard); std::cout << std::endl;
	std::cout << "Ïðÿìîóãîëüíèê: " << std::endl;
	Rect.print_info(&Rect); std::cout << std::endl;
	std::cout << "Êâàäðàò: " << std::endl;
	Square.print_info(&Square); std::cout << std::endl;
	std::cout << "Ïàðàëëåëîãðàìì: " << std::endl;
	Paral.print_info(&Paral); std::cout << std::endl;
	std::cout << "Ðîìá: " << std::endl;
	Rhombus.print_info(&Rhombus); std::cout << std::endl;
	return EXIT_SUCCESS;
}
