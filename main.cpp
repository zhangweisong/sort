#include <iostream>
#define MAXSIZE 10

using namespace std;


struct SqList
{
    int r[MAXSIZE+1]; //0���ڴ洢�ڱ�����ʱ����
    int length; //����

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
    for(i=1; i<L->length; i++) //i����Ҫ�����һλ
    {
        for(j=i+1; j<=L->length; j++) //j����Ҫ�ǵ�һλ
        {
            if(L->r[i]>L->r[j])
            {
                swap(L,i,j);
            }

        }
    }
}
//�����ð������ �������ϡ�ð�ݡ�
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
// ��ѡ������ �ҵ�n-i����С�� ����min�� �����i������ �ܹ�����n-1��
void SelectSort(SqList *L)
{
    int i,j,min;
    for(i=1; i<L->length; i++) //i����Ҫ�����һλ
    {
        min = i;
        for(j=i+1; j<=L->length; j++) //j����Ҫ�ǵ�һλ
        { 
            if(L->r[j]<L->r[min]) //�����
            {
                min = j; //�ҵ���С���±�
            }
        } 
        if(L->r[min] != L->r[i]) //��i��������С���򽻻�
        {
            swap(L,min,i);
        }
    }
}

void InsertSort(SqList *L)
{
    //Ĭ��r1 Ϊ���б� ��r2 ��rl���뵽���б���
    int i,j;
    for(i=2; i<=L->length; i++) //2~L
    {
        //�������
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
    do //����do{}while ��while()do
    {
        inc = inc/3+1;
        for(i=inc+1; i<=L->length; i++)
        {
        //���в�������
            if(L->r[i]<L->r[i-inc]) //���С��֮ǰ�� ���в��� ��������
            {
                L->r[0] = L->r[i];
                //������������
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


//���� ���ҵ�һ����  ʹ�������ҷֱ�С�ڴ����� Ȼ���ٷֱ�������ҵ��Ӵ����зָ�
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
        �㷨����
        ���� L �͵� �ߵ�
        ��� �ֽ�ֵ��������
        ѡȡ��һ����Ϊ�ֽ� ��ֵ��pivotKey
        �������������޸�high ���ҵ��� ����б�PKС�� ���н�������֤�ұߵĶ������� ��ߵĶ�����С��
        �޸�low ������ ��PK��� ���н���
        ����LOW��λ��
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
