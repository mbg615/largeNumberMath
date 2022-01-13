#include <iostream>
#include <string>

int main() {
    std::string veryLargeNumberOne, veryLargeNumberTwo;

    std::cout << "Enter your first number: ";
    std::cin >> veryLargeNumberOne;
    std::cout << "\nEnter your second number: ";
    std::cin >> veryLargeNumberTwo;

    std::string largeSubtractor(std::string minuend, std::string subtrahend);
    std::cout << largeSubtractor(veryLargeNumberOne, veryLargeNumberTwo) << std::endl;
}

std::string largeSubtractor(std::string minuend, std::string subtrahend) {
    std::string minuendCharEnd, subtrahendCharEnd, differenceCharEnd, finalDifference = "";
    int minuendDigitEnd, subtrahendDigitEnd, differenceDigitEnd;

    // Get initial lenght of strengs to prevent needless recalculations
    const int minuendLength = minuend.length();
    const int subtrahendLength = subtrahend.length();

    // Add leading 0's to make string lengths even
    if(minuendLength != subtrahendLength) {
        if(minuendLength > subtrahendLength) {
            while(subtrahend.length() != minuendLength) {
            subtrahend = '0' + subtrahend; 
            }
        }
        if(subtrahendLength > minuendLength) {
            while(minuend.length() != subtrahendLength) {
                minuend = '0' + minuend;
            }
        }
    }
    

    // Main processing loops
    if(minuendLength <= subtrahendLength) {
        while(minuend.length() != 0){
            // Read and remove the last character of each number
            minuendCharEnd = minuend.back();
            minuend.pop_back();
            subtrahendCharEnd = subtrahend.back();
            subtrahend.pop_back();

            // Convert the last character to an integer
            minuendDigitEnd = std::atoi(minuendCharEnd.c_str());
            subtrahendDigitEnd = std::atoi(subtrahendCharEnd.c_str());

            // Borrow logic
            if(subtrahendDigitEnd > minuendDigitEnd) {
                minuendDigitEnd += 10;

                // Logic for borrow path
                if(minuend.back() == '0') {
                    // Find the number of zeros in a row
                    int count = 0;
                    while(minuend.back() == '0') {
                        count++;
                        minuend.pop_back();
                    }

                    // Fill zeros with 9's
                    std::string nines = "";
                    for(int i = 0; i != count; i++) {
                        nines.push_back('9');
                    }
                }
                // Logic for single borrow
                else {

                    std::string minuendCharEndTemp(1, minuend.back());
                    minuend.pop_back();
                    int minuendDigitEndTemp = std::atoi(minuendCharEndTemp.c_str());
                    minuend.push_back(minuendDigitEndTemp - 1);
                    
                }
            }
            // Borrowless subtraction
            else {
                differenceDigitEnd = minuendDigitEnd - subtrahendDigitEnd;
            }

            // Convert the difference digit to a string
            differenceCharEnd = std::to_string(differenceDigitEnd);

            finalDifference = differenceCharEnd + finalDifference;
        }
    }
    else {

    }

    return finalDifference;
}
