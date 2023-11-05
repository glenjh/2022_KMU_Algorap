#include "MyPolynomial.h"
#include <cmath>
#include <vector>
#include <algorithm>
/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c, unsigned e) : numterms(1)
{
    terms = new myTerm[1];
    terms[0] = myTerm(c,e);
}
myPolynomial::myPolynomial(int nTerms, int mono[]) : numterms(nTerms)
{
    terms = new myTerm[numterms];
    for(int i=0 ; i<numterms ; i++){
        terms[i]=myTerm(mono[2*i], mono[2*i + 1]);
        
    }
    sort();
}
myPolynomial::myPolynomial(int nTerms, const myTerm *term) : numterms(nTerms)
{
     terms = new myTerm[numterms];
     for(int i=0 ; i<numterms ; i++){
         terms[i] = term[i];
     }
     sort();
     
}

myPolynomial::myPolynomial(const myPolynomial &poly) : numterms(poly.numterms)
{
    terms = new myTerm[numterms];
    for(int i=0 ; i<poly.numterms ; i++){
        terms[i] = poly.terms[i];
    }
    sort();
}

int myPolynomial::getDegree() const {  
    for(int i=0 ; i< numterms ; i++){
        if(terms[i].getCoeff()==0 && terms[i].getExp() == 0){ return 0; }
    }
    return terms[0].getExp();
 }
unsigned myPolynomial::getNumTerms() const { return numterms; }
void myPolynomial::setCoeff(int c) {  coeff = c; }

myPolynomial myPolynomial::ddx() const{
    myPolynomial rel(*this);
    for(int i=0 ; i<rel.numterms ; i++){
        rel.terms[i] =  terms[i].ddx();
    }
    return rel; 
}

myPolynomial myPolynomial::operator +(const myPolynomial &poly) const{
    int pos = 0, i=0, j=0;
    int len =  numterms +  poly.numterms;
    myTerm *rel = new myTerm[len];
    while (i < numterms && j < poly.numterms) {
        if (terms[i].getExp() == poly.terms[j].getExp()) {
            rel[pos] = myTerm(terms[i].getCoeff() + poly.terms[j].getCoeff(), terms[i].getExp());
            pos++;
            i++;
            j++;
        }
        else if (terms[i].getExp() < poly.terms[j].getExp()) {
            rel[pos] = poly.terms[j];
            pos++;
            j++;
        }
        else {
            rel[pos] = terms[i];
            pos++;
            i++;
        }
    }
    while (i < numterms) {
        rel[pos] = terms[i];
        pos++;
        i++;
    }
    while (j < poly.numterms) {
        rel[pos] = poly.terms[j];
        pos++;
        j++;
    }
    return myPolynomial(pos, rel);
}

myPolynomial myPolynomial::operator -(const myPolynomial &poly) const{
    int pos = 0, i=0,j=0;
    int len =  numterms +  poly.numterms;
    myTerm *rel = new myTerm[len];
    while (i < numterms && j < poly.numterms) {
        if (terms[i].getExp() == poly.terms[j].getExp()) {
            rel[pos] = myTerm(terms[i].getCoeff() - poly.terms[j].getCoeff(), terms[i].getExp());
            pos++;
            i++;
            j++;
        }
        else if (terms[i].getExp() < poly.terms[j].getExp()) {
            rel[pos] = -poly.terms[j];
            pos++;
            j++;
        }
        else {
            rel[pos] = terms[i];
            pos++;
            i++;
        }
    }
    while (i < numterms) {
        rel[pos] = terms[i];
        pos++;
        i++;
    }
    while (j < poly.numterms) {
        rel[pos] = -poly.terms[j];
        pos++;
    }
    return myPolynomial(pos, rel);
}

myPolynomial myPolynomial::operator *(const myPolynomial &poly) const{
    myPolynomial rel(myPolynomial::ZERO); 
    for(int i=0 ; i<numterms ; i++){
        myTerm *tmp = new myTerm[poly.numterms];
        for(int j=0; j <poly.numterms ; j++){
            tmp[j] = myTerm(terms[i].getCoeff()*poly.terms[j].getCoeff() , terms[i].getExp()+poly.terms[j].getExp());
        }
        rel += myPolynomial(poly.numterms , tmp);
    }
    return rel;
}

myPolynomial myPolynomial::operator *(int k) const{
    myPolynomial rel(*this);
    for(int i=0 ; i<numterms ; i++){
        rel.terms[i].setCoeff(rel.terms[i].getCoeff() * k);
    }
    return rel;
}

myPolynomial operator *(const int k , const myPolynomial &poly){
    myPolynomial rel(poly);
    for(int i=0 ; i<poly.numterms ; i++){
        rel.terms[i].setCoeff(poly.terms[i].getCoeff() * k);
    }
    return rel;
}

long myPolynomial::operator() (int x) const{
    long rel = 0;
    for(int i=0 ; i<numterms ; i++){
        rel += pow(x,terms[i].getExp()) * terms[i].getCoeff();
    }
    return rel;
}

myPolynomial myPolynomial::operator -() const{
    return (*this)*-1 ;
} 

bool myPolynomial::operator == (const myPolynomial &poly) const{
    if(numterms != poly.numterms) { return false ; }
    for(int i=0 ; i<numterms ; i++){
        if(terms[i] != poly.terms[i]) { return false; }
    }
    return true;
}
bool myPolynomial::operator != (const myPolynomial &poly) const{
    return !( (*this) == poly );
}

myPolynomial& myPolynomial::operator += (const myPolynomial &poly){
    (*this) = (*this) + poly;
    return (*this);
}
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly){
    (*this) = (*this) - poly;
    return (*this);
}
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly){
    (*this) = (*this) * poly;
    return (*this);
}
myPolynomial& myPolynomial::operator *= (int k){
    (*this) = (*this) * k;
    return (*this);
}

void myPolynomial::sort(){
    for(int i=0 ; i<numterms-1 ; i++){
        if(terms[i].getExp() < terms[i+1].getExp()){
            myTerm tmp = terms[i+1];
            terms[i+1] = terms[i];
            terms[i] = tmp;
            i = -1;
        }
    }
}

// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
    
    if (poly == myPolynomial::ZERO)
        return outStream << 0;
    /********************* add your code here ********************************/
    if(poly.terms[0].getCoeff() == 0){
        outStream<<0;
    }else{
        outStream << poly.terms[0];
    }
    for(int i=1 ; i<poly.numterms ; i++){
        if(poly.terms[i].getCoeff() > 0){
            outStream << "+" << poly.terms[i];
        }else if(poly.terms[i].getCoeff() ==0){
            poly.terms[i].setExp(0);
            poly.terms[i].setExp(0);
            outStream << poly.terms[i];
        }
        else{
            outStream << poly.terms[i];
        }
    }
    return outStream;
}

const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x