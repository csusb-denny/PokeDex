#include "Pokedex.h"
#include "handleMenu.h"
#include <iostream>
#include <unistd.h>

int main() {

    //Debugging purposes
    /*
     char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {6
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        perror("getcwd error");
    }
    */
    std::string filename;
    Pokedex pokedex;
    // Load Pokemon
    pokedex.loadPokemonFromFile("PokemonList.txt");
    handleMenu(pokedex);
    return 0;
}
