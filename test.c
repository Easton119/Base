#include<stdio.h>
struct{
    char a;//1 - > 8
    double c;//8
    int b; //4 -> 8
}node;
struct{
    char a;//1 - > 4
    int b; //4
    double c;//8
}node2;

int main(){
    // const char *p = "Aello world";
    // cout<<*p<<endl;
    // int d;
    // cout<<d<<endl;
    // int c;
    // cout<<c<<endl;
    
    // static int g;
    // cout<<g<<endl;

    printf("%d",sizeof(node));//24
    printf("%d",sizeof(node2));//16
    
}