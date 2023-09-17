#include<stdio.h>		//pt bac 2
#include<math.h>

int main(){
	float a,b,c;
	float delta ,x1,x2 , var ;
	printf(" ax^2 + bx + c = 0");
	printf("\na = ");scanf("%f",&a);
	printf("\nb = ");scanf("%f",&b);
	printf("\nc = ");scanf("%f",&c);
	delta = b*b - 4*a*c;
	var = sqrt(delta);
	if (delta < 0){
		printf("Pt vo nghiem");
	}
	else if (delta > 0){
		x1 = (-b-var)/(2*a);
		x2 = (-b+var)/(2*a);
		printf("\tPt co 2 nghiem pb :\n x1 = %f \n x2 = %f",x1,x2);
	}
	else if (delta == 0){
		x1 = -b/2*a;
		printf("Pt co nghiem kep: x1 = x2 = %f",x1);
	}
	
	
}
