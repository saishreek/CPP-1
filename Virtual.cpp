#include <iostream>
#include <cstdlib>
using namespace std;

class A {

    public:

        string n = "Class A";
        static int a;
        virtual void disp(){
            cout << "Name: " << n << "  Bonus: " << a << endl;
        }

};
int A::a = 10;
class B: virtual public A {

    public:

        string n = "Class B";
        static int b;
        void disp(){
            cout << "Name: " << n << "  Bonus: " << b << endl;
        }
    public:

};
int B::b = 20;
class C: virtual public A {

    public:

        string n = "Class C";
        static int c;
         void disp(){
            cout << "Name: " << n << "  Bonus: " << c << endl;
        }
    public:

};
int C::c = 30;
class D: public B, C {

    public:

        string n = "Class D";
        static int d;
         void disp(){
            cout << "Name: " << n << "  Bonus: " << d << endl;
        }
    public:

};
int D::d = 40;

void display(A *a){
    a->disp();
}

int main (){

    A * o1 = new A();
    B * o2 = new B();
    C * o3 = new C();
    D * o4 = new D();

    display(o1);
    display(o2);
    display(o3);
    display(o4);

    return 0;
}
