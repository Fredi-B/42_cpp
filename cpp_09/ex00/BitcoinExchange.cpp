#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &input, std::ifstream &data) : input(input)
{
    std::string next_line;

    // skip first line
    std::getline(data, next_line);
    int i = 0;
    while (std::getline(data, next_line))
    {
        this->fillExchangeRate(next_line, ",");
        i++;
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::fillExchangeRate(std:: string line, std::string delim)
{
    std::string         _date;
    std::string         _value_string;
    std::stringstream   magical_converter_stream;
    std::pair<std::string, double>  data;

    data.first = line.substr(0, line.find(delim));
    data.second = -1;
    _value_string = line.erase(0, line.find(delim));
    if (_value_string != "")
        _value_string = line.erase(0, delim.length());
    magical_converter_stream << _value_string;
    magical_converter_stream >> data.second;
    this->exchange_rate.insert(data);
    return ;
}

double  BitcoinExchange::getAmount(std::string date)
{

}

//copilot
// std::pair<std::string, double>  BitcoinExchange::getExchangeRate(std::string date)
// {
//     std::pair<std::string, double>  data;
//     std::map<std::string, double>::iterator it = this->exchange_rate.begin();
//     while (it != this->exchange_rate.end())
//     {
//         if (it->first == date)
//         {
//             data.first = it->first;
//             data.second = it->second;
//             return (data);
//         }
//         it++;
//     }
//     data.first = "Error";
//     data.second = -1;
//     return (data);
// }