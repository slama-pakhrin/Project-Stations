

#include "Station.h"
#include "Utilities.h"

namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const string& str) {
        Utilities token;
        size_t next_pos{ 0 };
        bool more{ false };

        if (!str.empty()) {
            s_name = token.extractToken(str, next_pos, more);
            if (more) {
                s_nextSerialNo = std::stoi(token.extractToken(str, next_pos, more));
            }
            if (more) {
                s_numInStock = std::stoi(token.extractToken(str, next_pos, more));
            }
            if (m_widthField < token.getFieldWidth()) {
                m_widthField = token.getFieldWidth();
            }
            if (more) {

            while (str[next_pos] == ' ') {
            next_pos++;
            }
            s_description = token.extractToken(str, next_pos, more);
            }
        }
        s_id = ++id_generator;
    }
    const string& Station::getItemName() const {
        return s_name;
    }
    size_t Station::getNextSerialNumber() {
        return s_nextSerialNo++;
    }
    size_t Station::getQuantity() const {
        return s_numInStock;
    }
    void Station::updateQuantity() {
        s_numInStock = s_numInStock < 0 ? 0 : s_numInStock - 1;
    }
    void Station::display(std::ostream& os, bool full) const {
        os << std::setw(3) << std::setfill('0') << std::right << s_id
            << " | " << std::setw(m_widthField) << std::setfill(' ') << std::left << s_name
            << "| " << std::setw(6) << std::setfill('0') << std::right << s_nextSerialNo << " | ";
        if (full) {
            os <<  std::setw(4) << std::setfill(' ') << s_numInStock
             << " | " <<std::left << s_description;
        }
        os << std::endl;
    }
}
