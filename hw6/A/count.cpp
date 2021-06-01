//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include <thread>
#include <cstring>
static std::mutex cntexc;
void thread_counter(int* a, int sz, int *cnt, int maxv){
	int *local_counts = new int[maxv + 1];
	memset(local_counts, 0, sizeof(local_counts));
	for (int i = 0; i < sz; ++i) ++local_counts[a[i]];
	cntexc.lock();
	for (int i = 0; i <= maxv; ++i){
		cnt[i] += local_counts[i];
	}
	cntexc.unlock();
}
void parallel_count(int array[], int array_size, int counts[], int max_value){
	std::thread *mythr[splits];
	int ksz = array_size / splits, cur = 0;
	for (int i = 0; i < splits - 1; ++i, cur += ksz)
		mythr[i] = new thread(thread_counter, array + cur, ksz, counts, max_value);
	mythr[splits - 1] = new thread(thread_counter, array + cur, array_size - cur, counts, max_value);
	for (int i = 0; i < splits; ++i) mythr[i]->join();
	for (int i = 0; i < splits; ++i) delete mythr[i];
}

