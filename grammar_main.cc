/**
* Universidad de La Laguna
* Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 8: Gramática para expresiones aritméticas
* Autor: Aday Chocho Aisa
* Correo: alu0101437538@ull.edu.es
* Fecha: 14/11/2021
* Archivo grammar_main.cc: programa cliente
* Contiene la función principal del proyecto
* Referencias:
* Enlaces de interés:
*/

#include <iostream>
#include "grammar.h"

void Help(char* argv[]) {
  std::cout << argv[0] << std::endl;
  std::cout << "El programa pide por parámetros tres ficheros: un fichero "
  << ".cfg que creará una gramática, un fichero de entrada que contendrá "
  << "las producciones deseadas y un fichero de salida donde devolverá el "
  << "recorrido y el resultado final. ";
  std::cout << "Modo de empleo: " << std::endl << argv[0] <<
  " [Fichero cfg] [Fichero de entrada drv] [Fichero de salida]" << std::endl;
}

void MissingParameters(char* argv[]) {
  std::cout << argv[0] << std::endl;
  std::cout << "Modo de empleo: " << std::endl << argv[0] <<
  " [Fichero cfa] [Fichero de entrada drv] [Fichero de salida]" << std::endl;
  std::cout << "Para más información, use " << argv[0] << " --help";
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc == 4) {
    Grammar grammar(argv[1]);
    grammar.Print_Process(argv[2], argv[3]);
  }
  else if (argc == 2) {
    std::string option = argv[1];
    if (option == "--help" || option == "-h") {
      Help(argv);
    }
    else {
      MissingParameters(argv);
    }
  }
  else {
    MissingParameters(argv);
  }
  return 0;
}