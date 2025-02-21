# Nome do executável final
pokedex: main.o cadastros.o pokedex.o
	g++ main.o cadastros.o pokedex.o -o pokedex

# Como compilar o main.cpp
main.o: main.cpp cadastros.hpp pokedex.hpp
	g++ -c main.cpp

# Como compilar o cadastros.cpp
cadastros.o: cadastros.cpp cadastros.hpp
	g++ -c cadastros.cpp

# Como compilar o pokedex.cpp
pokedex.o: pokedex.cpp pokedex.hpp
	g++ -c pokedex.cpp

# Comando para limpar arquivos gerados
clean:
	rm -f *.o pokedex
