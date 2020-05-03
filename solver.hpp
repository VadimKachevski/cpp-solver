#pragma once
#include <complex>

using namespace std;
namespace solver
{

    class RealVariable
    {
    
     
    private:
    double power,coef;   
    double other;
    public:
    RealVariable() : power(0),coef(1),other(0){}
    RealVariable(double power,double coef,double other)
    {
        this->power = power;
        this->coef = coef;
        this->other = other;
    }
    double getPower(){return this->power;}
    double getCoef(){return this->coef;}
    double getOther(){return this->other;}
   // RealVariable operator + (const RealVariable& c1);
   friend RealVariable operator + (const RealVariable& c2,double c1);
    friend RealVariable operator + (const RealVariable& c1,const RealVariable& c2);
    friend RealVariable operator + (double c1,const RealVariable& c2);


    //RealVariable operator - (const RealVariable& c1);
   // RealVariable operator - (const double c1);
   friend RealVariable operator - (const RealVariable& c2,double c1);
    friend RealVariable operator - (const RealVariable& c1,const RealVariable& c2);
    friend RealVariable operator - (double c1,const RealVariable& c2);

    // RealVariable operator * (const RealVariable& c1);
    // RealVariable operator * (const double c1);
    friend RealVariable operator * (const RealVariable& c2,double c1);
    friend RealVariable operator * (const RealVariable& c1,const RealVariable& c2);
    friend RealVariable operator * (double c1,const RealVariable& c2);



    // RealVariable operator / (const RealVariable& c1);
    // RealVariable operator / (const double c1);
    friend RealVariable operator / (const RealVariable& c2,double c1);
    friend RealVariable operator / (const RealVariable& c1,const RealVariable& c2);
    friend RealVariable operator / (double c1,const RealVariable& c2);

    friend RealVariable operator ^ (const RealVariable& c2,const double c1);


    // RealVariable operator == (const RealVariable& c1);
    // RealVariable operator == (const double c1);
    friend RealVariable operator == (const RealVariable& c2,double c1);
    friend RealVariable operator == (const RealVariable& c1,const RealVariable& c2);
    friend RealVariable operator == (double c1,const RealVariable& c2);

    };

    class ComplexVariable
    {
   private:
    complex<double> power,coef;   
    complex<double> other;
    public:
    ComplexVariable() : power(0),coef(1),other(0){}
    ComplexVariable(complex<double> power,complex<double> coef,complex<double> other)
    {
        this->power = power;
        this->coef = coef;
        this->other = other;
    }
    complex<double> getPower(){return this->power;}
    complex<double> getCoef(){return this->coef;}
    complex<double> getOther(){return this->other;}
   // ComplexVariable operator + (const ComplexVariable& c1);
   friend ComplexVariable operator + (const ComplexVariable& c2,complex<double> c1);
    friend ComplexVariable operator + (const ComplexVariable& c1,const ComplexVariable& c2);
    friend ComplexVariable operator + (complex<double> c1,const ComplexVariable& c2);


    //ComplexVariable operator - (const ComplexVariable& c1);
   // ComplexVariable operator - (const complex<double> c1);
   friend ComplexVariable operator - (const ComplexVariable& c2,complex<double> c1);
    friend ComplexVariable operator - (const ComplexVariable& c1,const ComplexVariable& c2);
    friend ComplexVariable operator - (complex<double> c1,const ComplexVariable& c2);

    // ComplexVariable operator * (const ComplexVariable& c1);
    // ComplexVariable operator * (const complex<double> c1);
    friend ComplexVariable operator * (const ComplexVariable& c2,complex<double> c1);
    friend ComplexVariable operator * (const ComplexVariable& c1,const ComplexVariable& c2);
    friend ComplexVariable operator * (complex<double> c1,const ComplexVariable& c2);



    // ComplexVariable operator / (const ComplexVariable& c1);
    // ComplexVariable operator / (const complex<double> c1);
    friend ComplexVariable operator / (const ComplexVariable& c2,complex<double> c1);
    friend ComplexVariable operator / (const ComplexVariable& c1,const ComplexVariable& c2);
    friend ComplexVariable operator / (complex<double> c1,const ComplexVariable& c2);

    friend ComplexVariable operator ^ (const ComplexVariable& c2,const double c1);


    // ComplexVariable operator == (const ComplexVariable& c1);
    // ComplexVariable operator == (const complex<double> c1);
    friend ComplexVariable operator == (const ComplexVariable& c2,complex<double> c1);
    friend ComplexVariable operator == (const ComplexVariable& c1,const ComplexVariable& c2);
    friend ComplexVariable operator == (complex<double> c1,const ComplexVariable& c2);

    };

    double solve(RealVariable x);
    complex<double> solve(ComplexVariable x);


}