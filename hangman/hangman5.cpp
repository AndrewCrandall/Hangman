/*
Andrew Crandall
CSC 160
12/4/2021
Title: Hangman #5
Summary: Obtain input from hangman.dat file, there are more decisions asking if the player would like to play hangman,
		 functions are in myFunctions.cpp and randWord.cpp, declared in myFuncts.h and randWord.h
		 There are ways for the player to win and lose the game.
*/

#include "myFuncts.h"   // includes function declaration from myFuncts.h
#include "randWord.h"  // includes function declaration from randWord.h


int main() //start of main
{

	/*
	int play is declared at 1
	string response declared
	string answer declared
	*/

	int play = 1;
	std::string response;
	int answer;

	std::cout << "WORDS!" << std::endl;
	std::cout << "-----------" << std::endl;
	getWords("hangman.dat"); // calls on getWords, to obtain all words in hangman.dat file


	while (play < 4) {    // Player gets three consecutive attempts to start a game, if the game doesn't start program ends


		std::cout << std::endl << "Would you like to play hangman? (y/n) ";   //output to console
		std::cin >> response;   //recieves input from console, storing into string "response"

		answer = promptYN(response);   // uses input from "response" to call on promptYn function, which is stored into "answer"



		if (answer == PLAY) {  // if the user decides to play hangman
			play = 1; // resets play to 1, allowing for another 3 consecutive attempts

			/*
			Declares string firstWord
			Declares int guesses, set to 0
			Declares char letter
			Declares Array letterGuessed, with 26 values equal to '0'
			Declares int count
			Declare String copy, copies firstWord
			bool correct is false until user guesses all correct letters in firstWord
			*/

			std::string firstWord;
			int guesses = 0;
			char letter;
			char letterGuessed[26];
			int count;
			std::string copy;
			bool correct = false;
			int used = 0;


			std::cout << std::endl << "Let's PLAY!" << std::endl << std::endl;   // output to console
			firstWord = getNextWord();   // calls function getNextWord, this is stored into firstWord
			firstWord = strToUpper(firstWord);   // calls on strToUpper, with firstWord variable


			std::cout << std::endl;


			// MASKED WORD

			copy = firstWord; // copies firstWord into string "copy". Replaces each letter into "_"
			for (int i = 0; i < firstWord.length(); i++) {
				copy[i] = '_';
			}

			std::cout << std::endl;




			//Outputs each letter with a space to console
			for (int i = 0; i < firstWord.length(); i++)
				std::cout << " " << copy[i] << " ";

			std::cout << std::endl;

			std::cout << drawBoards(guesses);   // draws corresponding board to the variable "guesses"


			while (guesses <= 5 && correct != true) { // while guess, is <= 5, meaning this is the maximum the user can get wrong

				// declares check as bool
				bool check;

				std::cout << std::endl;
				std::cout << std::endl;

				std::cout << "Enter a letter to guess";   // output to console, asking for letter input
				std::cin >> letter;   // obtains input from console, stores into char letter
				std::cout << "Your letter to guess is: " << letter << std::endl;  // outputs their letter to console
				letter = charToUpper(letter);  // calls on charToUpper using variable letter

				int found;

				found = binarySearch(letterGuessed, letter, used);

				if (found == -1) { // NOT FOUND and hasn't been used
					letterGuessed[used] = letter; // assigns the letterGuessed[used] with the letter guessed
					used++; // increment used allowing for another input to the array
					bubbleSort(letterGuessed, used); // call on bubble sort function

				}

				else {
					std::cout << "Already Guessed, try again!"; //the letterGuessed is already in the array
					continue;
				}


				/*
				Output Guessed Letters to the console after each turn.
				All the if statements check each index of the array letterGuessed
				Each value is associated with the letter of the alphabet
				*/



				std::cout << std::endl;
				std::cout << "GUESSED LETTERS: " << std::endl; // Outputs array
				std::cout << "----------------" << std::endl;

				for (int j = 0; j < used; j++) { // Outputs the values with ascii values of greater than 65 (alphabet)
					if (letterGuessed[j] >= 64)
						std::cout << " " << letterGuessed[j] << " ";
				}



				std::cout << std::endl;
				std::cout << std::endl;



				check = letterCheck(letter, firstWord); // calls on letterCheck using letter, and firstWord



				if (check == true) {   // if true letter is found in the word
					std::cout << letter << " is in the word to guess! " << std::endl; // outputs player correctly guessed
					std::cout << drawBoards(guesses); // draws corresponding board calling on drawBoards function


					/*
					Only if the user guesses a correct letter
					Loops through the firstWord
					Checks to see if the letter guessed is equal to ever index of firstWord[i]
					If the letter is equal to the letter in firstWord,
					The string "copy", then makes the same index that letter
					Outputs to the console
					*/

					for (int i = 0; i < firstWord.length(); i++) {
						if (letter == firstWord[i]) {
							copy[i] = firstWord[i];
						}
						std::cout << " " << copy[i] << " ";
					}

					/*
					Checks to see if the player has won the game, after each turn
					For loop goes through each index of string "copy" and "firstWord"
					If it is equal, counter increases by one

					if counter is equal to firstWord length, that means the player has won the game
					*/

					int counter = 0;

					for (int j = 0; j <= firstWord.length(); j++) {
						if (copy[j] == firstWord[j])
							counter = counter + 1;

						else {
							break;
						}


					}

					if (counter - 1 == firstWord.length()) {
						correct = true;
					}


					continue;
				}

				else if (check == false) {   // if check is false, the guess is not in the word
					std::cout << letter << " is NOT in the word to guess " << std::endl;   // outputs to user that the guess is incorrect
					guesses = guesses + 1; // adds 1 to guess variable
					std::cout << drawBoards(guesses);  // draws corresponding board


					//If the player guessed wrong, it will output copy[i], which will be all correct guesses possibly made as well as "_"
					for (int i = 0; i < firstWord.length(); i++)
						std::cout << " " << copy[i] << " ";

					std::cout << std::endl;
					std::cout << std::endl;

					continue;

				}



				else {   // on the chance that the program has an error, this will output to console
					std::cout << "Error playing the game, please restart." << std::endl; // outputs error message to console
					break; //ends game
				}


			}

			if (guesses >= 5) {

				std::cout << std::endl;
				std::cout << "Sorry you lose, the word was: " << firstWord << std::endl; // tells user that they exceeded the number of incorrect guesses
				// loops to the top of while loop, this will prompt the user to restart the game if wanted
			}


			if (correct == true) { // Player has won the game!
				std::cout << std::endl << std::endl << "Correct! Great job :)" << std::endl; // Output to the console
			}

		}


		else if (answer == STOP) // if user does not want to play
		{
			std::cout << std::endl << "Are you sure you don't want to play?" << std::endl; // output to console
			play = play + 1; // adds to play variable, if it exceeds 3 while loop ends
			continue; // continues to the top of the loop


		}
		else { // if there is an error input

			std::cout << "Error, please enter (y/n)"; // output to console to ask for y/n input
			play = play + 1; // adds to play variable, if it exceeds 3, while loop ends
			continue;
		}

	}

	std::cout << std::endl << "Thanks for playing!" << std::endl; // output to console, thanks user

	return 0; // end of int main
}
