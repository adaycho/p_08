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
* Archivo production.cc: clase producción
* @brief Contiene las definiciones de la clase producción
*/

#include "production.h"

/**
* @brief constructor de la producción
* @param start símbolo inicial de la producción
* @param end resultado de la producción
*/
Production::Production(const Symbol& start, const std::vector<Symbol>& end) {
  start_ = start;
  end_ = end;
}

/**
* @brief Método que comprueba el símbolo terminal de la producción
* @param start simbolo terminal buscado
* @return true si coincide, false si si no
*/
bool Production::CheckProduction(const Symbol& start) const {
  bool flag {false};
  if(start == start_) {
    flag = true;
  }
  return flag;
}

/**
* @brief Método que devuelve el estado final del arco
* @return devuelve el estado final de la producción
*/
std::vector<Symbol> Production::GetEnd() const {
  return end_;
}
