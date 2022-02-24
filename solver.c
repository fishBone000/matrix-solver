#include<stdio.h>
#include<stdlib.h>

void simplify(int *source, int *target, int count, int lvl){
	int t_factor = target[lvl];
	int s_factor = source[lvl];
	for(int i = lvl; i < count+1; i++)
		target[i] = source[i]*t_factor - target[i]*s_factor;
}
int main(){
	int count;
	printf("Count of unknowns: ");
	scanf("%d", &count);
	int matrix[count][count+1];
	printf("Matrix:\n");
	for(int i = 0; i < count; i++)
		for(int j = 0; j < count+1; j++)
			scanf("%d", &matrix[i][j]);

	int lvl = 0;
	int *source = matrix[lvl];
	int *target;
	while(lvl < count-1){
		for(int i = 1; i+lvl < count; i++){
			target = matrix[lvl+i];
			simplify(source, target, count, lvl);
		}
		source = matrix[++lvl];
	}

	for(int i = 0; i < count+1; i++)
		printf("%d ", matrix[count-1][i]);

	return 0;
}
