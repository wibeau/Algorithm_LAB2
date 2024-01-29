#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#define MAX 30


//최소 거리 두점 의 거리 찾기. 

struct Point {
    double x, y;
};

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double min(double x, double y) {
    return (x < y) ? x : y;
}

int CompareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x < p2->x) ? -1 : 0;
    //첫번째가 작으면 -1
}
// quick sort 가 어떻게 비교할 것 인지.
// 

int CompareY(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y < p2->y) ? -1 :0 ;
}



/////////////////////



double stripClosest(Point strip[], int size, double d) {
    // 가운데 선에서 최소 거리 구함. 
    double min = d;
    qsort(strip, size, sizeof(strip[0]), CompareY);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && j<(strip[j].y - strip[i].y) < min; j++) {

            // 조건: j 가 size를 벗어나지 않고,
            //      현재까지 최소 거리 min 보다 작아야함. 
            if (dist(strip[i].x, strip[i].y, strip[j].x, strip[j].y) < min) {
                min = dist(strip[i].x, strip[i].y, strip[j].x, strip[j].y);
            }
        }
    }

    return min;
}


double bruteForce(Point point[], int n)
{
    double min = INFINITY;

    for (int i = 0; i < n; ++i) {
    
    
        for (int j = i + 1; j < n; ++j) {
            if (dist(point[i].x, point[i].y, point[j].x, point[j].y) < min) {
                min = dist(point[i].x, point[i].y, point[j].x, point[j].y);

            }
        
        }
           
    
    }
      
    return min;
}


double closestUtil(Point point[], int n) {


    if (n <= 3) { 
    
        return bruteForce(point, n);

    }

    int mid = n / 2;
    Point midPoint = point[mid];
    double dL = closestUtil(point, mid);
    double dR = closestUtil(point + mid, n - mid);
    double d = min(dL, dR);
    //d는 현재까지 구한 최소거리. 


    // 가운데 선 기준으로 좌우로 d만큼 떨어진 점들을 선택하고(strip)애
    //이들간 최소 거리 선택. 
    Point strip[MAX];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs((long)point[i].x - (long)midPoint.x) < d) { 
            // 현재 점[i]이 가운데(midPoint) 로부터 d 이하로 떨어져있는지
            // 더 작은게 있다면 현재점[i]은 strip 배열에 포함 될 수 있다. 
            strip[j] = point[i];
            j++;
            // j 개수
        }
    }

    //최종적으로 strip에 저장된 점들간의 최소 거리 구해야함. 
    //그 결과와 현재까지 구한 최소 거리 비교.
    return min(d, stripClosest(strip, j, d));
}


double closest(Point point[], int n) {
    qsort(point, n, sizeof(point[0]), CompareX);
    //point 들 속 땡 땡 사이즈의 점 n개를 x기준 정렬. 
    return closestUtil(point, n);
}



int main() {
    int n;
    int i = 0;
    int cnt = 0;

    while (1) {
        scanf("%d", &n);

        if (n == 0)
            break;

        Point point[MAX];

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &point[i].x, &point[i].y);
        }

        //n개의 점. 
        double closestDistance = closest(point, n);

     
        /////////////////////////////////////////////////////////
       

        if (closestDistance >= 10000) {
            printf("Infinity\n");
            break;
        }
        else {
            printf("%.2lf\n", closestDistance);
        }
    }

    return 0;
}
