#include<stdio.h>
#define nv 4
#define INF 999
void printMatrix(int matrix[][nv]);

void printMatrix(int matrix[][nv])
{
	for(int i=0;i<nv;i++){
		for(int j=0;j<nv;j++){
			if(matrix[i][j]==INF)
				printf("%4s","INF");
			else
				printf("%4d",matrix[i][j]);
		}
		printf("\n");
	}
}
void floydWarshall(int graph[][nv]){
	int matrix[nv][nv],i,j,k;
	for(i=0;i<nv;i++)
		for(j=0;j<nv;j++)
			matrix[i][j] = graph[i][j];
			
		
	for(k=0;k<nv;k++){
		for(i=0;i<nv;i++){
			for(j=0;j<nv;j++){
				if(matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j]=matrix[i][k] + matrix[k][j];
			}
		}		
	}
	printMatrix(matrix);
} 

int main(){
	int graph[nv][nv]= {{0,3,INF,7},
	                   {8,0,2,INF},
					   {5,INF,0,1},
					   {2,INF,INF,0}};
	floydWarshall(graph);
	return 0;
}