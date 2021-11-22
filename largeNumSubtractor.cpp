#include <iostream>
#include <string>

int main() {
    std::string veryLargeNumberOne, veryLargeNumberTwo;

    veryLargeNumberOne = std::to_string(367);
    veryLargeNumberTwo = std::to_string(35);

    //std::cout << "Enter your first number: ";
    //std::cin >> veryLargeNumberOne;
    //std::cout << "\nEnter your second number: ";
    //std::cin >> veryLargeNumberTwo;

    std::string largeSubtractor(std::string minuend, std::string subtrahend);
    std::cout << largeSubtractor(veryLargeNumberOne, veryLargeNumberTwo);
}

std::string largeSubtractor(std::string minuend, std::string subtrahend) {
    int workingDigitMinuend, workingDigitMinuendTwo, workingDigitSubtrahend, difference, borrowedDigit;
    std::string workingCharMinuend, borrowedChar, workingCharSubtrahend, finalDifference, workingDiffrenceChar;

    while(minuend.length() > 0) {
    }
        // Get the last character in the number and delete it from the number
        workingCharMinuend = minuend.back();
        minuend.pop_back();
        workingCharSubtrahend = subtrahend.back();
        subtrahend.pop_back();

        // Convert working characters to integers
        workingDigitMinuend = std::stoi(workingCharMinuend);
        workingDigitSubtrahend = std::stoi(workingCharSubtrahend);

        // Check weather to use borrow.
        if(workingDigitSubtrahend < workingDigitMinuend) {
            workingDigitMinuend += 10;

            // Works if the digit to borrow from is not 0;
            if(minuend.back() != '0') {
                borrowedChar = minuend.back();
                minuend.pop_back();
                borrowedDigit = std::stoi(borrowedChar) - 1;
                minuend.append(std::to_string(borrowedDigit));

                // Subtract and convert to string
                difference = workingDigitMinuend - workingDigitSubtrahend;
                workingDiffrenceChar = std::to_string(difference);
            }
            // Case to handle borrow digits that are 0's
            else {
                int borrowHoldDigit, counter = 0;
                std::string borrowHold;

                // Get number of 0's in a row to determine the borrow path.
                while(minuend.back() == '0') {
                    minuend.pop_back();
                    counter++;
                }

                // Subtract the borrow digit
                borrowHold = minuend.back();
                borrowHoldDigit = std::stoi(borrowHold);
                minuend.pop_back();
                minuend.append(std::to_string(borrowHoldDigit - 1));

                // Set the borrow path
                std::string nines = "";
                for(int i = 0; i <= counter; i++) {
                    nines.push_back('9');
                }
                minuend.append(nines);

                // Subtract and convert to string
                workingDigitMinuend += 10;
                difference = workingDigitMinuend - workingDigitSubtrahend;
                workingDiffrenceChar = std::to_string(difference);
            }

            // Add the digit difference to the final difference
            finalDifference = workingDiffrenceChar + finalDifference;
        }

        // Numbers that don't need borrow
        else {
            difference = workingDigitMinuend - workingDigitSubtrahend;
            workingDiffrenceChar = std::to_string(difference);

            finalDifference = workingDiffrenceChar + finalDifference;
        }
    
    return finalDifference;
}