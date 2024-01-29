#include <stdio.h>
#include <math.h>
#define MAX 30
struct Dot{

double x, y;

}dot[MAX];

struct Set {

	int element[MAX];
	int size;


}set;

bool initialization(Set*set) {
	set->size = 0;

}


bool contains(Set* set, double element) {

	for (int i = 0; i < set->size; i++) {
		if (set->element[i] == element) {
			return true;
		}
	
	
	}

	return false;

}


void addelement(Set*set,double element) {
	if (set->size < MAX) {
		set->element[set->size++] = element;
	
	}


}

int main() {
	
	int n;
	scanf("%d",&n);

	struct Dot dot[MAX];
	struct Set set;
	initialization(&set);

	//ют╥б.
	for (int i = 0; i < n; i++) {	
		scanf("%lf %lf",&dot[i].x,&dot[i].y);

	}
	

	int cnt = 0;
	double sum = 0;
	while (cnt != n) {
		double min = 10000;
		int flag1 = 0;
		int flag2 = 0;

		for (int i = 0; i < n; i++) {
		
		
			for (int j = 0; j < n; j++) {
			
				if (i == j || contains(&set, i) && contains(&set, j))
					continue;
				else {
					double dist = sqrt(pow(dot[i].x - dot[j].x,2) + pow(dot[i].y-dot[j].y, 2));
					if (dist < min) {
						min = dist;
						flag1 = i;
						flag2 = j;
					
					}
				
				
				
				}
			}
		
		}


		//////////////////////////////////////
	
		addelement(&set, flag1);
		addelement(&set, flag2);
		cnt++;
		sum =+ min;
	
	}

	
	printf("%.2lf",round(sum*100)/100);
	
	
	
	return 0; }