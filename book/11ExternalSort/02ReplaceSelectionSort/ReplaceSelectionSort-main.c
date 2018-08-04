#include "ReplaceSelectionSort.c"

int main(int argc, char** argv)
{
	int ls[6];
	RecordNode wa[6];
	
	printf("÷√ªª—°‘Ò≈≈–Ú≤‚ ‘\n");
	{
		FILE* fp_in = fopen("TestData.txt", "r");
		Replace_Selection(fp_in, ls, wa);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
