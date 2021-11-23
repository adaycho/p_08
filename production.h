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
* Archivo production.h: clase producción
* @brief Contiene la clase producción
*/

#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <vector>
#include "alphabet.h"

/**
* @brief Clase producción, que representa una producción de una gramática
*/
class Production {
 public:
  Production() : start_(), end_() {};
  Production(const Symbol& start, const std::vector<Symbol>& end);
  bool CheckProduction(const Symbol& start) const;
  std::vector<Symbol> GetEnd() const;
 private:
  Symbol start_;
  std::vector<Symbol> end_;
};

#endif

