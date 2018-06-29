#include "TripleSparseMatrix.c"

int main(int argc, char **argv)
{
	TMatrix M;
	
	printf("CreateMatrix测试...\n");
	{
		FILE *fp;
		printf("创建一个稀疏矩阵M\n");
		fp = fopen("TestData.txt", "r");
		CreateMatrix_T(fp, 1, &M);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("PrintMatrix测试...\n");
	{
		printf("M = \n");
		PrintMatrix_T(M);
		printf("\n");
	}
	PressEnter;
	
	printf("CopyMatrix测试...\n");
	{
		TMatrix Tmp;
		printf("复制M到Tmp\n");
		CopyMatrix_T(M, &Tmp);
		printf("Tmp = \n");
		PrintMatrix_T(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("TransposeMatrix测试...\n");
	{
		TMatrix T;
		TransposeMatrix_T(M, &T);
		printf("M的转置T = \n");
		PrintMatrix_T(T);
		printf("\n");
	}
	PressEnter;
	
	printf("FastTransposeMatrix测试...\n");
	{
		TMatrix FT;
		FastTransposeMatrix_T(M, &FT);
		printf("M的快速转置FT = \n");
		PrintMatrix_T(FT);
		printf("\n");
	}
	PressEnter;
	
	printf("DestroyMatrix测试...\n");
	{
		DestroyMatrix_T(&M);
		M.rows && M.cols && M.nozeros ? printf("M存在\n") : printf("M不存在\n");
		printf("\n");
	}
	PressEnter;
	
	return 1;
}
