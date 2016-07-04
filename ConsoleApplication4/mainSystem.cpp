#include <iostream>
#include "Classes.cpp"

#define VERSION 0.1
#define numberOfAbilites  3
using namespace std;


unit *beginGame(unit possibleHumans[3])
{
	int i = 0;
	cout << "Hello, and welcome to game of duel v" << VERSION << endl;
	cout << "Please, make your choice:"<<endl;
	for each (unit s in possibleHumans)
	{
		cout <<  i << ": to select " << s.name << endl;
		i++;
	}
	int res;
	cin >> res;
	return &possibleHumans[res];
}
int aiTurn(unit *you)
{
	int bestOption = 0;
	int prevDMG = 0;
	for (int i = 0; i < numberOfAbilites; i++)
	{
		if (you->skills[i]->curCooldown == 0 && you->skills[i]->dmg>prevDMG)
		{
			prevDMG = you->skills[i]->dmg;
			bestOption = i+3;
		}
	}
	if (bestOption != 0)
		return bestOption;
	if (you->rangeDMG > you->meleeDMG)
		return attackRanged;
	else
		return attackMelee;
}
bool performTurn(unit *you, unit *enemy, int answer = 0)
{
	canDo c = (canDo)answer;
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
	performTurn(enemy, you, aiTurn(enemy));
	*turnCount += 1;
	return true;
}




void main()
{
	int turnCount = 1;
	int *turn =  &turnCount;

	magician mp;
	warrior wr;
	orc oc;
	unit possibleHumans[3] = { mp, wr, oc };
	unit *selectedPlayer = beginGame(possibleHumans);
	bool gameRuns = true;
	while (gameRuns)
		gameRuns  = gameTick(selectedPlayer, &wr, turn);
	system("PAUSE");
}