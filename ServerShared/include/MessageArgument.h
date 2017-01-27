#pragma once

class MessageArgument
{
private:
	union Value
	{
		int i;
		float f;
		void* v;
	};

public:
	explicit MessageArgument(int val);
	explicit MessageArgument(float val);
	explicit MessageArgument(void* val);

	int Int() const;
	float Float() const;
	void* VoidPointer() const;

private:
	Value val;
};