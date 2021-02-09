#include <iostream>
using namespace std;

class Box
{
public:
    Box(int len,int wid,int hei);
    Box();
    ~Box();

    int printvolume();

private:
    int length;
    int width;
    int height;
    int volume;
};
Box::Box(int len,int wid,int hei)
{
    length = len;
    width = wid;
    height = hei;
}
Box::~Box()
{
    cout << "Object is being deleted." << endl;
}

int Box::printvolume()
{
    volume = length * width * height;
}


int main()
{

}