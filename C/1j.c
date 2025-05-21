/*
#include<stdio.h>

int main()
{
	FILE *f,*g,*h;					//File Handling -> ODD EVEN
	int x;

	f = fopen("hi.txt","w");
	g = fopen("even.txt","w");
	h = fopen("odd.txt","w");
	
	if(f==NULL)
	return 1;
	
	int i,b[10],a[10] = {1,2,3,4,5,6,7,8,9,10};

	for(i=0;i<10;i++)
	fprintf(f,"%d\n",a[i]);

	rewind(f);

	fclose(f);

	f = fopen("hi.txt","r");

	if(f==NULL||g==NULL||h==NULL)
	return 2;
	
	for(i=0;i<10;i++)
	{
		fscanf(f,"%d",&b[i]);
		if(b[i]%2==0)
		fprintf(g,"%d\n",b[i]);
		else
		fprintf(h,"%d\n",b[i]);
	}

	fclose(f);
	fclose(g);
	fclose(h);

}
*/






/*
#include<stdio.h>

int main()
{
	FILE *f,*g,*h;				//File Handling -> Upper & Lower Case 
	int x;

	f = fopen("hi.txt","w");
	g = fopen("even.txt","w");
	h = fopen("odd.txt","w");
	
	if(f==NULL)
	return 1;
	
	int i;
	char b[10],a[] = "APplE BaLl";

	for(i=0;i<10;i++)
	fprintf(f,"%c",a[i]);

	fclose(f);

	f = fopen("hi.txt","r");

	if(f==NULL||g==NULL||h==NULL)
	return 2;
	
	for(i=0;i<10;i++)
	{
		fscanf(f,"%c",&b[i]);
		printf("%c",b[i]);
		if(b[i]>=65&&b[i]<=90)
		fprintf(g,"%c",b[i]);
		else if(b[i]>=97&&b[i]<=122)
		fprintf(h,"%c",b[i]);
	}

	fclose(f);
	fclose(g);
	fclose(h);

}
*/


/*
#include<stdio.h>
int main()				//infinite loop
{
int n;
for(n = 7; n!=0; n--)
	printf("n = %d", n--);
getchar();
return 0;
}
*/


/*
#include<stdio.h>
int main()
{
printf("%x", -1<<1);
getchar();
return 0;
}
*/


/*
#include<stdio.h>
int main()					//ffffffe
{

	printf("%x",-1<<1);
	getchar();
	return 0;

}
*/



/*
#include<stdio.h>
int main(void)				//3 6 
{
int a = 1;
int b = 0;
b = (++a) + (++a);
printf("%d %d",a,b);
getchar();
return 0;
}
*/



/*
#include<stdio.h>
//&a is address of the whole array a[]. If we add 1 to &a, we get “base address of a[] + sizeof(a)”. And this value is typecasted to int *. So ptr – 1 points to last element of a[] 
//Please write comments if you find any of the answers/explanations incorrect, or you want to share more information about the topics discussed above.
int main()
{
int a[] = {1, 2, 3, 4, 5, 6};
int *ptr = (int*)(&a+1);
printf("%d ", *(ptr-1) );
getchar();
return 0;
} 
*/



/*
#include <stdio.h> 

//Output: Some string starting with “I see you”
//Explanation: (Thanks to Venki for suggesting this solution)
//The function fun() returns pointer to char. Apart from printing string “I see you”, printf() function returns number of characters it printed(i.e. 9). The expression [fun()+ printf(“I see you”)] can be boiled down to
//[“awake” + 9] which is nothing but base address of string literal “awake” displaced by 9 characters. Hence, the expression [“awake” + 9] returns junk data when printed via %s specifier till it finds ‘\0’.

char* fun() 
{ 
return "awake"; 
} 
int main() 
{ 
printf("%s",fun()+ printf("I see you")); 
getchar(); 
return 0; 
} 
*/


/*
#include <stdio.h> 

int main() 
{ 
	unsigned i ; 
	for( i = 0 ; i < 4 ; ++i ) 
	fprintf( stdout , "i = %d\n" , ("11213141") ) ; 
	getchar(); 
	return 0 ; 
} 
*/


/*
#include <stdio.h> 

int main() 
{ 
	unsigned int i=65000; 
	while ( i++ != 0 ); 
	printf("%d",i); 
	return 0; 
} 
*/

/*
#include <stdio.h> 

int main() 
{ 
	int i=0; 
	while ( +(+i--) != 0) 			//i--, -1, +, 1, +, 1,
		i-=i++; 			//1, i++, 2, 1-2, -1,
	printf("%d",i); 
	return 0; 
} 
*/





