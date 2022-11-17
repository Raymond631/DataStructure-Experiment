#include<iostream>
using namespace std;

/*
1、直接插入排序
2、折半插入排序

3、冒泡排序
4、快速排序

5、简单选择排序
6、堆排序

7、基数排序
*/

//1、直接插入排序
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

//2、折半插入排序
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

//3、冒泡排序
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

//4、快速排序
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

//5、简单选择排序
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

//6、堆排序
void max_heapify(int arr[], int start, int end)
{
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)  //若子节点指标在范围内才做比较
    {
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else  //否则交换父子内容再继续子节点和孙节点比较
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heapSort(int arr[], int len)
{
    //初始化，i从最後一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

//7、基数排序
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int d = 1; //保存最大的位数
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
void radixSort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int* tmp = new int[n];
    int* count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}

//验证排序是否成功
bool isSort(int arr[], int len)
{
    for (int i = 0; i <= len - 2; i++)
    {
        //如果存在逆序，返回false
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
//输出数组,可用可不用
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

    //1、生成不同随机数组
    
    srand(time(0));
    for (int i = 0; i <= length - 1; i++)
        array[i] = rand() % length;
    

    //2、生成极端数组（正序）
    /*
    for (int i = 0; i <= length - 1; i++)
        array[i] = i;
    */

    //3、生成极端数组（逆序）
    /*
    for (int i = 0; i <= length - 1; i++)
        array[i] = length - i - 1;
    */

    //4、生成相同随机数组
	/*
    srand(1);
    for (int i = 0; i <= length - 1; i++)
        array[i] = rand() % length;
    */



    //输出排序前的数组，可不用
    //output(array, length);

    clock_t start_time = clock();
    {
        //1、直接插入排序
        insertSort(array, length);

        //2、折半插入排序
        //binaryInsertSort(array, length);

        //3、冒泡排序
        //bubbleSort(array, length);

        //4、快速排序
        //quickSort(array, 0, length - 1);

        //5、简单选择排序
        //selectSort(array, length);

        //6、堆排序
        //heapSort(array, length);

        //7、基数排序
        //radixSort(array, length);
    }
    clock_t end_time = clock();
    cout << "排序算法的运行时间为：" << double(end_time - start_time) / CLOCKS_PER_SEC << "秒" << endl;

    cout << "排序结果检查：";
    if (isSort(array, length))
        cout << "不存在逆序，排序成功！" << endl;
    else
        cout << "存在逆序，排序算法有误！" << endl;
    
    //输出排序后的数组，可不用
    //output(array, length);

	return 0;
}