#pragma once
#include <bits/stdc++.h>
#include "ModularArithmetic.h"
using namespace std;

// Data structure representing a Fraction modulo a prime MOD
template <class T, const T MOD> struct FractionMod {
    static_assert(is_integral<T>::value, "T must be an integral type");
    static_assert(0 < MOD, "MOD must be a positive integer");
    using FM = FractionMod<T, MOD>; T num, den; FractionMod(T num = 0, T den = 1) : num(posMod(num, MOD)), den(posMod(den, MOD)) {}
    FM operator + (const FM &f) const { return FM(addMod(mulMod(num, f.den, MOD), mulMod(f.num, den, MOD), MOD), mulMod(den, f.den, MOD)); }
    FM &operator += (const FM &f) { num = addMod(mulMod(num, f.den, MOD), mulMod(f.num, den, MOD), MOD); den = mulMod(den, f.den, MOD); return *this; }
    FM operator - (const FM &f) const { return FM(subMod(mulMod(num, f.den, MOD), mulMod(f.num, den, MOD), MOD), mulMod(den, f.den, MOD)); }
    FM &operator -= (const FM &f) { num = subMod(mulMod(num, f.den, MOD), mulMod(f.num, den, MOD), MOD); den = mulMod(den, f.den, MOD); return *this; }
    FM operator * (const FM &f) const { return FM(mulMod(num, f.num, MOD), mulMod(den, f.den, MOD)); }
    FM &operator *= (const FM &f) { num = mulMod(num, f.num, MOD); den = mulMod(den, f.den, MOD); return *this; }
    FM operator / (const FM &f) const { return FM(mulMod(num, f.den, MOD), mulMod(den, f.num, MOD)); }
    FM &operator /= (const FM &f) { T t_num = mulMod(num, f.den, MOD), t_den = mulMod(den, f.num, MOD); num = t_num; den = t_den; return *this; }
    T eval() const { return divModPrime(num, den, MOD); }
    bool operator == (const FM &f) const { return mulMod(num, f.den, MOD) == mulMod(f.num, den, MOD); }
    bool operator != (const FM &f) const { return mulMod(num, f.den, MOD) != mulMod(f.num, den, MOD); }
};
