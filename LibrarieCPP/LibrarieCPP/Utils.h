#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

namespace Utils
{
	namespace Functions
	{
		template <typename T>
		int BinarySearchArray(T* array, int size, T value)
		{
			int left = 0;
			int right = size - 1;
			int middle = 0;
			while (left <= right)
			{
				middle = (left + right) / 2;
				if (array[middle] == value)
					return middle;
				else if (array[middle] < value)
					left = middle + 1;
				else
					right = middle - 1;
			}
			return -1;
		}

		template <typename T>
		int BinarySearchSubArray(T* array, int left, int right, T value)
		{
			int middle = 0;
			while (left <= right)
			{
				middle = (left + right) / 2;
				if (array[middle] == value)
					return middle;
				else if (array[middle] < value)
					left = middle + 1;
				else
					right = middle - 1;
			}
			return -1;
		}

		template <typename T>
		int BinarySearchVector(std::vector<T> array, T value)
		{
			int left = 0;
			int right = array.size() - 1;
			int middle = 0;
			while (left <= right)
			{
				middle = (left + right) / 2;
				if (array[middle] == value)
					return middle;
				else if (array[middle] < value)
					left = middle + 1;
				else
					right = middle - 1;
			}
			return -1;
		}

		template <typename T>
		int BinarySearchSubVector(std::vector<T> array, int left, int right, T value)
		{
			int middle = 0;
			while (left <= right)
			{
				middle = (left + right) / 2;
				if (array[middle] == value)
					return middle;
				else if (array[middle] < value)
					left = middle + 1;
				else
					right = middle - 1;
			}
			return -1;
		}

		//Sorting algorithms
		template <typename T>
		void BubbleSortArray(T* array, int size)
		{
			for (int i = 0; i < size - 1; i++)
			{
				for (int j = 0; j < size - i - 1; j++)
				{
					if (array[j] > array[j + 1])
					{
						T temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
					}
				}
			}
		}
		
		template <typename T>
		void BubbleSortVector(std::vector<T> array)
		{
			for (int i = 0; i < array.size() - 1; i++)
			{
				for (int j = 0; j < array.size() - i - 1; j++)
				{
					if (array[j] > array[j + 1])
					{
						T temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
					}
				}
			}
		}

		template <typename T>
		void InsertionSortArray(T* array, int size)
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
		void InsertionSortVector(std::vector<T> array)
		{
			for (int i = 1; i < array.size(); i++)
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
		void SelectionSortArray(T* array, int size)
		{
			for (int i = 0; i < size - 1; i++)
			{
				int min = i;
				for (int j = i + 1; j < size; j++)
				{
					if (array[j] < array[min])
						min = j;
				}
				T temp = array[min];
				array[min] = array[i];
				array[i] = temp;
			}
		}

		template <typename T>
		void SelectionSortVector(std::vector<T> array)
		{
			for (int i = 0; i < array.size() - 1; i++)
			{
				int min = i;
				for (int j = i + 1; j < array.size(); j++)
				{
					if (array[j] < array[min])
						min = j;
				}
				T temp = array[min];
				array[min] = array[i];
				array[i] = temp;
			}
		}

		template <typename T>
		void MergeSortArray(T* array, int left, int right)
		{
			if (left < right)
			{
				int middle = (left + right) / 2;
				MergeSortArray(array, left, middle);
				MergeSortArray(array, middle + 1, right);
				MergeArray(array, left, middle, right);
			}
		}

		template <typename T>
		void MergeSortVector(std::vector<T> array, int left, int right)
		{
			if (left < right)
			{
				int middle = (left + right) / 2;
				MergeSortVector(array, left, middle);
				MergeSortVector(array, middle + 1, right);
				MergeVector(array, left, middle, right);
			}
		}
		
		template <typename T>
		int PartitionArray(T* array, int left, int right, bool isReversed)
		{
			T pivot = array[right];
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (isReversed)
				{
					if (array[j] <= pivot)
					{
						i++;
						T temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
				else {
					if (array[j] >= pivot)
					{
						i++;
						T temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}

			}
			return i;
		}
		
		template <typename T>
		void QuickSortArray(T* array, int left, int right)
		{
			if (left < right)
			{
				int pivot = PartitionArray(array, left, right);
				QuickSortArray(array, left, pivot - 1);
				QuickSortArray(array, pivot + 1, right);
			}
		}

		//partition vector
		template <typename T>
		int PartitionVector(std::vector<T> array, int left, int right, bool isReversed)
		{
			T pivot = array[right];
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (isReversed)
				{
					if (array[j] <= pivot)
					{
						i++;
						T temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
				else
				{
					if (array[j] >= pivot)
					{
						i++;
						T temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}
			}
			return i;
		}
		
		
		template <typename T>
		void QuickSortVector(std::vector<T> array, int left, int right)
		{
			if (left < right)
			{
				int pivot = PartitionVector(array, left, right);
				QuickSortVector(array, left, pivot - 1);
				QuickSortVector(array, pivot + 1, right);
			}
		}
		
		
	}

	template<typename T>
	void PrintArray(const T* array, const int& size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << '\n';
	}

	template<typename T>
	void WriteArrayToFile(std::string fileName, const T* array, const int& size)
	{
		std::ofstream file(fileName);
		for (int i = 0; i < size; i++)
		{
			file << array[i] << " ";
		}
		file.close();
	}

	template<typename T>
	std::pair<T*,int> ReadArrayFromFile(std::string fileName)
	{
		std::ifstream file(fileName);
		if (!file.is_open())
		{
			std::cout << "File not found!\n";
			return std::make_pair(nullptr, 0);
		}

		int size;
		file >> size;
		T* array = new T[size];
		for (int i = 0; i < size; i++)
			file >> array[i];
		
		file.close();
		return std::make_pair(array, size);
	}

	template<typename T>
	void PrintVector(const std::vector<T>& vector)
	{
		for (const auto& element : vector)
		{
			std::cout << element << " ";
		}
		std::cout << '\n';
	}

	template<typename T>
	void PrintMatrix(const std::vector<std::vector<T>>& matrix)
	{
		for (const auto& vector : matrix)
		{
			PrintVector(vector);
		}
	}

	template<typename T>
	std::vector<T> ReadVectorFromFileWithUnknownLength(std::string fileName)
	{
		std::ifstream file(fileName);
		std::vector<T> vector;
		T element;
		while (file >> element)
		{
			vector.push_back(element);
		}
		file.close();
		return vector;
	}

	template<typename T>
	std::pair<std::vector<T>, int> ReadVectorFromFileWithLength(std::string fileName)
	{
		int length;
		std::vector<T> vector;
		std::ifstream file(fileName);
		file >> length;
		T element;
		while (file >> element)
		{
			vector.push_back(element);
		}
		file.close();
		return std::make_pair(vector, length);
	}

	template<typename T>
	void WriteVectorToFile(std::string fileName, const std::vector<T>& vector)
	{
		std::ofstream file(fileName);
		for (const auto& element : vector)
		{
			file << element << " ";
		}
		file.close();
	}

	
}
