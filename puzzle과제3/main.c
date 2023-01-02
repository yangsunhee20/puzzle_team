#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>


char pz[3][3] = { '0','1','2','3','4','5','6','7','8' };
int zero_col;
int zero_row;
void init();
void display();
void getkey();
void zero();
void num_rand();
int check();
int play(char *);

int main()
{
   int cnt;
   char answer;
   char * pzPoint[9] = {"star","one","two","three","four","five","six","seven","eight" };
    srand(GetTickCount());
    init();
    num_rand();

    while (1)
    {
        system("cls");
       
        if (check() == 1)
        {
         display();
         printf("\ncount : %d \n",cnt);
         //printf("one , five , star");
            printf("\nfinish!!\n");
         printf("계속 하시겠습니까? (y/n) : ");
         scanf("%c",&answer);
         if(answer == 'n') return 0;
        }
      display();
      cnt = play(*pzPoint);
    }
}

int play(char* pzPoint)
{
   static int count;
   count ++;
   printf("\n count : %d",count);
    getkey();

    return count;
}

void init(){
    int r, c;
    int count = 1;

    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            pz[r][c] = count;
            count++;
        }
    }
    pz[2][2] = 0;
}

void display() 
{
    int r, c;

    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
         if(pz[r][c] == 0) printf(" * ");
         else printf("%2d ", pz[r][c]);
         
        }
        printf("\n");
    }
}

void zero()
{
    int i, k = 0;
    for (i = 0; i < 3; i++) {
        for (k = 0; k < 3; k++) {
            if (pz[i][k] == 0) {
                zero_row = i;
                zero_col = k;
                return;
            }
        }
    }
}


void getkey()
{
   int temp;
   int next_row;
   int next_col;

    if (_kbhit)
    {
        int key = _getch();

        if (key == 224)
        {
            key = _getch();
            zero();

            next_row = zero_row;
            next_col = zero_col;


            switch (key)
            {
            case 75: //왼쪽
                if (zero_col == 0) return;
                next_col--;
                break;

            case 77: //오른쪽
                if (zero_col == 2) return;
                next_col++;
                break;

            case 72: //위
                if (zero_row == 0) return;
                next_row--;
                break;

            case 80: //아래
                if (zero_row == 2) return;
                next_row++;
                break;
            }

            temp = pz[zero_row][zero_col];
            pz[zero_row][zero_col] = pz[next_row][next_col];
            pz[next_row][next_col] = temp;
        }
    }
}

void num_rand()
{
    int next_row;
    int next_col;
    int shuffle;
    int i, temp;

    for (i = 0; i < 30; i++)
    {
        shuffle = rand() % 4;
        zero();
        next_row = zero_row;
        next_col = zero_col;

        switch (shuffle)
        {
        case 0:
            if (zero_col == 0) continue;
            next_col--;
            break;
        case 1:
            if (zero_col == 2) continue;
            next_col++;
        case 2:
            if (zero_row == 0) continue;
            next_row--;
            break;
        case 3:
            if (zero_row == 2) continue;
            next_row++;
            break;
        }
        temp = pz[zero_row][zero_col];
        pz[zero_row][zero_col] = pz[next_row][next_col];
        pz[next_row][next_col] = temp;
    }
}

int check()
{
    int r, c;
    int count = 1;
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            if (pz[r][c] == count) count++;
        }
    }

    if (count == 9 && pz[2][2] == 0) return 1;
    else return 0;
}