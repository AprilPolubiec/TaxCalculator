//============================================================================
// Program     : apolubiec_project3.cpp
// Programmer  : April Polubiec
// Date        : November 25, 2018
// Purpose     : Calculate the square footage of homes and their property taxes.
//============================================================================

#include <iostream>
using namespace std;

double totalRoomArea(string room, double&tax);
void calculateTax(double roomAreas[], size_t SIZE, double&totalTax);

int main(){
	const size_t SIZE=4;						//CONSTANT: Stores the size of arrays roomTypes[] and roomAreas[].
	string roomTypes[SIZE]={"kitchen",
			"bathroom", "bedroom",
			"other room"}; 						//OUTPUT: Stores the names of all rooms being measured.
	double roomAreas[SIZE];						//WORKING: Stores the total area for each type of room in the
												//			same order as roomTypes[].
	double totalTax = 0;						//OUTPUT: Stores the total tax owed.

	//Find total area for each room.
	for(size_t i=0; i<SIZE; ++i)
		roomAreas[i] = totalRoomArea(roomTypes[i], totalTax);

	//Calculate total taxes owed.
	calculateTax(roomAreas, SIZE, totalTax);

	//Output total area and taxes owed.
	cout << "Total square footage: " << roomAreas[0] + roomAreas[1]
										+ roomAreas[2] + roomAreas[3]
										<< " square ft." << endl;
	cout << "Total tax: $" << totalTax << endl;

}

//Asks users for how many of room they have and length & width for each room.
//		Finds and returns total area of the room type. Also updates totalTax
//		if a room is luxury size.
//Pre: totalTax and room are defined variables.
//Post: total area of particular room type will be returned. totalTax will
//		be increased if luxury rooms are present.
double totalRoomArea(string room, 					//INPUT: Input argument indicating the room whose area & tax
													//			are being calculated.
						double&totalTax){			//INPUT: Input argument (passed by reference) which accumulates
													//			and stores total tax.
	size_t count = 0;								//INPUT: Stores number of rooms user has.
	double width, 									//INPUT: Stores width of room.
			length, 								//INPUT: Stores length of room.
			area=0;									//OUTPUT: Stores total area for room.
	const int LUXURY_SIZE = 200;					//CONSTANT: Stores the minimum square footage required to be
													//			considered luxury.
	const double LUXURY_TAX = 490;					//CONSTANT: Stores the amount of tax owed for luxury rooms.

	//Ask how many rooms user has.
	cout << "How many " << room << "s do you have?";
	cin >> count;

	//For each room, ask for width and length.
	for(size_t i=1; i<=count; ++i){					//WORKING: Counter for for loop.
		cout << "Enter width of " << room << " " << i << ": ";
		cin >> width;
		cout << "Enter length of " << room << " " << i << ": ";
		cin >> length;

		//Determine if room is "luxury". If so, increase totalTax by LUXURY_TAX.
		if (width*length>=LUXURY_SIZE)
				totalTax += LUXURY_TAX;

		//Increase area.
		area += width*length;
		}

	//Return area.
	return area;
}

//Calculates the total tax owed based on total sq. footage of each area. Changes
//		value of totalTax (which is passed by reference) to reflect calculations.
//Pre: roomAreas[], SIZE and totalTax are defined variables. roomAreas[] contains
//		areas of each room type in the following order: kitchen, bathroom, bedroom, other.
//Post: totalTax equals the total amount of taxes due.
void calculateTax(double roomAreas[], 					//INPUT: Input argument containing total areas for each type of room.
						size_t SIZE, 					//INPUT: Input argument indicating the size of array roomAreas[].
						double&totalTax){				//OUTPUT: Stores total taxes owed.
	const double KITCHEN_TAX=2.99, 						//CONSTANT:Stores the tax rate per square foot for kitchens.
			BATHROOM_TAX=4.99, 							//CONSTANT: Stores the tax rate per square foot for bathrooms.
			BEDROOM_TAX=1.49, 							//CONSTANT: Stores the tax rate per square foot for bedrooms.
			OTHER_TAX=0.49, 							//CONSTANT: Stores the tax rate per square foot for other rooms.
			MINIMUM_TAX=1400;							//CONSTANT: Stores the minimum total tax.
	enum roomAreasEnum{KITCHEN, BATHROOM, BEDROOM, OTHER};

	//Calculate total tax and increase value of totalTax.
	totalTax += (roomAreas[KITCHEN]*KITCHEN_TAX) + (roomAreas[BATHROOM]*BATHROOM_TAX) +
			(roomAreas[BEDROOM]*BEDROOM_TAX) + (roomAreas[OTHER]*OTHER_TAX);

	//Check if total tax is above minimum. If not, set totalTax to MINIMUM_TAX.
	if (totalTax<MINIMUM_TAX)
		totalTax = MINIMUM_TAX;

}
