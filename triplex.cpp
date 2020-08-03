#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nYou are a secret agent!!!! You have to enter the level " << Difficulty; 
    std::cout << " secure server room!\nTo do that you have to find the correct codes\n\n";
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;

    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "* There are 3 numbers in the code\n" ;
    std::cout << "* Sum of 3 numbers is : " << CodeSum;
    std::cout << "\n* The codes multiply to give:  " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\nYou entered: " << GuessA <<  GuessB <<  GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if ( GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n*** Perfect! Moving to next level ***";
        return true;
    }else {
        std::cout << "\n*** Try again!! ***";
        return false;
    }
}

int main(){

    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    while(LevelDifficulty <= 5){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete) {
            ++LevelDifficulty;
        }
    }
    std::cout << "\nGreat job! You got all the files. It's time to get out there";
    return 0;    
}