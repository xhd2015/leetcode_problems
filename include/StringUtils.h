
#ifndef StringUtils_h__
#define StringUtils_h__

#include <string>
#include <iterator>
#include <numeric>
#include <vector>

namespace x2{
	std::string toString(int x);
	std::string toString(char ch);
	std::string toString(bool b);


	std::string toString(int *arr,int sz);
	std::string toString(int *arr,int rowsz,int colsz);

	template <class U,class V>
	std::string toString(const std::pair<U,V> & p);

	template <class T>
	std::string toString(const T& t);
	template <class T>
	std::string toString(const std::vector<T>& vec);

	template <class T>
	std::string toString(const std::vector<std::vector<T>> & vec);
	template <class T>	std::string sumVecString(std::string s,T t);
}

namespace x2{
//===========template syntax
	template <class U,class V>
	std::string toString(const std::pair<U,V> & p)
	{
		return std::string("<")+toString(p.first) + "," + toString(p.second) +">";
	}
	template <class T>
	std::string toString(const T& t)
	{
		return "UNKNOWN TYPE";
	}

	template <class T>
	std::string toString(const std::vector<T>& vec)
	{
		return std::accumulate(vec.begin(),vec.end(),std::string("["),sumVecString<T>)+"]";
	}

	template <class T>
	std::string toString(const std::vector<std::vector<T>> & vec)
	{
		std::string s="{\n";
		for(auto &eachvec:vec)
		{
			s+=std::string("\t") + toString(eachvec) + "\n";
		}
		s+="}";
		return s;
	}
	template <class T>
		std::string sumVecString(std::string s,T t)
		{
		//		std::cout << s <<std::endl;
			return s + toString(t) + ", ";
		}

}

#endif //StringUtils_h__
