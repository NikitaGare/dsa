#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Client
{
    string name;
    long phoneNumber;
};
class HashTable
{
public:
    static const long size=10;
    Client table[size];
    long collisions[size];
    long hash(int key) { return key%size; }
    HashTable() { for(int i=0;i<size;i++) collisions[i]=0; }
    void linearprobing(Client client)
    {
        long index=hash(client.phoneNumber);
        long count=0;
        while(collisions[index]==1)
        {
            index=(index+1)%size;
            count++;
        }
        table[index]=client;
        collisions[index]=1;
        cout<<"Inserted "<<client.name<<"'s phone number after "<<count<<" collisions using linear probing."<<endl;
    }
    void quadraticprobing(Client client)
    {
        long index=hash(client.phoneNumber);
        long count=0;
        while(collisions[index]!=0 && collisions[index]!=client.phoneNumber)
        {
            count++;
            index=(hash(client.phoneNumber)+count*count)%size;
        }
        table[index]=client;
        collisions[index]=1;
        cout<<"Inserted "<<client.name<<"'s phone number after "<<count<<" collisions using quadratic probing."<<endl;
    }
    bool search(int phoneNumber)
    {
        long index=hash(phoneNumber);
        int count=0;
        while(collisions[index]!=0)
        {
            if(table[index].phoneNumber==phoneNumber)
            {
                cout<<"Found "<<table[index].name<<"'s phone number after "<<count<<" comparisons using linear probing."<< endl;
                return true;
            }
            index=(index+1)%size;
            count++;
        }
        cout<<"Phone number not found."<<endl;
        return false;
    }
};

int main()
{
    HashTable ht;
    int number;
    string name;
    int x=11;
    int y;
    while(x!=0)
    {
        cout<<"\n1.INSERT NUMBER\n2.SEARCH NUMBER\n0.EXIT\nEnter your choice:";
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"\nEnter name:";
                cin>>name;
                cout<<"Enter number:";
                cin>>number;
                cout<<"\n1.Linear probing\n2.Quadratic probing\nEnter your option:";
                cin>>y;
                if(y==1) ht.linearprobing({name, number});
                else if(y==2) ht.quadraticprobing({name, number});
                else cout<<"Error! invalid option\n";
                cout<<endl;
                break;
            case 2:
                cout<<"\nEnter number to search:";
                cin>>number;
                ht.search(number);
                break;
            case 0:
                cout<<"\nExitinggg....\n\n";
                break;
            default:
                cout<<"\nInvalid choice!!\nEnter again\n\n";
                break;
        }
    }
    return 0;
}
/*output:

1.INSERT NUMBER
2.SEARCH NUMBER
0.EXIT
Enter your choice:1

Enter name:Mahadev
Enter number:123

1.Linear probing
2.Quadratic probing
Enter your option:1
Inserted Mahadev's phone number after 0 collisions using linear probing.


1.INSERT NUMBER
2.SEARCH NUMBER
0.EXIT
Enter your choice:1

Enter name:Mahadev
Enter number:123

1.Linear probing
2.Quadratic probing
Enter your option:2
Inserted Mahadev's phone number after 1 collisions using quadratic probing.


1.INSERT NUMBER
2.SEARCH NUMBER
0.EXIT
Enter your choice:1

Enter name:abc
Enter number:123

1.Linear probing
2.Quadratic probing
Enter your option:1
Inserted abc's phone number after 2 collisions using linear probing.


1.INSERT NUMBER
2.SEARCH NUMBER
0.EXIT
Enter your choice:2

Enter number to search:123
Found Mahadev's phone number after 0 comparisons using linear probing.

1.INSERT NUMBER
2.SEARCH NUMBER
0.EXIT
Enter your choice:2

Enter number to search:1233
Phone number not found.

1.INSERT NUMBER
2.SEARCH NUMBER
0.EXIT
Enter your choice:0

Exitinggg.... */
