// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void leftRotateByOne(int arr[],int n)
{
	int temp = arr[0];
	for(int i=0;i<n;i++)
	{
		arr[i] = arr[i+1];
	}
	arr[n-1] = temp;
}

void leftRotate(int arr[], int d, int n)
{
	for(int i=0;i<d;i++)
	{
		leftRotateByOne(arr,n);
	}
}

void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<" "<<arr[i];
	cout<<endl;
}

int gcd(int a,int b)
{
    if(b == 0)
    return a;
     
    else
    return gcd(b, a%b);
}

int search(int arr[], int l, int h, int key)
{
	if(l>h) return -1;
	
	int mid=(l+h)/2;
	if(arr[mid]==key) return mid;
	
	if(arr[l] <= arr[mid])
	{
		if(key >= arr[l] && key <= arr[mid])
		{
			return search(arr,l,mid-1,key);
		}
		else
			return search(arr,mid+1,h,key);
	}
	
	if(key >= arr[mid] && key <= arr[h])
		return search(arr,mid+1,h,key);
	else
		return search(arr,l,mid-1,key);	
	
}

char *removeDups(char *str)
{
	int j=0;
	bool count[256]={false};
	for(int i=0;i<strlen(str);i++)
	{
		if(count[str[i]]==false)
		{
			str[j]=str[i];
			count[str[i]]=true;
			j++;
		}
	}
	str[j]='\0';
	return str;
}

unsigned countWords(char *str)
{
//	if(strlen(str)==0) return 0;
	int count=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]) && ((i== strlen(str)-1) || !(isalpha(str[i+1]))))
			count++;
	}
	return count;
	
}
int main(int argc, char** argv) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Function calling
    leftRotate(arr, 2, n); // O(n*d)
    printArray(arr,n);
    
//    JugArray(arr,)

	int arr1[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int key = 6;
    int i = search(arr1, 0, n1-1, key);
    cout<<"FOUND INDEX ::"<<i<<endl;
    
    char str[] = "geeksforgeeks";
    printf("%s", removeDups(str));

    char str1[] = "One two         three\n    four\tfive  ";
    printf("No of words : %u", countWords(str1));
    
	return 0;
}

