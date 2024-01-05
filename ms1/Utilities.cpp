

#include "Utilities.h"

namespace sdds {

	char Utilities::m_delimiter = ','; 

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string token{};
		size_t first_pos = next_pos;
		next_pos = str.find(m_delimiter, first_pos);

		if (first_pos == next_pos) {
			more = false;
			throw "No token found!";
		}
		else if (next_pos != string::npos) { 
			token = str.substr(first_pos, next_pos - first_pos);
			m_widthField = std::max(token.length(), m_widthField); 
			more = true;
		}
		else if (next_pos == string::npos) { 
			token = str.substr(first_pos);
			m_widthField = std::max(token.length(), m_widthField);
			more = false;
		}
		next_pos++;
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}