#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[110] = {10, 10, 9, 8, 8, 7, 7, 7, 6, 5};
int partition(int l, int r)
{
	int i = l, j = r, tmp = a[l];
	while (i < j) {
		while (a[j] >= tmp && i < j) j--;
		while (a[i] <= tmp && i < j) i++;
		if (i < j) swap(a[i], a[j]); 
	}
	swap(a[l], a[i]);
	return j;
}
int partition3(int l, int r)
{
	int i = l, j = r, tmp = a[i];
	while (i < j) {
		while (i < j && a[j] >= x) j--;
		if (i < j) {
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < x) i++;
		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}
	a[i] = tmp;
	return i;
}
int split(int l, int r)
{
	int i = l, tmp = a[i];
	for (int j = l+1; j <= r; j++)
		if (a[j] <= tmp) {
			i++;
			swap(a[i], a[j]);
		}
	swap(a[l], a[i]);
	for (int i = l; i <= r; i++)
		printf("%d ", a[i]);
	puts("");
	return i;
}
void mysort(int l, int r)
{
	if (l < r) {
		// int p = partition(l, r);
		int p = split(l, r);
		mysort(l, p-1);
		mysort(p+1, r);
	}
}
int main()
{
	mysort(0, 9);
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	puts("");
	return 0;
}