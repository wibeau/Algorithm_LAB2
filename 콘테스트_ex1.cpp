#include <stdio.h>
#include <string.h>

#define MAXN 100 //역
#define MAXT 1000 //시간표개수
#define MAXNAMELENGTH 100 //역명


static char cityname[MAXN][MAXNAMELENGTH];
static int train[MAXT][MAXN][2]; //최종 저장 덩어리. 
static int n, t;
// static int n은 도시 개수 city name 에 저장한,
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
	//초기화
	for (int i = 0; i < n; i++) {
		mintime[i][0] = 10000;
		mintime[i][1] = -1;
		check[i] = 0;
	}

	//!!! 출발지 설정.
	mintime[start][0] = depart;

	// 가장 작은 도착 구하기
	for (int i = 0; i < n; i++) {
		now = -1;
		// 위치 구하기
		for (int j = 0; j < n; j++) {
			if (check[j] == 1)
			{
				continue;
			}

			else{
				
				if(	now == -1 || mintime[now][0] > mintime[j][0]) 
				//now 가 작아야함. 
					now = j;
				}
		
		}

		if (mintime[now][0] = 10000)
			break;

		check[now] = 1;


		// 작은 시간 구하기 
		for (int j = 0; j <t; j++) {
			for (int k = 0; k < tn[j] - 1; k++) {
			
				if (train[j][k][1] == now && mintime[now][0]<=train[j][k][0]) {
					//현재 역에서 출발하는 열차 들 중에서
					// 검사할만한 가치가 있으면.
				
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

	// 가장 큰 출발 구하기

	//다시 check 초기화.
	
	for (i = 0; i < n; i++) {
		check[i] = 0;
	}

	mintime[end][1] = mintime[end][0];


	for (int i = 0; i < n; i++) {
		now = -1;
		// 큰 위치 구하기
		for (int j = 0; j < n; j++) {
			if (check[j] == 1)
			{
				continue;
			}

			else {

				if (now == -1 || mintime[now][1] < mintime[j][1])
					//now 가 작아야함. 
					now = j;
			}

		}

	

		check[now] = 1;


		// 큰 시간 구하기 
		for (int j = 0; j < t; j++) {
			for (int k = 0; k < tn[j] - 1; k++) {

				if (train[j][k][1] == now && mintime[now][1] >= train[j][k][0]) {
					//현재 역에서 출발하는 열차 들 중에서
					// 검사할만한 가치가 있으면.

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
	//테스트 케이스
	scanf("%d",&s);

	while (cnt != s) {
	
		// 도시(역) 개수
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%s",cityname[i]);
		}

		//시간표 개수
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {

			//해당 시간표에 몇개의 역이 있는지
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
	
		printf("출발지명 출발시간",cityname(start),mintime[start][1]);
		printf("도착지명 도착.시간", cityname(end), mintime[end][0]);



	
	
	}

	else 
	{
		printf("unconnected");
	
	}






	return 0;
}


