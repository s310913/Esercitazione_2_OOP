#pragma once

template<typename T> requires std::floating_point<T>
class complex_number
{
	T m_re;
	T m_ima;

public:
	complex_number()
		: m_re(0), m_ima(0)
	{}

	explicit complex_number(T r)
		: m_re(r), m_ima(0)
		{
			std::cout << "converting constructor called" << std::endl;
		}

	complex_number(T r, T i)
		: m_re(r), m_ima(i)
	{}

	T re(void) const {
		return m_re;
	}

	T ima(void) const {
		return m_ima;
	}

	complex_number<T> conj(void) const {
		return complex_number(m_re, -m_ima);
	}
	
	complex_number& operator+=(const complex_number& other) {
		T re1 = m_re;
		T ima1 = m_ima;
		T re2 = other.m_re;
		T ima2 = other.m_ima;
		m_re = re1 + re2;
		m_ima = ima1 + ima2;
		return *this;
	}
	
	complex_number operator+(const complex_number& other) const {
		complex_number ret = *this;
		ret += other;
		return ret;
	}
	
	complex_number& operator+=(const T& other) {
		m_re += other;
		return *this;
	}
	
	complex_number& operator+(const T& other) const {
		complex_number ret = *this;
		ret += other;
		return ret;
	}
	
	complex_number& operator*=(const complex_number& other) {
		T re1 = m_re;
		T ima1 = m_ima;
		T re2 = other.m_re;
		T ima2 = other.m_ima;
		m_re = re1*re2 - ima1*ima2;
		m_ima = re1*ima2 + ima1*re2;
		return *this;
	}
	
	complex_number operator*(const complex_number& other) const {
		complex_number ret = *this;
		ret *= other;
		return ret;
	}

	complex_number& operator*=(const T& other) {
		m_re *= other;
		m_ima *= other;
		return *this;
	}
	
	complex_number operator*(const T& other) const {
		complex_number ret = *this;
		ret *= other;
		return ret;
	}
};

double err = 1.0e-6;
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& n) {
	if (abs(n.ima()) < err)
		os << n.re();
	else if (abs(n.re()) < err)
		os << n.ima() << "i";
	else if (n.ima() < -err)
		os << n.re() << n.ima() << "i";
	else if (n.ima() > err)
		os << n.re() << "+" << n.ima() << "i";
	return os;
}


