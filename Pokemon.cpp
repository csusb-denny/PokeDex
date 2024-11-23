//
// Created by Denny on 11/20/24.
//
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "Pokedex.h"
// Constructor implementation
Pokemon::Pokemon(const std::string& name, const std::string& type, const std::string& location, const std::string& kind)
    : name(name), elementType(type), location(location), kind(kind) {}

// Display Pokemon info
void Pokemon::displayInfo() const {
    std::cout << "Name: " << name << "\n"
              << "Type: " << elementType << "\n"
              << "Location: " << location << "\n"
              << "Kind: " << kind << "\n";
};
