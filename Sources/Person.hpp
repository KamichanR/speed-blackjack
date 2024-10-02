#pragma once

#include <string>
#include "Hand.hpp"

class Person {
public:
	Person();
	~Person();
	void Reset();
	Hand* GetHand() const;

protected:
	Hand* hand;
};
