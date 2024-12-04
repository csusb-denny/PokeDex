//
// Created by Denny on 11/20/24.
//

#ifndef POKEDEX_H
#define POKEDEX_H

#include "Pokemon.h"
#include <vector>
#include <string>

class Pokedex {
private:
    std::vector<Pokemon> pokemons;

public:
    // loadPokemon
    void loadPokemonFromFile(const std::string& filename);  //denny
    // Add a Pokémon to the Pokedex
    void addPokemon(const Pokemon& pokemon);            //Daniel

    // Remove a Pokémon by name
    bool removePokemon(const std::string& name);        //Daniel

    // Search functions
    Pokemon* searchByName(const std::string& name);
    void searchByType(const std::string& type) const;
    void searchByLocation(const std::string& location) const;
    void searchByKind(const std::string& kind) const;   //denny

    // Display all Pokémon
    void displayAll() const;        //daniel
};

#endif // POKEDEX_H