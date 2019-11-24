#pragma once

#include <vector>
class InputValue
{
public:
	InputValue(const std::vector<bool> &values,
				const bool expected);
	~InputValue();

	std::vector<bool> values() const;

	bool expected() const;

private:
	std::vector<bool> m_values;
	bool m_expected;
};

