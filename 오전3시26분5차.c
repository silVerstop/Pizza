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
		error("��ġ ����");
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
		error("����Ʈ �����÷ο�");
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
		error("��ġ����");
	item = L->array[pos];

	L->array[pos] = 0;

	return item;
}

int find(order *L, int item)
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)//array�� ���ҿ� ã������ item���� ���� �� ���� �ݺ�
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
		printf("�Ұ������");
		break;
	case 2:
		printf("������������");
		break;
	case 3:
		printf("��������");
		break;
	case 4:
		printf("����������");
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
		printf("�մ� ��� = 1\n");
		printf("���� ��� = 2\n");

		printf("\n��带 �����Ͻÿ� : ");
		scanf_s("%d", &select);
		printf("=========================================================\n");


		if (select == 1)
		{
			printf("1. �Ұ������ 2. ������������ 3. �������� 4. ����������\n\n");
			printf("���ϴ� ������ ��ȣ�� �Է��Ͽ� �ּ��� : ");

			scanf_s("%d", &ord);

			if (list.size == 0)
				insert(&list, 0, ord);
			else
				insert_last(&list, ord);

		}

		else if (select == 2)
		{
			int b;
			printf("�ֹ� �޴� ���� = 1   ���� ���� = 2\n");
			scanf_s("%d", &b);

			if (b == 1)
			{
				printf("\n���� �ֹ�\n");
				printf("----------------------------\n");
				print_list(&list);
				printf("--------------------------\n\n");

				printf("���� ������ ��ȣ�� �Է��Ͽ� �ּ��� : ");
				scanf_s("%d", &revod);

				int give = find(&list, revod);

				printf("\n�ش� �޴��� �ֹ��Ͻ� �մԲ� �˸��� �︳�ϴ�.\n\n");

				printf("%d�� �մ�, �ֹ��Ͻ� ", give + 1);
				pizza_menu(revod); printf(" ���Խ��ϴ�.\n\n");
				delete(&list, give);
			}
			else
				break;

		}
	}
	return 0;
}