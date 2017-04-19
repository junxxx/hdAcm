/*
program climbing worm 1049.c
author: junxxx
date: 2016-06-24
*/

#include <stdio.h>
int main()
{
    int height,step,slips_down;
    int cost_time;    
    while(scanf("%d%d%d",&height,&step,&slips_down) != EOF)
    {
        cost_time = 0;
        if(height == 0)
            break;
        else
        {
            while(height)
            {
                if(height - step <= 0 )
                {
                    cost_time++;
                    break;
                }
                else
                {
                    height -= step - slips_down;
                    cost_time += 2;
                }                    
            }
        }
            
        printf("%d\n",cost_time);
    }
    return 0;
}