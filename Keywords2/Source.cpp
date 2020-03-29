#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


int main()
{

	// Display Title of the program to the user
	cout << "\n\n\t\t *** Welcome to the CIA Game Breaker Training program!";
	// Ask the recruit to log in using their name
	cout << "\nEnter your name: ";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name;
	getline(cin, name);
	// Display an overview of what Keywords II is to the recruit 
	cout << "This is meant to test your ability to accurately guess my Keywords!\n";
	// Display directions to the recruit on how to use Keywords
	cout << "Simply type in the letter. My program will tell you if you're right or wrong! Type the correct letters to guess a word! Try to get all 10!\n";


	// Create a collection of 10 words you had written down manually
	vector<string> words;
	words.push_back("GENERAL");
	words.push_back("TIMING");
	words.push_back("ITEMS");
	words.push_back("FORGE");
	words.push_back("SIMPLY");
	words.push_back("MASTER");
	words.push_back("FIRE");
	words.push_back("RETREAT");
	words.push_back("ADVANCE");
	words.push_back("FINAL");
	// Create an int var to count the number of simulations being run starting at 1
	int simulation_number = 1;
	string play_again;
	do
	{
		// Display the simulation # is starting to the recruit. 
		cout << "Simulation #" << simulation_number;
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		for (int i = 0; i < 3; i++)
		{
			srand(time(0));
			random_shuffle(words.begin(), words.end());
			string word = words[0];
			string guess(word.length(), '_');
			string guessed_letters;
			int incorrect_guesses = 0;


			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while (incorrect_guesses < 4 && guess != word)
			{

				//     Tell recruit how many incorrect guesses he or she has left
				cout << "incorrect guesses: " << 4 - incorrect_guesses << endl;
				//     Show recruit the letters he or she has guessed
				cout << "letters guessed: " << guessed_letters << endl;
				//     Show player how much of the secret word he or she has guessed
				cout << "word so far: " << guess << endl;
				//     Get recruit's next guess
				cout << "Enter your next guess: ";
				string letters;
				getline(cin, letters);

				for (int j = 0; j < letters.length(); j++)
				{
					//     While recruit has entered a letter that he or she has already guessed
					while (guessed_letters.find(letters[j]) != string::npos)
					{
						//          Get recruit ’s guess
						getline(cin, letters);
					}
					letters[j] = toupper(letters[j]);
				}
				//     Add the new guess to the group of used letters
				guessed_letters += letters;

				for (char letter : letters)
				{
					bool letter_found = false;
					for (int j = 0; j < word.length(); j++)
					{
						if (word[j] == letter)
						{
							guess[j] = letter;
							letter_found = true;
						}
					}
					if (letter_found == false)
					{
						incorrect_guesses++;
					}
				}
			}
		

				// If the recruit has made too many incorrect guesses
				if (incorrect_guesses >= 4)
				{
					//     Tell the recruit that he or she has failed the Keywords II course.
					cout << "Sorry, you got it wrong\n";
				}
				// Otherwise
				else
				{
					//     Congratulate the recruit on guessing the secret words
					cout << "Congratulations, you got it right!\n";
				}
				cout << "Your word was : " << word << endl;
		}
	


		// Ask the recruit if they would like to run the simulation again
		cout << "Do you want to play again?";
		getline(cin, play_again);
		// If the recruit wants to run the simulation again
		if (play_again.find('Y') != string::npos)
		{
			//     Increment the number of simulations ran counter
			simulation_number++;
			//     Move program execution back up to // Display the simulation # is starting to the recruit. 
		}
		// Otherwise 
	} while (play_again.find('Y') != string::npos);
	//     Display End of Simulations to the recruit
	cout << "number of simulations ran: " << simulation_number << endl;
	//     Pause the Simulation with press any key to continue
	system("pause");
	return 0;
}