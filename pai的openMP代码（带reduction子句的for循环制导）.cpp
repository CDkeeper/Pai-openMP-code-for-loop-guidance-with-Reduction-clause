#include<stdio.h>
#include<time.h>
#include<omp.h>  //导入omp头文件 
using namespace std;
const int N = 1e8; //定义划分区间数
const int NUM_THREADS = 4;
double pai = 0; //存储运算pai的结果
int main() {
	clock_t startTime, endTime; //定义时间变量用于记录线程耗费时间
	int i; // i作为私有变量表示当前分块传入制导语句
	omp_set_num_threads(NUM_THREADS); //设置线程数目
	startTime = clock(); //程序开始
	#pragma omp parallel private(i) // 编译制导语句，由制导标识符，制导名称，子句以及括号内传入参数等
	{
		int tidnub = omp_get_thread_num();//获取当前线程号，如果在外部定义tidnub就得以私有变量传入，因为线程号不共享
		#pragma omp for reduction(+: pai)
		for (i = 0; i < N; i ++) {  //如果i从0开始那么就到N-1结束否则结果不准确
			double tmp = (i + 0.5) / N; //用来表示公式中的( i + 0.5 ) / N
			pai += 4 / (1 + tmp * tmp); //加上每一区间运算结果
		}

	}
	pai /= N; //除以N,由于pai定义为double类型，所以无需对分母转换为double类型，自动向高精度对齐
	endTime = clock(); //记录程序结束时间
	printf("Name:Chen Da\tStudent id:1004192118\n\n\n");
	printf("Calculation time:%ld ms\n pai is approximately:%.12f", endTime - startTime, pai);    //打印耗时和结果
	return 0;
}
