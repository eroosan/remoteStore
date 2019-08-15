#ifndef INTERVALMAP_CPP_
#define INTERVALMAP_CPP_

#include <map>
#include <limits>
#include <iostream>
template <typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

	void showMap() {
		std::cout << "---------" << std::endl;
		for (auto it = m_map.begin(); it != m_map.end(); ++it) {
			std::cout << "1: " << it->first << " 2: " << it->second
					<< std::endl;
		}
		std::cout << "---------" << std::endl;
	}

public:
	interval_map(V const& val) {
		m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(), val));
	}
	virtual ~interval_map() = default;

	bool assign(K const& keyBegin, K const& keyEnd, V const& val)
	{
		if (keyBegin >= keyEnd) return false;

		auto lowerBound = m_map.lower_bound(keyBegin);
		auto upperBound = m_map.upper_bound(keyEnd-1);

		if (lowerBound->second != 0 && upperBound ->second != 0 )
		{
			if (((std::prev(lowerBound))->second == val) || (upperBound->second == val))
				return false;
		}

		if (upperBound->second == 0)
		{
			if (upperBound != m_map.end())
				m_map.erase(lowerBound, std::prev(upperBound));
			m_map.insert(std::make_pair(keyEnd,std::prev(lowerBound)->second));
		}



		if (keyEnd < m_map.upper_bound(keyEnd)->first)
			m_map.insert(std::make_pair(keyEnd,std::prev(lowerBound)->second));

		m_map.insert(std::make_pair(keyBegin,val));

		return true;
	}

	V const& operator[]( K const& key ) const {
		return (--m_map.upper_bound(key))->second;
	}

	auto getMap() const
	{
		return m_map;
	}


//	interval_map(interval_map &&other);
//	interval_map(const interval_map &other);
//	interval_map& operator=(const interval_map &other);
//	interval_map& operator=(interval_map &&other);
};
//
//int main() {
//	interval_map<unsigned short,char> imap('F');
//}
#endif /* INTERVALMAP_CPP_ */
