  #include <iostream>
  #include <cmath>
  #include <string>

int main() {
  std::string veryLargeNumberOne, veryLargeNumberTwo;

  std::cout << "Enter your first number: ";
  std::cin >> veryLargeNumberOne;
  std::cout << "\nEnter your second number: ";
  std::cin >> veryLargeNumberTwo;

  std::string largeAddder(std::string addendOne, std::string addendTwo);
  std::cout << largeAddder(veryLargeNumberOne, veryLargeNumberTwo);

}

std::string largeAddder(std::string addendOne, std::string addendTwo) {
  int workingDigitOne, workingDigitTwo, workingSumInt = 0, carry = 0;
  std::string workingCharOne, workingCharTwo, finalSum, workingSumChar;
  bool carryFlag = false;

  if (addendOne.length() != addendTwo.length()) {
    // Set the numbers lengths equal
    int stringLengthDiff = addendOne.length() - addendTwo.length();

    if (stringLengthDiff < 0) {
      for (int i = std::abs(stringLengthDiff); i > 0; i--) {
        addendOne = "0" + addendOne;
      }
    }
    else {
      for (int i = stringLengthDiff; i > 0; i--) {
        addendTwo = "0" + addendTwo;
      }
    }
  }

  if (addendOne.length() == addendTwo.length()) { // If the numers are the same length
    // Allows the final carry digit to be added to the front
    addendOne = "0" + addendOne;
    addendTwo = "0" + addendTwo;

    while (addendOne.length() > 0) {
      // Get the last character in the number and delete it from the number
      workingCharOne = addendOne.back();
      addendOne.pop_back();
      workingCharTwo = addendTwo.back();
      addendTwo.pop_back();

      // Convert last character to an integer
      workingDigitOne = std::stoi(workingCharOne);
      workingDigitTwo = std::stoi(workingCharTwo);

      // Add working digits together with carry if necessary
      if (carryFlag) {
        workingSumInt = workingDigitOne + workingDigitTwo + 1;
        carryFlag = false;
      }
      else {
        workingSumInt = workingDigitOne + workingDigitTwo;
      }

      // If the sum is less than 9, add it to the number
      if (workingSumInt < 10) {
        workingSumChar = std::to_string(workingSumInt);
        finalSum = workingSumChar + finalSum;
      } else {
        carryFlag = true;
        workingSumChar = std::to_string(workingSumInt % 10);
        finalSum = workingSumChar + finalSum;
      }
    }
  }

  // Removing leading zero
  if (finalSum.at(0) == '0') {
    finalSum.erase(0,1);
  }
  return finalSum;
}
