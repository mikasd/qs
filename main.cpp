#include <iostream>

using namespace std;

void swap2(int a[],int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

//lomutos partition
int lomutoPart(int a[], int l, int r){
    int p = a[l];
    int s = l;
    for (int i=s+1;i<=r;i++)
    {
        if(p > a[i]){
            s++;
            swap2(a,i,s);
        }
    }
    swap2(a,l,s);
    return s;
}

//quickselect finds kth smallest element in a list
int quickSelect(int a[],int l, int r, int k)
//list being changed but k needs to remain constant.
{
    int s = lomutoPart(a,l,r);
    //if partition element = k, return it, done
    if(s == k-1){
        return a[s];
    }
    //k stays constant, shift left on array
    else if(s > l+k-1) {
        return quickSelect(a,l,s-1,k);
    }
    //k stays constant, shift right on array
    else {
        return quickSelect(a,s+1,k-s-1,k);
    }
}

int main() {
    const int size = 9;
    int list[size] = {1,2,3,4,5,6,7,8,9};
    cout << "4th smallest element is " << quickSelect(list,0,size,4) << endl;
    return 0;
}

