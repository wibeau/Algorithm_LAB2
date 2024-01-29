/*
직선 연결 길이 최소 구하는거임.

*/


#include <stdio.h>
#include <math.h>
#define MAX 30

struct Dot {

	double x, y;

}dot[MAX];

struct Set {

	int elements[MAX];
	int size;// 해당 set 에 몇개의 원소가 있는지


};

//set 초기화
void Initializeset(struct Set *set) {

	set->size = 0;
}


//set 에 원소가 있는지 확인
bool Contains(struct Set* set, int element) {

	for (int i = 0; i < set->size; i++) {
		if (set->elements[i] == element) {
			return true;
		}
	}
	return false;
}

//set에 원소 추가
void AddToset(struct Set* set, int element) {

	if (set->size < MAX) { //꽉 안찼으면
		set->elements[set->size++] = element;
		// 추가되면 set size 올림, 
	}


}



int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%lf %lf", &dot[i].x, &dot[i].y);

	}

	/*print test
	for (int i = 0; i < n; i++) {

		printf("입력:%.2lf %.2lf",dot[i].x,dot[i].y);

	}
	*/

	double sum = 0;


	int cnt = 0;

	struct Set set;
	Initializeset(&set);

	while (cnt != n - 1) {



		int flag1 = 0;
		int flag2 = 0;
		double min = 100000;



		 
		for (int i = 0; i < n; i++) { // 기준점을 이동하는 for문




			for (int j = 0; j < n; j++) { // 비교하는 for 문

				if (j == i || (Contains(&set,i)&&Contains(&set,j))) // 집합에 있으면 계속
//i==j 조건은 둘다 0일때만(맨첨에.) 해당되는 거임. 그걸 걍 간결하게 쓴거
//그리고 컨티뉴 만나면 안쪽 for 문으로 감.
// 그리고  뒤부턴 contains 만 고려하게됨. 
					continue;

				else {
				
					double dis = sqrt(pow(dot[i].x - dot[j].x, 2) + pow(dot[i].y - dot[j].y, 2));//a^2+b^2
					if (dis < min) { 
						min = dis;
						flag1 = i;
						flag2 = j;
					}	
				}
				
			}


		}


		AddToset(&set, flag1);
		AddToset(&set, flag2);
		cnt++;
		sum = sum + min;

	}


	//////////////////////////////////////

	printf("%.2f\n", round(sum * 100) / 100.0);

	/*
	c언어에서 소수점 이하의 수를 반올림함.
	기준은 5.
	5미만-> 내림
	5이상-> 올림.
	
	*/

	return 0;
}