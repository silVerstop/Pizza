#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_SIZE];
	int size;
}order;

void error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

void init(order *L)
{
	L->size = 0;
}

int is_empty(order *L)
{
	return L->size == 0;
}

int is_full(order *L)
{
	return L->size == MAX_SIZE;
}

element get_entry(order *L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

void print_list(order *L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(order *L, element item)
{
	if (L->size >= MAX_SIZE)
		error("리스트 오버플로우");
	L->array[L->size++] = item;
}

void insert(order *L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

element delete(order *L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		error("위치오류");
	item = L->array[pos];

	L->array[pos] = 0;

	return item;
}

int find(order *L, int item)
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)//array의 원소와 찾으려는 item값이 같을 때 까지 반복
	{
		if (L->array[i] == item) {
			return i;
			break;
		}
	}
}

void pizza_menu(int a)
{
	switch (a) {
	case 1:
		printf("불고기피자");
		break;
	case 2:
		printf("포테이토피자");
		break;
	case 3:
		printf("고구마피자");
		break;
	case 4:
		printf("쉬림프피자");
		break;
	}
}

int main(void)
{
	int select, ord, revod;
	int i;
	order list;
	init(&list);
	for (i = 0; i < MAX_SIZE; i++) {
		printf("\n=======================\n");
		printf("손님 모드 = 1\n");
		printf("점원 모드 = 2\n");

		printf("\n모드를 선택하시오 : ");
		scanf_s("%d", &select);
		printf("=========================================================\n");


		if (select == 1)
		{
			printf("1. 불고기피자 2. 포테이토피자 3. 고구마피자 4. 쉬림프피자\n\n");
			printf("원하는 피자의 번호를 입력하여 주세요 : ");

			scanf_s("%d", &ord);

			if (list.size == 0)
				insert(&list, 0, ord);
			else
				insert_last(&list, ord);

		}

		else if (select == 2)
		{
			int b;
			printf("주문 메뉴 나감 = 1   영업 종료 = 2\n");
			scanf_s("%d", &b);

			if (b == 1)
			{
				printf("\n들어온 주문\n");
				printf("----------------------------\n");
				print_list(&list);
				printf("--------------------------\n\n");

				printf("나온 피자의 번호를 입력하여 주세요 : ");
				scanf_s("%d", &revod);

				int give = find(&list, revod);

				printf("\n해당 메뉴를 주문하신 손님께 알림을 울립니다.\n\n");

				printf("%d번 손님, 주문하신 ", give + 1);
				pizza_menu(revod); printf(" 나왔습니다.\n\n");
				delete(&list, give);
			}
			else
				break;

		}
	}
	return 0;
}