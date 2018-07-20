#include "MST.h"

int MiniSpanTree_Prim(MGraph G, char e)
{
	EdgeNode closedge[G.vexNum+1];//0号单元弃用，建立辅助数组保存边的权值 
	int order = LocateVertex_M(G, e);//得到给定的起始顶点的序号
	 
	//初始化辅助数组，保存给定顶点到其余顶点的权值
	for(int j=1; j<=G.vexNum; j++) 
	{
		//if(j!=order)//自己到自己没意义 
		//{
			//closedge[j].vertex = e;//保存字母不重要 
			closedge[j].lowcost = G.matrix[order][j].vertexRelation;//保存当前节点到各点的权值 
		//}
	} 
	closedge[order].lowcost = 0;//设定辅助数组中起始顶点到起始顶点的权值为0，以便在下面的遍历中忽略 
	
	printf("Start:%c\n", e);//打印起始节点，其后就可以通过辅助数组依次打印到其余边的最小权值、最小权值边的尾节点了 
	
	//更新辅助数组，探索战争迷雾，找已连接出的图连向其他节点的最小权值 
	for(int i=1; i<=G.vexNum-1; i++)//总共需要vexNum-1次寻找最小边，因为生成树不能构成回路，边最大也要比节点少1 
	{
		order = Minimum(closedge, G.vexNum);//寻找辅助数组中权值最小的边的序号，忽略0权边 
		printf("--%2d--%c\n", closedge[order].lowcost, G.vertex[order]);//打印最小边的权值和最小边对应的尾节点
		
		closedge[order].lowcost = 0;//最小边权值置0，这样再寻找下一个最小边时就会忽略这条边 
		for(int j=1; j<=G.vexNum; j++)//找到已经完成探索的最小权值图中，伸向其余顶点的最小权值，更新到辅助数组中
		{
			if(G.matrix[order][j].vertexRelation < closedge[j].lowcost)//怎么找？最新探索出的顶点到其余顶点的权值如果比原来辅助数组中同样位子的要小，则更新 
			{
				//closedge[j].vertex = G.vertex[order];
				closedge[j].lowcost = G.matrix[order][j].vertexRelation;//把最新最小权值更新到辅助数组中同样的位置 
			} 
		} 
	}
	return 1;
}

int Minimum(EdgeNode closedge[], int n)
{
	int min = INT_MAX;
	int order=0;
	for(int i=1; i<=n; i++)
	{
		if(closedge[i].lowcost)//从权值不为0的边中选权值最小的边
		{
			if(closedge[i].lowcost<=min) 
			{
				min = closedge[i].lowcost;
				order = i;
			}
		} 
	}
	return order;
}
