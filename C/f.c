#include <cs50.h>
int main()
{
	int n,i=0;
	printf("No of paracetamol Used this Month : ");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("%d Liver is not safe, go to the doctor\n",i);
		i++;
	}
	
	return 0;
}