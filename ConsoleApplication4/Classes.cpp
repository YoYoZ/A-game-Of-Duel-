#include "unit.cpp"
class magician : public unit
{
public:
	magician() : unit(100, 5, 10, 4, 2, 150, "Magician")
	{
		skills[0] = new ability("Fireball", 30, 10, 5, "A horrible fire falls on their heads!");
		skills[1] = new ability("Ice Shard", 40, 25, 8, "Your enemy turns into freaking ICE SHARD!");
		skills[2] = new ability("Whoosh", 3, 5, 1, "Something blows on your enemy!");
	}

};
class warrior : public unit
{
public:
	
	warrior() : unit(100, 15, 3, 7, 6, 50, "Warrior")
	{
		skills[0] = new ability("Dash", 10, 10, 5, "YOU DASH!");
		skills[1] = new ability("Double Dash", 20, 25, 8, "YOU DASH HARDER!");
		skills[2] = new ability("Tripple Dash", 30, 40, 13, "YOU DASH THE DASHEST POSSIBLE");
	}
};

class orc : public unit
{
public:

	orc() : unit(100, 15, 3, 7, 6, 50, "Orc")
	{
		skills[0] = new ability("Dash", 10, 10, 5, "YOU DASH!");
		skills[1] = new ability("Double Dash", 20, 25, 8, "YOU DASH HARDER!");
		skills[2] = new ability("Tripple Dash", 30, 40, 13, "YOU DASH THE DASHEST POSSIBLE");
	}
};