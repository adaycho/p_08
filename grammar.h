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
* Archivo grammar.h: clase gramática
* @brief Contiene la clase gramática
*/

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "chain.h"
#include "production.h"
#include "fstream"

/**
* @brief Clase que representa a una gramática
*/
class Grammar{
 public:
  Grammar() : alphabet_(), states_(), start_() {};
  Grammar(const std::string& file);
  void Print_Process(const std::string& infile, const std::string& outfile);
 private:
  Alphabet alphabet_;
  std::set<Symbol> states_;
  Symbol start_;
  std::vector<Production> productions_;
};

#endif