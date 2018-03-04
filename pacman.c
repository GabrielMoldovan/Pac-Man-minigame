    #include <stdio.h>
#include <stdlib.h>

void printTask2(int n, int m, int y, int x, int p, char direction, int l1, int l2,
        int l3, int c1, int c2, int c3) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("*");
                continue;
            }
            if (i == x && j == y) {
                if (direction == 'w') {
                    printf("^");
                    continue;
                }
                if (direction == 's') {
                    printf("v");
                    continue;
                }
                if (direction == 'a') {
                    printf("<");
                    continue;
                }
                if (direction == 'd') {
                    printf(">");
                    continue;
                }
            }
            if (p > 0) {
                if (p == 1) {
                    if (i == l1 && j == c1) {
                        printf("x");
                        continue;
                    }
                }
                if (p == 2) {
                    if ((i == l1 && j == c1) || (i == l2 && j == c2)) {
                        printf("x");
                        continue;
                    }
                }
                if (p == 3) {
                    if ((i == l1 && j == c1) || (i == l2 && j == c2) ||
                            (i == l3 && j == c3)) {
                        printf("x");
                        continue;
                    }
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

char movePlayer(int n, int m, int *y, int *x, char olddirection) {
    char direction;
    scanf("%c", &direction);
    if (direction == 'w') {
        if ((*x) <= 1) {
            return olddirection;
            //printf("out of border");
        } else {
            (*x) = (*x) - 1;
            return direction;
        }
    }
    if (direction == 's') {
        if ((*x) >= (n - 2)) {
            return olddirection;
            //printf("out of border");
        } else {
            (*x) = (*x) + 1;
            return direction;
        }
    }
    if (direction == 'a') {
        if ((*y) <= 1) {
            return olddirection;
            //printf("out of border");
        } else {
            (*y)--;
            return direction;
        }
    }
    if (direction == 'd') {
        if ((*y) >= (m - 2)) {
            return olddirection;
            //printf("out of border");
        } else {
            (*y)++;
            return direction;
        }
    }
    return 'q';
}

void moveObstacle(int *y, int *x, int *l1, int *l2, int *l3, int *c1, int *c2,
        int *c3, char m1, char m2, char m3, int p) {

    if (m1 == 'm') {
        if ((*l1) == (*x)) {
            if ((*c1) < (*y)) {
                (*c1)++;
            } else {
                (*c1)--;
            }
        }
        if ((*c1) == (*y)) {
            if ((*l1) < (*x)) {
                (*l1)++;
            } else {
                (*l1)--;
            }
        }
        if (((*c1) != (*y)) && ((*l1) != (*x))) {
            if ((*c1) < (*y)) {
                (*c1)++;
            } else {
                (*c1)--;
            }
            if ((*l1) < (*x)) {
                (*l1)++;
            } else {
                (*l1)--;
            }
        }
    }

    if (m2 == 'm') {
        if ((*l2) == (*x)) {
            if ((*c2) < (*y)) {
                (*c2)++;
            } else {
                (*c2)--;
            }
        }
        if ((*c2) == (*y)) {
            if ((*l2) < (*x)) {
                (*l2)++;
            } else {
                (*l2)--;
            }
        }
        if (((*c2) != (*y)) && ((*l2) != (*x))) {
            if ((*c2) < (*y)) {
                (*c2)++;
            } else {
                (*c2)--;
            }
            if ((*l2) < (*x)) {
                (*l2)++;
            } else {
                (*l2)--;
            }
        }

    }

    if (m3 == 'm') {
        if ((*l3) == (*x)) {
            if ((*c3) < (*y)) {
                (*c3)++;
            } else {
                (*c3)--;
            }
        }
        if ((*c3) == (*y)) {
            if ((*l3) < (*x)) {
                (*l3)++;
            } else {
                (*l3)--;
            }
        }
        if (((*c3) != (*y)) && ((*l3) != (*x))) {
            if ((*c3) < (*y)) {
                (*c3)++;
            } else {
                (*c3)--;
            }
            if ((*l3) < (*x)) {
                (*l3)++;
            } else {
                (*l3)--;
            }
        }

    }
}

int verifyObstacle(int *y, int *x, int *l, int *c){
    
    if ((*x) == (*l) && (*y) == (*c)){
        printf("GAME OVER\n");
        return 0;
    }
    return 1;
}

int main() {
    char junk;
    int n, m, *x, *y, p;
    char direction = 's';
    x = malloc(sizeof (int));
    y = malloc(sizeof (int));
    scanf("%d %d %d %d %d", &n, &m, x, y, &p);
    n += 2;
    m += 2;
    // *x = valx;
    // *y = valy;
    int *l1 = malloc(sizeof (int));
    int *c1 = malloc(sizeof (int));
    int *l2 = malloc(sizeof (int));
    int *c2 = malloc(sizeof (int));
    int *l3 = malloc(sizeof (int));
    int *c3 = malloc(sizeof (int));
    *l1 = -1;
    *l2 = -1;
    *l3 = -1;
    *c1 = -1;
    *c2 = -1;
    *c3 = -1;
    char m1 = 'f', m2 = 'f', m3 = 'f';
    if (p > 0) {
        if (p == 1) {
            scanf("%d %d %c", l1, c1, &m1);
        }
        if (p == 2) {
            scanf("%d %d %c", l1, c1, &m1);
            scanf("%d %d %c", l2, c2, &m2);
        }
        if (p == 3) {
            scanf("%d %d %c", l1, c1, &m1);
            scanf("%d %d %c", l2, c2, &m2);
            scanf("%d %d %c", l3, c3, &m3);
        }
    }
    
    printTask2(n, m, *x, *y, p, direction, *l1, *l2, *l3, *c1, *c2, *c3);
    int counter = 1;
    while ((*x) != (m - 2) || (*y) != (n - 2)) {
        scanf("%c", &junk);
        if (!verifyObstacle(x, y, l1, c1)) return 0;
        if (!verifyObstacle(x, y, l2, c2)) return 0;
        if (!verifyObstacle(x, y, l3, c3)) return 0;
        if (counter == 2) {
            moveObstacle(x, y, l1, l2, l3, c1, c2, c3, m1, m2, m3, p);
            counter = 1;
        } else {
            counter++;
        }
        direction = movePlayer(n, m, x, y, direction);
//        printf("11 = %d c1 = %d\n", *l1, *c1);
//        printf("12 = %d c2 = %d\n", *l2, *c2);
//        printf("13 = %d c3 = %d\n", *l3, *c3);
//        printf("x = %d y = %d\n", *x, *y);
        
        if (!verifyObstacle(x, y, l1, c1)) return 0;
        if (!verifyObstacle(x, y, l2, c2)) return 0;
        if (!verifyObstacle(x, y, l3, c3)) return 0;
        if (direction == 'q')
            return 1;
        //printf("\n");
        
        if (!((*x) == (*l1 + 1) && (*y) == (*c1 + 1)) && 
            !((*x) == (*l2 + 1) && (*y) == (*c2 + 1)) && 
            !((*x) == (*l3 + 1) && (*y) == (*c3 + 1)))
                printTask2(n, m, *x, *y, p, direction, *l1, *l2, *l3, *c1, *c2, *c3);
        else{
            printf("GAME OVER\n");
            return 0;
        }
        //        printf("x = %d y = %d", *x, *y);
        if ((*x) == m - 2 && (*y) == n - 2)
            break;
    }
    printf("GAME COMPLETED\n");



    return 1;
}
