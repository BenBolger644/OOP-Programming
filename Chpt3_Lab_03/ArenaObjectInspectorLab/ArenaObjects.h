#pragma once

class ArenaObject
{
public:
	virtual ~ArenaObject() = default;
	virtual void report() const = 0;
};

class Guard : public ArenaObject
{
public:
	explicit Guard(int t_health);
	void report() const override;
	int health() const;

private:
	int m_health;
};

class EliteGuard : public Guard
{
public:
	EliteGuard(int t_health, int t_bonus);
	void report() const override;
	int bonus() const;

private:
	int m_bonus;
};

class SupplyCrate : public ArenaObject
{
public:
	explicit SupplyCrate(int t_items);
	void report() const override;
	int items() const;

private:
	int m_items;
};
