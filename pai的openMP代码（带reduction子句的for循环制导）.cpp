#include<stdio.h>
#include<time.h>
#include<omp.h>  //����ompͷ�ļ� 
using namespace std;
const int N = 1e8; //���廮��������
const int NUM_THREADS = 4;
double pai = 0; //�洢����pai�Ľ��
int main() {
	clock_t startTime, endTime; //����ʱ��������ڼ�¼�̺߳ķ�ʱ��
	int i; // i��Ϊ˽�б�����ʾ��ǰ�ֿ鴫���Ƶ����
	omp_set_num_threads(NUM_THREADS); //�����߳���Ŀ
	startTime = clock(); //����ʼ
	#pragma omp parallel private(i) // �����Ƶ���䣬���Ƶ���ʶ�����Ƶ����ƣ��Ӿ��Լ������ڴ��������
	{
		int tidnub = omp_get_thread_num();//��ȡ��ǰ�̺߳ţ�������ⲿ����tidnub�͵���˽�б������룬��Ϊ�̺߳Ų�����
		#pragma omp for reduction(+: pai)
		for (i = 0; i < N; i ++) {  //���i��0��ʼ��ô�͵�N-1������������׼ȷ
			double tmp = (i + 0.5) / N; //������ʾ��ʽ�е�( i + 0.5 ) / N
			pai += 4 / (1 + tmp * tmp); //����ÿһ����������
		}

	}
	pai /= N; //����N,����pai����Ϊdouble���ͣ���������Է�ĸת��Ϊdouble���ͣ��Զ���߾��ȶ���
	endTime = clock(); //��¼�������ʱ��
	printf("Name:Chen Da\tStudent id:1004192118\n\n\n");
	printf("Calculation time:%ld ms\n pai is approximately:%.12f", endTime - startTime, pai);    //��ӡ��ʱ�ͽ��
	return 0;
}
