#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int *arr;
	int len;
} set;

void sort(int a[], int len)
{
	int i, j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(a[i] < a[j])
			{
				int t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
}

int set_len(int a[], int len)
{
	sort(a, len);
	int i, j;
	
	int count = 0;
	for(i=0;i<len;i=j)
	{
		for(j=i;j<len;j++)
		{
			if(j == i)
			{
				count += 1;
			}
			if(a[j] != a[i])
			{
				break;
			}
		}
	}
	return count;
}

set create_set(int a[], int len)
{
	int s_len = set_len(a,len);
	
	set res;
	res.len = s_len;
	res.arr = (int*)malloc(sizeof(int)*s_len);
	
	int i,j,k=0;
	for(i=0;i<len;i=j)
	{
		for(j=i;j<len;j++)
		{
			if(j == i)
			{
				res.arr[k] = a[i];
				k++;
			}
			if(a[j] != a[i])
			{
				break;
			}
		}
	}
	
	return res;
}

void print_list(set a)
{
	if(a.len <= 0 || a.arr == NULL)
	{
		printf("ø\n");
	}else{
		int i;
		printf("{ ");
		for(i=0;i<a.len;i++)
		{
			printf("%d ",a.arr[i]);
		}
		printf("}\n");
	}
}

set intersect(set a, set b){
	
	if(a.len <= 0 || b.len <= 0)
	{
		set m;
		m.len = 0;
		m.arr = NULL;
	}
	
	set inter;
	inter.len = 0;
	int i,j;
	for(i=0;i<a.len;i++)
	{
		for(j=0;j<b.len;j++)
		{
			if(a.arr[i] == b.arr[j])
			{
				inter.len++;
				break;
			}
		}
	}
	
	inter.arr = (int*)malloc(sizeof(int)*inter.len);
	int k =0;
	for(i=0;i<a.len;i++)
	{
		for(j=0;j<b.len;j++)
		{
			if(a.arr[i] == b.arr[j])
			{
				inter.arr[k] = a.arr[i];
				k++;
				break;
			}
		}
	}
	return inter;
}

set minus(set a, set b)
{
	set in = intersect(a,b);
	set m;
	m.len = a.len - in.len;
	if(m.len <= 0)
	{
		m.arr = NULL;
		return m;
	}
	m.arr = (int*)malloc(sizeof(int)*m.len);
	
	int i,j,k=0;
	for(i=0; i<a.len;i++)
	{
		for(j=0;j<in.len;j++)
		{
			if(a.arr[i] == in.arr[j])
			{
				break;
			}
		}
		if(j == in.len)
		{
			m.arr[k] = a.arr[i];
			k++;
		}
	}
	
	free(in.arr);
	return m;
}

set unions(set a, set b)
{
	
	if(a.len <= 0 && b.len <= 0)
	{
		set m;
		m.len = 0;
		m.arr = NULL;
		return m;
	}
	
	if(b.len <= 0)
	{
		return a;
	}
	
	if(a.len <= 0)
	{
		return b;
	}
	
	set u;
	set in = intersect(a,b);
	
	u.len = a.len + b.len - in.len;
	u.arr = (int*)malloc(sizeof(int)*u.len);
	
	int i,j,k=0;
	for(i=0; i<a.len;i++)
	{
		for(j=0;j<in.len;j++)
		{
			if(a.arr[i] == in.arr[j])
			{
				break;
			}
		}
		if(j == in.len)
		{
			u.arr[k] = a.arr[i];
			k++;
		}
	}
	
	for(i=0; i<b.len;i++)
	{
		u.arr[k] = b.arr[i];
		k++;
	}
	
	sort(u.arr, u.len);
	
	free(in.arr);
	return u;
}

int main(int argc, char *argv[])
{
	int aa[10];
	int bb[10];
	
	int i;
	printf("Enter 10 numbers to array A: ");
	for(i=0;i<10;i++)
	{
		scanf(" %d", &aa[i]);
	}
	
	printf("Enter 10 numbers to array B: ");
	for(i=0;i<10;i++)
	{
		scanf(" %d", &bb[i]);
	}
	
	set a = create_set(aa, 10);
	set b = create_set(bb, 10);
	
	printf("\nSet A: ");
	print_list(a);
	printf("Set B: ");
	print_list(b);
	
	set c = intersect(a,b);
	set d = unions(a,b);
	set e = minus(a,b);
	set f = minus(b,a);
	
	printf("\nA intersect B: ");
	print_list(c);
	printf("A union B:     ");
	print_list(d);
	printf("A minus B:     ");
	print_list(e);
	printf("B minus A:     ");
	print_list(f);
	
	free(a.arr);
	free(b.arr);
	free(c.arr);
	free(d.arr);
	free(e.arr);
	free(f.arr);
	return 0;
}