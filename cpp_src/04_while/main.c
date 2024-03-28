// 1부터 10까지의 합을 구하는 프로그램 (while문 사용)
// 시작 값  => 10
// 끝 값   => 20
// 10부터 20까지의 합은 165입니다.
#include <stdio.h>

int main(void){
    int start, end, sum = 0;
    // unsigned char sum = 0, i = 10;
    // while(i < 10) {
    //     sum += ++i;

    // }
    printf("시작값 입력 : ");
    scanf("%d", &start);

    printf("끝 값 입력 : ");
    scanf("%d", &end);

    if (start > end) {
        int tmp = start;
        start = end;
        end = tmp;
    }

    // while(start <= end) {
    //     sum += start++;
    // }

    for (;start <= end; start++) {
        sum += start;
    }

    printf("sum : %d\n", sum);
    
    return 0;
}