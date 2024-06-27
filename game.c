6#include<stdio.h>
next(int *p)
{
    if(*p==1)
        *p=2;
    else
        *p=1;
}
void afficher(int t[6][7])
{
    int i,j;
    for(i=0;i<6;i++)
    {

        for(j=0;j<7;j++)
        {
            printf("%d  |  ",t[i][j]);
        }
        printf("\n");
        printf("----------------------------------------\n");
    }
    printf("0     1     2     3     4     5     6\n");
}
int jouer(int t[6][7],int p,int *lig)
{
    int col,i=0;
    do{
    printf("le joueur (%d) joue , choisissez une colonne : ",p);
    scanf("%d",&col);
    if(t[0][col]!=0)
        printf("impossible\n");
    }while((col>7)||(t[0][col]!=0));
    printf("\n");
    while((t[i][col]==0)&&(i<6))
    {
        i=i+1;
    }
    t[i-1][col]=p;
    afficher(t);
    *lig=i-1;
    return col;
}
int vertical(int t[6][7],int col,int p)
{
    int test=0,i=0;
    while((test==0)&&(i<3))
    {
        if((t[i][col]==p)&&(t[i+1][col]==p)&&(t[i+2][col]==p)&&(t[i+3][col]==p))
            test=1;
        i++;
    }
    return test;
}
int horizontal(int t[6][7],int lig,int p)
{
    int test=0,i=0;
    while((test==0)&&(i<4))
    {
        if((t[lig][i]==p)&&(t[lig][i+1]==p)&&(t[lig][i+2]==p)&&(t[lig][i+3]==p))
            test=1;
        i++;
    }
    return test;
}
int diagonal1(int t[6][7],int col,int lig,int p)
{
    int i,j,test=0;
    while((col>0)&&(lig<5))
    {
        col--;
        lig++;
    }
    i=lig;
    j=col;
    while((test==0)&&(0<=i-3)&&(j+3<7))
    {
        if((t[i][j]==p)&&(t[i-1][j+1]==p)&&(t[i-2][j+2]==p)&&(t[i-3][j+3]==p))
            test=1;
        i--;
        j++;
    }
    return test;
}
int diagonal2(int t[6][7],int col,int lig,int p)
{
    int test=0,i,j;
    while((col<6)&&(lig<5))
    {
        col++;
        lig++;
    }
    i=lig;
    j=col;
    while((test==0)&&(i-3>=0)&&(j-3>=0))
    {
        if((t[i][j]==p)&&(t[i-1][j-1]==p)&&(t[i-2][j-2]==p)&&(t[i-3][j-3]==p))
            test=1;
        i--;
        j--;
    }
    return test;
}

int pleine(int t[6][7])
{
    int i,s=0;
    for(i=0;i<7;i++)
    {
    if(t[0][i]!=0)
        s=s+1;
    }
    if(s==7)
        return 1;
    else
        return 0;
}

void main()
{
int t[6][7]={0};
    int p=2;
    int col,lig;
    afficher(t);
    do{
    next(&p);
    col=jouer(t,p,&lig);
    }while((horizontal(t,lig,p)==0)&&(vertical(t,col,p)==0)&&(diagonal1(t,col,lig,p)==0)&&(diagonal2(t,col,lig,p)==0)&&(pleine(t)==0));
    if(pleine(t)==1)
        printf("egalite");
    else
        printf("joueur %d a gagne\n",p);
}
