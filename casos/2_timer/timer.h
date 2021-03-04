/*
 * timer.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <string>
#include <sstream>

using namespace std;
/*
se declaran las variables, metodos, funciones y sobrecarga de operadores
necesarios para la clase Timer
*/

class Timer {
private:
	int hours, minutes;

public:
	Timer();
	Timer(int, int);
	Timer(const Timer&);

	int getHours() const;
	int getMinutes() const;
	std::string toString() const;

	void operator= (const Timer&);
	void operator+= (const Timer&);
};
/*
Se establece valor inicial 0 horas y 0 minutos
*/
Timer::Timer() : hours(0), minutes(0) {}

/*
Se realiza correccion numerica para utilizar
Horas de 0 a 23
y minutos de 0 a 59
*/

Timer::Timer(int hh, int mm) {
	minutes = mm % 60;
	hours = (hh + (mm / 60)) % 24;
}

Timer::Timer(const Timer &t) {}

/*
Se establece la funcion get para las horas
*/

int Timer::getHours() const {
	
	return hours;
}

/*
Se establece la funcion get para los minutos
*/



int Timer::getMinutes() const {
	return minutes;
}

/*
Se define funcion toString() que convierte los datos de Timer
a tipo Sting y los muestra en formato HH:MM
*/
std::string Timer::toString() const {
	 std::stringstream aux;

	 if (hours < 10) {
		 aux << "0";
	 }
	 aux << hours << ":";
	 if (minutes < 10) {
		 aux << "0";
	 }
	 aux << minutes;
	 return aux.str();
}

/*
Se sobrecarga operador = para declaracion de variables 
de la clase Timer*/


void Timer::operator= (const Timer &right) {
	
	hours = right.getHours();
	minutes = right.getMinutes();
	
	
	
}

/*
Se sobrecarga operador += de incremento
Se incrementan los minutos en la cantidad de minutos de la derecha
Se incrementa las horas en la cantidad de horas de la derecha
*/

void Timer::operator+= (const Timer &right) {
	
	int aux;

	aux = minutes + right.minutes;
	minutes = aux % 60;
	hours = (hours + right.hours + (aux / 60)) % 24;
}

/*
Se sobrecarga el operador == de comparacion igual a 
dos tiempos de la clase Timer son iguales si y solo si
Hora1 == Hora2
y 
Minutos1 == Minutos2
*/

bool operator== (const Timer &left, const Timer &right) {
	if (left.getHours() == right.getHours() && left.getMinutes() == right.getMinutes()){
		return true;
		
	}else{
		return false;
	}
}
/*
Se sobrecarga el operador > de comparación mayor que 
tiempo1 es mayor que tiempo2 de la clase Timer si y solo si
Hora1 > Hora2
y 
Minutos1 > Minutos2
*/

bool operator> (const Timer &left, const Timer &right) {
	if (left.getHours()>= right.getHours() && left.getMinutes() >= right.getMinutes()){
		return true;
		
	}else{
		return false;
	}
}

#endif /* TIMER_H_ */
