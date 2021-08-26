#pragma once

#include "..\Common.h"
#include "assert.h"
#include "string"
#include "vector"
#include "string"
#include "iostream"

class Tree;

static bool GetSector(double& s0, double& s1, double check)
{
	assert(s1 > s0 && check >= s0 && check <= s1);

	double size = (s1 - s0);
	double place = (check - s0) / size;

	if (place >= 0.5)
	{
		s0 += size / 2;

		return 1;
	}

	s1 -= (size / 2);

	return 0;
}

class TreeIndexer
{
private:

	int Dimensions;
	int Range;

public:

	TreeIndexer(int Dimensions, int Range)
	{
		assert(Dimensions < 32 && Dimensions > 0);

		this->Dimensions = Dimensions;
		this->Range = Range;
	}

	void GetIndexes(int* des, double* LocationVector, int Depth)
	{
		memset(des, 0, Depth * sizeof(int));

		int HelperSize = (Dimensions) * 2;

		double* Helpers = new double[HelperSize];

		for (int i = 0; i < HelperSize / 2; ++i)
		{
			Helpers[i * 2] = 0;
			Helpers[(i * 2) + 1] = Range;
		}

		for (int level = 0; level < Depth; ++level)
		{
			for (int axis = 0; axis < Dimensions; ++axis)
			{
				int index = axis * 2;

				des[level] |= (GetSector(Helpers[index], Helpers[index + 1], LocationVector[axis]) & 1) << axis;
			}
		}

		delete[] Helpers;
	}
};

class TreeNode
{
public:

	Tree* Base = nullptr;
	TreeNode* Parent = nullptr;
	TreeNode* Children = nullptr;
	int Index = 0;
	int ChildCount = 0;
	bool IsActive = false;

	TreeNode()
	{

	}

	TreeNode(Tree* Base, TreeNode* Parent, int Index, int ChildCount)
	{
		this->Base = Base;
		this->Parent = Parent;
		this->Index = Index;
		this->ChildCount = ChildCount;
	}

	void Activate()
	{
		if (IsActive)
			return;

		IsActive = true;

		Children = new TreeNode[ChildCount];

		for (int i = 0; i < ChildCount; ++i)
		{
			Children[i] = TreeNode(Base, Parent, i, ChildCount);
		}
	}

	void DeActivate()
	{
		if (!IsActive)
			return;

		IsActive = false;

		if (Children != nullptr)
		{
			for (int i = 0; i < ChildCount; ++i)
			{
				Children[i].DeActivate();
			}

			delete[] Children;
		}
	}
};

class Tree
{
public:

	TreeNode* Base;
	TreeIndexer* indexer;

	Tree(int Dimensions, int Range)
	{
		Base = new TreeNode(nullptr, nullptr, 0, 1 << Dimensions);
		indexer = new TreeIndexer(Dimensions, Range);
	}

	~Tree()
	{
		Base->DeActivate();

		delete Base;
		delete indexer;
	}

	void ComitActionBasedOnLocation(double* LocationVector, int depth)
	{
		int* Indexes = new int[depth];

		indexer->GetIndexes(Indexes, LocationVector, depth);

		TreeNode* Current = Base;

		for (int i = 0; i < depth; ++i)
		{
			int index = Indexes[i];

			Current->Activate();

			Current = &Current->Children[index];
		}

		delete[] Indexes;
	}
};