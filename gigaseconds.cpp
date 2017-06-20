#include <iostream>
#include <sstream>
#include <locale>
#include <ctime>
#include <iomanip>
 
int main(int argc, const char* argv[])
{
    std::cout << argc << "\n";

    if (argc < 3) {
        printf("Input Error. Use this format\nD-M-Y H:M:S\n");
        exit(1);
    }
    std::string date;
    date = date.assign(argv[1]) + ' ' + date.assign(argv[2]);
    std::istringstream ss(date);

    std::tm t = {}; 
    // ----- tm: Structure holding a calendar date and time broken down into its components. 
    ss.imbue(std::locale("it_IT.utf-8")); 
    ss >> std::get_time(&t, "%d-%m-%Y %H:%M:%S");
    if (ss.fail()) {
        std::cout << "Parse failed\nUse this format\nD-M-Y H:M:S\n";
        return 1;
    }
    
    std::time_t time = mktime(&t); 
    // ----- time_t : Arithmetic type capable of representing times. 
    // ----- mktime() : Converts local calendar time to a time since epoch as a time_t object.
    //std::cout << std::asctime(std::localtime(&time));
    //std::cout << time << "\n";
    time += 1000000000;
    t = *std::localtime(&time); 
    // ----- localtime : Converts given time since epoch as std::time_t value into calendar time, expressed in local time. 
    //std::cout << time << "\n";
    //std::cout.imbue(std::locale("it_IT.utf-8"));
    std::cout << "Your 10^9th second of life: " << std::put_time(&t, "%c %Z") << '\n'; 
    // ----- put_time(tmb, fmt) : Converts the date and time information from a given calendar time tmb...
    // ----- ... to a character string according to format string fmt,

    return 0;
}