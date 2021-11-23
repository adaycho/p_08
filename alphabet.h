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
* Archivo alphabet.h: clase alfabeto
* @brief Contiene la clase alfabeto
*/

#ifndef ALPHABET_H
#define ALPHABET_H

#include "symbol.h"
#include <cassert>
#include <set>
#include <vector>

/**
* @brief Clase que permite almacenar los símbolos usados en una cadena
*/
class Alphabet{
 public:
  Alphabet(void);
  Alphabet(const std::vector<Symbol>& symbols);
  Alphabet(std::string string);
  std::set<Symbol> GetSymbols() const;
  void SetSymbols(const std::set<Symbol>& new_symbols);
  void Insert(const Symbol& new_symbol);
  int GetSize(void) const;
  bool Check(const std::string& chain);
  friend std::ostream& operator<<(std::ostream& out,
  const Alphabet& alphabet);
  friend std::istream& operator>>(std::istream& in, Alphabet& alphabet);
 private:
  std::set<Symbol> symbols_;
};

#endif