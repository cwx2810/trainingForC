#include "BuddySystem.c"

int main(int argc, char** argv)
{
	FreeList available;
	
	printf("函数InitSpace测试\n");
	{
		InitSpace_b(available);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为1的内存块后\n");
	{
		SpaceNode* p = AllocBuddy(available, 1);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为2的内存块后\n");
	{
		SpaceNode* p = AllocBuddy(available, 2);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为3的内存块后\n");
	{
		SpaceNode* p = AllocBuddy(available, 3);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为1的内存块后\n");
	{
		SpaceNode* p = AllocBuddy(available, 1);
		PrintLayout_b(available);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
