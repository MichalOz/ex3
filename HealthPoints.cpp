#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHp) {
    if (maxHp <= 0) {
        throw InvalidArgument();
    } else{
        m_maxHp = maxHp;
    }
    m_currentHp = m_maxHp;
}

HealthPoints &HealthPoints::operator+=(const int hp) {
    m_currentHp += hp;
    if (m_currentHp > m_maxHp) {
        m_currentHp = m_maxHp;
    } else if (m_currentHp < 0) {
        m_currentHp = 0;
    }
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int hp) {
    *this += (hp * (-1));
    return *this;
}

HealthPoints operator+(const int hp, const HealthPoints &hpObject) {
    HealthPoints result = hpObject;
    result += hp;
    return result;
}

HealthPoints operator+(const HealthPoints &hpObject, const int hp) {// what if hpObj is null
    return (hp + hpObject);
}

HealthPoints operator-(const HealthPoints &hpObject, const int hp) {
    return (hpObject + (hp * (-1)));
}

bool operator<(const HealthPoints &hp1, const HealthPoints &hp2) {
    return (hp1 <= hp2) && (hp1 != hp2);
}

bool operator>(const HealthPoints &hp1, const HealthPoints &hp2) {
    return (hp1 >= hp2) && (hp1 != hp2);
}

bool operator<=(const HealthPoints &hp1, const HealthPoints &hp2) {
    return hp1.m_currentHp <= hp2.m_currentHp;
}

bool operator>=(const HealthPoints &hp1, const HealthPoints &hp2) {
    return hp2 <= hp1;
}

bool operator==(const HealthPoints &hp1, const HealthPoints &hp2) {
    return (hp1 <= hp2) && (hp2 <= hp1);
}

bool operator!=(const HealthPoints &hp1, const HealthPoints &hp2) {
    return !(hp1 == hp2);
}

std::ostream &operator<<(std::ostream &os, const HealthPoints &hp) {
    os << hp.m_currentHp << '(' << hp.m_maxHp << ')';
    return os;
}
