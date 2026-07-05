# Car Insurance Calculator

## Overview
This is an object-oriented C++ console application designed to calculate annual insurance premiums for different types of vehicles. It uses inheritance and polymorphism to handle specific calculations for Personal, Company, and Fleet cars.

## Features
* **Object-Oriented Design:** Implements a base `Car` class with derived subclasses for `Personalcar`, `Companycar`, and `Fleetcar`.
* **Polymorphism:** The `Calculateinsurance()` method is overridden in each subclass to apply specific premium rate logic based on the vehicle type.
* **Input Validation:** Ensures correct data entry by validating license plate formats, accepting only specific colors (White, Black, Red, Blue), and enforcing 17-character limits for chassis and engine numbers.
* **Memory Management:** Utilizes dynamic memory allocation with the `new` keyword and safely prevents memory leaks using a `delete` loop and a virtual destructor.
