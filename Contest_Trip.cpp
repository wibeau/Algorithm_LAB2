/*
시간 절약 하기 위해 출발 도착지 시간 장소 정하는 프로그램임
같은경로라도 더 빨리 도착하는 경로 선택.
*/
#include <stdio.h>
#include <string.h>

#define MAXN 100 //역
#define MAXT 1000 //시간표개수
#define MAXNAMELENGTH 100 //역명

static char cityname[MAXN][MAXNAMELENGTH];
static int n, t, depart, start, end, tn[MAXT], train[MAXT][MAXN][2];
static int mintime[MAXN][2], check[MAXN];
//체크는 각 역에 대한 체크 여부.  해당 역이 이미 처리 되었는지 확인하는 배열
// check[now]=1 이면 해당역을 다시 검사하지 않음. 
// check[end]=1 이면 해당역을 다시 검사하지 않음. 


//mintime[i][0]= i역으로의 도착시간 중 가장 빠른 도착 시간
//mintime[i][1] == i역으로의 출발시간 중 가장 늦은 출발시간
//출발이 늦고 도착이 빨라야 최단시간. 


//train: 열차의 시간표 정보 저장 1. 시간표 개수
//							     2. 각 시간표에 포함된 역의 개수
// 0은 시간 1은 역명
//삼차원 배열  3D==>[]///[][]==>2D

//배열하나하나 검사하기 어려우니 역명에 인덱스를 달고 인덱스를 비교하는 거임.

int getcitytag(char* name) { // 주어진 역 이름에 해당하는 역의 인덱스 반환
	//주어진 역이름(name)과 배열에 저장된 역이름이 일치하는경우
	//해당 역의 인덱스 반환.

	int i;
	for (i = 0; i < n; i++) {

		//string .compare ==> 문자열과 문자열 비교 
		//즉, cityname[i]또한 문자열임.

		if (strcmp(name, cityname[i]) == 0){
		return i;
	}
	}
	return -1;

}

