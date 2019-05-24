#include <iostream>
#include "UnionFind.h"
#include <stdio.h>

using namespace std;

int main()
{
    int numElements, operation, element1, element2; // variables
    const char* INPUTFILE = "uf-medium.in";

    freopen(INPUTFILE, "r", stdin); // opening the file "uf-medium.in" in read mode with stdin as the stream
    scanf("%d", &numElements); // reads the first number in the file and stores it in numElements

    UnionFind *disjointSets = new UnionFind(numElements); // instantiate UnionFind and pass in the number of elements to the constructor

    while (3 == scanf("%d %d %d", &operation, &element1, &element2)) // this is just a condition to ensure there is nothing wrong with the file
    {
        if (operation == -1 && element1 == -1 && element1 == -1) // break-condition when the inputs are -1 -1 -1, indicating end of the file
            break;
        else if (!operation) // Connect/Union. Predefined that when operation == 0, form a connection
        {
            disjointSets->Union(element1 - 1, element2 - 1); // I subtract 1 because the ith element has index i-1
        }
        else // Connected/Find Predefined that when operation == 1, determine if elements are connected and output T or F
        {
            if(disjointSets->IsConnected(element1-1,element2-1))
                cout<<"T"<<endl;
            else
                cout<<"F"<<endl;
        }
    }
    disjointSets->~UnionFind(); //clean up memory and destruct! boom

    string eof;
    cin>>eof; // This is used for IDEs that automatically close their console window after runtime, forcing them to wait for user input
    return 0;
}