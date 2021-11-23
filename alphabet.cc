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
* Archivo alphabet.cc: clase alfabeto
* @brief Definición de métodos de la clase alfabeto
*/

#include "alphabet.h"

/**
* @brief Constructor determinado
*/
Alphabet::Alphabet() : symbols_() {}

/**
* @brief Constructor a partir de un vector de símbolos
* @param symbols: Vector de símbolos
*/
Alphabet::Alphabet(const std::vector<Symbol>& symbols) {
  for(int i = 0; i < symbols.size(); ++i) {
    symbols_.insert(symbols[i]);
  }
}

/**
* @brief Constructor a partir de una string
* @param string: String que contiene el alfabeto
*/
Alphabet::Alphabet(std::string string) {
  int found;
  while (string.find_first_of(" ") != -1) {
    found = string.find_first_of(" ");
    std::string symbol = string.substr(0, found);
    string = string.substr(found +1);
    Symbol symbol_in(symbol);
    Insert(symbol_in);
  }
  std::string symbol = string;
  Symbol symbol_in(symbol);
}

/**
* @brief Getter del alfabeto completo
  @return Set de símbolos que componen el alfabeto
*/
std::set<Symbol> Alphabet::GetSymbols() const {
  return symbols_;
}

/**
* @brief Setter del alfabeto completo
* @param new_symbols: Set que va a reemplazar al actual alfabeto
*/
void Alphabet::SetSymbols(const std::set<Symbol>& new_symbols) {
  symbols_ = new_symbols;
}

/**
* @brief Método que insertar un simbolo al alfabeto
* @param new_symbol: Símbolo a insertar
*/
void Alphabet::Insert(const Symbol& new_symbol) {
   symbols_.insert(new_symbol);
}

/**
* @brief Método que devuelve el nº de símbolos del alfabeto
* @return Tamaño del alfabeto
*/
int Alphabet::GetSize() const{
  return symbols_.size();
}

/**
* @brief Método que comprueba si una cadena  pertenece a un alfabeto
* @param chain: Cadena a comprobar
* @return true si la palabra pertenece al alfabeto, false si no
*/
bool Alphabet::Check(const std::string& chain){
  for (int i{0}; i < chain.size(); ++i) {
    bool flag = false;
    for (auto& symbol:GetSymbols()) {
      std::string symbol_ch = chain.substr(i, symbol.Size());
      if (symbol.GetSymbol() == symbol_ch) {
        i += symbol.Size() - 1;
        flag = true;
        break;
      }
    }
    if (flag == false) {
      return false;
    }
  }
  return true;
}

/**
* @brief Sobrecarga de salida
*/
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << "{";
  bool flag = false;
  for (auto& i : alphabet.symbols_){
    if (flag) {
      out << ", ";
    }
    out << i;
    flag = true;
  }
  out << "}";
  return out;
}

/**
* @brief Sobrecarga de entrada
*/
std::istream& operator>>(std::istream& in, Alphabet& alphabet) {
  int number;
  std::cout << "Nº Símbolos: ";
  in >> number;
  for (int i{0}; i < number; ++i){
    std::string string;
    in >> string;
    Symbol symbol(string);
    alphabet.symbols_.insert(symbol);
  }
  return in;
}