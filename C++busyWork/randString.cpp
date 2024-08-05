// Jason Berroa
// 08/04/24

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

// Function prototype to create the string
void makeRandString(const char* article[], const char* noun[], const char* verb[], const char* preposition[], int options, char* result);

int main() {
    // Initialize char arrays to pass to function
    const char* article[] = {"the", "a", "one", "some", "any"};
    const char* noun[] = {"boy", "girl", "dog", "town", "car"};
    const char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char* preposition[] = {"to", "from", "over", "under", "on"};

    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    // Initialize result string
    char sentence[100];

    for (int i = 0; i < 20; i++) { // make 20 random sentences and output
        makeRandString(article, noun, verb, preposition, 5, sentence);
        std::cout << sentence << std::endl;
    }

    return 0;
}

void makeRandString(const char* article[], const char* noun[], const char* verb[], const char* preposition[], int options, char* result) {
    // Initialize the result as an empty string
    result[0] = '\0';

    // Randomly select words from the provided arrays and concatenate them to the sentence
    strcat(result, article[rand() % options]);
    strcat(result, " ");
    strcat(result, noun[rand() % options]);
    strcat(result, " ");
    strcat(result, verb[rand() % options]);
    strcat(result, " ");
    strcat(result, preposition[rand() % options]);
    strcat(result, " ");
    strcat(result, article[rand() % options]);
    strcat(result, " ");
    strcat(result, noun[rand() % options]);
    strcat(result, ".");
    result[0] = toupper(result[0]); // make the first letter uppercase
}
