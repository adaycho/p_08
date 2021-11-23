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
* Archivo chain.h: clase cadena
* @brief Contiene la clase cadena
*/

#ifndef STRING_H
#define STRING_H

#include "alphabet.h"

const char kSpace {' '};
const Symbol kEpsilon ("&");

/**
* @brief Clase que almacena una secuencia de símbolos
*/
class Chain{
 public:
  Chain(void);
  Chain(std::string line);
  Chain(std::string string, const Alphabet& alphabet);
  Alphabet GetAlphabet(void) const;
  std::vector<Symbol> GetChain(void) const;
  int GetSize(void) const;
  void Invert();
  void Push_back(const Symbol symbol);
  friend Chain operator^(const Chain& chain, const int& number);
  friend Chain operator*(const Chain& chain1, const Chain& chain2);
  friend bool operator==(const Chain& chain1, const Chain& chain2);
  friend bool operator<(const Chain& chain1, const Chain& chain2);
  friend bool operator>(const Chain& chain1, const Chain& chain2);
  friend bool operator!=(const Chain& chain1, const Chain& chain2);
  friend std::ostream& operator<<(std::ostream& out, const Chain& string);
  friend std::istream& operator>>(std::istream& in, Chain& stringt);

 private:
  std::vector<Symbol> string_pos_;
  Alphabet alphabet_;
};   

#endif