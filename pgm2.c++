#include <iostream>

int main() {
    int a[10],n,pos,item;
    std::cout<<"enter no of ele: ";
    std::cin>>n;
    std::cout<<"Enter "<<n<<" elem:\n";
    for(int i=0;i<n;i++)
    {std::cin>>a[i];}
    std::cout << "Enter the item to insert: ";
    std::cin >> item;
    std::cout << "Enter the position (1 to " << n + 1 << "): ";
    std::cin >> pos;
    int i=n;
    while(i>=pos)
    {
        a[i]=a[i-1];
        i--;
    }
    a[pos]=item;
    n++;
    std::cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        std::cout<< a[i] << " ";
    }
    return 0;
}