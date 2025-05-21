/*

#include <stdio.h>
#include <string.h>


int main() {
	int n,c;
    FILE *file = fopen("hi.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
	
    fseek(file , -1, SEEK_END);
	n=ftell(file);
	n++;

	for(int j=1;j<=n;j++)
	{
		
		fseek(file,-j,SEEK_END);
		c=fgetc(file);
		putchar(c);	
		
	}
	printf("\n");
	printf("%d\n",n);

    fclose(file);
    return 0;
}

*/


/*

#include<stdio.h>

void sort2(int a[][5],int r, int c);

int main()					
{
	int a[5][5],r,c;
	printf("Enter rows and columns : ");
	scanf("%d %d",&r,&c);
	printf("Enter Elements : ");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	}
	sort2(a,r,c);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}

void sort2(int a[][5],int r, int c)
{
	int t;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int x=0;x<r;x++)
			{
				for(int y=0;y<c;y++)
				{
					if(a[x][y]>a[i][j])
					{
						t=a[x][y];
						a[x][y]=a[i][j];
						a[i][j]=t;
					}
				}
			}
		}
	}
}

*/




/*

#include<stdio.h>
#include<string.h>

int main()					//strlen
{
	int n=0;
	char a[50];
	printf("Enter a String : ");
	fgets(a,sizeof(a),stdin);

	while(a[n]!='\0'&&a[n]!='\n')
	{
		printf("%d ",a[n]);
		n++;
	}
	
	printf("\n%d\n",n);
}

*/


/*

#include<stdio.h>
#include<string.h>

int main()					//strcmp
{
	int n=0,x=0;
	char a[50],b[50];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	printf("Enter 2nd String : ");
	fgets(b,sizeof(b),stdin);

	while(a[n]!='\0'&&a[n]!='\n'&&b[n]!='\0'&&b[n]!='\n')
	{
		if(a[n]!=b[n])
		x++;
		n++;
	}

	if(x==0)
	printf("Same String!");
	else
	printf("Not Same String!");

	printf("\n%d\n",n);
}

*/


/*
#include<stdio.h>
#include<string.h>

int main()					//strcpy
{
	int n=0,x=0;
	char a[50],b[50];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	while(a[n]!='\0'&&a[n]!='\n')
	{
		b[n]=a[n];
		n++;
	}

	puts(a);
	puts(b);

	printf("\n%d\n",n);
}
*/


/*
#include<stdio.h>
#include<string.h>

int main()					//strcat
{
	int n=0,m=0;
	char a[50],b[50],c[100];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	printf("Enter 2nd String : ");
	fgets(b,sizeof(b),stdin);

	while(a[n]!='\0'&&a[n]!='\n')
	{
		c[n]=a[n];
		n++;
	}

	while(b[m]!='\0' && b[m]!='\n')
	{
		c[n]=b[m];
		n++,m++;
	}
		
	puts(c);

	printf("\n%d\n",n);
}
*/


/*
#include<stdio.h>
#include<string.h>

int main()					//rev string
{
	int n=0,m;
	char a[50],b[50];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	while(a[n]!='\n'&&a[n]!='\0')
	n++;

	m=n;
	for(int i=0;i<=m;i++)
	{
		b[i]=a[n];
		n--;
	}

	puts(a);
	puts(b);
}
*/


/*
#include<stdio.h>
#include<string.h>

int main()					//palindrome
{
	int n=0,m,x,i;
	char a[50],b[50],c[100];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	n=strlen(a)-1;
	if(a[n]=='\n')
	a[n]='\0';
	
	puts(a);
	
	for(i=0;i<n;i++)
	{
		b[i]=a[n-i-1];
	}
	b[i]='\0';

	puts(b);

	x=strcmp(a,b);

	if(x==0)
	printf("Palindrome\n");
	else
	printf("Not Palindrome\n");
}

*/



/*

#include<stdio.h>
#include<string.h>

int main()					//vowel
{
	int n=0,m,x,i;
	char a[50],b[50],c[100];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	while(a[n]!='\n'&&a[n]!='\0')
	{
		if(a[n]=='a'||a[n]=='e'||a[n]=='i'||a[n]=='o'||a[n]=='u'||a[n]=='A'||a[n]=='E'||a[n]=='I'||a[n]=='O'||a[n]=='U')
		x++;
		n++;
	}

	printf("%d\n",x);
}

*/



