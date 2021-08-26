#pragma once

#include "vector"

template <typename T>
static inline void RemoveObjectFromVector(std::vector<T>* data, T object)
{
	for (int i = 0; i < data->size(); i++)
	{
		if ((*data)[i] == object)
		{
			data->erase(data->begin() + i);

			break;
		}
	}
}
