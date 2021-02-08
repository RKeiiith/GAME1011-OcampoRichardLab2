/*
 * GAME1011 - Advanced Programming Lab 2
 * Prof. Joss Moo Young and Wallace Balaniuc
 *
 * Student: Richard Ocampo (101332726)
 * 
 */


#include <iostream>
#include <string>

using namespace std;

//Base Class
//Abstract base character class
class characterClass
{
	public:
		string characterName;
		string classVoice;
		int characterHP = 0;
		virtual string DisplayInfo() = 0;
	
};

//Another stand alone weapon class
class weaponClass
{
public:
	string weaponName;
	string description;
	int damageValue = 0;
	string specialSkillArray[3] = { "Double Attack", "Glass Cannon", "Fortified Sentinel" };
};


//DERIVED CLASSES / INHERITED CLASSES
//There are 3 classes. Assassin, Mage and Warrior
//The unique trait (virtual function) is the class voice
class Assassin : public characterClass
{
public:
	string DisplayInfo() override
	{
		classVoice = "Your death will be swift.... but deadly";
		
		return (classVoice);
	};
	
};

class Mage : public characterClass
{
public:
	string DisplayInfo() override
	{
		classVoice = "You will perish by the power of my magic!";
		return (classVoice);
	}
	
};

class Warrior : public characterClass
{
public:
	string DisplayInfo() override
	{
		classVoice = "CHAARRGE!!!!!!!";
		return (classVoice);
	}
};


