#include "Pokedex.h"
#include "handleMenu.h"
#include <iostream>

int main() {
    Pokedex pokedex;
    // Load Pokemon
    pokedex.loadPokemonFromFile("PokemonList.txt");
    handleMenu(pokedex);
    return 0;
}
