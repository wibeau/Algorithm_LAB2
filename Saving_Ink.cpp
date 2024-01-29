/*
���� ���� ���� �ּ� ���ϴ°���.

*/


#include <stdio.h>
#include <math.h>
#define MAX 30

struct Dot {

	double x, y;

}dot[MAX];

struct Set {

	int elements[MAX];
	int size;// �ش� set �� ��� ���Ұ� �ִ���


};

//set �ʱ�ȭ
void Initializeset(struct Set *set) {

	set->size = 0;
}


//set �� ���Ұ� �ִ��� Ȯ��
bool Contains(struct Set* set, int element) {

	for (int i = 0; i < set->size; i++) {
		if (set->elements[i] == element) {
			return true;
		}
	}
	return false;
}

//set�� ���� �߰�
void AddToset(struct Set* set, int element) {

	if (set->size < MAX) { //�� ��á����
		set->elements[set->size++] = element;
		// �߰��Ǹ� set size �ø�, 
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

		printf("�Է�:%.2lf %.2lf",dot[i].x,dot[i].y);

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



		 
		for (int i = 0; i < n; i++) { // �������� �̵��ϴ� for��




			for (int j = 0; j < n; j++) { // ���ϴ� for ��

				if (j == i || (Contains(&set,i)&&Contains(&set,j))) // ���տ� ������ ���
//i==j ������ �Ѵ� 0�϶���(��÷��.) �ش�Ǵ� ����. �װ� �� �����ϰ� ����
//�׸��� ��Ƽ�� ������ ���� for ������ ��.
// �׸���  �ں��� contains �� ����ϰԵ�. 
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
	c���� �Ҽ��� ������ ���� �ݿø���.
	������ 5.
	5�̸�-> ����
	5�̻�-> �ø�.
	
	*/

	return 0;
}