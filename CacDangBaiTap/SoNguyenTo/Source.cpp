#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

enum {
	SUDUNG_VONGLAP,
	SUDUNG_DEQUY
};

int number;

//Menu chinh
void menu();
void nhap();
//Cac ham tra ve 1 neu la so nguyen to, 0 neu la hop so
int nguyentoVongLap(long num);
int nguyentoDeQuy(long num, int i = 2);

void inday(int chonlua);

int main(int agrc, char** argv) {
	menu();

	return 0;
}

//implement
void menu() {
	int choice;

	while (1) {
		printf("Chon lua chuc nang\n");
		printf("1. Chon 1 de Nhap so nguyen duong\n");
		printf("2. Chon 2 de Hien thi cac so nguyen to su dung vong lap\n");
		printf("3. Chon 4 de Hien thi cac so nguyen to su dung de quy\n");
		printf("4. Chon 3 de Ket thuc\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			nhap();
			break;
		case 2:
			inday(SUDUNG_VONGLAP);
			break;
		case 3:
			exit(1);
			break;
		case 4:
			inday(SUDUNG_DEQUY);
			break;
		default:
			break;
		}

		//pause screen to view
		getch();
		system("cls");
	}
}

void nhap() {
	do {
		printf("Nhap so nguyen duong: ");
		scanf("%d", &number);
		if (number <= 0)
			printf("Vui long nhap 1 so nguyen duong!\n");
	} while (number <= 0);
}

int nguyentoVongLap(long num) {
	int i;

	for (i = 2; i < sqrt((double)num); i++)
	{
		if (num % i == 0)
			return 0;
	}
	
	return 1;
}


int nguyentoDeQuy(long num, int i) {
	if (i == num) return 1;
	if (num % i == 0) return 0;
	return nguyentoDeQuy(num, i + 1);
}

void inday(int chonlua) {
	int i;
	
	if (number == 0) {
		printf("Vui long chon chuc nang 1 de nhap so nguyen duong truoc\n");
		return;
	}

	printf("Cac so nguyen to tu nho hon %d\n", number);

	for (i = 2; i < number; i++)
	{
		if (chonlua == SUDUNG_VONGLAP) {
			if (nguyentoVongLap(i) == 1)
				printf("%10d", i);
		}
		else {
			if (nguyentoDeQuy(i) == 1)
				printf("%10d", i);
		}
	}
}

void inday2() {

}