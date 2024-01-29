#include <stdio.h>
#include <math.h>
#define MAX 30
struct Dot {

	double x, y;
}dot[MAX];

struct Set {

	int element[MAX];
	int size;



}set;

bool contains(Set *set,int element) {

	for (int i = 0; i < set->size; i++) {
		if (set->element[i]==element)
			return true;
	
	}

	return false;
}

void initialization(Set *set) {


	set->size = 0;
}

void addelement(Set *set,int element) {
	// 꽉 찼을때 조건 추가.
	if(set->size<MAX)
	set->element[set->size++] = element;

}
int main() {
	int n;
	scanf("%d",&n);

	int cnt = 0; 


	//sum이 최종이니 바깥에
	double sum = 0;

	for (int i = 0; i < n; i++) {

		scanf("%lf %lf", &dot[i].x, &dot[i].y);

	}


	//////////////////////////////////


	while (cnt != n-1) {

		int flag1 = 0;
		int flag2 = 0;
		double min = 10000;

	
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++){

				if (i == j || contains(&set, i) && contains(&set, j))
					continue;
				else {

					double dist = sqrt(pow(dot[i].x-dot[j].x, 2) + pow(dot[i].y - dot[j].y, 2));
					if (dist<min) {
						min = dist;
						flag1 = i;
						flag2 = j;

					
					
					}
				
				
				}


		}
	}



		addelement(&set,flag1);
		addelement(&set, flag2);
		cnt++;
		sum = sum + min;


	}
	
	


	//결과 출력해야지!
	printf("%.2lf",round(sum*100)/100);


	return 0;
}