
// Implements a list of numbers using a linked list
#include <cs50.h> 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
}
node;

int main(int argc, char *argv[])
node *list = NULL;			// Memory for numbers

for (int i = 1; 1 < argc; it+)		// For each command-line argument
{
// Convert argument to int
style50
日


• list.c
1/
style50
1819202122232425262728293033233343333
node *LISt = NULL;
// For each command-line argument
for (int i = 1; i < argc; i++)
｛
// Convert argument to int
int number = atoi(argvlil);
// Allocate node for number
node *n = malloc(sizeof (node));
if (n == NULL)
｛
return 1;
}
n>number = number;
n-next = NULL;
// If list is empty
if
(list == NULL)
｛
// This node is the whole list
list = n;

@ list.c

style50
日
// If list is empty
if
(list == NULL)
{
// This node is the whole list
List= ni
}
/ If list has numbers already else
{
// Iterate over nodes in list
for (node *ptr = list; ptr != NULL; ptr = ptr->next)
{
// If at end of list
if (ptr->next == NULL)
{
// Append node
ptr->next = n;
break;
}
}