/*Задачка про огромный пирог

Огромный пирог разделили между сотней гостей.
Первый гость получил 1% целого пирога,
второй — 2% того, что осталось,
третий — 3% того, что осталось после перых двух гостей, и так далее.
Последний гость получил 100% того, что осталось после 99-го гостя.
Чей кусок пирога оказался самым большим?*/



#include <stdio.h>
#include <windows.h>

int procent()
{
	static int i = 0;
	i++;
	return i;
}

void pirog(float *size, int max)
{
	int i;
	int tmp = 0;

	i = procent(); // номер гостя и процент

	if (i <= 100)
	{
		printf("%-3d  %2.2f\n", i, (*size)*i/100); // вывод номера гостя и размер его прирога

		*size -= (*size)*i/100; // уменьшаем размер пирога
		pirog(size, max); //
	}
}


int main(int argc, char const *argv[])
{
	float size = 0;

	printf("Size pirog:");
	scanf("%f",&size);
	pirog(&size, -1);

	return 0;
}