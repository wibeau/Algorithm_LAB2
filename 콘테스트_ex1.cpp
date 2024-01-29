#include <stdio.h>
#include <string.h>

#define MAXN 100 //��
#define MAXT 1000 //�ð�ǥ����
#define MAXNAMELENGTH 100 //����


static char cityname[MAXN][MAXNAMELENGTH];
static int train[MAXT][MAXN][2]; //���� ���� ���. 
static int n, t;
// static int n�� ���� ���� city name �� ������,
static int mintime[MAXN][2];
static int check[MAXN];

static int tn[MAXT];

static int depart, start, end;

int getcitytag(char* name) {

	for (int i = 0; i <n; i++) {

		if(strcmp(name,cityname[i]) == 0)
		return i;
	
	}



	return -1;
}


void solve() {

	int k, z, now,i,j;
	//�ʱ�ȭ
	for (int i = 0; i < n; i++) {
		mintime[i][0] = 10000;
		mintime[i][1] = -1;
		check[i] = 0;
	}

	//!!! ����� ����.
	mintime[start][0] = depart;

	// ���� ���� ���� ���ϱ�
	for (int i = 0; i < n; i++) {
		now = -1;
		// ��ġ ���ϱ�
		for (int j = 0; j < n; j++) {
			if (check[j] == 1)
			{
				continue;
			}

			else{
				
				if(	now == -1 || mintime[now][0] > mintime[j][0]) 
				//now �� �۾ƾ���. 
					now = j;
				}
		
		}

		if (mintime[now][0] = 10000)
			break;

		check[now] = 1;


		// ���� �ð� ���ϱ� 
		for (int j = 0; j <t; j++) {
			for (int k = 0; k < tn[j] - 1; k++) {
			
				if (train[j][k][1] == now && mintime[now][0]<=train[j][k][0]) {
					//���� ������ ����ϴ� ���� �� �߿���
					// �˻��Ҹ��� ��ġ�� ������.
				
					z = k + 1;
					if (mintime[train[j][z][1]][0]>train[j][z][0]) {
						mintime[train[j][z][1]][0] = train[j][z][0];
					
					}
				
				}
			}
		
		
		
		}

	
	}

	if (check[end] == 0)
		return;

	// ���� ū ��� ���ϱ�

	//�ٽ� check �ʱ�ȭ.
	
	for (i = 0; i < n; i++) {
		check[i] = 0;
	}

	mintime[end][1] = mintime[end][0];


	for (int i = 0; i < n; i++) {
		now = -1;
		// ū ��ġ ���ϱ�
		for (int j = 0; j < n; j++) {
			if (check[j] == 1)
			{
				continue;
			}

			else {

				if (now == -1 || mintime[now][1] < mintime[j][1])
					//now �� �۾ƾ���. 
					now = j;
			}

		}

	

		check[now] = 1;


		// ū �ð� ���ϱ� 
		for (int j = 0; j < t; j++) {
			for (int k = 0; k < tn[j] - 1; k++) {

				if (train[j][k][1] == now && mintime[now][1] >= train[j][k][0]) {
					//���� ������ ����ϴ� ���� �� �߿���
					// �˻��Ҹ��� ��ġ�� ������.

					z = k - 1;
					if (mintime[train[j][z][1]][1] < train[j][z][0]) {
						mintime[train[j][z][1]][1] = train[j][z][0];

					}

				}
			}



		}


	}
	

}

int main() {
	char name[MAXNAMELENGTH];
	int cnt = 0;
	int s;
	//�׽�Ʈ ���̽�
	scanf("%d",&s);

	while (cnt != s) {
	
		// ����(��) ����
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%s",cityname[i]);
		}

		//�ð�ǥ ����
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {

			//�ش� �ð�ǥ�� ��� ���� �ִ���
			scanf("%d", &tn[i]);


			for (int j = 0; j < tn[i]; j++) {
			
				scanf("%d %s",train[i][j][0], name);
				train[i][j][1]=getcitytag(name);
			
			}
		}

		scanf("%d",depart);

		scanf("%s",name);
		start = getcitytag(name);
	
	
	
		scanf("%s", name);
		end = getcitytag(name);
	/////////////////////////////////////////////
	
	
	
		cnt++;
	}

	solve();


	if (check[end]) {
	
		printf("������� ��߽ð�",cityname(start),mintime[start][1]);
		printf("�������� ����.�ð�", cityname(end), mintime[end][0]);



	
	
	}

	else 
	{
		printf("unconnected");
	
	}






	return 0;
}