/*
#include<stdio.h>
#include<string.h>

int main()					//single multi
{
	int n=0,i,k,x=0,y=0;
	char a[50],m[25],s[50];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	while(a[n]!='\n'&&a[n]!='\0')
	n++;
	
	for(i=0;i<n;i++)
	{
		k=0;
		if(a[i]=='*')
		continue;
		for(int j=1;j<n;j++)
		{
			if(a[j+i]=='*')
			continue;
			if(a[i]==a[j+i])
			{
				a[j+i]='*';
				k++;
			}
		}
		if(k==0)
		{
			s[x]=a[i];
			x++;
		}
		else
		{
			m[y]=a[i];
			y++;
		}
		a[i]='*';
	}

	printf("Single : ");
	for(int p=0;p<x;p++)
	printf("%c ",s[p]);
	printf("\n");

	printf("Multi : ");
	for(int p=0;p<y;p++)
	printf("%c ",m[p]);
	printf("\n");
}
*/




/*

#include<stdio.h>

int main()				//rev using pointer
{
	int a[10],i,n,j,t;

	printf("Enter n Elements : ");
	scanf("%d",&n);

	printf("Enter Elements : ");
	for(i=0;i<n;i++)
	scanf("%d",a+i);

	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		t=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=t;
	}

	printf("Modified Array :");
	for(i=0;i<n;i++)
	printf(" %d",*(a+i));
	printf("\n");
}

*/



/*
#include<stdio.h>

void sort(int a[],int n);

int main()					//sort using pointer
{

	int a[10],i,n,j,t;

	printf("Enter n Elements : ");
	scanf("%d",&n);

	printf("Enter Elements : ");
	for(i=0;i<n;i++)
	scanf("%d",a+i);

	sort(a,n);

	printf("Modified Array :");
	for(i=0;i<n;i++)
	printf(" %d",*(a+i));
	printf("\n");

}


void sort(int a[],int n)
{
	int t;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(*(a+i)>*(a+j))
			{
				t=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=t;
			}
		}
	}
}
*/


/*
#include<stdio.h>

int main()					//vowel using pointer
{
	int n=0,m,x,i;
	char a[50],b[50],c[100];

	printf("Enter 1st String : ");
	fgets(a,sizeof(a),stdin);

	while(*(a+n)!='\n' && *(a+n)!='\0')
	{
		if(*(a+n)=='a'||*(a+n)=='e'||*(a+n)=='i'||*(a+n)=='o'||*(a+n)=='u'||*(a+n)=='A'||*(a+n)=='E'||*(a+n)=='I'||*(a+n)=='O'||*(a+n)=='U')
		x++;
		n++;
	}

	printf("%d\n",x);

}
*/


/*

#include<stdio.h>
#include<stdlib.h>

void sort(int *a,int n);

int main()					//sorting using DMA
{
	int n;
	
	printf("Enter no of Elements : ");	
	scanf("%d",&n);
	
	int *a = (int*)malloc(n*sizeof(int));

	printf("Enter Elements : ");
	for(int i=0;i<n;i++)
	scanf("%d",a+i);

	sort(a,n);

	printf("Modified Elements :");
	for(int i=0;i<n;i++)
	printf(" %d",*(a+i));
	printf("\n");

	free(a);

}

void sort(int *a,int n)
{
	int t;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(*(a+i)>*(a+j))
			{
				t=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=t;
			}
		}
	}
}

*/



/*
#include<stdio.h>
#include<math.h>

struct point
{
	int x,y;
};

float dis(struct point a,struct point b);

int main()						//Distance b/w two points (structure)
{
	struct point a,b;
	float d;

	printf("Enter Co-ordinates for a : ");
	scanf("%d %d",&a.x,&a.y);	

	printf("Enter Co-ordinates for b : ");
	scanf("%d %d",&b.x,&b.y);

	d = dis(a,b);

	printf("%.3f",d);	

}

float dis(struct point a,struct point b)
{
	int m,n;
	float k;
	
	m=(b.x-a.x)*(b.x-a.x);
	n=(b.y-a.y)*(b.y-a.y);
	k=sqrt(m+n);
	return k;
}
*/



/*
#include<stdio.h>

struct Item 
{ 
	char n[50];
	int q;
	float ppu;
};

struct order 
{
	int id;
	struct Item item[10];
	int c;
};

int main()
{
	struct order x;

	printf("Enter order id : ");
	scanf("%d",&x.id);

	printf("Enter Item Count : ");
	scanf("%d",&x.c);

	for(int i=0;i<x.c;i++)
	{
		printf("Enter Name of Item %d : ",i+1);
		fgets(x.item[i].n,sizeof(x.item[i].n),stdin);

		printf("Enter Quantity of Item %d : ",i+1);
		scanf("%d",&x.item[i].q);

		printf("Enter Price per unit of Item %d : ",i+1);
		scanf("%f",&x.item[i].ppu);
	}

}
*/


