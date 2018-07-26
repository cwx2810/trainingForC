#include "BoundaryTagMethod.c"

int main(int argc, char** argv)
{
	SpaceNode memory[1000];
	SpaceNode* pstart;
	
	printf("����InitSpace����\n");
	{
		InitSpace(memory);
		pstart = start;
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ100���ڴ���\n");
	{
		SpaceNode* p = AllocBoundTag(&pstart, 100);
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ600���ڴ���\n");
	{
		SpaceNode* p = AllocBoundTag(&pstart, 600);
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ200���ڴ���\n");
	{
		SpaceNode* p = AllocBoundTag(&pstart, 200);
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
