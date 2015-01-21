#ifndef POKER_ID_CONTAINER
#define POKER_ID_CONTAINER

#include <map>

/// @brief container storing elements with unique ids
template <class T>
class IdContainer {
public:
	std::map<int, T> data_;

	/// @brief Add element to container
	/// @return id given to it
	int add(const T &val) {
		int id = findFreeId();
		data_[id] = val;
		return id;
	}

	/// @brief Remove element with given id
	void remove(const int id) {
		data_.erase(id);
	}
	
	/// @brief Returns id which can be binded to new element
	int findFreeId() {
		int ret = 0;
		while (data_.find(ret) != data_.end()) ++ret;
		return ret;
	}

	/// @brief Checks if given key is used
	/// @return true if k is used by an element, false otherwise
	bool exist(int k) {
		return data_.find(k) != data_.end();
	}

	/// @brief Get element associated with given key, assuming it exists
	T &get(int k) {
		return data_.find(k)->second;
	}
};

#endif
