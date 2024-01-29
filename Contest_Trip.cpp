/*
�ð� ���� �ϱ� ���� ��� ������ �ð� ��� ���ϴ� ���α׷���
������ζ� �� ���� �����ϴ� ��� ����.
*/
#include <stdio.h>
#include <string.h>

#define MAXN 100 //��
#define MAXT 1000 //�ð�ǥ����
#define MAXNAMELENGTH 100 //����

static char cityname[MAXN][MAXNAMELENGTH];
static int n, t, depart, start, end, tn[MAXT], train[MAXT][MAXN][2];
static int mintime[MAXN][2], check[MAXN];
//üũ�� �� ���� ���� üũ ����.  �ش� ���� �̹� ó�� �Ǿ����� Ȯ���ϴ� �迭
// check[now]=1 �̸� �ش翪�� �ٽ� �˻����� ����. 
// check[end]=1 �̸� �ش翪�� �ٽ� �˻����� ����. 


//mintime[i][0]= i�������� �����ð� �� ���� ���� ���� �ð�
//mintime[i][1] == i�������� ��߽ð� �� ���� ���� ��߽ð�
//����� �ʰ� ������ ����� �ִܽð�. 


//train: ������ �ð�ǥ ���� ���� 1. �ð�ǥ ����
//							     2. �� �ð�ǥ�� ���Ե� ���� ����
// 0�� �ð� 1�� ����
//������ �迭  3D==>[]///[][]==>2D

//�迭�ϳ��ϳ� �˻��ϱ� ������ ������ �ε����� �ް� �ε����� ���ϴ� ����.

int getcitytag(char* name) { // �־��� �� �̸��� �ش��ϴ� ���� �ε��� ��ȯ
	//�־��� ���̸�(name)�� �迭�� ����� ���̸��� ��ġ�ϴ°��
	//�ش� ���� �ε��� ��ȯ.

	int i;
	for (i = 0; i < n; i++) {

		//string .compare ==> ���ڿ��� ���ڿ� �� 
		//��, cityname[i]���� ���ڿ���.

		if (strcmp(name, cityname[i]) == 0){
		return i;
	}
	}
	return -1;

}

