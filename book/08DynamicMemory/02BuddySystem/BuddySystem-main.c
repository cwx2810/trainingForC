#include "BuddySystem.c"

int main(int argc, char** argv)
{
	FreeList available;
	
	printf("����InitSpace����\n");
	{
		InitSpace_b(available);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ1���ڴ���\n");
	{
		SpaceNode* p = AllocBuddy(available, 1);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ2���ڴ���\n");
	{
		SpaceNode* p = AllocBuddy(available, 2);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ3���ڴ���\n");
	{
		SpaceNode* p = AllocBuddy(available, 3);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ1���ڴ���\n");
	{
		SpaceNode* p = AllocBuddy(available, 1);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
