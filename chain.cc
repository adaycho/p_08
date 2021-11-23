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
* Archivo chain.cc: clase cadena
* @brief Contiene las definiciones de la clase cadena
*/

#include "chain.h"
#include <fstream>

/**
* @brief Constructor determinado
*/
Chain::Chain() : string_pos_(), alphabet_() {}

/**
* @brief Constructor a partir de una string que contiene la cadena (y alfabeto)
* @param line string que contiene tanto el alfabeto como la cadena
*/
Chain::Chain(std::string line) {
  int found;
  if (line.find_last_of(kSpace) == -1) {
    std::string string_copy;
    string_copy = line;
    for (int i{0}; i < string_copy.size(); ++i) {
      std::string symbol(1, string_copy[i]);
      bool flag = true;
      for (auto& alphabet_sym : alphabet_.GetSymbols()) {
        if (alphabet_sym == symbol) {
          flag = false;
        }
      }

      if (flag == true) {
        Symbol symbol_in(symbol);
        alphabet_.Insert(symbol_in);
      }
    }
  }
  else {
    while (line.find_first_of(kSpace) != -1) {
      found = line.find_first_of(kSpace);
      std::string symbol = line.substr(0, found);
      line = line.substr(found +1);
      bool flag = true;
      for (auto& alphabet_sym : alphabet_.GetSymbols()) {
        if (alphabet_sym == symbol) {
          flag = false;
        }
      }
      if (flag == true) {
        Symbol symbol_in(symbol);
        alphabet_.Insert(symbol_in);
      }
    }
  }
  for (int i{0}; i < line.size(); ++i) {
    for (auto& symbol:alphabet_.GetSymbols()) {
      std::string symbol_ch = line.substr(i, symbol.Size());
      if (symbol.GetSymbol() == symbol_ch) {
        string_pos_.push_back(symbol);
        i += symbol.Size() - 1;
        break;
      }
    }
  }
}

/**
* @brief Constructor a partir de un alfabeto y una cadena
* @param string: string que contiene la cadena
* @param alphabet: alfabeto de la cadena
*/
Chain::Chain(std::string string, const Alphabet& alphabet) {
  alphabet_ = alphabet;
  for (int i{0}; i < string.size(); ++i) {
    for (auto& symbol:alphabet_.GetSymbols()) {
      std::string symbol_ch = string.substr(i, symbol.Size());
      if (symbol.GetSymbol() == symbol_ch) {
        string_pos_.push_back(symbol);
        i += symbol.Size() - 1;
        break;
      }
    }
  }
}

/**
* @brief Getter que devuelve el alfabeto
* @return alfabeto
*/
Alphabet Chain::GetAlphabet() const {
  return alphabet_;
}

/**
* @brief Getter que devuelve el vector de símbolo
* @return vector de símbolos
*/
std::vector<Symbol> Chain::GetChain() const {
  return string_pos_;
}

/**
* @brief Método que devuelve el tamaño de la cadena
* @return tamaño de la cadena
*/
int Chain::GetSize() const {
  return string_pos_.size();
}

/**
* @brief Método que invierte la cadena
*/
void Chain::Invert() {
  std::vector<Symbol> v_copy = string_pos_;
  for (int i{0}; i < v_copy.size(); ++i) {
    string_pos_[v_copy.size() - i - 1] = v_copy[i];
  }
}

/**
* @brief Método para añadir letras a la cadena
* @param symbol simbolo a añadir a la cadena
*/
void Chain::Push_back(const Symbol symbol) {
  string_pos_.push_back(symbol);
}

/**
* @brief Sobrecarga del operador elevar
* @param chain cadena a elevar
* @param number número de potencia
*/
Chain operator^(const Chain& chain, const int& number) {
  int size = chain.GetSize();
  Chain raised_chain;
  for (int i{0}; i < number; ++i) {
    for (int j{0}; j < size; ++j){
      raised_chain.Push_back(chain.GetChain()[j]);
    }
  }
  return raised_chain;
}

/**
* @brief Sobrecarga del operador concatenar
* @param chain1 cadena base
* @param chain2 cadena a concatenar
*/
Chain operator*(const Chain& chain1, const Chain& chain2) {
  Chain new_chain = chain1;
  for (auto& symbol:chain2.GetAlphabet().GetSymbols()) {
    new_chain.alphabet_.Insert(symbol);
  }
  for (int i{0}; i < chain2.GetSize(); ++i){
    new_chain.string_pos_.push_back(chain2.string_pos_[i]);
  }
  
  return new_chain;
}

/**
* @brief Sobrecarga del operador de igualdad
*/
bool operator==(const Chain& chain1, const Chain& chain2) {
  bool flag = true;
  if(chain1.GetSize() == chain2.GetSize()) {
    for(int i{0}; i < chain1.GetSize(); ++i) {
      if(chain1.string_pos_[i] != chain2.string_pos_[i]) {
        flag = false;
      }
    }
  }
  else {
    flag = false;
  }
  return flag;
}

/**
* @brief Sobrecarga del operador menor que
*/
bool operator<(const Chain& chain1, const Chain& chain2) {
  for (int i{1}; i <= chain2.GetSize(); ++i) {
    for (int j{0}; j < chain2.GetSize() + 1 - i; ++j) {
      Chain new_chain;
      for (int k{0}; k < i; ++k) {
        new_chain.Push_back(chain2.GetChain()[k + j]);
      }
      if (chain1 == new_chain) {
        return true;
      }
    }
  }
  return false;
}

/**
* @brief Sobrecarga del operador mayor que
*/
bool operator>(const Chain& chain1, const Chain& chain2) {
  for (int i{1}; i <= chain1.GetSize(); ++i) {
    for (int j{0}; j < chain1.GetSize() + 1 - i; ++j) {
      Chain new_chain;
      for (int k {0}; k < i; ++k) {
        new_chain.Push_back(chain1.GetChain()[k + j]);
      }
      if (chain2 == new_chain) {
        return true;
      }
    }
  }
  return false;
}

/**
* @brief Sobrecarga del operador de desigualdad
*/
bool operator!=(const Chain& chain1, const Chain& chain2) {
  bool flag = false;
  if(chain1.GetSize() == chain2.GetSize()) {
    for(int i{0}; i < chain1.GetSize(); ++i) {
      if(chain1.string_pos_[i] != chain2.string_pos_[i]) {
        flag = true;
      }
    }
  }
  else {
    flag = true;
  }
  return flag;
}

/**
* @brief Sobrecarga del operador de salida
*/
std::ostream& operator<<(std::ostream& out, const Chain& string) {
  for (int i{0}; i < string.string_pos_.size(); i++) {
    out << string.string_pos_[i];
  }
  return out;
}

/**
* @brief Sobrecarga del operador de entrada
*/
std::istream& operator>>(std::istream& in, Chain& string) {
  std::string line;
  in >> line;
  Chain chain(line);
  string.string_pos_ = chain.GetChain();
  string.alphabet_ = chain.GetAlphabet();
  return in;
}