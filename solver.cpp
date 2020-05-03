#include "solver.hpp"
#include <complex>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;
using namespace solver;
// Real Vars
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

RealVariable solver::operator+(const RealVariable &c2, double c1)
{
    return RealVariable(c2.power, c2.coef, c2.other + c1);
}
RealVariable solver::operator+(const RealVariable &c1, const RealVariable &c2)
{
    return RealVariable(c2.power + c1.power, c2.coef + c1.coef, c2.other + c1.other);
}
RealVariable solver::operator+(double c1, const RealVariable &c2)
{
    return RealVariable(c2.power, c2.coef, c2.other + c1);
}

// --------------------------
RealVariable solver::operator-(const RealVariable &c2, double c1)
{
    return RealVariable(c2.power, c2.coef, c2.other - c1);
}
RealVariable solver::operator-(const RealVariable &c1, const RealVariable &c2)
{
    return RealVariable(c1.power - c2.power, c1.coef - c2.coef, c1.other - c2.other);
}
RealVariable solver::operator-(double c1, const RealVariable &c2)
{
    
    return RealVariable(-c2.power, -c2.coef, -c2.other + c1);
}

// *****************
RealVariable solver::operator*(const RealVariable &c2, double c1)
{
    return RealVariable(c2.power * c1, c2.coef * c1, c2.other * c1);
}
RealVariable solver::operator*(const RealVariable &c1, const RealVariable &c2)
{
    return RealVariable(c2.power * c1.power, c2.coef * c1.coef, c2.other * c1.other);
}
RealVariable solver::operator*(double c1, const RealVariable &c2)
{
    return RealVariable(c2.power * c1, c2.coef * c1, c2.other * c1);
}

// ////////////////////////////////////////////
RealVariable solver::operator/(const RealVariable &c2, double c1)
{
    if(c1==0)
    {
        throw invalid_argument("power can't be bigger then 2"); 
    }
    return RealVariable(c2.power / c1, c2.coef / c1, c2.other / c1);
}
RealVariable solver::operator/(const RealVariable &c2, const RealVariable &c1)
{
    return RealVariable(c2.power / c1.power, c2.coef / c1.coef, c2.other / c1.other);
}
RealVariable solver::operator/(double c1, const RealVariable &c2)
{
    return RealVariable(c1/c2.power , c1/c2.coef, c1/c2.other);
}

//  ^^^^^^^

RealVariable solver::operator^(const RealVariable &c2, const double c1)
{
    // assuming ^ will have prio TODO later make sure works ----------------------------
    if (c1 == 2)
    {
        return RealVariable(1, 0, 0);
    }
    if (c1 == 1)
    {
        return RealVariable(0, 1, 0);
    }
    if (c1 == 0)
    {
        return RealVariable(0, 0, 1);
    }
    throw invalid_argument("power can't be bigger then 2");
}
// =============================
RealVariable solver::operator==(const RealVariable &c2, double c1)
{
    return RealVariable(c2.power, c2.coef, c2.other - c1);
}
RealVariable solver::operator==(const RealVariable &c1, const RealVariable &c2)
{
    return RealVariable(c1.power - c2.power, c1.coef - c2.coef, c1.other - c2.other);
}
RealVariable solver::operator==(double c1, const RealVariable &c2)
{
    return RealVariable(-c2.power, -c2.coef, -c2.other + c1);
}
// 
// solve
double solver::solve(RealVariable x)
{
    double a = x.getPower();
    double b = x.getCoef();
    double c = x.getOther();
    if (a != 0)
    {
        if((b*b - 4 *a*c) < 0)
        {
            throw invalid_argument("no real solution");
        }
        double ans1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        return ans1;
    }
    else
    {
        if (b == 0)
        {
            throw invalid_argument("no real solution");
        }
        return (-c / b);
    }
}

// complex vars
// ++++++++++++++
ComplexVariable solver::operator+(const ComplexVariable &c2, complex<double> c1)
{
    return ComplexVariable(c2.power, c2.coef, c2.other + c1);
}
ComplexVariable solver::operator+(const ComplexVariable &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.power + c1.power, c2.coef + c1.coef, c2.other + c1.other);
}
ComplexVariable solver::operator+(complex<double> c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.power, c2.coef, c2.other + c1);
}

// --------------------------
ComplexVariable solver::operator-(const ComplexVariable &c2, complex<double> c1)
{
    return ComplexVariable(c2.power, c2.coef, c2.other - c1);
}
ComplexVariable solver::operator-(const ComplexVariable &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c1.power - c2.power, c1.coef - c2.coef, c1.other - c2.other);
}
ComplexVariable solver::operator-(complex<double> c1, const ComplexVariable &c2)
{
    return ComplexVariable(-c2.power, -c2.coef, -c2.other + c1);
}

// *****************
ComplexVariable solver::operator*(const ComplexVariable &c2, complex<double> c1)
{
    return ComplexVariable(c2.power * c1, c2.coef * c1, c2.other * c1);
}
ComplexVariable solver::operator*(const ComplexVariable &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.power * c1.power, c2.coef * c1.coef, c2.other * c1.other);
}
ComplexVariable solver::operator*(complex<double> c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.power * c1, c2.coef * c1, c2.other * c1);
}

// ////////////////////////////////////////////
ComplexVariable solver::operator/(const ComplexVariable &c2, complex<double> c1)
{
    return ComplexVariable(c2.power / c1, c2.coef / c1, c2.other / c1);
}
ComplexVariable solver::operator/(const ComplexVariable &c2, const ComplexVariable &c1)
{
    return ComplexVariable(c2.power / c1.power, c2.coef / c1.coef, c2.other / c1.other);
}
ComplexVariable solver::operator/(complex<double> c1, const ComplexVariable &c2)
{
    return ComplexVariable(c1/ c2.power ,c1/ c2.coef ,c1/ c2.other );
}

//  ^^^^^^^

ComplexVariable solver::operator^(const ComplexVariable &c2, const double c1)
{
    // assuming ^ will have prio TODO later make sure works ----------------------------
    if (c1 == 2)
    {
        return ComplexVariable(1, 0, 0);
    }
    if (c1 == 1)
    {
        return ComplexVariable(0, 1, 0);
    }
    if (c1 == 0)
    {
        return ComplexVariable(0, 0, 1);
    }
    throw invalid_argument("power can't be bigger then 2");
}
// =============================
ComplexVariable solver::operator==(const ComplexVariable &c2, complex<double> c1)
{
    return ComplexVariable(c2.power, c2.coef, c2.other - c1);
}
ComplexVariable solver::operator==(const ComplexVariable &c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.power - c1.power, c2.coef - c1.coef, c2.other - c1.other);
}
ComplexVariable solver::operator==(complex<double> c1, const ComplexVariable &c2)
{
    return ComplexVariable(c2.power, c2.coef, c2.other - c1);
}
complex<double> solver::solve(ComplexVariable x)
{
    complex<double> a = x.getPower();
    complex<double> b = x.getCoef();
    complex<double> c = x.getOther();
    if(a!= complex(0.0,0.0))
    {
    complex<double> ans1 = (-b + sqrt(b * b - complex(4.0,0.0) * a * c)) / (complex(2.0,0.0) * a);
    return ans1;
    }
    else
    {
        if(b == complex(0.0,0.0))
        {
            throw invalid_argument("x is gone");
        }
        return (-c / b);
    }
    
}