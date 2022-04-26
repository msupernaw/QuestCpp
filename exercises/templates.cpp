#include <iostream>

template<class T>
void swap(T& a, T& b)
{
    std::cout<<"line 6:"<<std::endl;
    T tmp = a;
    std::cout<<"line 8:"<<std::endl;

    a = b;
    b = tmp;
}


class MyClass{

    public:
        int a;
        int b;

        MyClass(int a, int b){
            this->a = a;
            this->b = b;
        }

        MyClass(const MyClass& other){
            this->a = other.a;
            this->b = other.b;
        }



    
};

template<class T2>
class MyClass2{
    public:
        T2 a;
        T2 b;

    MyClass2(const T2 a, const T2 b){
        this->a = a;
        this->b = b;
    }

    MyClass2(const MyClass2& other){
        std::cout<<"copy constructor"<<std::endl;
        a = other.a;
        b = other.b;
    }

        template<class T3>
        MyClass2(const MyClass2<T3>& other){
        std::cout<<"copy constructor"<<std::endl;
        a = static_cast<T2>(other.a);
        b = static_cast<T2>(other.b);
    }
};

//next week talk about typedefs
int main()
{
    int a = 10;
    int b = 20;
    swap<int>(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    double c = 10.0;
    double d = 20.0;
    swap<double>(c, d);
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    MyClass e(10, 20);
    MyClass f(30, 40);
    swap<MyClass>(e, f);

    std::cout << e.a << std::endl;  
    std::cout << e.b << std::endl;

    MyClass2<float> g(10.0,20.0);
    MyClass2<int> h(30.0,40.0);

    MyClass2<float> i(h);

    std::cout<<"MyClass2 Ex."<<std::endl;
    std::cout<<"before swap: "<<std::endl;
    std::cout << g.a << std::endl;
    std::cout << g.b << std::endl;
    std::cout << h.a << std::endl;
    std::cout << h.b << std::endl;

   // swap<MyClass2<float> >(g, h);
    std::cout<<"after swap: "<<std::endl;
    std::cout << g.a << std::endl;
    std::cout << g.b << std::endl;
    std::cout << h.a << std::endl;
    std::cout << h.b << std::endl;
}
