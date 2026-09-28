#include "Dispatch.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

int main()
{
	Dispatch::printHeading();

	std::cout << "Enter the depot name: ";
	std::string depotName;
	if (!std::getline(std::cin, depotName))
	{
		std::cerr << "Error reading depot name. Input ended unexpectedly.\n";
		return 1;
	}

	int requestedUnits = 0;
	bool haveValidRequest = false;

	while (!haveValidRequest)
	{
		std::cout << "Enter the number of units to dispatch (0-60): ";
		if (std::cin >> requestedUnits)
		{
			// Numeric Prefix policy even if extra characters follow on the same line, we will ignore them and only consider the numbers
			// Discard the remainder of line so it cant be misread as a second value later.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (requestedUnits >= 0 && requestedUnits <= 60)
			{
				haveValidRequest = true;
			}
			else
			{
				std::cerr << "Requested units must be between 0 and 60. Please try again.\n";
			}
		}
		else
		{
			// Checked after a failed extraction: eof() is true if the end of the input stream has been reached, otherwise it is false. If eof() is true, then the input stream has been closed and no more input can be read. If eof() is false, then the input stream is still open and more input can be read.
			if (std::cin.eof())
			{
				std::cerr << "Input ended before a valid request was received.\n";
				return 1;
			}
			else
			{
				// A failed extraction leaves the stream in a failed state
				// Clear the failed state and ignore the rest of the line to prepare for the next input attempt
				// These are needed or the same input will be read again and again, causing an infinite loop.
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "Invalid input. Try Again. \n";
			}
		}
	}

	// Checks if the file "batches.txt" exists and can be opened
	std::ifstream batchFile("batches.txt");
	if (!batchFile.is_open())
	{
		std::cerr << "Error: could not open batches.txt.\n";
		return 1;
	}

	int batchCount = 0;
	int totalStock = 0;
	int lowBatchCount = 0;

	int value = 0;

	while (true)
	{
		batchFile >> std::ws;
		if (batchFile.eof())
		{
			break;
		}

		if (!(batchFile >> value))
		{
			if (batchFile.bad())
			{
				std::cerr << "Error reading from batches.txt.\n";
			}
			else
			{
				std::cerr << "Invalid data in batches.txt. Expected an integer.\n";
			}
			return 1;
		}

		if (value < 0 || value > 40)
		{
			std::cerr << "Invalid batch value in batches.txt. Expected a value between 0 and 40.\n";
			return 1;
		}

		++batchCount;
		if (batchCount > 12)
		{
			std::cerr << "Error: more than 12 batches in batches.txt.\n";
			return 1;
		}

		totalStock += value;
		if (value < 10)
		{
			++lowBatchCount;
		}
	}

	if (batchCount == 0)
	{
		std::cerr << "Error: no batches found in batches.txt.\n";
		return 1;
	}

	int dispatchedUnits = 0;
	if (requestedUnits <= totalStock)
	{
		dispatchedUnits = requestedUnits;
	}
	else
	{
		dispatchedUnits = totalStock;
	}

	int availableStock = totalStock;
	int dispatchCount = 0;
	int* selectedQuantity = &availableStock;

	*selectedQuantity -= dispatchedUnits;

	selectedQuantity = &dispatchCount;

	if (dispatchedUnits > 0)
	{
		*selectedQuantity = *selectedQuantity + 1;
	}

	std::cout << "Depot: " << depotName << '\n';
	std::cout << "Batches: " << batchCount << '\n';
	std::cout << "Low Batches: " << lowBatchCount << '\n';
	std::cout << "OriginalStock: " << totalStock << '\n';
	std::cout << "Requested Units: " << requestedUnits << '\n';
	std::cout << "Dispatched Units: " << dispatchedUnits << '\n';
	std::cout << "AvailableStock: " << availableStock << '\n';
	std::cout << "Dispatch Count: " << dispatchCount << '\n';

	selectedQuantity = nullptr;

	if (selectedQuantity != nullptr)
	{
		std::cout << "Selected Quantity: " << *selectedQuantity << '\n';
	}
	else
	{
		std::cout << "No Quantity Selected.\n";
	}

	return 0;

}