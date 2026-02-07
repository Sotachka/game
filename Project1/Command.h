#pragma once
class  Command
{
public:
	~Command() {};
	virtual void Execute() = 0;

};

class AttackCommand : public Command
{
public:
	void Execute() override	
	{
		
	}
};