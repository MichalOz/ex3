#ifndef _HEALTH_POINTS_
#define _HEALTH_POINTS_
const int MAX_HP_DEFAULT = 100;

class HealthPoints
{
public:
    class InvalidArgument{};
    HealthPoints(int max_hp = MAX_HP_DEFAULT);
    HealthPoints(const HealthPoints& otherHp) = default;
    HealthPoints& operator=(const HealthPoints& otherHp) = default;
    ~HealthPoints() = default;
    HealthPoints& operator+=(const int hp);
    HealthPoints& operator-=(const int hp);

private:
    int m_maxHp;
    int m_currentHp;
    friend std::ostream& operator<<(std::ostream&, const HealthPoints& hp);
    friend bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);
};

HealthPoints operator+(const int hp, const HealthPoints& otherHp);
HealthPoints operator+(const HealthPoints& otherHp, const int hp);
HealthPoints operator-(const HealthPoints& otherHp, const int hp);
bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);

#endif