void solve() {

	int i, j, k, z, now;


	//초기화.
	for (i = 0; i < n; i++) {
		mintime[i][0] = 10000; // 도착시간 가장빠른==>  계속 작아져야함.
		mintime[i][1] = -1; // 가장 느린 출발시간==> 계속 커져야함. 
		check[i] = 0;  // 아직 모든 역에 대한 검사를 진행하지 않았다는 뜻.

	}

	

	//출발 시간 보다 작을 수 없기떄문. min time 은. 
	mintime[start][0] = depart;



	for (i = 0; i < n; i++) {

		now = -1; //현재역 초기화 . 아직 처리되지 않은 역중 가장 빠른 도착시간 찾음. 
		// now 는 역을 의미!!!!!1

		for (j = 0; j < n; j++) {
			if (check[j])//1이면 처리된 역. 
				continue;
		
			//mintime[now][0] > mintime[j][0] 이부분이 
			if (now == -1 || mintime[now][0] > mintime[j][0])
				//해석: now가 초기화되지않았거나 현재까지 확인한 역(now)의 도착시간이
				// 비교대상 역 [j]보다 큰지 확인. 
				// 빠르다 = 작다 ==>작은거 선택 해야됨.
				//시간이 크다 == 느리다. 
				now = j;
			//now 는 작아야함. 그래서 now를 j로 업데이트 

		}

		//초기화 안됐을시
		if (mintime[now][0] == 10000)
			break;

		//now역 검사 완료.
		check[now] = 1;
		
		// 위치.
		/////////////////////////////////////////////////////////////
		// 시간.

		//다익스트라의 핵심 부분.
		//now 역에서 출발하는 열차들을 확인하고 현재역~ 각 역 까지 최단 도착시간 (가장작은)
		// 업데이트.

		for(j=0; j<t; j++){ //시간표 개수만큼. 


			for (k = 0; k < tn[j]-1; k++) {
				//시간표의 각 역. (역 도착은 같되 시간이 다를 수도 있는거고. ) 

				if (train[j][k][1] == now && mintime[now][0] <= train[j][k][0]) {

				// 현재 역에서 출발하는 열차 중에서.
					//현재 도착 보다 더 나중 도착 찾으면

					// ㄴㄴㄴㄴ 맞으니까. 
					// 타당하니까 다음역에 대한 검사를 시행하는거지. 
					z = k + 1;
					// 다음역으로!

					if (mintime[train[j][z][1]]   [0] > train[j][z][0])
					//만약 다음역의 도착시간이이 (작아야하는데) 크다면						
						mintime[train[j][z][1]][0] = train[j][z][0];
					// 작게 갱신한다. 
				
				}

				//mintime[now][0]은 현재까지 확인한 역 중에서 
				// 역 now로의 가장 빠른 도착 시간
				//현재 역에서의 도착 시간"은
				//다익스트라 알고리즘이 어떤 역에 도착하는데 걸리는 
				//최단 시간을 추적하는 데 사용되는 값
			}
		
		}

	}

	if (check[end] == 0)
		return;

	/////////////////////////////////////


	

	//가장 늦은 출발 (mintime[][1]) 시간

	// 커야됨 mintime[][1]이 커야해 커야해 


	for (i = 0; i < n; i++) {
		check[i] = 0;
	}



	mintime[end][1] = mintime[end][0];



	for (i = 0; i < n; i++) {
		now = -1;

		//위치 
		for (j = 0; j < n; j++) { 
			if (check[j])
				continue;

			if (now == -1 || mintime[now][1] < mintime[j][1])
				// 현재 위치 보다 큰게 있다?
				//mintime[][0]이랑 반대!!!!

				now = j;
		}

		check[now] = 1;



		// 시간
		for (j = 0; j < t; j++) { //시간표만큼
			for (k = 1; k < tn[j]; k++) {
				if (train[j][k][1] == now && mintime[now][1] >= train[j][k][0]) {

					// 현재역에서 출발하는 열차중
					// k번째 보다 출발 더 큰게 있다=> 검사할 가치가 있는거임. 

					z = k - 1;

					// 전 열차로 가서 .

					// 전열차역의 출발이 더 큰게 있다면. 
					// 크게 갱신 
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

	// 테스트 케이스 
	scanf("%d",&s);

	for (int i = 1; i <= s; i++) {

		// 역개수 
		scanf("%d", &n);

		for(j=0; j<n; j++){
		
			// 도시명 
			scanf("%s", cityname[j]);
			//1행 2행 3행에 받는거임. 
		
		}

		//전체 입력할 시간표 개수
		scanf("%d", &t);

		for (j = 0; j < t; j++) {

			//tn 은 시간표 t 에 포함된 역 개수(해당시간표에 몇개의 역이 있는지). 
			scanf("%d",&tn[j]);

			for(int k=0; k<tn[j]; k++){
			
				//시간과 이름(열병)
				scanf("%d %s", &train[j][k][0], name);

				//역명과 인덱스 매치에서 train[][][]에 저장. 
				train[j][k][1] = getcitytag(name);
			}
		}


		// 출발시간 입력
		scanf("%d",&depart);

		//출발지 입력
		scanf("%s", name);
		start = getcitytag(name);
		
		//도착지 입력
		scanf("%s",name);
		end = getcitytag(name);
		
		/// /////////////////////////////////////////////////////////////
		// 위까지가 다 인풋. 
	
		solve();

		printf("Scenario %d\n", i);

		if (check[end]) { // 도착지 까지 검사를 완료 했다면. 
			
			printf("Departure %04d %s \n", mintime[start][1], cityname[start]);
			//start 의 가장 큰 출발시간과 ..... 출발지와
			printf("Arrival %04d %s", mintime[end][0], cityname[end]);
			//end 의 가장 작은 도착시간을 프린트함.... 도착지와.  
		}


		else
			printf("No connection\n");
		printf("\n");

	}




	return 0;
}