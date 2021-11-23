p07_nfa_analyzer: grammar_main.cc grammar.cc production.cc chain.cc alphabet.cc symbol.cc
	g++ -o p08_grammar grammar_main.cc grammar.cc production.cc chain.cc alphabet.cc symbol.cc

clean:
	rm -rf *.txt p08_grammar
