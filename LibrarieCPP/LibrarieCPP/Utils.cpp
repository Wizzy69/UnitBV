#pragma once
#include "Utils.h"

template <typename T>
void Utils::Array::Print(T *array, int &size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
std::pair<T *, int> Utils::Array::ReadFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "File not found!\n";
        return std::make_pair(nullptr, -1);
    }

    int size;
    file >> size;
    T *array = new T[size];

    for (int i = 0; i < size; i++)
    {
        file >> array[i];
    }

    file.close();
    return std::make_pair(array, size);
}

template <typename T>
void Utils::Array::WriteToFile(std::string fileName, T *array, int &size)
{
    std::ofstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "File not found!\n";
        return;
    }

    file << size << "\n";
    for (int i = 0; i < size; i++)
    {
        file << array[i] << " ";
    }

    file.close();
}

template <typename T>
int Utils::Array::BinarySearch::Search(T *array, int &size, T value)
{
    int left = 0;
    int right = size - 1;
    int middle = 0;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (array[middle] == value)
        {
            return middle;
        }
        else if (array[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

template <typename T>
void Utils::Array::SortingAlgorithms::BubbleSort(T *array, int &size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template <typename T>
void Utils::Array::SortingAlgorithms::InsertionSort(T *array, int &size)
{
    for (int i = 1; i < size; i++)
    {
        T key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

template <typename T>
void Utils::Array::SortingAlgorithms::SelectionSort(T *array, int &size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}

template <typename T>
void Utils::Array::SortingAlgorithms::MergeSort(T *array, int &size)
{
    if (size <= 1)
    {
        return;
    }

    int middle = size / 2;
    int leftSize = middle;
    int rightSize = size - middle;

    T *left = new T[leftSize];
    T *right = new T[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        left[i] = array[i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        right[i] = array[middle + i];
    }

    MergeSort(left, leftSize);
    MergeSort(right, rightSize);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

template <typename T>
void Utils::Array::SortingAlgorithms::QuickSort(T *array, int &size)
{
    if (size <= 1)
    {
        return;
    }

    int pivot = array[size / 2];
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        while (array[left] < pivot)
        {
            left++;
        }
        while (array[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            std::swap(array[left], array[right]);
            left++;
            right--;
        }
    }

    QuickSort(array, right + 1);
    QuickSort(array + left, size - left);
}