//Main
int main()
{
	//Class Objects
	Assassin myAssassin;
	Mage myMage;
	Warrior myWarrior;
	weaponClass myWeapon;
	
	//Variable Declaration
	string className;
	int mainMenuChoice = 0;
	int characterChoice = 0;
	int classID = 0;
	bool mainMenuQuit = false;
	bool classSelect = false;


	/*
	 * MAIN MENU While loop. User indicate choice by entering a number. The user stays on this loop until they choose to quit
	 */
	
	while (!mainMenuQuit == true)
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "GAME1011 - Lab 2 by Richard Ocampo (101332726)" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "WELCOME TO THE CHARACTER SELECTION SCREEN" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "1) Create a Character" << endl;
		cout << "2) View Character" << endl;
		cout << "3) Delete Character" << endl;
		cout << "4) Exit Program" << endl;
		cout << "------------------------" << endl;
		cout << "Please specify your choice (Enter 1-4): ";
		cin >> mainMenuChoice;


		if (mainMenuChoice == 1)
		{

			//CREATE A character. Another while loop.
			//Indicate choice
			//Break out of this loop once the character is created
			while (!classSelect == true)
			{
				classID = 0;
				mainMenuChoice = 0;
				characterChoice = 0;
				
				cout << "------------------------" << endl;
				cout << "SELECT A CLASS!" << endl;
				cout << "------------------------" << endl;
				cout << "1) Assassin" << endl;
				cout << "2) Mage" << endl;
				cout << "3) Warrior" << endl;
				cout << "Please specify your choice (Enter 1-3): ";
				cin >> characterChoice;


				//Assassin Selected. Initialize theses traits
				if (characterChoice == 1)
				{
				
					cout << "ASSASSIN SELECTED" << endl;
					cout << "Enter the Name of the character: ";
					cin >> myAssassin.characterName;
					cout << "CHARACTER CREATED!" << endl;
					
					classID = 1;
					classSelect = true;
					myWeapon.weaponName = "Bloody Dagger";
					myWeapon.description = "Incredibly Bloody!";
					myWeapon.damageValue = 80;
					myAssassin.characterHP = 70;
					myWeapon.specialSkillArray[0];
				
				}

				//Mage Selected. Initialize theses traits
				else if (characterChoice == 2)
				{
					cout << "MAGE SELECTED" << endl;
					cout << "Enter the Name of the character: ";
					cin >> myMage.characterName;
					cout << "CHARACTER CREATED!" << endl;
					
					classID = 2;
					classSelect = true;
					myWeapon.weaponName = "Ice Staff";
					myWeapon.description = "Incredibly Frosty!";
					myWeapon.damageValue = 30;
					myWeapon.specialSkillArray[1];
					myMage.characterHP = 50;
				
				}

				//Warrior Selected. Initialize theses traits
				else if (characterChoice == 3)
				{
					cout << "WARRIOR SELECTED" << endl;
					cout << "Enter the Name of the character: ";
					cin >> myWarrior.characterName;
					cout << "CHARACTER CREATED!" << endl;

					classID = 3;
					classSelect = true;
					myWeapon.weaponName = "Barbaric Axe";
					myWeapon.description = "A very mighty axe!";
					myWeapon.damageValue = 95;
					myWeapon.specialSkillArray[2];
					myWarrior.characterHP = 120;
			
				}

				//Input validation
				else
				{
					cout << "ERROR: Enter a number of 1-3!";
					classID = 0;
					classSelect = false;
				}
				
			}

			
		}

		//Display the character's information.
		//After creating the character. (It must be created first)
		//Depending on the class chosen, display the specific character's traits to the console
		
		else if (mainMenuChoice == 2)
		{
			cout << "-------------------------" << endl;
			cout << "CHARACTER INFORMATION" << endl;
			cout << "-------------------------" << endl;

			
			if (classID == 1)
			{
				cout << "Character Name: " << myAssassin.characterName << endl;
				cout << "Character HP: " << myAssassin.characterHP << endl;
				cout << "Unique Voiceline: " << myAssassin.DisplayInfo() << endl;
				cout << "-------------------------" << endl;
				cout << "EQUIPMENT INFORMATION" << endl;
				cout << "-------------------------" << endl;
				cout << "Starting Weapon: " << myWeapon.weaponName << endl;
				cout << "Weapon Description: " << myWeapon.description << endl;
				cout << "Damage Value: " << myWeapon.damageValue << endl;
				cout << "Weapon Skill: " << myWeapon.specialSkillArray[0] << endl;
				
			}

			else if (classID == 2)
			{
				cout << "Character Name: " << myMage.characterName << endl;
				cout << "Character HP: " << myMage.characterHP << endl;
				cout << "Unique Voiceline: " << myMage.DisplayInfo() << endl;
				cout << "-------------------------" << endl;
				cout << "EQUIPMENT INFORMATION" << endl;
				cout << "-------------------------" << endl;
				cout << "Starting Weapon: " << myWeapon.weaponName << endl;
				cout << "Weapon Description: " << myWeapon.description << endl;
				cout << "Damage Value: " << myWeapon.damageValue << endl;
				cout << "Weapon Skill: " << myWeapon.specialSkillArray[1] << endl;
			}

			else if (classID == 3)
			{
				cout << "Character Name: " << myWarrior.characterName << endl;
				cout << "Character HP: " << myWarrior.characterHP << endl;
				cout << "Unique Voiceline: " << myWarrior.DisplayInfo() << endl;
				cout << "-------------------------" << endl;
				cout << "EQUIPMENT INFORMATION" << endl;
				cout << "-------------------------" << endl;
				cout << "Starting Weapon: " << myWeapon.weaponName << endl;
				cout << "Weapon Description: " << myWeapon.description << endl;
				cout << "Damage Value: " << myWeapon.damageValue << endl;
				cout << "Weapon Skill: " << myWeapon.specialSkillArray[2] << endl;
			}
		
		
			
		}

		//Delete the character
		else if (mainMenuChoice == 3)
		{
			cout << "Character Deleted!" << endl;
			classID = 0;
			mainMenuChoice = 0;
			characterChoice = 0;
		}

		//Exit
		else if (mainMenuChoice == 4)
		{
			mainMenuQuit = true;
			cout << "Exiting program..." << endl;
		}
	}
	
}