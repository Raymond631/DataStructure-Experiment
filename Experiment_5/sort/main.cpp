#include<iostream>
using namespace std;

/*
1��ֱ�Ӳ�������
2���۰��������

3��ð������
4����������

5����ѡ������
6��������

7����������
*/

//1��ֱ�Ӳ�������
void insertSort(int arr[], int len)
{
    int temp, i, j;
    for (i = 1; i <= len-1; i++)
    {
        temp = arr[i];
        for(j=i-1;j>=0;j--)
        {
            if (temp < arr[j])
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }
}

//2���۰��������
void binaryInsertSort(int arr[], int len)
{
    int temp, i, j, low, high, mid;
    for (i = 1; i <= len - 1; i++)
    {
        temp = arr[i];
        low = 0;
        high = i - 1;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if (temp < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            arr[j + 1] = arr[j];
        arr[high + 1] = temp;
    }
}

//3��ð������
void bubbleSort(int arr[], int len)
{
    int temp;
    for (int i = 0; i <= len - 2; i++)
    {
        for (int j = 0; j <= len-2-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//4����������
void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        int i = low;
        int j = high;
        int key = array[i];
        while (i < j)
        {
            while (i < j && array[j] >= key)
                j--;
            array[i] = array[j];

            while (i < j && array[i] <= key)
                i++;
            array[j] = array[i];
        }
        array[i] = key;
        quickSort(array, low, i - 1);
        quickSort(array, i + 1, high);
    }
}

//5����ѡ������
void selectSort(int arr[], int len)
{
    int min_index;
    int temp;
    for (int i = 0; i <= len - 1; i++)
    {
        min_index = i;
        for (int j = i; j <= len - 1; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

//6��������
void max_heapify(int arr[], int start, int end)
{
    //�������ڵ�ָ����ӽڵ�ָ��
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)  //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
    {
        if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
            son++;
        if (arr[dad] > arr[son]) //������ڵ����ӽڵ���������ϣ�ֱ����������
            return;
        else  //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heapSort(int arr[], int len)
{
    //��ʼ����i������һ�����ڵ㿪ʼ����
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

//7����������
int maxbit(int data[], int n) //���������������ݵ����λ��
{
    int d = 1; //��������λ��
    int p = 10;
    for (int i = 0; i < n; ++i)
    {
        while (data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixSort(int data[], int n) //��������
{
    int d = maxbit(data, n);
    int* tmp = new int[n];
    int* count = new int[10]; //������
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //����d������
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //ÿ�η���ǰ��ռ�����
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}

//��֤�����Ƿ�ɹ�
bool isSort(int arr[], int len)
{
    for (int i = 0; i <= len - 2; i++)
    {
        //����������򣬷���false
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
//�������,���ÿɲ���
void output(int arr[], int len)
{
    int num = 0;
    for (int i = 0; i <= len - 1; i++)
    {
        cout << arr[i] << " ";
        num++;
        if (num % 20 == 0)
            cout << endl;
    }
}


int main()
{
	int array[100000];
	int length = sizeof(array) / sizeof(array[0]);

    //1�����ɲ�ͬ�������
    
    srand(time(0));
    for (int i = 0; i <= length - 1; i++)
        array[i] = rand() % length;
    

    //2�����ɼ������飨����
    /*
    for (int i = 0; i <= length - 1; i++)
        array[i] = i;
    */

    //3�����ɼ������飨����
    /*
    for (int i = 0; i <= length - 1; i++)
        array[i] = length - i - 1;
    */

    //4��������ͬ�������
	/*
    srand(1);
    for (int i = 0; i <= length - 1; i++)
        array[i] = rand() % length;
    */



    //�������ǰ�����飬�ɲ���
    //output(array, length);

    clock_t start_time = clock();
    {
        //1��ֱ�Ӳ�������
        insertSort(array, length);

        //2���۰��������
        //binaryInsertSort(array, length);

        //3��ð������
        //bubbleSort(array, length);

        //4����������
        //quickSort(array, 0, length - 1);

        //5����ѡ������
        //selectSort(array, length);

        //6��������
        //heapSort(array, length);

        //7����������
        //radixSort(array, length);
    }
    clock_t end_time = clock();
    cout << "�����㷨������ʱ��Ϊ��" << double(end_time - start_time) / CLOCKS_PER_SEC << "��" << endl;

    cout << "��������飺";
    if (isSort(array, length))
        cout << "��������������ɹ���" << endl;
    else
        cout << "�������������㷨����" << endl;
    
    //������������飬�ɲ���
    //output(array, length);

	return 0;
}