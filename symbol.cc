/**
* Universidad de La Laguna
* Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 8: Gramática para expresiones aritméticas
* Correo: alu0101437538@ull.edu.es
* @author Aday Chocho Aisa
* @date 22/11/2021
* Archivo symbol.cc: clase símbolo
* @brief Contiene las definiciones de la clase símbolo
*/

#include "symbol.h"

/**
* @brief Getter del símbolo
* @return simbolo
*/
std::string Symbol::GetSymbol() const {
  return symbol_;
}

/**
* @brief Setter que establece el nuevo símbolo
* @param new_symbol símbolo de reemplazo
*/
void Symbol::SetSymbol(const std::string& new_symbol) {
  symbol_ = new_symbol;
}

/**
* @brief Método que devuelve el tamaño de la cadena
* @return tamaño de la cadena
*/
int Symbol::Size() const{
  return symbol_.size();
}

/**
* @brief Sobrecarga del operador menor que
*/
bool operator<(const Symbol& string1, const Symbol& string2) {
  return string1.GetSymbol() < string2.GetSymbol();
}

/**
* @brief Sobrecarga del operador mayor que
*/
bool operator>(const Symbol& string1, const Symbol& string2) {
  return string1.GetSymbol() > string2.GetSymbol();
}

/**
* @brief Sobrecarga del operador de igualdad
*/
bool operator==(const Symbol& string1, const Symbol& string2) {
  return string1.GetSymbol() == string2.GetSymbol();
}

/**
* @brief Sobrecarga del operador de desigualdad
*/
bool operator!=(const Symbol& string1, const Symbol& string2) {
  return string1.GetSymbol() != string2.GetSymbol();
}

/**
* @brief Sobrecarga del operador de salida
*/
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.GetSymbol();
  return out;
}

/**
* @brief Sobrecarga del operador de entrada
*/
std::istream& operator>>(std::istream& in, const Symbol& symbol) {
  in >> symbol.symbol_;
  return in;
}