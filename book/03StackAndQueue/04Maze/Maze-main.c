#include "Maze.c"

int main(int argc, char **argv)
{
	int maze[15][15];
	MazePos start,end;
	MazeInfo info;
	char Re = 'Y';
	
	while(Re=='Y' || Re=='y')
	{
		InitMaze(maze, &start, &end);
		ShowMaze(maze);
		MazePath(maze, start, end);
		
		printf("÷ÿ÷√£ø(Y/N)£∫");
		scanf("%c", &Re);
	}
	return 0;
}


