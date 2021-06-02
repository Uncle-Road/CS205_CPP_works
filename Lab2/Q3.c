#include<stdio.h>

int main(){
    printf("Please Enter a Character : ");
    char a;
    scanf("%c",&a);

    printf("Please Enter an Integer Value : ");
    int b;
    scanf("%d",&b);
    
    printf("Please Enter Float Value : ");
    double c;
    scanf("%lf",&c);

    printf("\nThe variables you entered were : ");
    printf("\nThe Character Value that you Enterd is : %c ",a);
    printf("\nThe Integer Value that you Enterd is : %d ",b);
    printf("\nThe Float Value that you Enterd is : %.3lf \n",c);
    return 0;
}
