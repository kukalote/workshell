#include <stdio.h>  
#define len(a) (sizeof(a) / sizeof(a[0])) //数组长度  
int lis(int arr[], int len)  
{  
    int longest[len];  
    for (int i=0; i<len; i++)  
        longest[i] = 1;  

printf("%4d %4d %4d %4d \n", arr[i], arr[j], longest[i], longest[j]);
    for (int j=1; j<len; j++) {   
        for (int i=0; i<j; i++) {   
printf("%4d %4d \n", arr[i], arr[j]);
            if (arr[j]>arr[i] && longest[j]<longest[i]+1){ //注意longest[j]<longest[i]+1这个条件，不能省略。                                      
printf("%4d %4d %4d %4d \n", arr[i], arr[j], longest[i], longest[j]);
                longest[j] = longest[i] + 1; //计算以arr[j]结尾的序列的最长递增子序列长度  
            }   
        }
    }   

    int max = 0;  
    for (int j=0; j<len; j++) {   
        printf( "longest[%d]\n", longest[j] );
        if (longest[j] > max) max = longest[j];  //从longest[j]中找出最大值  
    }   
    return max;  
}  

int main()  
{  
//    int arr[] = {1, 4, 5, 6, 2, 3, 8}; //测试数组  
    int arr[] = { 22, 23, 7, 8, 11, 25, 10}; //测试数组  
    int ret = lis(arr, len(arr));  
//    cout << "1, 4, 5, 6 ,2, 3, 8"  << endl;  
    printf( " 22, 23, 7, 8, 11, 25, 10 " );
    printf( "max increment substring len=%d\n", ret );
    return 0;  
} 