/*
int main() 
{ 
	float f=5,g=10; 
	enum{i=10,j=20,k=50}; 
	printf("%d\n",++k); 
	printf("%f\n",f<<2); 
	printf("%lf\n",f%g); 
	printf("%lf\n",fmod(f,g)); 
	return 0; 
} 
*/
//Output:
//Program will not compile and give 3 errors
//
//Explanation:
//Here, i, j and k are inside the enum and therefore, they are like constants. In other words, if want to use 10 anywhere in the program, we can use i instead. In the first printf, the value of k is being modified 
//which is not allowed because it’s enum constant. In the second printf, left-shift operator is being applied on a float which is also not allowed. Similarly, in the third printf, modulus operator is being applied on
//float f and g which is also not allowed.


/*
#include<stdio.h>

//write a program to input some character and display the content of file

int main()
{
	FILE *f;					//File Handling -> INPUT OUTPUT
	char x[50],y;

	f = fopen("hi.txt","w");
	
	if(f==NULL)
	return 1;
	
	int i,n,z=0;

	printf("Enter Some character : ");
	fgets(x,50,stdin);

	puts(x);

	for(i=0;x[i]!='\0';i++)
	fprintf(f,"%c",x[i]);

	fclose(f);

	f = fopen("hi.txt","r");

	if(f==NULL)
	return 2;
	
	while(fgetc(f)!= EOF)
	z++;

	rewind(f);

	for(i=0;i<z;i++)
	{
		y=fgetc(f);
		printf("%c",y);
	}

	fclose(f);
}
*/





/*
#include<stdio.h>

//write a program to create a file input 5 integers in the file and display those integers which are multiple of 5

int main()
{
	FILE *f;					//File Handling -> MULTIPLE OF 5
	int x;

	f = fopen("hi.txt","w");
	
	if(f==NULL)
	return 1;
	
	int i,a[10];

	for(i=0;i<5;i++)
	scanf("%d",&a[i]);

	for(i=0;i<5;i++)
	fprintf(f,"%d\n",a[i]);

	fclose(f);

	f = fopen("hi.txt","r");

	if(f==NULL)
	return 2;
	
	for(i=0;i<5;i++)
	{
		fscanf(f,"%d",&x);
		if(x%5==0)
		printf("%d\n",x);
	}

	fclose(f);
}
*/




/*
#include<stdio.h>

//write a program to copy the content from 1 file to another file.

int main()
{
	FILE *f,*g;					//File Handling -> FILE COPY
	char y;

	f = fopen("even.txt","r");
	g = fopen("odd.txt","w");
	
	if(f==NULL||g==NULL)
	return 1;
	
	int i,z=0;

	while(fgetc(f)!=EOF)
	z++;

	rewind(f);

	for(i=0;i<z;i++)
	{
		fscanf(f,"%c",&y);
		fprintf(g,"%c",y);
	}
	

	fclose(f);
	fclose(g);
}
*/






/*
#include<stdio.h>

//Count no of words

int main()
{
	FILE *f;					//File Handling -> Number of words

	char y;

	f = fopen("hi.txt","r");
	
	if(f==NULL)
	return 1;
	
	int i,z=0,x=0;

	while(fgetc(f)!=EOF)
	z++;

	rewind(f);

	for(i=0;i<z;i++)
	{
		fscanf(f,"%c",&y);
		if(y==' ')
		x++;
	}
	x++;
	printf("%d\n",x);
}
*/




/*
#include<stdio.h>

//Count no of Vowels

int main()
{
	FILE *f;					//File Handling -> Number of Vowel

	char y;

	f = fopen("hi.txt","r");
	
	if(f==NULL)
	return 1;
	
	int i,z=0,x=0;

	while(fgetc(f)!=EOF)
	z++;

	rewind(f);

	for(i=0;i<z;i++)
	{
		fscanf(f,"%c",&y);
		if(y=='a'||y=='e'||y=='i'||y=='o'||y=='u'||y=='A'||y=='E'||y=='I'||y=='O'||y=='U')
		x++;
	}
	
	printf("%d\n",x);
}
*/



/*
//cook your dish here
#include <stdio.h>
int main() 
{
    // your code goes here
    int N;
    scanf("%d", &N);
    if(N>=1&&N<=18)
    printf("ADVITIYA");
    else
    printf("WAITING FOR ADVITIYA"); 
    return 0;
}
*/




