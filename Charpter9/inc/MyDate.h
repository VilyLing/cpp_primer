#pragma once
#include <array>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>

//接受 
// 1. Jan 1 1970
// 2. 1/1/1970
// 3. Janary 1, 1970    
//分析需求 第一项为 月份，第二项为日期，第三项为年份
class MyDate{
    public:
    explicit MyDate(std::string const &s)
    {
        if (s.empty()) {
            return;
        }

        std::string symbol = " /,";

        if (s.find_first_of(symbol) == std::string::npos) {
            throw std::invalid_argument("Invalid date format");
        }
        
        auto pos1 = s.find_first_of(symbol);
        std::string month = s.substr(0, pos1);

        setMonth(month);

        auto pos2 = s.find_first_of(symbol, pos1 + 1);

        std::string date = s.substr(pos1+1,pos2-pos1-1);

        m_date = std::stoi(date);

        std::string year = s.substr(pos2+1);

        m_year = std::stoi(year);
    }
    public:
        void print() const {
            std::cout << m_year << "-" 
                      << m_month << "-"
                      << m_date << std::endl;
        }
    private:
        unsigned m_year = 1970;
        unsigned m_month = 1;
        unsigned m_date = 1;

        std::array<std::string, 12> m_months = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };

        void setMonth(std::string const &month) {
            if (month.empty()) {
                return;
            }

            if (std::isdigit(month[0])) {
                m_month = std::stoi(month);
            } else {
                for (size_t i = 0; i < m_months.size(); ++i) {
                    if (month.find_first_of(m_months[i]) != std::string::npos) {
                        m_month = i + 1;
                        break;
                    }
                }
            }
        }
};