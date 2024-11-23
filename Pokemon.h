//
// Created by Denny on 11/20/24.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>

class Pokemon {

public:
    // Attributes
    std::string name;
    std::string elementType;
    std::string location;
    std::string kind;

    // Constructor
    Pokemon(const std::string& name, const std::string& type, const std::string& location, const std::string& kind);
    // Getters
    std::string getName() const {
        return name;
    }
    std::string getType() const {
        return elementType;
    }
    std::string getLocation() const {
        return location;
    }
    std::string getKind() const {
        return kind;
    }
    // Display information
    void displayInfo() const;
    // load pokemon
    void loadPokemonFromFile(const std::string& fileName);
private:
    std::string trim(const std::string& str);
};

#endif // POKEMON_H
