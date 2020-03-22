#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_mat(int **mat,int n,int m);
char* find_lcs(char *x,char *y,char *r);

int main()
{
	char x[30],y[30],r[30];
	printf("Enter the first string:\n");
	scanf("%s",x);
	printf("Enter the second string:\n");
	scanf("%s",y);
	find_lcs(x,y,r);
	printf("\n\nlongest common string is:\n%s\n",r);
}

char *find_lcs(char *x,char *y,char *r)
{
	int n,m;
	n=strlen(x);
	m=strlen(y);
	int **mat=(int**)malloc((n+1)*sizeof(int*));
	for(int i=0;i<=n;i++)
	{
		mat[i]=(int*)malloc((m+1)*sizeof(int));
	}
	for(int i=0;i<=n;i++)
	{
		mat[i][0]=0;
	}
	for(int i=0;i<=m;i++)
	{
		mat[0][i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(x[i-1]==y[j-1])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=mat[i-1][j]>mat[i][j-1]?mat[i-1][j]:mat[i][j-1];
		}
	int len = mat[n][m];
	for(int i=n,j=m,k=len-1;i>0 && j>0;)
	{
		if(mat[i][j]==mat[i-1][j])
			i--;
		else if(mat[i][j]==mat[i][j-1])
			j--;
		else
		{
			i--;
			j--;
			r[k]=x[i];
			k--;
		}
	}
	r[mat[n][m]]='\0';
	return r;
}
