#include <iostream>
#define MAXSIZE 10

using namespace std;


struct SqList
{
    int r[MAXSIZE+1]; //0用于存储哨兵或临时变量
    int length; //表长度

};
void swap(SqList *L,int i,int j);
void show(SqList *L);
void bubbleSort1(SqList *L);//16
void bubbleSort2(SqList *L);//24
void SelectSort(SqList *L);//18
void InsertSort(SqList *L);
void ShellSort(SqList *L);
void QuickSort(SqList *L);
void QSort(SqList *L,int low,int high);
int Partition(SqList *L,int low,int high);
 
int main()
{
    SqList myL = {{0,2,1,4,5,3},5};
    QuickSort(&myL);
    show(&myL); 
    return 0;
}


void swap(SqList *L,int i,int j)
{ 
    int temp;
    temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
    return;

}


void show(SqList *L)
{
    for(int i=1; i<=L->length; i++)
    {
        cout<<L->r[i]<<endl;
    }
}

void bubbleSort1(SqList *L)
{
    int i,j;
    for(i=1; i<L->length; i++) //i不需要是最后一位
    {
        for(j=i+1; j<=L->length; j++) //j不需要是第一位
        {
            if(L->r[i]>L->r[j])
            {
                swap(L,i,j);
            }

        }
    }
}
//经典的冒泡排序 从下往上“冒泡”
void bubbleSort2(SqList *L)
{
    int i,j;
    for(i=1; i<L->length; i++)
    {
        for(j=L->length-1; j>=i; j--)
        { 
            if(L->r[j]>L->r[j+1])
            {
                swap(L,j,j+1);
            }
        }
    }

}
// 简单选择排序 找到n-i中最小的 放在min中 并与第i个交换 总共交换n-1次
void SelectSort(SqList *L)
{
    int i,j,min;
    for(i=1; i<L->length; i++) //i不需要是最后一位
    {
        min = i;
        for(j=i+1; j<=L->length; j++) //j不需要是第一位
        { 
            if(L->r[j]<L->r[min]) //如果有
            {
                min = j; //找到最小的下标
            }
        } 
        if(L->r[min] != L->r[i]) //第i个不是最小的则交换
        {
            swap(L,min,i);
        }
    }
}

void InsertSort(SqList *L)
{
    //默认r1 为现有表 将r2 到rl插入到现有表中
    int i,j;
    for(i=2; i<=L->length; i++) //2~L
    {
        //插入操作
        if(L->r[i]<L->r[i-1])
        {
            L->r[0] = L->r[i];
            for(j=i-1; L->r[0]<L->r[j]; j--)
            {
                L->r[j+1] = L->r[j];
            }
            L->r[j+1] = L->r[0];
        }
    }
}

void ShellSort(SqList *L)
{
    int i,j;
    int inc = L->length;
    do //活用do{}while 和while()do
    {
        inc = inc/3+1;
        for(i=inc+1; i<=L->length; i++)
        {
        //进行插入排序
            if(L->r[i]<L->r[i-inc]) //如果小于之前的 进行插入 否则跳过
            {
                L->r[0] = L->r[i];
                //满足条件后移
                for(j=i-inc; j>0 && L->r[0]<L->r[j]; j-=inc)
                {
                    L->r[j+inc] = L->r[j];
                }
                L->r[j+inc] = L->r[0];

            }
        }
    }
    while(inc>1);
}


//快排 先找到一个点  使他的左右分别小于大于他 然后再分别对他左右的子串进行分割
void QuickSort(SqList *L)
{
    QSort(L,1,L->length);
}
void QSort(SqList *L,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot = Partition(L,low,high);
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}
int Partition(SqList *L,int low,int high)
{
    /*
        算法核心
        输入 L 低点 高点
        输出 分界值所在坐标
        选取第一个作为分界 赋值给pivotKey
        遍历————修改high 从右到左 如果有比PK小的 进行交换（保证右边的都比他大 左边的都比他小）
        修改low 从左到右 比PK大的 进行交换
        返回LOW的位置
    */
    int pivotKey = L->r[low];
    while(low<high)
    {
        while(low<high && L->r[high]>=pivotKey)
        {
            high--;
        }
        swap(L,low,high);
        while(low<high && L->r[low]<=pivotKey)
        {
            low++;
        }
        swap(L,low,high);
    }
    return low;

}
