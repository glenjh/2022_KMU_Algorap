#include "MyRational.h"

myRational::myRational(long num, long den) : _num(num), _den(den) 
{
    reduce();
}
myRational::myRational(const myRational &art){
    _num = art._num;
    _den = art._den;
}

long myRational::getNumerator() const{
    return _num;
}
long myRational::getDenominator() const{
    return _den;
}
myRational myRational::reciprocal() const{
    myRational ret = (_den , _num);
    return ret;
} 


myRational myRational:: operator +(const myRational& a){
    long new_num = (_num * a._den) + (a._num *_den);
    long new_den = _den * a._den;
    return myRational(new_num, new_den);
}
myRational myRational:: operator +(long value){
    return (*this)+myRational(value) ;
}
myRational operator +(long value, myRational a){
    return myRational(value) + a;
}

myRational myRational:: operator -(const myRational& a){
    long new_num = (_num * a._den) - (a._num * _den);
    long new_den = _den * a._den;
    return myRational(new_num, new_den);
}
myRational myRational:: operator -(long value){
    return (*this) - myRational(value);
}
myRational operator -(long value, myRational a){
    return myRational(value) - a;
}

myRational myRational:: operator *(const myRational& a){
    long new_num = _num * a._num;
    long new_den = _den * a._den;
    return myRational(new_num, new_den);
}
myRational myRational:: operator *(long value){
    return (*this) * myRational(value);
}
myRational operator *(long value, myRational a){
    return myRational(value) * a;
}

myRational myRational:: operator /(const myRational& a){
    // if(a._num == 0 || a._den == 0){ return 0; }
    long new_num = _num * a._den;
    long new_den = _den * a._num;
    return myRational(new_num, new_den);
}
myRational myRational:: operator /(long value){
    if(value == 0){ return 0; }
    return (*this) / myRational(value);
}
myRational operator /(long value, myRational a){
    return (myRational(value) / a);
}

myRational myRational:: operator++(){
    _num = _num + _den;
    return myRational(_num, _den);
}
myRational myRational:: operator++(int){
    myRational r(*this); operator++();
    return r;
}
myRational myRational:: operator--(){
    _num = _num - _den;
   return myRational(_num, _den);
}
myRational myRational:: operator--(int){
    myRational r(*this); operator--();
    return r;
}

myRational myRational:: operator -(){
    return myRational(-_num, _den);
}

bool myRational::operator <(const myRational& a) const{
    return (  a._num*(*this)._den > a._den*(*this)._num );
}
bool myRational::operator <(long value) const{
    return ( (*this) > myRational(value));
}

bool myRational::operator <=(const myRational& a) const{
    return !(  (a._num)*(*this)._den < (*this)._num*(a._den) );
}
bool myRational::operator <=(long value) const{
    return !( (*this) < myRational(value));
}

bool myRational::operator >(const myRational& a) const{
    return (  (a._num)*(*this)._den < (*this)._num*(a._den) );
}
bool myRational::operator >(long value) const{
    return ( (*this) < myRational(value));
}

bool myRational::operator >=(const myRational& a) const{
    return !(  (a._num)*(*this)._den > (*this)._num*(a._den) );
}
bool myRational::operator >=(long value) const{
    return !( (*this) > myRational(value));
}

bool myRational::operator ==(const myRational& a) const{
    return (a._num == (*this)._num && a._den == (*this)._den );
}
bool myRational::operator ==(long value) const{
    return ( (*this) == myRational(value));
}

bool myRational::operator !=(const myRational& a) const{
    return !(*this == a);
}
bool myRational::operator !=(long value) const{
    return !((*this) == myRational(value));
}

myRational& myRational::operator =(const myRational& a){
    this->_num = a._num;
    this->_den = a._den;
}
myRational& myRational::operator =(long value){
    _num = value;
    _den = 1;
    return *this;
}

myRational& myRational::operator +=(const myRational& a){
    (*this) = (*this) + a;
    return *this;
}
myRational& myRational::operator +=(long value){
    (*this) = (*this) + myRational(value);
    return *this;
}

myRational& myRational::operator -=(const myRational& a){
    (*this) = (*this) - a;
    return *this;
}
myRational& myRational::operator -=(long value){
    (*this) = (*this) - myRational(value);
    return *this;
}

myRational& myRational::operator *=(const myRational& a){
    (*this) = (*this) * a;
    return *this;
}
myRational& myRational::operator *=(long value){
    (*this) = (*this) * myRational(value);
    return *this;
}

myRational& myRational::operator /=(const myRational& a){
    (*this) = (*this) / a;
    return *this;
}
myRational& myRational::operator /=(long value){
    (*this) = (*this) / myRational(value);
    return *this;
}

ostream &operator <<(ostream &outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;
    return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)  
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;

    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
} 