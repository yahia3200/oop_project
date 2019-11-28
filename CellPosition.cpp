#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///done: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}
	else
	{
		
		return false; // this line sould be changed with your implementation
	}
}

bool CellPosition::SetHCell(int h)
{
	///done: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	else
	{
	
		return false; // this line sould be changed with your implementation
	}
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file (Done)
	if (vCell == -1 || hCell == -1)
		return false; //Setters aren't Called
	else return true; //Setters are called
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	//CellPosition position = cellPosition;
	int vc = cellPosition.VCell();
	int hc = cellPosition.HCell();
	int cellNum = 0;
	///Done: Implement this function as described in the .h file
	if (vc != -1 && hc != -1)
	{
		
		if (hc > vc)
		{
			--vc;
		}
		cellNum += 10 * (8 - vc);
		if (hc > vc)
		{
			vc++;
			cellNum += hc - (vc + 1);
		}
		else
		{
			cellNum += hc + 1 + (8 - vc);
		}
	}
	else
	{
		cellNum = -1;
	}
	return cellNum; // this line should be changed with your implementation

}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	if (cellNum >= 1 && cellNum <= 99)
	{
		if (cellNum % 11 == 0)
		{
			position.SetHCell(10);

		}
		else
		{
			position.SetHCell(10 - (11 - cellNum % 11));
		}

		if (cellNum / 10 == 9)
		{
			position.SetVCell(0);

		}
		else
		{
			position.SetVCell(8 - cellNum / 10);

		}

		if (position.HCell() > position.VCell() && cellNum / 10 != 9)
		{
			position.SetVCell(position.VCell() + 1);

		}
	}

	else
	{
		position.SetVCell(-1);
		position.SetHCell(-1);
	}
	/// Done: Implement this function as described in the .h file
	


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file (Done)
	//int NewCellNumber = addedNum+GetCellNum();
	GetCellPositionFromNum(addedNum + GetCellNum());

	// Note: this function updates the data members (vCell and hCell) of the calling object

}