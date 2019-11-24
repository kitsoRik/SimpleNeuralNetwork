#include "inputvalue.h"

InputValue::InputValue(const std::vector<bool>& values,
						const bool expected)
{
	m_values = values;
	m_expected = expected;
}


InputValue::~InputValue()
{

}

std::vector<bool> InputValue::values() const
{
	return m_values;
}

bool InputValue::expected() const
{
	return m_expected;
}
