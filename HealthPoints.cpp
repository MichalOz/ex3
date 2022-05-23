#include "HealthPoints.h"

bool HealthPoints::operator<(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1 <= hp2) && (hp1 != hp2);
}

bool HealthPoints::operator>(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1 >= hp2) && (hp1 != hp2);
}

bool HealthPoints::operator<=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.m_Hp <= hp2.m_Hp;
}
bool HealthPoints::operator>=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.m_Hp >= hp2.m_Hp;
}

bool HealthPoints::operator==(const HealthPoints& hp1, const HealthPoints& hp2) {
    return (hp1<=hp2) && (hp2<=hp1);
}

bool HealthPoints::operator!=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return !(hp1 == hp2);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp) {
    os << hp.m_healthHp<<'('<<hp.m_maxHp<<')';
    return os;
}
