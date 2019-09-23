# C++ Project: Aid Management App (AMA)

This is the final project of Course OOP244 at Seneca College, finished in 2019 Winter Semester.

## Project Overview

When disaster hits a populated area, the most critical task is to provide immediately affected
people with what they need as quickly and as efficiently as possible.
This project completes an application that manages the list of goods that need to be shipped to the disaster area. The client application tracks the quantity of items needed, tracks the quantity on hand, and stores the information in a file for future use.
The types of goods that need to be shipped are of two categories;
- Non-Perishable products, such as blankets and tents, which have no expiry date. We refer to products in this category as Product objects.
- Perishable products, such as food and medicine, that have an expiry date. We refer to products in this category as Perishable.


## Project Developement Process

- [x] Milestone 1: **Date** Class: Hold the expiry date of the perishable items.
- [x] Milestone 2: **ErrorState** Class: Keep track of the error state of client code. Errors may occur during data entry and user interaction.

- [x] Milestone 3: **Product** Class: Manage non-perishable products.
- [x] Milestone 4: **iProduct** Class: An interface to the Product hierarchy. This interface exposes the features of the hierarchy available to the client application.
- [x] Milestone 5: **Perishable** Class: Managing perishable products, also inherit the structure of the “Product” class and manages an expiry date.


For more details, please check the `.pdf` file of each milestone.
