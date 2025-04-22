#include <iostream>
#include <cmath>

using namespace std;

class Vector {
protected:
    double x;
    double y;
public:
    Vector(double x,double y): x(x),y(y){}   //конструктор
    double leng() const{// функция для вычесления длины вектора
        return sqrt(x*x+y*y);
    }
    void pr() const{//функция для вывода координат вектора и его длины
        cout<<"Vector=("<<x<<","<<y<<"),Длина вектора = "<<leng()<<endl;
    }
};

class Vector2: public Vector{//этот класс наследует public Vector
private:
    double z;
public:
    Vector2(double x,double y,double z):Vector(x,y),z(z){}//конструктор
    double leng2() const{
        return sqrt(x*x+y*y+z*z);
    }
    void pr2() const{
        cout<<"Vector2=("<<x<<","<<y<<","<<z<<").Длина вектора = "<<leng2()<<endl;
    }
};

int main(){
    Vector v1(4,3);
    v1.pr();
    Vector2 v2(4,3,0);
    v2.pr2();
    //динамический полиморфизм
    Vector* vt=&v2;//указать указывает на класс Vector,но на объект v2 производного класса
    vt -> pr();// вызовется функция pr() из класса Vector в Vector2 благодаря динамическому полиморфизму
    return 0;
}
