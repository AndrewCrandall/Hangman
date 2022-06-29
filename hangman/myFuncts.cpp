/*
Andrew Crandall
CSC 160
12/4/2021
Title: Function Implementations
Summary: Functions declared within myFuncts.h file
*/

#include "myFuncts.h" // includes 


/*
promptYN

obtains string reply variable
converts reply to uppercase calling on the strToUpper function
checks for all of the options to play the game, such as YES, SURE, OK, and Y
checks for all options to NOT play game such as, NO, QUIT, STOP, N, Q, TERMINATE
returns appropriate input such as PLAY, STOP, and ERROR
*/

int promptYN(std::string reply)
{
	reply = strToUpper(reply);
	if (reply == "YES" || reply == "SURE" || reply == "OK" || reply == "Y")
		return PLAY;
	else if (reply == "NO" || reply == "QUIT" || reply == "STOP" || reply == "N" || reply == "Q" || reply == "TERMINATE")
		return STOP;
	else
		return ERROR;
}


/*
strToUpper

takes variable string str
for i length of string, convert toupper
return ans (fully uppercased str)
*/

std::string strToUpper(std::string str)
{
	std::string ans = str;
	for (int i = 0; i < ans.length(); i++)
		ans[i] = toupper(str[i]);
	return ans;
}

/*
strToLower

takes variable string str
for i length of string, convert tolower
return ans (fully lowercased str)
*/

std::string strToLower(std::string str)
{
	std::string ans = str;
	for (int i = 0; i < ans.length(); i++)
		ans[i] = tolower(str[i]);
	return ans;
}

/*
charToUpper

obtains char variable letter
converts letter toupper
returns uppercased letter
*/
char charToUpper(char letter) {
	letter = toupper(letter);
	return letter;
}


/*
drawBoards

parameter of int wrongGuesses
declares all of the different hangman boards, as constants
checks for what value wrongGuesses, returns the correct board
*/
std::string drawBoards(int wrongGuesses) {
	const std::string BOARD_1 =

		" -------| \n"
		" |      | \n"
		"        | \n"
		"        | \n"
		"        | \n"
		"        | \n"
		"       ____ \n";

	const std::string BOARD_2 =

		" -------| \n"
		" |      | \n"
		" O      | \n"
		"        | \n"
		"        | \n"
		"        | \n"
		"       ____ \n";

	const std::string BOARD_3 =

		" -------| \n"
		" |      | \n"
		" O      | \n"
		" |      | \n"
		"        | \n"
		"        | \n"
		"       ____ \n";

	const std::string BOARD_4 =

		" -------| \n"
		" |      | \n"
		" O      | \n"
		"-|      | \n"
		"        | \n"
		"        | \n"
		"       ____ \n";

	const std::string BOARD_5 =


		" -------| \n"
		" |      | \n"
		" O      | \n"
		"-|-     | \n"
		"        | \n"
		"        | \n"
		"       ____ \n";

	const std::string BOARD_6 =

		" -------| \n"
		" |      | \n"
		" O      | \n"
		"-|-     | \n"
		"/       | \n"
		"        | \n"
		"       ____ \n";

	const std::string BOARD_7 =

		" -------| \n"
		" |      | \n"
		" O      | \n"
		"-|-     | \n"
		"/ \\     | \n"
		"        | \n"
		"       ____ \n";

	if (wrongGuesses == 0)
		return BOARD_1;


	else if (wrongGuesses == 1)
		return BOARD_2;


	else if (wrongGuesses == 2)
		return BOARD_3;


	else if (wrongGuesses == 3)
		return BOARD_4;


	else if (wrongGuesses == 4)
		return BOARD_5;


	else if (wrongGuesses == 5)
		return BOARD_6;


	else if (wrongGuesses == 6)
		return BOARD_7;



}

/*
letterCheck

has letter and string parameter
converts both letter and string toupper
uses find function to see if char is in the word, if so, return true, if not return false
if not return error
*/


bool letterCheck(char letter, std::string word) {
	letter = charToUpper(letter);
	word = strToUpper(word);

	if (word.find(letter) != std::string::npos) {
		return true;
	}
	else
		return false;

}



/*
BinarySearch
takes array, letter, and int
sorts through the array, with variable start and end
start is equal to 0
end is equal to int passed through

*/

int binarySearch(char usedLetters[], char letterToGuess, int used) {
	int start = 0;
	int end = used - 1;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (usedLetters[mid] == letterToGuess)
			return mid;
		else if (letterToGuess > usedLetters[mid]) {
			start = mid + 1;
		}
		else if (letterToGuess < usedLetters[mid])
			end = mid - 1;
	}
	return -1;

}

void bubbleSort(char nums[], int used) {
	for (int i = 0; i <= used + 1; i++) {
		for (int j = 0; j < used - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
		used--;
	}
}