#include <iostream>
#include <vector>


int countGreaterThan(const std::vector<int>& arr, int pivot) {
    int left = 0;
    int right = arr.size() - 1;
    int result = 0;
    

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= pivot) {
            // Если элемент меньше или равен pivot, идем вправо
            left = mid + 1;
        } else {
            // Если элемент больше pivot, запоминаем его позицию
            // и ищем еще более левый элемент, который тоже может быть больше pivot
            result = arr.size() - mid;  // все элементы справа от mid тоже больше pivot
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    
    std::vector<int> arr = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    
   
    int pivot;
    std::cout << "Введите точку отсчета: ";
    std::cin >> pivot;
    

    int count = countGreaterThan(arr, pivot);
    
   
    std::cout << "Количество элементов в массиве больше " << pivot 
              << ": " << count << std::endl;
    
    return 0;
}