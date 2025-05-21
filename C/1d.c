Hash Tables
He talesmete rasdom acces abiliy of an aray with
• This means (assuming we define our hash table well):
• Insertion can start to tend toward 0(1)
• Deletion can start to tend toward 0(1)
• Lookup can start to tend toward 0(1)
• We're gaining the advantages of both types of data structure,
while mitigating the disadvantages.


Hash Tables
• To get this performance upgrade, we create a new structure whereby when we insert data into the structure, the data itself gives us a clue about where we will find the data, should we need to later look it up.
• The trade off is that hash tables are not great at ordering or sorting data, but if we don't care about that, then we're good to go!


Hash Tables
• A hash table amounts to a combination of two things with which we're quite familiar.
• First, a hash function, which returns an nonnegative integer value called a hash code.
• Second, an array capable of storing data of the type we wish to place into the data structure.
• The idea is that we run our data through the hash function, and then store the data in the element of the array represented by the returned hash code.


Hash Tables
• How to define a hash function? Really no limit to the number of possible hash functions.
• A good hash function should:
• Use only the data being hashed
• Use all of the data being hashed
• Be deterministic
• Uniformly distribute data
• Generate very different hash codes for very similar data


Hash Tables
unsigned int hash(char* str)
{
int sum = 0;
for (int j = 0; str[j] != '10'; j++)
{
sum †= str[j];
}
return sum % HASH_MAX;
}


Hash Tables
• Resolving collisions: Linear probing
• Linear probing is subject to a problem called clustering. Once there's a miss, two adjacent cells will contain data, making it more likely in the future that the cluster will grow.
• Even if we switch to another probing technique, we're still limited. We can only store as much data as we have locations in our array.


Hash Tables
• Resolving collisions: Chaining
• We've eliminated clustering.
• We know from experience with linked lists that insertion (and creation, if necessary) into a linked list is an O(1) operation.
• For lookup, we only need to search through what is hopefully a small list, since we're distributing what would otherwise be one huge list across n lists.



Tries
• We have seen a few data structures that handle the mapping of key-value pairs.
• Arrays: The key is the element index, the value is the data at that
• iss alta haShing Yo that hash code of the data, the value is a linked
• What about a slightly different kind of data structure where the key is guaranteed to be unique, and the value could be as simple as a Boolean that tells you whether the data exists in the structure?


Tries
• Tries combine structures and pointers together to store data in an interesting way.
• The data to be searched for in the trie is now a roadmap.
• If you can follow the map from beginning to end, the data exists in the trie
• If you can't, it doesn't.
• Unlike with a hash table, there are no collisions, and no two pieces of data (unless they are identical) have the same path.


Tries
• Let's map key-value pairs where the keys are four-digit years
(YYYY) and the values are names of universities founded during those years.
• In a trie, the paths from a central root node to a leaf node (where the school names would be), would be labeled with digits of the year.
• Each node on the path from root to leaf could have 10 pointers emanating from it, one for each digit.


Tries
typedef struct _trie
{
char university[20];
struct _trie* paths[10];
}
trie;




Doubly-Linked Lists
• Singly-linked lists really extend our ability to collect and organize data, but they suffer from a crucial limitation.
• We can only ever move in one direction through the list.
• Consider the implication that would have for trying to delete a node.
• A doubly-linked list, by contrast, allows us to move forward and backward through the list, all by simply adding one extra pointer to our struct definition.


Doubly-Linked Lists
• In order to work with linked lists effectively, there are a number of operations that we need to understand:
1. Create a linked list when it doesn't already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.


Doubly-Linked Lists
• Insert a new node into the linked list.
d11node* insert(dllnode* head, VALUE val);
• Steps involved:
a. Dynamically allocate space for a new dlInode.
b. Check to make sure we didn't run out of memory.
c. Populate and insert the node at the beginning of the linked list.
d. Fix the prev pointer of the old head of the linked list.
e. Return a pointer to the new head of the linked list.


Doubly-Linked Lists
• Linked lists, of both the singly- and doubly-linked varieties, support extremely efficient insertion and deletion of elements.
• In fact, these operations can be done in constant time.
• What's the downside? Remember how we had to find an element? We've lost the ability to randomly-access list elements.
• Accessing a desired element may now take linear time.



Hash Tables
He talesmete rasdom acces abiliy of an aray with
• This means (assuming we define our hash table well):
• Insertion can start to tend toward 0(1)
• Deletion can start to tend toward 0(1)
• Lookup can start to tend toward 0(1)
• We're gaining the advantages of both types of data structure,
while mitigating the disadvantages.



Singly-Linked Lists
• In order to work with linked lists effectively, there are a number of operations that we need to understand:
1. Create a linked list when it doesn't already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.


Singly-Linked Lists
slInode* new = create(6);
a. Dynamically allocate space for a new sl1node.
b. Check to make sure we didn't run out of memory.
c. Initialize the node's val field.
d. Initialize the node's next field.
e. Return a pointer to the newly created s11node.

			new
			 6

Singly-Linked Lists
• Insert a new node into the linked list.
sllnode* insert(sl1node* head, VALUE val);
• Steps involved:
a. Dynamically allocate space for a new s11node.
b. Check to make sure we didn't run out of memory.
c. Populate and insert the node at the beginning of the linked list.
d. Return a pointer to the new head of the linked list.