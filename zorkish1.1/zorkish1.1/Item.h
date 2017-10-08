#pragma once

//---------------------------------Item_Class---------------------------------
class Item
{
public:

	Item()
	{
	}

	~Item()
	{
	}
	std::string itemName;

	inline std::string printItems() const
	{
		return this->itemName;
	};
};
