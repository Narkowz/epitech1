#include "Student.hpp"
#include "Assistant.hpp"
#include "Dean.hpp"
#include <cstdlib> // Pour std::srand
#include <ctime>   // Pour std::time

int main() {
    // Initialisation du générateur aléatoire
    std::srand(std::time(nullptr));

    // Création d'un étudiant, d'un assistant et d'un doyen
    Student student1("Alice");
    Assistant assistant(42);
    Dean dean("Dr. Smith");

    // Début du travail du doyen
    dean.timeCheck();

    // Le doyen enseigne une leçon
    dean.teachStudent(&student1, "Learning C++ is fun!");

    // Le doyen enseigne une autre leçon (éventuellement sans énergie)
    dean.teachStudent(&student1, "Mastering C++ in one week!");

    // Le doyen termine son travail
    dean.timeCheck();

    // L'assistant aide l'étudiant
    assistant.timeCheck();
    assistant.helpStudent(&student1);
    assistant.timeCheck();

    return 0;
}