void solve() {

	int i, j, k, z, now;


	//�ʱ�ȭ.
	for (i = 0; i < n; i++) {
		mintime[i][0] = 10000; // �����ð� �������==>  ��� �۾�������.
		mintime[i][1] = -1; // ���� ���� ��߽ð�==> ��� Ŀ������. 
		check[i] = 0;  // ���� ��� ���� ���� �˻縦 �������� �ʾҴٴ� ��.

	}

	

	//��� �ð� ���� ���� �� ���⋚��. min time ��. 
	mintime[start][0] = depart;



	for (i = 0; i < n; i++) {

		now = -1; //���翪 �ʱ�ȭ . ���� ó������ ���� ���� ���� ���� �����ð� ã��. 
		// now �� ���� �ǹ�!!!!!1

		for (j = 0; j < n; j++) {
			if (check[j])//1�̸� ó���� ��. 
				continue;
		
			//mintime[now][0] > mintime[j][0] �̺κ��� 
			if (now == -1 || mintime[now][0] > mintime[j][0])
				//�ؼ�: now�� �ʱ�ȭ�����ʾҰų� ������� Ȯ���� ��(now)�� �����ð���
				// �񱳴�� �� [j]���� ū�� Ȯ��. 
				// ������ = �۴� ==>������ ���� �ؾߵ�.
				//�ð��� ũ�� == ������. 
				now = j;
			//now �� �۾ƾ���. �׷��� now�� j�� ������Ʈ 

		}

		//�ʱ�ȭ �ȵ�����
		if (mintime[now][0] == 10000)
			break;

		//now�� �˻� �Ϸ�.
		check[now] = 1;
		
		// ��ġ.
		/////////////////////////////////////////////////////////////
		// �ð�.

		//���ͽ�Ʈ���� �ٽ� �κ�.
		//now ������ ����ϴ� �������� Ȯ���ϰ� ���翪~ �� �� ���� �ִ� �����ð� (��������)
		// ������Ʈ.

		for(j=0; j<t; j++){ //�ð�ǥ ������ŭ. 


			for (k = 0; k < tn[j]-1; k++) {
				//�ð�ǥ�� �� ��. (�� ������ ���� �ð��� �ٸ� ���� �ִ°Ű�. ) 

				if (train[j][k][1] == now && mintime[now][0] <= train[j][k][0]) {

				// ���� ������ ����ϴ� ���� �߿���.
					//���� ���� ���� �� ���� ���� ã����

					// �������� �����ϱ�. 
					// Ÿ���ϴϱ� �������� ���� �˻縦 �����ϴ°���. 
					z = k + 1;
					// ����������!

					if (mintime[train[j][z][1]]   [0] > train[j][z][0])
					//���� �������� �����ð����� (�۾ƾ��ϴµ�) ũ�ٸ�						
						mintime[train[j][z][1]][0] = train[j][z][0];
					// �۰� �����Ѵ�. 
				
				}

				//mintime[now][0]�� ������� Ȯ���� �� �߿��� 
				// �� now���� ���� ���� ���� �ð�
				//���� �������� ���� �ð�"��
				//���ͽ�Ʈ�� �˰������� � ���� �����ϴµ� �ɸ��� 
				//�ִ� �ð��� �����ϴ� �� ���Ǵ� ��
			}
		
		}

	}

	if (check[end] == 0)
		return;

	/////////////////////////////////////


	

	//���� ���� ��� (mintime[][1]) �ð�

	// Ŀ�ߵ� mintime[][1]�� Ŀ���� Ŀ���� 


	for (i = 0; i < n; i++) {
		check[i] = 0;
	}



	mintime[end][1] = mintime[end][0];



	for (i = 0; i < n; i++) {
		now = -1;

		//��ġ 
		for (j = 0; j < n; j++) { 
			if (check[j])
				continue;

			if (now == -1 || mintime[now][1] < mintime[j][1])
				// ���� ��ġ ���� ū�� �ִ�?
				//mintime[][0]�̶� �ݴ�!!!!

				now = j;
		}

		check[now] = 1;



		// �ð�
		for (j = 0; j < t; j++) { //�ð�ǥ��ŭ
			for (k = 1; k < tn[j]; k++) {
				if (train[j][k][1] == now && mintime[now][1] >= train[j][k][0]) {

					// ���翪���� ����ϴ� ������
					// k��° ���� ��� �� ū�� �ִ�=> �˻��� ��ġ�� �ִ°���. 

					z = k - 1;

					// �� ������ ���� .

					// ���������� ����� �� ū�� �ִٸ�. 
					// ũ�� ���� 
					if (mintime[ train[j][z][1]]      [1] < train[j][z][0])
						mintime[ train[j][z][1]]      [1] = train[j][z][0];

				}
			}
		}

	}
}

int main() {
	
	int s, i, j;
	char name[MAXNAMELENGTH];

	// �׽�Ʈ ���̽� 
	scanf("%d",&s);

	for (int i = 1; i <= s; i++) {

		// ������ 
		scanf("%d", &n);

		for(j=0; j<n; j++){
		
			// ���ø� 
			scanf("%s", cityname[j]);
			//1�� 2�� 3�࿡ �޴°���. 
		
		}

		//��ü �Է��� �ð�ǥ ����
		scanf("%d", &t);

		for (j = 0; j < t; j++) {

			//tn �� �ð�ǥ t �� ���Ե� �� ����(�ش�ð�ǥ�� ��� ���� �ִ���). 
			scanf("%d",&tn[j]);

			for(int k=0; k<tn[j]; k++){
			
				//�ð��� �̸�(����)
				scanf("%d %s", &train[j][k][0], name);

				//������ �ε��� ��ġ���� train[][][]�� ����. 
				train[j][k][1] = getcitytag(name);
			}
		}


		// ��߽ð� �Է�
		scanf("%d",&depart);

		//����� �Է�
		scanf("%s", name);
		start = getcitytag(name);
		
		//������ �Է�
		scanf("%s",name);
		end = getcitytag(name);
		
		/// /////////////////////////////////////////////////////////////
		// �������� �� ��ǲ. 
	
		solve();

		printf("Scenario %d\n", i);

		if (check[end]) { // ������ ���� �˻縦 �Ϸ� �ߴٸ�. 
			
			printf("Departure %04d %s \n", mintime[start][1], cityname[start]);
			//start �� ���� ū ��߽ð��� ..... �������
			printf("Arrival %04d %s", mintime[end][0], cityname[end]);
			//end �� ���� ���� �����ð��� ����Ʈ��.... ��������.  
		}


		else
			printf("No connection\n");
		printf("\n");

	}




	return 0;
}