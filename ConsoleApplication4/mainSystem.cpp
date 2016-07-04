#include <iostream>
#include "unit.cpp"
#define VERSION 0.1
using namespace std;


bool beginGame()
{
	cout << "Hello, and welcome to game of duel v" << VERSION << endl;
	cout << "Please, make your choice: 0 for magician, 1 for warrior" << endl;
	bool res;
	cin >> res;
	return res;
}
int aiTurn(unit you)
{
	int bestOption = 0;
	int prevDMG = 0;
	for (int i = 0; i < 2; i++)
	{
		if (you.skills[i]->curCooldown == 0 && you.skills[i]->dmg>prevDMG)
		{
			prevDMG = you.skills[i]->dmg;
			bestOption = i;
		}
	}
	if (bestOption != 0)
		return bestOption;
	if (you.rangeDMG > you.meleeDMG)
		return 1;
	else
		return 0;
}
bool performTurn(unit *you, unit *enemy, int answer = 0)
{
	switch (answer)
	{
	case 1:
		you->attackMelee(enemy);
		break;
	case 2:
		you->attackRanged(enemy);
		break;
	case 3:
	case 4:
	case 5:
		you->useAbility(enemy, you->skills[answer - 3]);
		break;
	default:
		cout << "You entered incorrect number!" << endl;
		break;
	}

	system("cls");
	return true;
}
bool gameTick(unit *you, unit *enemy, int *turnCount)
{	
	if (enemy->health <= 0)
	{
		cout << "You won!" << endl;
		return false;
	}
	else if (you->health <= 0)
	{
		cout << "You lost!" << endl;
		return false;
	}
	canDo c;
	cout << *turnCount << " turn begins." << endl;
	cout << "You have " << you->health << " HP, "<<you->mana<<" MP." << endl;
	cout << "Enemy has " << enemy->health << " HP, " << enemy->mana << " MP." << endl;
	cout << "Please, say what you'll do next:" << endl;
	cout << "1: Attack melee" << endl;
	cout << "2: Attack ranged" << endl;
	cout << "3: Use ability "<< you->skills[0]->name << endl;
	cout << "4: Use ability " << you->skills[1]->name << endl;
	cout << "5: Use ability " << you->skills[2]->name << endl;
	int answer;
	cin >> answer;
	performTurn(you, enemy, answer);
	performTurn(enemy, you, aiTurn(*enemy));
	*turnCount += 1;
	return true;
}


class magician : public unit
{
public:
	magician(): unit(100, 5, 10, 4, 2, 150)
	{
		skills[0] = new ability("Fireball", 30, 10, 5, "A horrible fire falls on their heads!"); 
		skills[1] = new ability("Ice Shard", 40, 25, 8, "Your enemy turns into freaking ICE SHARD!"); 
		skills[2] = new ability("Whoosh", 3, 5, 1, "Something blows on your enemy!");
	}

};
class warrior : public unit
{
public:
	//From my p*nis
	warrior() : unit(100, 15, 3, 7, 6, 50)
	{
		skills[0] = new ability("Dash", 10, 10, 5,"YOU DASH!");
		skills[1] = new ability("Double Dash", 20, 25, 8, "YOU DASH HARDER!");
		skills[2] = new ability("Tripple Dash", 30, 40, 13, "YOU DASH THE DASHEST POSSIBLE");
	}
};

void main()
{
	int turnCount = 1;
	int *turn =  &turnCount;
	magician mp;
	warrior wr;
	bool selectedPlayer = beginGame();
	bool gameRuns = true;
	while (gameRuns)
		if (!selectedPlayer)
			gameRuns = gameTick(&mp, &wr, turn);
		else
			gameRuns = gameTick(&wr, &mp, turn);
	system("PAUSE");
}