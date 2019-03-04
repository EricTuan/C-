## C++ �ļ�����

��ĿǰΪֹ�������Ѿ�ʹ���� iostream ��׼�⣬���ṩ�� cin �� cout �����ֱ����ڴӱ�׼�����ȡ�������׼���д������

���̳̽�����δ��ļ���ȡ�������ļ�д�����������Ҫ�õ� C++ ����һ����׼�� fstream���������������µ��������ͣ�

* ofstream������ļ��������ڴ����ļ������ļ�д����Ϣ��
* ifstream�������ļ��������ڴ��ļ���ȡ��Ϣ��
* fstream��	��ʾ�ļ�������ͬʱ���� ofstream �� ifstream ���ֹ��ܣ�����ζ�������Դ����ļ������ļ�д����Ϣ�����ļ���ȡ��Ϣ��

Ҫ�� C++ �н����ļ����������� C++ Դ�����ļ��а���ͷ�ļ� <iostream> �� <fstream>

## ���ļ�

�ڴ��ļ���ȡ��Ϣ�������ļ�д����Ϣ֮ǰ�������ȴ��ļ���ofstream �� fstream ���󶼿����������ļ�����д���������ֻ��Ҫ���ļ����ж���������ʹ�� ifstream ����

������ open() �����ı�׼�﷨��open() ������ fstream��ifstream �� ofstream �����һ����Ա��

```
void open(const char *filename, ios::openmode mode);
```

�����open() ��Ա�����ĵ�һ����ָ��Ҫ�򿪵��ļ������ƺ�λ�ã��ڶ������������ļ����򿪵�ģʽ��

ģʽ��־	����
* ios::app	׷��ģʽ������д�붼׷�ӵ��ļ�ĩβ��
* ios::ate	�ļ��򿪺�λ���ļ�ĩβ��
* ios::in	���ļ����ڶ�ȡ��
* ios::out	���ļ�����д�롣
* ios::trunc	������ļ��Ѿ����ڣ������ݽ��ڴ��ļ�֮ǰ���ضϣ������ļ�������Ϊ 0��

�����԰��������ֻ��������ϵ�ģʽ���ʹ�á����磬�������Ҫ��д��ģʽ���ļ�����ϣ���ض��ļ����Է��ļ��Ѵ��ڣ���ô������ʹ��������﷨��

```
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );  // ����writeģʽ
```

���Ƶأ��������Ҫ��һ���ļ����ڶ�д������ʹ��������﷨��

```
ifstream  afile;
afile.open("file.dat", ios::out | ios::in );
```

### �ر��ļ�

�ڳ�����ֹǰ�ر����д򿪵��ļ���

������ close() �����ı�׼�﷨��close() ������ fstream��ifstream �� ofstream �����һ����Ա��

```
void close();
```

### д���ļ�

�� C++ ����У�����ʹ��������������� << �����ļ�д����Ϣ������ʹ�ø�����������Ϣ����Ļ��һ����Ψһ��ͬ���ǣ���������ʹ�õ��� ofstream �� fstream ���󣬶����� cout ����

### ��ȡ�ļ�

�� C++ ����У�����ʹ������ȡ������� >> �����ļ���ȡ��Ϣ������ʹ�ø�������Ӽ���������Ϣһ����Ψһ��ͬ���ǣ���������ʹ�õ��� ifstream �� fstream ���󣬶����� cin ����

## �ļ�λ��ָ��

istream �� ostream ���ṩ���������¶�λ�ļ�λ��ָ��ĳ�Ա��������Щ��Ա������������ istream �� seekg��"seek get"���͹��� ostream �� seekp��"seek put"����

seekg �� seekp �Ĳ���ͨ����һ�������͡��ڶ���������������ָ�����ҷ��򡣲��ҷ�������� ios::beg��Ĭ�ϵģ������Ŀ�ͷ��ʼ��λ����Ҳ������ ios::cur�������ĵ�ǰλ�ÿ�ʼ��λ����Ҳ������ ios::end��������ĩβ��ʼ��λ����

�ļ�λ��ָ����һ������ֵ��ָ���˴��ļ�����ʼλ�õ�ָ������λ�õ��ֽ����������ǹ��ڶ�λ "get" �ļ�λ��ָ���ʵ����

```
// ��λ�� fileObject �ĵ� n ���ֽڣ������� ios::beg��
fileObject.seekg( n );
 
// ���ļ��Ķ�ָ��� fileObject ��ǰλ������� n ���ֽ�
fileObject.seekg( n, ios::cur );
 
// ���ļ��Ķ�ָ��� fileObject ĩβ������ n ���ֽ�
fileObject.seekg( n, ios::end );
 
// ��λ�� fileObject ��ĩβ
fileObject.seekg( 0, ios::end );
```

### ���� cin.ignore()

�����汾�� cin.ignore(int n, char a), �������� (cin) ����ȡ�ַ�����ȡ���ַ������� (ignore)������ʹ�á�

ÿ����һ���ַ�������Ҫ�����ͱȽ��ַ����������ֵ�ﵽ n ���߱��������ַ��� a���� cin.ignore()����ִ����ֹ�������������ȴ���

����һ�����ù��ܾ�����������Իس����������뻺���������ݣ�������һ���������һ�������Ӱ�졣

���������ô�ã�`cin.ignore(1024,'\n')`��ͨ���ѵ�һ���������õ��㹻������ʵ��������ֻ�еڶ������� \n �����ã�������һ����ǰѻس�(�����س�)֮ǰ�������ַ������뻺��(��)�������ȥ��

���cin.ignore()������������Ĭ�ϲ���Ϊcin.ignore(1,EOF) ���� EOF��end of file����д����ʾ"������"(stream)�Ľ�β��


### ���� cin �Ĳ��� 

ʹ�� getline(cin��str)��������ʵ�ָ��Ӽ��Լ���ȫ���ַ�������,

��ͬ�� cin.getline(char*, int a)��ǰ�߿���ֱ�Ӷ��ַ������в�����

```
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    fstream iofile;
    iofile.open("D:\\t.txt", ios::out | ios::in | ios::trunc);
    string bookname;
    string bookwriter;
    cout << "input the bookname:" << endl;
    getline(cin, bookname);
    iofile << bookname << endl;
    cout << "input the bookwriter:" << endl;
    getline(cin, bookwriter);
    iofile << bookwriter << endl;
    iofile.close();
    cout << "read the input file:" << endl;
    iofile.open("D:\\t.txt");
    while (getline(iofile, bookname))
    {
        cout << bookname << endl;

    }
 
    system("pause");
    return 0;

}
```

���� eof ָʾ���ڶ�ȡ�ļ�����β��ʱ�򣬲Ż�ı���Ч��״̬�����ǣ�����һ��û�ж������ݵ�ʱ��eof �Ż�ı䣻

���������ʱ������ eof ��־λ���ж��ļ��Ƿ������ end����ͼwhileѭ�������ͻᵼ�´�ʱ�� infile>>data ��仹���������ݣ��ļ������һ�����ݣ������¸��Ƶ��ļ��У�����һ�С�

```
while (!infile.eof())
{
    infile >> data;
    cout << data << endl;
    outfile << data << endl;
}
```

Ϊ��������Ķ�ȡ�����ƣ�����ֻ��Ҫ�ڻ��ܶ�ȡ�ļ����ݵ�ʱ�򣬲Ž����ݸ��Ƶ����ļ��м��ɣ���������Ըĳɣ�

```
while (infile >> data)
{
    cout << data << endl;
    outfile << data << endl;
}
```

