#include <iostream>
#include <string>

// Códigos de color ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::cout << GREEN << "Argumentos recibidos:\n" << RESET;
        for (int i = 1; i < argc; ++i) {
            std::cout << CYAN << "Argumento " << i << ": " << argv[i] << "\n" << RESET;
        }
    } else {
        std::cout << RED << "No se recibieron argumentos.\n" << RESET;
    }

    std::cout << BLUE << "Este es un mensaje en azul.\n" << RESET;
    std::cout << MAGENTA << "Y este es en magenta.\n" << RESET;

    return 0;
}