/*
#include<stdio.h>

int main()					//v,c,d,s
{
	char a[50],b;
	int n,v=0,c=0,d=0,s=0;
	FILE *f;

	f = fopen("hi.txt","w");

	printf("Enter a String : ");
	fgets(a,sizeof(a),stdin);

	fprintf(f,"%s",a);

	fclose(f);

	f = fopen("hi.txt","r");

	fseek(f,-1,2);
	n=ftell(f);
	rewind(f);

	for(int i=0;i<n;i++)
	{
		fscanf(f,"%c",&b);
		if(b=='a'||b=='e'||b=='i'||b=='o'||b=='u'||b=='A'||b=='E'||b=='I'||b=='O'||b=='U')
		v++;
		else if(b>=65 && b<=90 || b>=97 && b<=122)
		c++;
		else if(b>=30 && b<=39)
		d++;
		else
		s++;
	}	
	printf("C : %d\nV : %d\nD : %d\nS : %d\n",c,v,d,s);

	fclose(f);
}
*/


/*
#include<stdio.h>

int main()				//even odd
{
	FILE *f,*g,*h;

	int a[10],b,n;

	f = fopen("hi.txt","w");

	printf("Enter no of Elements : ");
	scanf("%d",&n);

	printf("Enter Elements : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		fprintf(f,"%d ",a[i]);
	}

	fclose(f);


	f = fopen("hi.txt","r");
	g = fopen("even.txt","w");
	h = fopen("odd.txt","w");
	
	for(int i=0;i<n;i++)
	{
		fscanf(f,"%d",&b);
		if(a[i]%2==0)
		fprintf(g,"%d ",b);
		else
		fprintf(h,"%d ",b);
	}


	fclose(f);
	fclose(g);
	fclose(h);
}
*/


/*
#include<stdio.h>

struct student
{
	int r;
	char n[20];
	int p,c,m;
	float av;
};

int main()
{
	struct student a[10];
	
	int l,h=0,s=-1;

	printf("Enter no of students : ");
	scanf("%d",&l);
	
	

	for(int i=0;i<l;i++)
	{
		getchar();
	
		printf("Enter Student %d Name : ",i+1);
		fgets(a[i].n,sizeof(a[i].n),stdin);
		
		printf("Enter Student %d Roll : ",i+1);
		scanf("%d",&a[i].r);
	
		printf("Enter Student %d marks in PCM : ",i+1);
		scanf("%d %d %d",&a[i].p,&a[i].c,&a[i].m);

		a[i].av=(a[i].p+a[i].c+a[i].m)/3.0;

	}

	for(int i=0;i<l;i++)
	{
		if(a[i].av>a[h].av)
		{
			s=h;
			h=i;
		}
	}

	printf("%s%d\n%d\n%d\n%d\n%f\n",a[s].n,a[s].r,a[s].p,a[s].c,a[s].m,a[s].av);

}
*/











/*
#include <stdio.h>
#include <string.h>

#define FILENAME "output.txt"
/*
void reverse_string(char *str, int length) 
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
*/

void reverse_string(char *str,int l)
{
	char t;
	for(int i=0,j=l-1;i<j;i++,j--)
	{
		t=str[i];
		str[i]=str[j];
		str[j]=t;
	}
}

int main() 
{
    char input[100];
    char buffer[100];
    FILE *file;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);


    size_t len = strlen(input);


    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }


    file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(file, "%s", input);
    fclose(file);


    file = fopen(FILENAME, "r");
    if (file == NULL) 
    {
        perror("Error opening file for reading");
        return 1;
    }


    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Error reading from file");
        fclose(file);
        return 1;
    }


    fclose(file);

    reverse_string(buffer, strlen(buffer));

    printf("Reversed string: %s\n", buffer);

    return 0;
}


*/



#include<stdio.h>
#include<string.h>
intmain() i
MgHf* \r
{ struct box
{ char shape[10];
}boxl,box2;
strcpy(boxl.shape,“TRI ANGLE”);
printf(“%s”,boxl .shape);
box2 -boxl;
strcyp(box2.shape,“SQUARE”);
printf(“%s”,boxl .shape);
return 0;}




