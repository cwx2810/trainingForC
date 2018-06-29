#include "TripleSparseMatrix.c"

int main(int argc, char **argv)
{
	TMatrix M;
	
	printf("CreateMatrix����...\n");
	{
		FILE *fp;
		printf("����һ��ϡ�����M\n");
		fp = fopen("TestData.txt", "r");
		CreateMatrix_T(fp, 1, &M);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("PrintMatrix����...\n");
	{
		printf("M = \n");
		PrintMatrix_T(M);
		printf("\n");
	}
	PressEnter;
	
	printf("CopyMatrix����...\n");
	{
		TMatrix Tmp;
		printf("����M��Tmp\n");
		CopyMatrix_T(M, &Tmp);
		printf("Tmp = \n");
		PrintMatrix_T(Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("TransposeMatrix����...\n");
	{
		TMatrix T;
		TransposeMatrix_T(M, &T);
		printf("M��ת��T = \n");
		PrintMatrix_T(T);
		printf("\n");
	}
	PressEnter;
	
	printf("FastTransposeMatrix����...\n");
	{
		TMatrix FT;
		FastTransposeMatrix_T(M, &FT);
		printf("M�Ŀ���ת��FT = \n");
		PrintMatrix_T(FT);
		printf("\n");
	}
	PressEnter;
	
	printf("DestroyMatrix����...\n");
	{
		DestroyMatrix_T(&M);
		M.rows && M.cols && M.nozeros ? printf("M����\n") : printf("M������\n");
		printf("\n");
	}
	PressEnter;
	
	return 1;
}
