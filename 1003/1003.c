#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,k,N,test_case;
	int start_index,end_index,tmp_max,tmp_sum;
	int* array;
	
	scanf("%d",&test_case);
	for(k = 1;k <=test_case;k++)
	{
		scanf("%d",&N);
		array = (int *)malloc(N*sizeof(int));
		for(i = 0; i < N;i++)
		{
			scanf("%d",&array[i]);
		}
		start_index = end_index = 0;
		tmp_max = tmp_sum = array[0];
		
		for(i =1;i<N;i++)
		{		
			if(tmp_sum + array[i] < array[i])
			{
				tmp_sum = array[i];
				start_index = i;
			}
			else
			{
				tmp_sum += array[i];
			}
			if(tmp_sum > tmp_max)
			{
				tmp_max = tmp_sum;
				start_index = start_index;
				end_index = i;
			}
		}
		
		printf("Case %d:\n",k);
		printf("%d %d %d\n",tmp_max,start_index+1,end_index+1);		
	}	
	return 0;
}
