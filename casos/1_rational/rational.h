 /*
 * rational.h
 *
 *  Created on: 14/02/2021
 *      Author: Yael Daniel
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "exception.h"
#include <string>
#include <sstream>

using namespace std;
/*
se declaran las variables, metodos, funciones y sobrecarga de operadores
necesarios para la clase Rational
*/
class Rational {
private:
	int numerator;
	int denominator;

	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	std::string toString() const;

	void operator=   (const Rational&);
	void operator+=  (const Rational&);

	operator double () const;
};

/*
Se establecen las variables internas de la clase Rational
numerator y denominator
*/

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

/*
Se establece la forma que tomara un numero de clase Rational
para expresar un numero entero.
Ejemplo 4 sera representado como 4/1
*/

Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}

/*
Se establece la forma que tomara un numero de clase Rational
para expresar un numero fraccionario
numerador/denominador
*/

Rational::Rational(int num, int dem){
	numerator = num;
	denominator = dem;
   
    normalize ();

    }
    
/*
Se establece la funcion get para Numerador
*/

int Rational::getNumerator() const {
	
	return numerator;
	
}
/*
Se establece la funcion get para Denominator
*/

int Rational::getDenominator() const {
	
	return denominator;
}

/*
Se define la funcion que representa a los numeros fraccionarios
de la clase Rational en fomrato numerator/denominator
*/

std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

/*
Se sobrecarga el operador double para la clase Rational
*/

Rational::operator double () const {
	double resultado = (double)numerator / (double) denominator;
	return resultado;
}

//Greatest common divisor

/*
Calcula el maximo comun divisor de los numeros que conforman
a un objeto de la clase Rational
*/
int gcd(int a, int b) {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}
/*
Se define la funcion normalize()
Normaliza o simplifica la fraccion
Si contiene un numero negativo, aplica ley de signo para mostrarlo de forma correcta
Muestra error si el denominador es 0
*/
void Rational::normalize() {
	
	if(denominator%numerator == 0 ){
	
	denominator = denominator/numerator;
	numerator = numerator/numerator;
}
	//Se imprimira el denominador entre el numerador
	if (denominator<0){
		
		denominator = denominator* -1;
		numerator = numerator* -1;
	}
	if (denominator == 0){
		throw RangeError();
		
	}
}

/*
Se sobrecarga el operador =
Se establece el valor de numerator y denominator 
a variables creadas con la clase Rational
*/
void Rational::operator= (const Rational &right) {
	
	numerator = right.numerator;
	denominator = right.denominator;
}

/*
Se sobrecarga el operador += de incremento
Se suman numeradores si los denominadores son iguales
o se aplica la regla de suma con distinto denominador (carita feliz o mariposa)
se normaliza el resultado
*/

void Rational::operator+= (const Rational &right) {
	
	int num1 = numerator * right.denominator;
	int num2 = right.numerator*denominator;
	if(denominator == right.denominator) {

		numerator = numerator + right.numerator;

	}else{
	numerator = (num1)+(num2);
	
	denominator = denominator * right.denominator;
	}
	
	normalize();
	
	}
	
	/*
Se sobrecarga el operador + para la suma
Se suman numeradores si el denominador es iguales
sino, se aplica regla para suma de distintos denominadores 
(mariposa o carita feliz)
*/
	

Rational operator+ (const Rational &left, const Rational &right) {
	int num= 0, dem=0;
	int num1 = left.getNumerator()*right.getDenominator();
	int num2 = right.getNumerator()*left.getDenominator();
	
	if (left.getDenominator()==right.getDenominator()){
		num = left.getNumerator() + right.getNumerator();
		dem= left.getDenominator();
	}
	else{
		num = (num1)+(num2);
		dem = left.getDenominator()*right.getDenominator();
	}
	return Rational(num, dem);
	
}

/*
Se sobrecarga el operador - para la resta
Se restan numeradores si el denominador es iguales
sino, se aplica regla para resta de distintos denominadores 
(mariposa o carita feliz)
*/
Rational operator- (const Rational &left, const Rational &right) {
	int num = 0, dem= 0;
	
	int num1 = left.getNumerator()*right.getDenominator();
	int num2 = right.getNumerator()*left.getDenominator();
	
	if (left.getDenominator() == right.getDenominator()){
		num= left.getNumerator() - right.getNumerator();
		dem = left.getDenominator();
	} else {
		
		num = (num1)-(num2);
		dem = left.getDenominator()*right.getDenominator();
		
	}
	return Rational(num, dem);
}

/*
Se sobrecarga el operador - para mostrar signo negativo
*/

Rational operator- (const Rational &right) {
	int num = 0;
	
	num = right.getNumerator()*(-1);
	
	return Rational(num, right.getDenominator());
	
}

/*
Se sobrecarga el operador == de comparacion igual a
Se utiliza la regla 
a/b == c/d si y solo si a*d == b*c
*/

bool operator== (const Rational &left, const Rational &right) {
	int num, dem;
		num = left.getNumerator() * right.getDenominator();
		dem = left.getDenominator() * right.getNumerator();
		
		if(num == dem){
			return true;
		}
		else {
			return false;
		}
	
}

/*
Se sobrecarga el operador < de comparacion menor que
Se utiliza la regla 
a/b < c/d si y solo si a*d < b*c
*/

bool operator<  (const Rational &left, const Rational &right) {
	int numizq, numderh;
	numizq = left.getNumerator()* right.getDenominator();
	numderh = left.getDenominator() * right.getNumerator();
	
	if(numizq < numderh){
		return true;
	} else{
	
	return false;
}
}

#endif /* RATIONAL_H_ */
