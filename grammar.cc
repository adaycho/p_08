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
* Archivo grammar.cc: clase gramática
* @brief Contiene las definiciones de la clase gramática
*/

#include "grammar.h"

/**
* @brief Constructor de la gramática
* @param file nombre del archivo donde está alojada la gramática
*/
Grammar::Grammar(const std::string& file) {
  std::ifstream infile(file);
  std::string target;
  getline(infile, target);
  Alphabet alphabet(target);
  alphabet_ = alphabet;
  getline(infile, target);
  int found;
  bool flag {true};
  while (target.find_first_of(kSpace) != -1) {
    found = target.find_first_of(kSpace);
    std::string symbol = target.substr(0, found);
    target = target.substr(found +1);
    Symbol state_in(symbol);
    states_.insert(state_in);
    if (flag) {
      start_ = state_in;
      flag = false;
    }
  }
  std::string symbol = target.substr(0, found);
  Symbol state_in(symbol);
  states_.insert(state_in);
  while (getline(infile, target)) {
    found = target.find_first_of(kSpace);
    std::string symbol = target.substr(0, found);
    Symbol start(symbol);
    target = target.substr(found +1);
    found = target.find_first_of(kSpace);
    target = target.substr(found +1);
    Chain end(target);
    Production production(start, end.GetChain());
    productions_.push_back(production);
  }
  infile.close();
}

/**
* @brief Método que imprime las derivaciones de la gramática
* @param in_file archivo que contiene las instrucciones para elegir producciones
* @param out_file archivo para guardar las derivaciones
*/
void Grammar::Print_Process(const std::string& in_file, const std::string& out_file) {
  std::ifstream infile(in_file);
  std::ofstream outfile(out_file);
  Chain grammar_chain;
  grammar_chain.Push_back(start_);
  std::string target;
  int found;
  outfile << grammar_chain;
  while (getline(infile, target)) {
    found = target.find_first_of(":");
    Symbol non_terminal(target.substr(0, found));
    found = target.find_first_of(kSpace);
    target = target.substr(found +1);
    int option = std::stoi(target);
    Chain newchain;
    bool flag {true};
    for (int i{0}; i < grammar_chain.GetSize(); ++i) {
      if (grammar_chain.GetChain()[i] == non_terminal && flag == true) {
        int option_search {1};
        for (int j{0}; j < productions_.size(); ++j) {
          if(productions_[j].CheckProduction(non_terminal) && option == option_search) {
            std::vector<Symbol> end = productions_[j].GetEnd();
            for (int k{0}; k < end.size(); ++k) {
              if (end[k] != kEpsilon) {
                newchain.Push_back(end[k]);
              }
              
            }
            break;
          }
          else if (productions_[j].CheckProduction(non_terminal)) {
            ++option_search;
            
          }
        }
        flag = false;
      }
      else {
        newchain.Push_back(grammar_chain.GetChain()[i]);
      }
    }
    grammar_chain = newchain;
    outfile << " => " << grammar_chain;
  }
  outfile << std::endl;
  outfile.close();
  infile.close();
}