#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#define MAX 30


//�ּ� �Ÿ� ���� �� �Ÿ� ã��. 

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
    //ù��°�� ������ -1
}
// quick sort �� ��� ���� �� ����.
// 

int CompareY(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y < p2->y) ? -1 :0 ;
}



/////////////////////



double stripClosest(Point strip[], int size, double d) {
    // ��� ������ �ּ� �Ÿ� ����. 
    double min = d;
    qsort(strip, size, sizeof(strip[0]), CompareY);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && j<(strip[j].y - strip[i].y) < min; j++) {

            // ����: j �� size�� ����� �ʰ�,
            //      ������� �ּ� �Ÿ� min ���� �۾ƾ���. 
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
    //d�� ������� ���� �ּҰŸ�. 


    // ��� �� �������� �¿�� d��ŭ ������ ������ �����ϰ�(strip)��
    //�̵鰣 �ּ� �Ÿ� ����. 
    Point strip[MAX];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs((long)point[i].x - (long)midPoint.x) < d) { 
            // ���� ��[i]�� ���(midPoint) �κ��� d ���Ϸ� �������ִ���
            // �� ������ �ִٸ� ������[i]�� strip �迭�� ���� �� �� �ִ�. 
            strip[j] = point[i];
            j++;
            // j ����
        }
    }

    //���������� strip�� ����� ���鰣�� �ּ� �Ÿ� ���ؾ���. 
    //�� ����� ������� ���� �ּ� �Ÿ� ��.
    return min(d, stripClosest(strip, j, d));
}


double closest(Point point[], int n) {
    qsort(point, n, sizeof(point[0]), CompareX);
    //point �� �� �� �� �������� �� n���� x���� ����. 
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

        //n���� ��. 
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
