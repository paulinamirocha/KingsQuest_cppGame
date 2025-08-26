#include <iostream>
#include <string>

#define true 1
#define false 0

using namespace std;



// -----

// THE TEMPLATE FOR CHARACTERS
struct Character
{
	string Name;		// what is the character called
	float Health;		// what is the remaining health of the character
	float Damage;		// how strong is the character
	int Stamina;		// how many times the character can attack before fainting

	void TakeDamage(float Damage)
	{
		Health = Health -= Damage; //subtracts dmg from Health
	}

};


//CHARACTER STRUCTURES -> Name,		MaxHP,	AttackDMG, Stamina

Character Bob =		{	"Bob",		100.f,	15.f,		1};

Character Frank =	{	"Frank",	75.f,	25.f,		1};

Character Jon =		{	"Jon",		200.f,	10.f,		1};

Character Dragon =	{	"Dragon",	150.f,	30.f,		5};


// GLOBAL VARIABLES

bool CanAttack = false;			// attack will happen by default

bool FirstAttack = true;		// safecheck so the intro rolls only once

Character* CurrentCharacter;	// pointer for the chosen character

string CharacterName;			// allows the player to choose the character


// -----

int main()

{
	// INTRO

	if (FirstAttack == true)	// it fires out only at the beginning of the game
	{
		cout << "After a very long journey, you finally arrive at the Dragon's Den, where you will face the King's challenge.\nCan you succeed, or will you join those bones at your feet?\n\n";
		system("pause");
			
		cout << "\nBut first, let's get to know our opponent!\n\n";
		cout << Dragon.Name << "'s Statistics: " << Dragon.Health << " Health, and " << Dragon.Damage << " Damage per Attack.\n";
		cout << "It has Stamina to withstand " << Dragon.Stamina << " rounds of fight! What a beast!\n\n";
		system("pause");

		cout << "\nAnd now, it's time to meet your little helpers!\n\n";
		cout << Bob.Name << "'s Statistics: " << Bob.Health << " Health, and " << Bob.Damage << " Damage per Attack.\n";
		cout << Frank.Name << "'s Statistics: " << Frank.Health << " Health, and " << Frank.Damage << " Damage per Attack.\n";
		cout << Jon.Name << "'s Statistics: " << Jon.Health << " Health, and " << Jon.Damage << " Damage per Attack.\n\n";
		
		FirstAttack = false;	// safety bool so the character infos cout only at the beginning
	}


	cout << "Which character do you want to deploy to fight the Dragon this round?\nBOB, FRANK, or JON?\n\n";

	cin >> CharacterName;	// player chooses which character to use


	if (CharacterName == "Frank" || CharacterName == "frank")
	{
		CanAttack = true;
		CurrentCharacter = &Frank;
	}

	else if (CharacterName == "Bob" || CharacterName == "bob")
	{
		CanAttack = true;
		CurrentCharacter = &Bob;
	}

	else if (CharacterName == "Jon" || CharacterName == "jon")
	{
		CanAttack = true;
		CurrentCharacter = &Jon;
	}

	else
	{
		CanAttack = false;

		cout << "This character does not exist! Try again.\n\n";
	}


	// THE REPEATABLE PART OF THE GAME - THE FIGHT WITH THE DRAGON

	while (Dragon.Stamina > 0)
	{
		if (Dragon.Stamina % 2 == 0 && CanAttack == true)
		{
			Dragon.Stamina--;

			Dragon.TakeDamage(CurrentCharacter->Damage);	// the Dragon takes damage from CurrentCharacter
			CurrentCharacter->TakeDamage(Dragon.Damage);	// CurrentCharacter takes damage from the Dragon

			//the fighting part of the round
			cout << endl;
			cout << "Chosen character: " << CurrentCharacter->Name << ".\n\n";
			
			cout << CurrentCharacter->Name << " charges forward!" << " (Damage: " << CurrentCharacter->Damage << ".)\n\n";

			cout << "Dragon's New Health: " << Dragon.Health << "\n\n";

			cout << "The Dragon attacks." << " (Damage: " << Dragon.Damage << ".)\n\n";

			cout << CurrentCharacter->Name << "'s New Health: " << CurrentCharacter-> Health << ".\n\n";

			cout << "Dragon's Current Stamina: " << Dragon.Stamina << ".\n\n";

			cout << "-----" << endl;

			break;
		}

		else if (Dragon.Stamina % 2 == 1 && CanAttack == true)
		{
			Dragon.Stamina--;

			Dragon.TakeDamage(CurrentCharacter->Damage);	// the Dragon takes damage from CurrentCharacter
			//---											// the Dragon does not attack this turn

			//the fighting part of the turn
			cout << endl;
			cout << "Chosen character: " << CurrentCharacter->Name << ".\n\n";
				
			cout << CurrentCharacter->Name << " charges forward!" << " (Damage: " << CurrentCharacter->Damage << ".) \n\n";

			cout << "Dragon's New Health: " << Dragon.Health << "\n\n";

			cout << "The Dragon growls." << " (Damage: 0)\n\n";

			cout << CurrentCharacter->Name << "'s New Health: " << CurrentCharacter->Health << ".\n\n";

			cout << "Dragon's Current Stamina: " << Dragon.Stamina << ".\n\n";

			cout << "-----" << endl;

			break;
		}

		else
		{
			break;
		}
	}

	
	// END SEQUENCE -> pops up when the dragon has no energy to fight

	if (Dragon.Stamina == 0 && (CanAttack == true || CanAttack == false))
	{
		cout << "What a fight! The dragon is too tired for another strike.\nIt leaves the Den with " << Dragon.Health << " Health left." << endl;
		cout << "You've won the King's challenge!\n";
		system("pause");
	}

	else
	{ 
		return main();	// if the dragon can attack again, jump back to the beginning of int main
	}
	
};