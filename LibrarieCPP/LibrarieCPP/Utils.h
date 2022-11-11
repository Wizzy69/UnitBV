#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace Utils
{
	namespace Array
	{
		template <typename T>
		std::pair<T *, int> ReadFromFile(std::string fileName);

		template <typename T>
		void WriteToFile(std::string fileName, T *array, int &size);

		template <typename T>
		void Print(T *array, int &size);

		namespace BinarySearch
		{
			template <typename T>
			int Search(T *array, int &size, T value);
		}

		namespace SortingAlgorithms
		{
			template <typename T>
			void BubbleSort(T *array, int &size);

			template <typename T>
			void InsertionSort(T *array, int &size);

			template <typename T>
			void SelectionSort(T *array, int &size);

			template <typename T>
			void MergeSort(T *array, int &size);

			template <typename T>
			void QuickSort(T *array, int &size);
		}
	}

}
