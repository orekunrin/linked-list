// Courtesy of Paul Programming
/* The objective of creating this program was to learn how to create
a linked list using C++. This program is able to add, delete, and print nodes.
Try out each function to your heart's desire!
*/

#include <cstdlib>
#include "List.h"

using namespace std;

int main()
{
    List Test;

    Test.AddNode(3);
    Test.AddNode(5);
    Test.AddNode(7);
    Test.DeleteNode(3);

    Test.PrintList();
    return 0;
}
