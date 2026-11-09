// Copyright (c) 2026 Kaylee R All rights reserved.
// .
// Created by: Kaylee R
// Date: 05,11,2026
// This program is for a shipping company. It asks the user
// to enter the dimensions of the package they want to deliver.
// If the weight and the volume of the package are under the limit,
// it lets them select a method of shipping.

#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // declare variables
    std::string pWeight, pLength, pWidth, pHeight, shipping;
    float weightF, lengthF, widthF, heightF, volumeInt;
    int shippingInt;

    // greet user
    std::cout <<"Welcome to TateXpress Shipping \n";

    // get user's package dimensions
    std::cout <<"Please enter you package dimensions \n";
    std::cout <<"Enter the weight in kg: ";
    std::cin >> pWeight;
    std::cout <<"Enter the length in cm: ";
    std::cin >> pLength;
    std::cout <<"Enter the width in cm: ";
    std::cin >> pWidth;
    std::cout <<"Enter the height in cm: ";
    std::cin >> pHeight;

    // try to cast dimensions to decimals
    try {
        weightF = std::stof(pWeight);
        lengthF = std::stof(pLength);
        widthF = std::stof(pWidth);
        heightF = std::stof(pHeight);

        // calculate the package weigth and height
        volumeInt = lengthF * widthF * heightF;

        // show user their package weight and volume
        std::cout <<"Your package weighs " << std::fixed;
        std::cout << std::setprecision(2) << weightF;
        std::cout <<"kg and has a volume of " <<std::fixed;
        std::cout << std::setprecision(2) << volumeInt <<"cm³\n";

        if (weightF >= 27 || volumeInt >= 10000) {
            std::cout <<"Your package exceeds company";
            std::cout <<"weight and volume limits\n";
        } else {
            // let user select shipping method
            std::cout <<"Next, please select your shipping method \n";
            std::cout <<"1 for truck, 2 for cargo and 3 for plane: ";
            std::cin >> shipping;
        } try {
            shippingInt = std::stoi(shipping);

            // check if package is eligable for selected shipping method
            if (shippingInt == 1 && weightF <= 10) {
                std::cout <<"Your package can be delivered by truck \n";
                std::cout <<"Expect delivery in 3-5 business days!";
            } else if (shippingInt == 2 && weightF <= 20) {
                std::cout <<"You package can be delivered by cargo \n";
                std::cout <<"Expect delivery in 3-5 business days!";
            } else if (shippingInt == 3 && weightF <= 27) {
                std::cout <<"Your package can be delivered by plane \n";
                std::cout <<"Expect delivery in 3-5 business days!";
            } else {
                std::cout <<"Your package is too heavy for";
                std::cout <<" the shipping method \n";
                std::cout <<"Please select a different shipping method";
            }
        } catch(std::invalid_argument) {
            std::cout <<"Please select the right shipping method";
        }
    } catch(std::invalid_argument) {
        std::cout <<"Dimension inputs must be integers";
    }
}
