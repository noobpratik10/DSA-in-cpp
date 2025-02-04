#include <iostream>
using namespace std;

class myArray
{
private:
    int total_size;
    int used_size;
    int *ptr;

public:
    // constructor isiliye use nhi kiya kyunki usme memoru ham pass nhi kar sakte

    void createArray(myArray *a, int tSize, int uSize)
    {
        total_size = tSize;
        used_size = uSize;
        // (*a).ptr=(int*)malloc(tSize*sizeof(int)); methods to request dynamic memory allocation in heap memory
        a->ptr = (int *)malloc(tSize * sizeof(int));
    }

    void show(myArray *a)
    {
        for (int i = 0; i < a->used_size; i++)
        {
            cout << (a->ptr)[i] << " ";
        }
    }

    void setVal(myArray *a)
    {
        int n;
        for (int i = 0; i < a->used_size; i++)
        {
            cout << "Enter the element " << i << " here:";
            cin >> n;
            (a->ptr)[i] = n;
        }
    }
};

int main()
{
    myArray marks;
    marks.createArray(&marks, 50, 3);
    cout << "We are running setVal function:\n";
    marks.setVal(&marks);
    cout << "We are running show function:\n";
    marks.show(&marks);

    return 0;
}