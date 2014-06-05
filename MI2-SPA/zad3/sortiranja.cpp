//
//void selection_sort(int *data, int length) {
//	for (int i = 0; i < length; ++i) {
//		int min_index = i;
//		for (int j = i + 1; j < length; ++j) {
//			if (data[j] < data[min_index]) {
//				min_index = j;
//			}
//		}
//		swap(data[min_index], data[i]);
//	}
//}
//
//void insertion_sort(int *data, int length) {
//	for (int i = 1; i < length; i++) { 
//		int temp = data[i];
//		for (int j = i; j >= 1 && data[j - 1] > temp; --j) {
//			swap(data[j], data[j - 1]);
//		}
//	}
//}
