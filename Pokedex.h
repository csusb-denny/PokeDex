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
    // Add a Pokémon to the Pokedex
    void addPokemon(const Pokemon& pokemon);

    // Remove a Pokémon by name
    bool removePokemon(const std::string& name);

    // Search functions
    Pokemon* searchByName(const std::string& name);
    void searchByType(const std::string& type) const;
    void searchByLocation(const std::string& location) const;
    void searchByKind(const std::string& kind) const;

    // Filter functions
    void filterByType(const std::string& type) const;
    void filterByLocation(const std::string& location) const;

    // Display all Pokémon
    void displayAll() const;
};

#endif // POKEDEX_H