/*
#include<stdio.h>
int main()
{
	FILE *f;
	int n,b;
	
	f = fopen("hi.txt","w");
	
	if(f==NULL)
	return 1;
	
	printf("Enter n Elements : ");
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		fprintf(f,"%d ",b);
	}

	fclose(f);

	f = fopen("hi.txt","r");
	
	if(f==NULL)
	return 2;
	
	while(fscanf(f,"%d",&b)!=EOF)
	{
		if(b%3==0)
		printf("%d ",b);
	}

	fclose(f);

	return 0;
}
*/



/*
#include<stdio.h>
int main()
{
	FILE *f,*g,*h;
	char a[50],b;

	f = fopen("hi.txt","w");
	
	if(f==NULL)
	return 1;

	fgets(a,sizeof(a),stdin);

	fputs(a,f);

	fclose(f);


	f = fopen("hi.txt","r");
	g = fopen("odd.txt","w");
	h = fopen("even.txt","w");
	
	if(f==NULL || g==NULL || h==NULL)
	return 2;

	while((b=fgetc(f))!=EOF)
	{
		if(b>='a' && b<='z')
		fputc(b,g);
		else
		fputc(b,h);
	}

	fclose(f);
	fclose(g);
	fclose(h);

	
}
*/


/*
1.  Start
2.  Read n
3.  
4.  open a file hi.txt for writing and assign its address to f using fopen("hi.,txt","w")
5.  set i<-0
6.  Repeat step 6 to 9 until i<n
7.  Read num
8.  store num to file using fprintf(f,"%d ",num)
9.  i<-i+1
10. save and close file using fclose(f)
11. open a file hi.txt for reading and assign its address to f using fopen("hi.txt","r")
12. open a file even.txt for reading and assign its address to g using fopen("even.txt","w")
13. open a file odd.txt for reading and assign its address to h using fopen("odd.txt","w")
14. repeat step 14 to 18 until 'fscanf(f,"%d",&num)!=EOF'
15. 
16. if 'num%2==0' is true goto step 17 otherwise goto step 18
17. store num to file f using fprintf(g,"%d ",num) and goto step 14
18. store num to file g using fprintf(h,"%d ",num) and goto step 14
19. save and close file f using fclose(f)
20. save and close file g using fclose(g)
21. save and close file h using fclose(h)
22. return 0
*/



/*
1.  Start
2.  open file [hi.txt] for writing and assign its address to f using fopen("hi.txt","w")
	if 'f==NULL' is true return 1 otherwise goto step 3
3.  Read s using fgets(s,sizeof(s),stdin)
4.  store s to file f using fputs(s,f)
5.  save and close file f using fclose(f)
6.  open file [hi.txt] for reading and assign its address to f using fopen("hi.txt","r")
7.  open file [odd.txt] for writing and assign its address to g using fopen("odd.txt","w")
8.  open file [even.txt] for writing and assign its address to h using fopen("even.txt","w")
9.  open file [kk.txt] for writing and assign its address to i using fopen("kk.txt","w")
	if 'f==NULL || g==NULL || h==NULL || i==NULL' is true return 2 otherwise goto step 10
10. repeat step 10 to step 15 until '(b=fgetc(f))!=EOF'
11. if b>='a' && b<='z' is true goto step 12 otherwise goto 13
12. store b to file g using fputc(b,g) and goto 10
13. if b>='A' && b<='Z' is true goto step 14 otherwise goto 15
14. store b to file h using fputc(b,h) and goto 10
15. store b to file i using fputc(b,i) and goto 10
16. save and close file f using fclose(f)
17. save and close file g using fclose(g)
18. save and close file h using fclose(h)
19. save and close file i using fclose(i)
20. return 0
*/




/*
#include<stdio.h>
#include<string.h>

struct student
{
	char n[20];
	int a, g;
};

void input(struct student *z);
void output(struct student x,struct student y);

int main()
{
	struct student x,y;

	input(&x);

	input(&y);

	output(x,y);
	
	return 0;
}

void input(struct student *z)
{
	printf("Enter Name : ");
	fgets(z->n,sizeof(z->n),stdin);
	z->n[strcspn(z->n,"\n")]='\0';

	printf("Enter Age : ");
	scanf("%d",&z->a);

	printf("Enter GPA : ");
	scanf("%d",&z->g);

	getchar();
}


void output(struct student x,struct student y)
{
	if(x.g > y.g)
	{
		printf("%s\n",x.n);
		printf("%d\n",x.a);
		printf("%d\n",x.g);
	}
	else
	{
		printf("%s",y.n);
		printf("%d\n",y.a);
		printf("%d\n",y.g);
	}

}
*/













