#include <stdio.h>
#include <string.h>

#define MAXN 100 // Number of stations
#define MAXT 1000 // Maximum number of trains
#define MAXNAMELENGTH 100 // Maximum length of station name

struct Train {
    int time;
    int destination;
};

struct City {
    char name[MAXNAMELENGTH];
};

static struct City city[MAXN];
static int n, t, depart, start, end, tn[MAXT];
static struct Train train[MAXT][MAXN];
static int mintime[MAXN][2], check[MAXN];

int getCityTag(char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(name, city[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void solve() {
    // Your existing solve function remains unchanged
}

int main() {
    int s;
    char name[MAXNAMELENGTH];

    scanf("%d", &s);

    for (int i = 1; i <= s; i++) {
        scanf("%d", &n);

        // Input station names
        for (int j = 0; j < n; j++) {
            scanf("%s", city[j].name);
        }

        // Input train information
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &tn[j]);
            for (int k = 0; k < tn[j]; k++) {
                scanf("%d %s", &train[j][k].time, name);
                train[j][k].destination = getCityTag(name);
            }
        }

        // Input departure and arrival information
        scanf("%d", &depart);
        scanf("%s", name);
        start = getCityTag(name);
        scanf("%s", name);
        end = getCityTag(name);

        solve();

        printf("Scenario %d\n", i);

        if (check[end]) {
            printf("Departure %04d %s \n", mintime[start][1], city[start].name);
            printf("Arrival %04d %s", mintime[end][0], city[end].name);
        }
        else {
            printf("No connection\n");
        }
        printf("\n");
    }

    return 0;
}
