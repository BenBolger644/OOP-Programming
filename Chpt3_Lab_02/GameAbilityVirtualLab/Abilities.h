#ifndef ABILITIES_H
#define ABILITIES_H

class GameAbility
{
public:
	explicit GameAbility(int t_power);
	virtual ~GameAbility();

	virtual void activate() const = 0;
	int power() const;

private:
	int m_power;
};

class ShieldAbility : public GameAbility
{
public:
	explicit ShieldAbility(int t_power);
	void activate() const override;
};

class HealAbility : public GameAbility
{
public:
	explicit HealAbility(int t_power);
	~HealAbility() override;
	void activate() const override;
};

#endif
