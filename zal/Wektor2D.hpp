#include <iostream>
#include <cmath>

class Wektor2D
{
    
    public:

    int populacja(){return num_wek;}

    void setX(double a) {x=a;}
    void setY(double a) {y=a;}
    double getX() {return x;}
    double getY() {return y;}
    void print() { std::cout <<"norma wektora wynosi: "<< norm() << '\n'; }

   Wektor2D (double a, double b){
        ++num_wek;
        x = a;
        y = b;
        std::cout << "x-> " << x << " y-> " <<  y << "\n";
    }

  Wektor2D() : x(0), y(0)
    {
        ++num_wek;
        
    }

    ~Wektor2D(){
        --num_wek;
       // std::cout << "Destruktor"<<"\n";
    }

   
    private:

    double x;
    double y;

    static int num_wek;
       
    double norm() {return sqrt((x*x)+(y*y)); }; 

    friend Wektor2D operator+(const Wektor2D& v_1, const Wektor2D& v_2);   
    friend Wektor2D operator*(double scalar,const Wektor2D& v_1);
    //friend std::ostream& operator<<(std::ostream& os, Wektor2D& v_1);        
};

int Wektor2D::num_wek = 0; // inizjaclizajca licznika zerem


Wektor2D operator+(Wektor2D& v_1, Wektor2D& v_2){

    double wynik_x = v_1.getX() + v_2.getX();
    double wynik_y = v_1.getY() + v_2.getY();
    return Wektor2D(wynik_x,wynik_y);
}

 double operator*(Wektor2D v_1,Wektor2D v_2){

        double wynik_x = v_1.getX() * v_2.getX();
        double wynik_y = v_1.getY() * v_2.getX();
        return wynik_x+wynik_y;
    }


std::ostream& operator<<(std::ostream& os, Wektor2D v_1){

    os<< "["<< v_1.getX()<<","<< v_1.getY()<<"]";
    return os;
}

