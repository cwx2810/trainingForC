#include "NQueens.c"

int main(int argc, char** argv)
{
	int c[N][N];
	
	printf("InitChassBoard≤‚ ‘\n");
	{
		InitChassBoard_CB(c);
		printf("≥ı ºªØ∆Â≈ÃÕÍ≥…\n");
		printf("\n");
	}
	PressEnter;
	
	printf("Output≤‚ ‘\n");
	{
		Output_CB(c);
		printf("\n");
	}
	PressEnter;
	
	printf("Trail≤‚ ‘\n");
	{
		Trial_CB(1, c);
		printf("\n");
	}
	PressEnter;
}
