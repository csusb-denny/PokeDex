//
// Created by Denny on 11/20/24.
//
#include "Pokedex.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

// Add a Pokémon to the Pokedex
void Pokedex::addPokemon(const Pokemon& pokemon) {
}

// Remove a Pokémon by name
bool Pokedex::removePokemon(const std::string& name) {
    return true;
}

// Search Pokémon by name
Pokemon* Pokedex::searchByName(const std::string& name) {
    return nullptr;
}

// Search Pokémon by type
void Pokedex::searchByType(const std::string& type) const {
}

// Search Pokémon by location
void Pokedex::searchByLocation(const std::string& location) const {
}

// Search Pokémon by kind
void Pokedex::searchByKind(const std::string& kind) const {
}

// Filter Pokémon by type
void Pokedex::filterByType(const std::string& type) const {
}

// Filter Pokémon by location
void Pokedex::filterByLocation(const std::string& location) const {
}

// Display all Pokémon
void Pokedex::displayAll() const {
}

void Pokedex::loadPokemonFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        return;
    }
    std::string line;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, type, location, kind;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, location, ',');
        std::getline(ss, kind);

        pokemons.emplace_back(name, type, location, kind);
    }
    file.close();
}