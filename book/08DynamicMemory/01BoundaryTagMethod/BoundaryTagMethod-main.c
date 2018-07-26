#include "BoundaryTagMethod.c"

int main(int argc, char** argv)
{
	SpaceNode memory[1000];
	SpaceNode* pstart;
	
	printf("函数InitSpace测试\n");
	{
		InitSpace(memory);
		pstart = start;
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为100的内存块后\n");
	{
		SpaceNode* p = AllocBoundTag(&pstart, 100);
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为600的内存块后\n");
	{
		SpaceNode* p = AllocBoundTag(&pstart, 600);
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	printf("申请大小为200的内存块后\n");
	{
		SpaceNode* p = AllocBoundTag(&pstart, 200);
		PrintLayout(start, pstart);
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
