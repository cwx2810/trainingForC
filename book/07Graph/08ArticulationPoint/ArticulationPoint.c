#include "ArticulationPoint.h"

int FindArticulation(ALGraph G)
{
	//count=1表示根节点是第一个访问的节点 
	Visited[1] = count = 1;//设1号节点为生成树的根，0号单元弃用，visit中保存count，代表每个节点第几个访问，越小越祖先 
	for(int i=2; i<=G.vexNum; i++)//其余节点都初始化为未访问 
		Visited[i] = 0;
	ArcNode* p = G.vertex[1].firstArc;//得到根的下一个弧 
	int order = p->order;//得到该弧的尾节点序号
	
	//处理根的左子树 
	DFSArticulation(G, order);//遍历根的左子树找到关节点存储起来 
	
	//处理根和根的右子树的左子树 
	if(G.vexNum > count)//树根至少有2棵子树，因为上面DFS完了count代表左子树节点数目，如果此时节点总数比左子树节点多，说明有右子树嘛 
	{
		SavePoint(1);//保存根节点 
		while(p->nextArc)//遍历其他子树 
		{
			p = p->nextArc;
			order = p->order;
			if(Visited[order]==0)
				DFSArticulation(G, order);
		}
	}	
	 
	return 1;
}

int DFSArticulation(ALGraph G, int order)
{
	int min;//暂存最早祖先 
	Visited[order] = min = ++count;//order是第count个访问的节点
	
	for(ArcNode* p=G.vertex[order].firstArc; p; p=p->nextArc)
	{
		int w = p->order;//w为order的邻接点的序号 
		if(Visited[w]==0)//w未访问，则是order的孩子，则DFS挖掘 
		{
			DFSArticulation(G, w);
			if(low[w]<min)//节点的祖先比已经记录的都要早，则更新最早祖先 
				min = low[w];
			if(low[w]>=Visited[order])//子树中的节点DFS追溯的最早祖先序号比自己大，说明追不到比自己更早的祖先，则order合法，是关节点 
				SavePoint(order);
		} 
		else			//w已经访问过了，是order的祖先 
		{
			if(Visited[w]<min)//这个祖先比已经记录的都要早，则更新 
				min = Visited[w];
		}
		low[order] = min;//order顶点最早的祖先
	} 
	
	return 1;
}

int SavePoint(int order)
{
	for(int i=1; i<=node[0]; i++)
	{
		if(node[i]==order)//该关节点已经存储过 
			return 0;
	}
	node[0]++;//若合法，则数量＋1 
	node[node[0]] = order;//把order号关节点存储到最后 
	return 1;
}

int OutputPoint(ALGraph G)
{
	for(int i=1; i<=node[0]; i++)
		printf("第%2d个找到的关节点%c，先序编号为%2d\n", i, G.vertex[node[i]].data, node[i]);
}
