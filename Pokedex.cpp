//
// Created by Denny on 11/20/24.
//


#include "Pokedex.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>

// Add a Pokémon to the Pokedex ****DANIEL******
void Pokedex::addPokemon(const Pokemon& pokemon) {
}

// Remove a Pokémon by name *******DANIEL********
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

// Search Pokémon by kind   *****DENNY******
void Pokedex::searchByKind(const std::string& kind) const {
    bool found = false; // Track if any matches are found

    //Convert user input to lowercase
    std::string searchKind = kind;
    std::transform(searchKind.begin(), searchKind.end(), searchKind.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    for (const auto& pokemon : pokemons) {
        //Convert Pokémon's kind to lowercase
        std::string pokemonKind = pokemon.getKind();
        std::transform(pokemonKind.begin(), pokemonKind.end(), pokemonKind.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        //Compare in lowercase
        if (pokemonKind == searchKind) {
            pokemon.displayInfo(); //Display Pokémon details
            std::cout << "------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Invalid Kind\n"; // no matches are found
    }
}

// Display all Pokémon *****DANIEL******
void Pokedex::displayAll() const {
}
//**DENNY***
void Pokedex::loadPokemonFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cout << "File unable to open";
        return;
    }
    std::string line;
    while(std::getline(file, line)) {
        //        std::cout << "Line Load: " << line << std::endl;              //debugging purposes

        std::stringstream ss(line);
        std::string name, type, location, kind;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, location, ',');
        std::getline(ss, kind);
        Pokemon pokemon(name, type, location, kind);
        pokemons.emplace_back(name, type, location, kind);
        pokemon.displayInfo();
        std::cout << "-------";
    }
    file.close();


}